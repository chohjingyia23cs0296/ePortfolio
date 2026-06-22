#include <iostream>
#include <fstream>
#include <string>
#include<iomanip>

using namespace std;

class Program {
private:
    string programName;
public:
    Program( string programName = "") : programName(programName) {}
    string getProgramName() const { return programName; }
    void setProgramName( string pN) {
        programName = pN;
    }
};

class Advisor {
private:
    string name;
public:
    Advisor( string name = "") : name(name) {}
    string getName() const { return name; }
    void setName( string n) { 
        name=n;
     }
};

class Supervisor {
private:
    string name;
public:
    Supervisor( string n = "") : name(n) {}
    string getName() const { 
        return name; 
        }
    void setName( string n) { 
        name=n;
     }
};

class Project {
private:
    string title;
public:
    Project(string t = "") : title(t) {}
    string getTitle() const { return title; }
    void setTitle( string t) { 
        title = t; 
    }
};

class Student {
private:
    string name;
    Program program;
    Advisor advisor;
    Supervisor supervisor;
    Project project;
public:
    Student( string n = "",  Program program = Program(),  Advisor a = Advisor(),  Supervisor s = Supervisor(), Project project = Project())
        : name(n), program(program), advisor(a), supervisor(s), project(project) {}

    string getName() const { return name; }
    Program getProgram() const { return program; }
    Advisor getAdvisor() const { return advisor; }
    Supervisor getSupervisor() const { return supervisor; }
    Project getProject() const { return project; }

    void printDetails() const {
        cout << name << endl;
        cout << program.getProgramName() << endl;
        cout << advisor.getName() << endl;
        cout << supervisor.getName() << endl;
        cout << project.getTitle() << endl;
    }
};

void readInputFile(const string &filename, Student *&students, int &numStudents) {
    ifstream infile(filename);
    infile >> numStudents;
    infile.ignore();

    students = new Student[numStudents];

    for (int i = 0; i < numStudents; ++i) {
        string name, programName, advisorName, supervisorName, projectTitle;

        getline(infile, name);
        getline(infile, programName);
        getline(infile, advisorName);
        getline(infile, supervisorName);
        getline(infile, projectTitle);
        infile.ignore();  

        Program program(programName);
        Advisor advisor(advisorName);
        Supervisor supervisor(supervisorName);
        Project project(projectTitle);

        students[i] = Student(name, program, advisor, supervisor, project);
    }
}

void writeOutputFile(const string &filename, const Student *students, int numStudents) {
    ofstream outfile(filename);
    outfile << "THE LIST OF POSTGRADUATE STUDENTS" << endl;
    outfile << left << setw(34)<<"No Name"
            << left << setw(30) << "Supervisor" 
            << left << setw(30) << "Project" << endl<<endl;

    for (int i = 0; i < numStudents; ++i) {
        outfile << left << setw(4) << i + 1
                << left << setw(30) << students[i].getName() 
                << left << setw(30) << students[i].getSupervisor().getName() 
                << left << setw(30) << students[i].getProject().getTitle() << endl;
    }
}

int main() {
    Student *students = nullptr;
    int numStudents = 0;

    readInputFile("pgstudents.txt", students, numStudents);
    writeOutputFile("output.txt", students, numStudents);

    delete[] students;

    return 0;
}