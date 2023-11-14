
void ShowCur(bool CursorVisibility) {
  CONSOLE_CURSOR_INFO ConCurInf = {10, CursorVisibility};
  SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ConCurInf);
}

void SetColor(int backgound_color, int text_color) {
  int color_code = backgound_color * 16 + text_color;
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_code);
}

void GoTo(SHORT posX, SHORT posY) {
  COORD Position = {posX, posY};
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Position);
}

void DrawLogo() {
  GoTo(0, 2);
  ifstream ifs("assets/logo.txt");
    while (!ifs.eof()) {
      string line;
      getline(ifs, line);
      cout << line << endl;
    }
}
