/*************************
* Автор: Базанов В.В.    *
* Название: Вариант №1   *
*************************/

#include <iostream>
#include <iomanip>  
#include <string>
#include <vector>

using namespace std;

enum {
  MONTHS_COUNT = 12,
  DAYS_IN_WEEK = 7
};

bool isLeapYear(int year) {
  return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

int getMonthDays(int month, int year) {
  int daysInMonth[] = { 31, 28, 31, 30, 31, 30,
                         31, 31, 30, 31, 30, 31 };
    if (month == 2 && isLeapYear(year))
      return 29;
  return daysInMonth[month - 1];
}

int getFirstWeekdayOfMonth(int year, int month) {
  int dayOfMonth, currentMonth, currentYear, yearOfCentury, century, weekdayCalculation, weekday;

  dayO[[fMonth = 1;
  currentMonth = month;
  currentYear = year;

  if (currentMonth < 3) {
    currentMonth += 12;
    currentYear -= 1;
  }

  yearOfCentury = currentYear % 100;
  century = currentYear / 100;
  weekdayCalculation = (dayOfMonth + 13 * (currentMonth + 1) / 5 + yearOfCentury +
  yearOfCentury / 4 + century / 4 + 5 * century) % 7;
  weekday = (weekdayCalculation + 6) % 7;
  return weekday;
}

int main() {
  int year, monthIndex, firstWeekday, daysInMonth, emptyCellCount, currentDay, cellPosition;
  vector<string> months;
  vector<string> weekDays;

  cout << "Enter year: ";
  cin >> year;

  months = {
          "January", "February", "March", "April", "May", "June",
          "July", "August", "September", "October", "November", "December"
  };
  weekDays = { "mon", "tue", "wed", "thu", "fri", "sat", "sun" };

  for (monthIndex = 1; monthIndex <= MONTHS_COUNT; ++monthIndex) {
    cout << left << setw(15) << months[monthIndex - 1] << endl;

    for (const auto& dayName : weekDays) {
      cout << setw(4) << dayName;
    }
    cout << endl;

    firstWeekday = getFirstWeekdayOfMonth(year, monthIndex);
    daysInMonth = getMonthDays(monthIndex, year);

    for (emptyCellCount = 0; emptyCellCount < firstWeekday; ++emptyCellCount) {
      cout << setw(4) << " ";
    }

    currentDay = 1;
    for (cellPosition = firstWeekday; currentDay <= daysInMonth; ++cellPosition) {
      if (cellPosition % DAYS_IN_WEEK == 0 && cellPosition != 0) {
        cout << endl;
      }
      cout << setw(4) << currentDay;
      ++currentDay;
    }
    cout << endl << endl;
  }
  return 0;
}

