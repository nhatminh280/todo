class Date {
  private:
    int day, month, year;
  
  public:
    // Constructors
    Date() {
      time_t currentTime;
      time (&currentTime);
      tm* currentDate = localtime(&currentTime);
      day = currentDate->tm_mday;
      month = currentDate->tm_mon + 1;
      year = currentDate->tm_year + 1900;
    };
    Date(int day) {
      this->day = month = year = 1;
      while (true) {
        this->day = day;
        if (month == 2) {
          day -= ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) ? 29 : 28;
        } else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
          day -= 31;
        } else {
          day -= 30;
        }
        if (day <= 0) break;
        month ++;
        if (month > 12) {
          year ++;
          month = 1;
        }
      }
    }
    Date(int day, int month, int year) {
      this->day = day;
      this->month = month;
      this->year = year;
    }
    Date(string dateStr) {
      stringstream ss(dateStr);
      string n;
      getline(ss, n, '/');
      this->day = stoi(n);
      getline(ss, n, '/');
      this->month = stoi(n);
      getline(ss, n);
      this->year = stoi(n);
    }
    // Methods
    string toString() {
      return to_string(day) + "/" + to_string(month) + "/" + to_string(year);
    }
    // Operators
    friend ostream& operator << (ostream& out, const Date& date) {
      out << setw(2) << setfill('0') << date.day << "/" << setw(2) << setfill('0') << date.month << "/" << setw(4) << setfill('0') << date.year;
      return out;
    }
    friend bool operator < (const Date& date1, const Date& date2) {
      if (date1.year == date2.year) {
        if (date1.month == date2.month) {
          return date1.day < date2.day;
        }
        return date1.month < date2.month;
      }
      return date1.year < date2.year;
    }
    friend Date operator - (const Date& date1, const Date& date2) {
      int countDay1 = 0;
      for (int i=1; i<date1.year; i++) countDay1 += ((i% 4 == 0 && i % 100 != 0) || (i % 400 == 0)) ? 366 : 365;
      for (int i=1; i<date2.month; i++) {
        if (i == 2) {
          countDay1 += ((date1.year % 4 == 0 && date1.year % 100 != 0) || (date1.year % 400 == 0)) ? 29 : 28;
        } else if ((i <= 7 && i % 2 == 1) || (i >= 8 && i % 2 == 0)) {
          countDay1 += 31;
        } else {
          countDay1 += 30;
        }
      }
      countDay1 += date1.day;

      int countDay2 = 0;
      for (int i=1; i<date2.year; i++) countDay2 += ((i% 4 == 0 && i % 100 != 0) || (i % 400 == 0)) ? 366 : 365;
      for (int i=1; i<date2.month; i++) {
        if (i == 2) {
          countDay2 += ((date2.year % 4 == 0 && date2.year % 100 != 0) || (date2.year % 400 == 0)) ? 29 : 28;
        } else if ((i <= 7 && i % 2 == 1) || (i >= 8 && i % 2 == 0)) {
          countDay2 += 31;
        } else {
          countDay2 += 30;
        }
      }
      countDay2 += date2.day; 

      return Date(countDay1 - countDay2);     
    }
};
