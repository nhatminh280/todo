
void formPage(string &page, int &slug, TaskList &list) {
  vector <string> options = {"TITLE", "DEADLINE", "NOTE", "SUBMIT"};
  int option = 0;

  string inputs[options.size() - 1];
  if (slug >= 0) {
    inputs[0] = list[slug].getTitle();
    inputs[1] = list[slug].getDeadline().toString();
    inputs[2] = list[slug].getNote();
  }

  while (true) {
    // Display to screen
    DrawLogo();
    GoTo(xStart, yStart - 3);
    cout << "ADD TASK";
    // Print options
    for (int i=0; i<options.size(); i++) {
      GoTo(xStart, yStart + 2*i);
      cout << ((i == option) ? ">> " : "   ");
      cout << options[i];
    }
    // Print inputs
    for (int i=0; i<options.size() - 1; i++) {
      GoTo(xStart + 15 , yStart + 2*i);
      cout << "   " <<  inputs[i];
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
      system("cls");
      if (option == 0) {
        do {
          cout << "Enter title: ";
          getline(cin, inputs[0]);
          if (validateTitle(inputs[0])) break;
        } while (true);
      } else if (option == 1) {
        do {
          string day, month, year;
          cout << "Enter deadline day: ";
          cin >> day;
          cout << "Enter deadline month: ";
          cin >> month;
          cout << "Enter deadline year: ";
          cin >> year;
          cin.ignore();
          if (validateDeadline(atoi(day.c_str()), atoi(month.c_str()), atoi(year.c_str()))) {
            inputs[1] = day + "/" + month + "/" + year;
            break;
          };
        } while (true);
      } else if (option == 2) {
        do {
          cout << "Enter note: ";
          getline(cin, inputs[2]);
          if (validateNote(inputs[2])) break;
        } while (true);
      } else {
        // Submit
        if (inputs[0] != "" && inputs[1] != "" && inputs[2] != "") {
          if (slug < 0) {
            // Add
            list.addList(Task(inputs[0], inputs[2], Date(inputs[1])));
            page = "menu";
          } else {
            // Edit
            list[slug].setTitle(inputs[0]);
            list[slug].setDeadline(Date(inputs[1]));
            list[slug].setNote(inputs[2]);
            page = "details";
          }
          list.saveData();
          break;
        }
      }
      system("cls");
    } else if (ctrl == keyLeft || ctrl == 'a' || ctrl == keyEsc) {
      // Back to menu
      if (slug < 0) {
        page = "menu";
      } else {
        page = "details";
      }
      break;
    }
  } 
}