  #include <iostream>
  #include <conio.h>
  #include <vector>
  #include <time.h>
  #include <string>
  #include <fstream>

  #include <iomanip>


  #define xStart 10
  #define yStart 11

  #define keyUp 72
  #define keyDown 80
  #define keyLeft 75
  #define keyRight 77
  #define keyEnter 13
  #define keyEsc 27

  #define STATUS_NOT_COMPLETED 0
  #define STATUS_IN_PROGRESS 1
  #define STATUS_COMPLETED 2
  #define STATUS_CANCELED 3
  #define STATUS_OVERDUE 4
void detailsPage(string &page, int &slug, TaskList& list) {
  DrawLogo();
  GoTo(xStart, yStart - 3);
  cout << "DETAIL";

  GoTo(xStart, yStart);
  cout << "Title: " << list[slug].getTitle();
  GoTo(xStart, yStart + 1);
  cout << "Status: " << list[slug].getStatusString();
  GoTo(xStart, yStart + 2);
  cout << "Priority: " << list[slug].getPriorityString();
  GoTo(xStart, yStart + 3);
  cout << "Start date: " << list[slug].getStart();
  GoTo(xStart, yStart + 4);
  cout << "Deadline: " << list[slug].getDeadline();
  GoTo(xStart, yStart + 5);
  cout << "Note: " << list[slug].getNote();

  vector <string> options = {"MAKE AS DONE", "MAKE AS NOT COMPLETED", "MAKE AS CANCELED / NOT CANCELED", "EDIT", "DELETE"};

  int option = 0;
  while (true) {
    // Display to screen
    for (int i=0; i<options.size(); i++) {
      GoTo(xStart, yStart + 8 + 2*i);
      cout << ((i == option) ? ">> " : "   ");
      if (
        // Block option
        list[slug].getStatus() == STATUS_NOT_COMPLETED && (i != 4) ||
        list[slug].getStatus() == STATUS_COMPLETED && (i != 4) ||
        list[slug].getStatus() == STATUS_CANCELED && (i == 0 || i == 1) ||
        list[slug].getStatus() == STATUS_OVERDUE && (i != 4)
      ) {
        cout << "[" << options[i] << "]";
      } else {
        cout << " " << options[i] << " ";
      }
    }
// Control
    char ctrl = getch();
    if (ctrl == keyUp || ctrl == 'w') {
      // Up
      option = (option == 0) ? options.size() - 1 : option - 1;
    } else if (ctrl == keyDown || ctrl == 's') {
      // Down
      option = (option == options.size() - 1) ? 0 : option + 1;
    } else if (ctrl == keyRight || ctrl == 'd' || ctrl == ' ' || ctrl == keyEnter) {
      // Next
      if (! (
        list[slug].getStatus() == STATUS_NOT_COMPLETED && (option != 4) ||
        list[slug].getStatus() == STATUS_COMPLETED && (option != 4) ||
        list[slug].getStatus() == STATUS_CANCELED && (option == 0 || option == 1) ||
        list[slug].getStatus() == STATUS_OVERDUE && (option != 4)
      )) {
        if (option == 0) {
          // Make as done
          list[slug].setStatus(STATUS_COMPLETED);
          list.saveData();
        } else if (option == 1) {
          // Make as not completed
          list[slug].setStatus(STATUS_NOT_COMPLETED);
          list.saveData();
        } else if (option == 2) {
          // Cancel
          if (list[slug].getStatus() == STATUS_IN_PROGRESS) {
            list[slug].setStatus(STATUS_CANCELED);
          } else {
            list[slug].setStatus(STATUS_IN_PROGRESS);
          }
          list.saveData();
        } else if (option == 3) {
          // Editor
          page = "form";
        } else {
          // Delete
          list.deleteTask(slug);
          list.saveData();
          page = "list";
        }
        break;
      }
    } else if (ctrl == keyLeft || ctrl == 'a' || ctrl == keyEsc) {
      // Back
      page = "list";
      slug = -1;
      break;
    }
  }
}