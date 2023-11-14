
void menuPage(string &page, TaskList &list) {
  DrawLogo();
  GoTo(xStart, yStart - 3);
  cout << "MAIN MENU";

  vector <string> options = {"VIEW TASKS", "ADD TASK", "STATISTICS", "EXPORT", "QUIT"};
  int option = 0;
  while (true) {
    // Display to screen
    for (int i=0; i<options.size(); i++) {
      GoTo(xStart, yStart + 2*i);
      cout << ((i == option) ? ">> " : "   ");
      cout << options[i];
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
      if (option == 0) {
        page = "list";
      } else if (option == 1) {
        page = "form";
      } else if (option == 2) {
        page = "statistics";
      } else if (option == 3) {
        list.exportData();
      } else {
        page = "quit";
      }
      break;
    }
  }
}