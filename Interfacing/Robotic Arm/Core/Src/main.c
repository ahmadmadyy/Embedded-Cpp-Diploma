#include "main.h"

class ServoMotor
{
public:
    ServoMotor() {
        RCC->APB2ENR |= RCC_APB2ENR_IOPAEN; // Enable GPIOA clock
        GPIOA->CRL |= (GPIO_CRL_MODE1_1 | GPIO_CRL_CNF1_1); // Configure PA1 as an output with 2 MHz speed and alternate function push-pull

        // Configure Timer2 for PWM generation
        RCC->APB1ENR |= RCC_APB1ENR_TIM2EN; // Enable Timer2 clock
        TIM2->PSC = 72 - 1; // Prescaler to get a 1 MHz timer clock
        TIM2->ARR = 20000 - 1; // Auto-reload value for 20 ms period (50 Hz)
        TIM2->CCR2 = 1500; // Initial pulse width for center position

        // Configure PWM mode 1 for CH2 (connected to PA1)
        TIM2->CCMR1 |= (TIM_CCMR1_OC2M_2 | TIM_CCMR1_OC2M_1);
        TIM2->CCMR1 &= ~TIM_CCMR1_OC2M_0;
        TIM2->CCMR1 |= TIM_CCMR1_OC2PE; // Enable preload for CH2

        TIM2->CCER |= TIM_CCER_CC2E; // Enable capture/compare channel 2 output
        TIM2->CR1 |= TIM_CR1_CEN; // Enable Timer2
    }

    // Sweep the servo motor back and forth
    void Sweep() {
        while (1) {
            for (uint16_t pulse_width = 1000; pulse_width <= 2000; pulse_width += 10) {
                TIM2->CCR2 = pulse_width;
                DelayMs(10);
            }

            for (uint16_t pulse_width = 2000; pulse_width >= 1000; pulse_width -= 10) {
                TIM2->CCR2 = pulse_width;
                DelayMs(10);
            }
        }
    }

private:
    void DelayMs(uint32_t ms) {
        SysTick_Config(SystemCoreClock / 1000);
        ms_delay = ms;
        while (ms_delay > 0) {
            // Wait for SysTick interrupt
        }
        SysTick->CTRL = 0; // Disable SysTick
    }
};

volatile uint32_t ms_delay = 0;

extern "C" void SysTick_Handler(void) {
    if (ms_delay > 0) {
        ms_delay--;
    }
}

int main() {
    ServoMotor servo;
    servo.Sweep();
    return 0;
}
