  #include <iostream>
  #include <windows.h>
  #include <conio.h>
  #include <fstream>



  using namespace std;

  // // Classes
  #include "classes/Date.cpp"
  #include "classes/Task.cpp"

  // Functions
  #include "utils/display.cpp"
  #include "utils/data.cpp"
  #include "utils/validator.cpp"

  // Interfaces
  #include "pages/details.cpp"
  #include "pages/statistics.cpp"
  #include "pages/form.cpp"
  #include "pages/list.cpp"
  #include "pages/menu.cpp"
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