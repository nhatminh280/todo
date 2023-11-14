#include "header.h"

int main() {
  TaskList list;

  // Console settings
  ShowCur(false);
  SetConsoleTitle(TEXT("Todo List"));

  // Router
  string page = "menu";
  int slug = -1;
  while (true) {
    system("cls");
    if (page == "menu") {
      menuPage(page, list);
    } else if (page == "list") {
      listPage(page, slug, list);
    } else if (page == "details") {
      detailsPage(page, slug, list);
    } else if (page == "form") {
      formPage(page, slug, list);
    } else if (page == "statistics") {
      statisticPage(page, list);
    } else if (page == "quit") {
      return 0;
    }
  }
}