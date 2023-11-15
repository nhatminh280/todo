
  #include <iostream>
  #include <string>
  
bool validateTitle(string title) {
  if (title.size() > 100) {
    cout << "Title length must be under 100 character !!!" << endl;
    return false;
  }
  return true;
}

bool validateDeadline(int day, int month, int year) {
  if (
    (day < 1 || day > 31) ||
    (day == 29 && month == 2 && !((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))) ||
    (day == 30 && month == 2) ||
    (day == 31 && !((month <= 7 && month % 2 == 1) || (month >= 8 && month % 2 == 0)))
  ) {
    cout << "Invalid date" << endl;
    return false;
  }
  
  Date currentDate;
  if (Date(day, month, year) - currentDate < 0) {
    cout << "Deadline must be after current day" << endl;
    return false;
  } 

  return true;
}

bool validateNote(string note) {
  if (note.size() > 1000) {
    cout << "Note length must be under 1000 character !!!" << endl;
    return false;
  }
  return true;
}