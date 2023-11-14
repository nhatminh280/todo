
void statisticPage(string &page, TaskList &list) {
  DrawLogo();
  GoTo(xStart, yStart - 3);
  cout << "STATISTICS";

  int counts[5] = {0};
  for (int i=0; i<list.size(); i++) {
    counts[list[i].getStatus()] ++;
  }

  GoTo(xStart, yStart);
  cout << "Not completed: " << counts[0] << " tasks";
  GoTo(xStart, yStart + 1);
  cout << "In progress:   " << counts[1] << " tasks";
  GoTo(xStart, yStart + 2);
  cout << "Completed:     " << counts[2] << " tasks";
  GoTo(xStart, yStart + 3);
  cout << "Canceled:      " << counts[3] << " tasks";
  GoTo(xStart, yStart + 4);
  cout << "Overdue:       " << counts[4] << " tasks";

  while (true) {
    // Control
    char ctrl = getch();
    if (ctrl == keyLeft || ctrl == 'a' || ctrl == keyEsc) {
      // Back
      page = "menu";
      break;
    }
  }
}