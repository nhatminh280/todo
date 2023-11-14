
class Task {
  private:
    int status, priority;
    char title[100], note[1000];
    Date start, deadline;

  public:
    // Constructors
    Task() {}
    Task(string title, string note, Date deadline) {
      this->status = STATUS_IN_PROGRESS;
      strcpy(this->title, title.c_str());
      strcpy(this->note, note.c_str());
      this->deadline = deadline;
      Date t = this->deadline - this->start;
      if (t < 2) {
        this->priority = PRIORITY_IN_DAY;
      } else if (t < 4) {
        this->priority = PRIORITY_IN_THREE_DAYS;
      } else if (t < 8) {
        this->priority = PRIORITY_IN_WEEK;
      } else if (t < 15) {
        this->priority = PRIORITY_IN_TWO_WEEKS;
      } else {
        this->priority = PRIORITY_IN_MONTH;
      }
    }
    // Settors
    void setStatus(int status) {
      this->status = status;
    }
    void setTitle(string title) {
      strcpy(this->title, title.c_str());
    }
    void setNote(string note) {
      strcpy(this->note, note.c_str());
    }
    void setDeadline(Date deadline) {
      this->deadline = deadline;
      Date t = this->deadline - this->start;
      if (t < 2) {
        this->priority = PRIORITY_IN_DAY;
      } else if (t < 4) {
        this->priority = PRIORITY_IN_THREE_DAYS;
      } else if (t < 8) {
        this->priority = PRIORITY_IN_WEEK;
      } else if (t < 15) {
        this->priority = PRIORITY_IN_TWO_WEEKS;
      } else {
        this->priority = PRIORITY_IN_MONTH;
      }
    }
    // Gettors
    string getTitle() {
      return title;
    }
    string getNote() {
      return note;
    }
    Date getStart() {
      return start;
    }
    Date getDeadline() {
      return deadline;
    }
    int getStatus() {
      return status;
    }
     int getPriority(){
      return priority ; 
    }
    string getStatusString() {
      switch (status) {
        case STATUS_NOT_COMPLETED:
          return "Not completed"; 
          break ;  
        case STATUS_IN_PROGRESS:
          return "In progress"; 
          break; 
        case STATUS_COMPLETED :
          return "Completed";
          break ;
        case STATUS_CANCELED:
          return "Canceled"; 
          break; 
        case STATUS_OVERDUE :
          return "Overdue"; 
          break; 
      }
    }
    string getPriorityString() {
      switch (priority) {
        case PRIORITY_IN_DAY:
          return "In day";
          break;
        case PRIORITY_IN_THREE_DAYS:
          return "In three days"; 
          break; 
        case PRIORITY_IN_WEEK:
          return "In week";  
          break;
        case PRIORITY_IN_TWO_WEEKS:
          return "In two weeks"; 
          break; 
        case PRIORITY_IN_MONTH:
          return "In month"; 
          break; 
      }
    }
   
};

class TaskList {
  private:
    vector <Task> list;
  
  public:
    // Constructors
    TaskList() {
      ifstream ifs("data/data.dat", ios::binary);
      Task task;
      while (true) {
        ifs.read((char*) &task, sizeof(Task));
        if (ifs.eof()) break;
        if (task.getDeadline() < Date()) {
          task.setStatus(STATUS_OVERDUE);
        }
        list.push_back(task);
      }
      ifs.close();
      saveData();
    }
    // Methods
    int size() {
      return list.size();
    }
    void addList(Task task) {
      list.push_back(task);
    }
    void editTask(int index, int status, string title, string note, Date deadline) {
      list.at(index).setStatus(status);
      list.at(index).setTitle(title);
      list.at(index).setNote(note);
      list.at(index).setDeadline(deadline);
    }
    void deleteTask(int index) {
      list.erase(list.begin() + index);
    }
    //sort task 
    
    void sortTask() {
      sort(list.begin() , list.end(), [](Task& task1 , Task & task2 ){
        return task1.getPriority() < task2.getPriority() ; 
      });  
    }
    void saveData() {
      ofstream ofs("data/data.dat", ios::binary);
      for (auto task : list) {
        ofs.write((char*) &task, sizeof(Task));
      }
      ofs.close();
    }
    void exportData() {
      ofstream ofs("data/report.txt");
      
      ofs << "REPORT" << endl << endl;
      ofs << "Date: " << Date() << endl;
      ofs << "--------------------" << endl << endl;

      for (auto task : list) {
        ofs << "Task: " << task.getTitle() << endl;
        ofs << "Status: " << task.getStatusString() << endl;
        ofs << "Priority: " << task.getPriorityString() << endl;
        ofs << "Start date: " << task.getStart() << endl;
        ofs << "Deadline: " << task.getDeadline() << endl;
        ofs << "Note: " << task.getNote() << endl;
        ofs << "------------------------------" << endl;
      }

      ofs.close();
    }
    // Operators
    Task& operator [] (int i) {
      return list.at(i);
    }
};