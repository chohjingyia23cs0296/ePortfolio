#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Contact {
private:
    string phone;
    string email;
public:
    Contact() : phone(""), email("") {}

    void setPhone( string _phone) {
        phone = _phone;
    }

    void setEmail( string _email) {
        email = _email;
    }

    string getPhone() const {
        return phone;
    }

    string getEmail() const {
        return email;
    }
};

class Person {
protected:
    string name;
    string id;
    Contact contact;
public:
    Person() : name(""), id("") {}

    void setName( string _name) {
        name = _name;
    }

    void setId( string _id) {
        id = _id;
    }

    string getName() const {
        return name;
    }

    string getId() const {
        return id;
    }

    void setPhone( string _phone) {
        contact.setPhone(_phone);
    }

    void setEmail( string _email) {
        contact.setEmail(_email);
    }

    string getPhone() const {
        return contact.getPhone();
    }

    string getEmail() const {
        return contact.getEmail();
    }
};

class Staff : public Person {
protected:
    string position;
public:
    Staff() : position("") {}

    void setPosition( string _position) {
        position = _position;
    }

    string getPosition() const {
        return position;
    }
};

class Project {
protected:
    string title;
    string area;
public:
    Project() : title(""), area("") {}

    void setTitle( string _title) {
        title = _title;
    }

    void setArea( string _area) {
        area = _area;
    }

    string getTitle() const {
        return title;
    }

    string getArea() const {
        return area;
    }
};

class Student : public Person {
protected:
    string program;
    Project project;
    Staff* advisor;
public:
    Student() : program(""), advisor(nullptr) {}

    void setProgram( string _program) {
        program = _program;
    }

    void setProject( Project _project) {
        project = _project;
    }

    void setAdvisor(Staff* _advisor) {
        advisor = _advisor;
    }

    string getProgram() const {
        return program;
    }

    string getProjectTitle() const {
        return project.getTitle();
    }

    string getProjectArea() const {
        return project.getArea();
    }

    string getAdvisorName() const {
        return  advisor->getName() ;
    }

    string getAdvisorPosition() const {
        return advisor->getPosition();
    }

    Staff* getAdvisor() const {
        return advisor;
    }

    void printInfo() const {
        cout << "Student Name: " << getName() << ", Phone: " << getPhone()
             << ", Email: " << getEmail() << ", Project Title: " << getProjectTitle() 
             << ", Project Area: " << getProjectArea();
        if (advisor) {
            cout << ", Advisor: " << advisor->getName() << " (" << advisor->getPosition()
                 << "), Phone: " << advisor->getPhone() << ", Email: " << advisor->getEmail()
                 << ", Program: " << getProgram();
        } else {
            cout << ", Advisor: None";
        }
        cout << endl;
    }
};

void assignAdvisors(vector<Student>& students, vector<Staff>& advisors) {
    for (size_t i = 0; i < students.size() && i < advisors.size(); ++i) {
        students[i].setAdvisor(&advisors[i]);
    }
}

void reassignAdvisors(Student& student1, Student& student2) {
    Staff* temp = student1.getAdvisor();
    student1.setAdvisor(student2.getAdvisor());
    student2.setAdvisor(temp);
}

void removeAdvisor(Student& student) {
    student.setAdvisor(nullptr);
}

int main() {
    // Sample data
    vector<Staff> advisors = {
        Staff(), Staff(), Staff()
    };
    advisors[0].setName("Prof. Dr. Muhammad Roslan Abdullah");
    advisors[0].setPosition("Lecturer");
    advisors[0].setPhone("0199875678");
    advisors[0].setEmail("mroslana29@gmail.com");

    advisors[1].setName("Mr. Qamarool Zaman");
    advisors[1].setPosition("Senior Technician");
    advisors[1].setPhone("01156781234");
    advisors[1].setEmail("qam23@gmail.com");

    advisors[2].setName("Dr. Siti Zubaidah Rosli");
    advisors[2].setPosition("Research Officer");
    advisors[2].setPhone("0101117456");
    advisors[2].setEmail("stzr983@gmail.com");

    vector<Student> students = {
        Student(), Student(), Student()
    };
    students[0].setName("Lim Sew Ying");
    students[0].setPhone("010897634045");
    students[0].setEmail("lsying12@live.utm.my");
    students[0].setProgram("Electrical Engineering");
    Project project1;
    project1.setTitle("Smart Dustbin");
    project1.setArea("AI");
    students[0].setProject(project1);

    students[1].setName("Abu Bakar Razali");
    students[1].setPhone("0111210000");
    students[1].setEmail("abraz78@live.utm.my");
    students[1].setProgram("Computer Science");
    Project project2;
    project2.setTitle("Money Recognition for Blind People");
    project2.setArea("Good");
    students[1].setProject(project2);

    students[2].setName("Nur Amalina Muhammad");
    students[2].setPhone("0129000123");
    students[2].setEmail("nam978@live.utm.my");
    students[2].setProgram("Biomedical Engineering");
    Project project3;
    project3.setTitle("Dengue Testing Kit");
    project3.setArea("Testing");
    students[2].setProject(project3);

    // Assign advisors to students
    assignAdvisors(students, advisors);

    // Print initial list
    cout << "Initial list:" << endl;
    for (const Student& student : students) {
        student.printInfo();
    }

    // Reassign advisors
    reassignAdvisors(students[0], students[1]);
    removeAdvisor(students[2]);

    // Print final list
    cout << "\nFinal list:" << endl;
    for (const Student& student : students) {
        student.printInfo();
    }

    return 0;
}