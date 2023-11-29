#include <iostream>
#include <iomanip>

int getFirstDayofTheYear(int year) {
    int day = (year * 365 + ((year - 1) / 4) - ((year - 1) / 100) + ((year - 1) / 400)) % 7;
    return day;
}

int main() {
    const char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int i, j, totalDays, weekDay = 0, spaceCounter = 0, year;

    std::cout << "Enter Your Favorite Year:\n";
    std::cin >> year;
    std::cout << "\n\n*************** Welcome to " << year << " *****************\n\n";

    // Check if it is a leap year
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        daysInMonth[1] = 29;
    }

    // Get the first day of the year
    weekDay = getFirstDayofTheYear(year);

    for (i = 0; i < 12; i++) {
        std::cout << "\n\n\n---------------------- " << months[i] << " -----------------------\n";
        std::cout << "\n   Sun   Mon   Tue   Wed   Thu   Fri   Sat\n\n";

        for (spaceCounter = 1; spaceCounter <= weekDay; spaceCounter++) {
            std::cout << "      ";
        }

        totalDays = daysInMonth[i];
        for (j = 1; j <= totalDays; j++) {
            std::cout << std::setw(6) << j;
            weekDay++;
            if (weekDay > 6) {
                weekDay = 0;
                std::cout << std::endl;
            }
        }
    }
    return 0;
}
