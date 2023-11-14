#include <iostream>
#include <windows.h>
#include <conio.h>
#include <vector>
#include <time.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include<algorithm>

#define xStart 10
#define yStart 11

#define keyUp 72
#define keyDown 80
#define keyLeft 75
#define keyRight 77
#define keyEnter 13
#define keyEsc 27

#define PRIORITY_IN_DAY 0
#define PRIORITY_IN_THREE_DAYS 1
#define PRIORITY_IN_WEEK 2
#define PRIORITY_IN_TWO_WEEKS 3
#define PRIORITY_IN_MONTH 4

#define STATUS_NOT_COMPLETED 0
#define STATUS_IN_PROGRESS 1
#define STATUS_COMPLETED 2
#define STATUS_CANCELED 3
#define STATUS_OVERDUE 4

using namespace std;

// Classes
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