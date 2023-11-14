
void listPage(string &page, int &slug, TaskList &list) {
  DrawLogo();
  GoTo(xStart, yStart - 3);
  cout << "LIST";
  GoTo(xStart, yStart);
  cout << setw(13) << setfill(' ') << "Task" << setw(12) << setfill(' ') << "Start" << setw(12) << setfill(' ') << "Deadline";
  list.sortTask() ; list.saveData() ; 
  int option = 0;
  while (true) {
    int pagination = option / 10;
    // Display to screen
    for (int i = pagination * 10; i < (pagination + 1) * 10 && i < list.size(); i++) {
      GoTo(xStart, yStart + 1 + i - (pagination * 10));
      cout << ((i == option) ? ">> " : "   ");
      cout << setw(10) << setfill(' ') << string(list[i].getTitle(), 0, 10) << "  " << list[i].getStart() << "  " << list[i].getDeadline();
    }
    // Control
    char ctrl = getch();
    if (ctrl == keyUp || ctrl == 'w') {
      // Up
      option = (option == 0) ? list.size() - 1 : option - 1;
    } else if (ctrl == keyDown || ctrl == 's') {
      // Down
      option = (option == list.size() - 1) ? 0 : option + 1;
    } else if (ctrl == keyRight || ctrl == 'd' || ctrl == ' ' || ctrl == keyEnter) {
      if (list.size() > 0) {
        // Go to editor
        page = "details";
        slug = option;
      }
      break;
    } else if (ctrl == keyLeft || ctrl == 'a' || ctrl == keyEsc) {
      // Back to menu
      page = "menu";
      break;
    }
  }
}