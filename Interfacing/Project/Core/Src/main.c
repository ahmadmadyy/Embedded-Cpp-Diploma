#include "stm32f1xx.h"

#define SERVO_PIN GPIO_PIN_8  // Assuming servo is connected to PA8
#define SERVO_PORT GPIOA
#define TIM_PERIOD 20000       // PWM period in microseconds
#define TIM_PULSE_MIN 1000     // Minimum pulse width in microseconds
#define TIM_PULSE_MAX 2000     // Maximum pulse width in microseconds

volatile uint16_t pulse_width = TIM_PULSE_MIN;
volatile uint8_t direction = 1;  // 1 for increasing pulse width, 0 for decreasing

void TIM1_UP_IRQHandler(void) {
    if (TIM1->SR & TIM_SR_UIF) {
        // Clear the update interrupt flag
        TIM1->SR &= ~TIM_SR_UIF;

        // Update the CCR1 register with the new pulse width
        TIM1->CCR1 = pulse_width;

        // Adjust the pulse width for the next iteration
        pulse_width += (direction) ? 10 : -10;

        // Change direction when reaching the limits
        if (pulse_width >= TIM_PULSE_MAX || pulse_width <= TIM_PULSE_MIN) {
            direction = !direction;
        }
    }
}

void TIM1_Config(void) {
    // Enable TIM1 clock
    RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;

    // Configure TIM1 for PWM mode
    TIM1->CR1 = 0;                  // Reset control register
    TIM1->CR1 |= TIM_CR1_ARPE;      // Auto-reload preload enable
    TIM1->CCMR1 |= TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1M_2; // PWM mode 1
    TIM1->CCER |= TIM_CCER_CC1E;    // Enable capture/compare channel 1 output
    TIM1->BDTR |= TIM_BDTR_MOE;     // Main output enable

    // Set the period and initial pulse width
    TIM1->ARR = TIM_PERIOD - 1;
    TIM1->CCR1 = TIM_PULSE_MIN;

    // Enable TIM1 update interrupt
    TIM1->DIER |= TIM_DIER_UIE;

    // Enable TIM1 interrupt in NVIC
    NVIC_EnableIRQ(TIM1_UP_IRQn);

    // Start the timer
    TIM1->CR1 |= TIM_CR1_CEN;
}

int main(void) {
    // Enable GPIOA clock
    RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;

    // Configure PA8 as output push-pull
    SERVO_PORT->CRH &= ~(GPIO_CRH_CNF8 | GPIO_CRH_MODE8);
    SERVO_PORT->CRH |= GPIO_CRH_MODE8_1;

    // Initialize TIM1 for PWM
    TIM1_Config();

    while (1) {
        // Your main code here
    }
}
