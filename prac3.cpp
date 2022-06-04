#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

// Notes the date with formated date functionality
struct date {
private:
  char separator = '.';

public:
  int day, mounth, year;
  string formated() {
    return to_string(this->day) + separator + to_string(this->mounth) +
           separator + to_string(this->year);
  }
};

// Structure with naming functionality
struct name {
  string firstname, familyname;
  string get_fullname() { return this->firstname + " " + this->familyname; }
};

struct parents {
  string father, mother;
};

string generate_fulname(struct name name) { return name.get_fullname(); }

/* A living class that representes a Human Being */
class Human {
  struct name name;
  struct date birth;
  struct parents parents;
  map<string, struct name> family;

public:
  // Born Constructor
  Human(struct name name, struct date birth) {
    this->name = name;
    this->birth = birth;
  }

  string get_name() { return this->name.get_fullname(); }

  string get_birth() { return this->birth.formated(); }

  void set_parents(struct name father, struct name mother) {

    this->parents.father = father.get_fullname(),
    this->parents.mother = mother.get_fullname();
    this->family["father"] = father, this->family["mother"] = mother;
  }

  struct parents get_parents() {
    return this->parents;
  }
};

struct subject {
  string name;
  int gained, outof;
};

class Student : public Human {
private:
  map<string, struct subject> subjects;
  string school;

public:
  Student(struct name name, struct date birth, string school = "ABC School")
      : Human(name, birth) {
    this->school = school;
  };

  friend void print_school(Student student);

  void add_marks(struct subject subject) {
    this->subjects[subject.name] = subject;
  }

  vector<string> get_marks() {
    vector<string> marks;
    map<string, struct subject>::iterator iter = this->subjects.begin();

    // Formating Marks in a standerd manner
    for (; iter != this->subjects.end(); iter++)
      marks.push_back(iter->second.name + ": " +
                      to_string(iter->second.gained) + "/" +
                      to_string(iter->second.outof));

    return marks;
  }
};

void print_school(Student student) { cout << student.school << endl; }

int main() {
  struct name name;
  struct date birth;
  name.firstname = "Rahul", name.familyname = "Mondal";
  birth.day = 25, birth.mounth = 1, birth.year = 2005;

  // Initializing a human
  Student rahul(name, birth, "Kanchrapara Harnett High School");

  struct name father, mother;
  father.firstname = "Pankaj", mother.firstname = "Shyamali",
  father.familyname = mother.familyname = "Mondal";

  rahul.set_parents(father, mother);

  // Setting student Subjects
  struct subject english, math, physics, chemistry;
  english.name = "English", math.name = "Math", physics.name = "Physics",
  chemistry.name = "Chemistry";

  english.gained = 89, math.gained = 96, physics.gained = 95,
  chemistry.gained = 94;

  english.outof = math.outof = physics.outof = chemistry.outof = 100;

  rahul.add_marks(english);
  rahul.add_marks(math);
  rahul.add_marks(physics);
  rahul.add_marks(chemistry);

  // Printing details

  cout << "Name: " << rahul.get_name() << endl;
  cout << rahul.get_birth() << endl;

  struct parents parents = rahul.get_parents();
  cout << "Father: " << parents.father << endl;
  cout << "Mother: " << parents.mother << endl;

  vector<string> marks = rahul.get_marks();
  for (int i = 0; i < marks.size(); i++) {
    cout << marks[i] << endl;
  }

  print_school(rahul);

  return 0;
}
