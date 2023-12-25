#include <iostream>

enum WEEK_DAYS : std::uint16_t // integer datatype 
{
    MONTAG=1U,
    DIENSTAG,
    MITTWOCH,
    DONNERSTAG,
    FRITAG,
    SAMSTAG,
    SONNTAG,
    WEEK_DAYS=7
};

int main()
{
    constexpr std::uint16_t TEN_DAYS = 10;
    std::uint16_t current_day = SAMSTAG;
    std::string day(" ");
    std::uint16_t meet_day = (current_day + TEN_DAYS) % WEEK_DAYS;

    switch (meet_day)
    {
    case MONTAG:
        day="MONTAG";
        break;
    case DIENSTAG:
        day="DIENSTAG";
        break;
    case MITTWOCH:
        day="MITTWOCH";
        break;
    case DONNERSTAG:
        day="DONNERSTAG";
        break;
    case FRITAG:
        day="FRITAG";
        break;
    case SAMSTAG:
        day="SAMSTAG";
        break;
    case SONNTAG:
        day="SONNTAG";
        break;
    default:
    day = "HI";
        break;
    }

    std::cout << "Meet Day: " << day << std::endl;
}
