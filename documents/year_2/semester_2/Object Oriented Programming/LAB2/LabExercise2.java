public class LabExercise2 {
    public static void main(String[] args) {
        System.out.println("--- Q1: Employee ---");
        Employee e1 = new Employee();
        e1.setEmpName("Choh Jing Yi");
        e1.setEmpNum(21);
        System.out.println("Name: " + e1.getEmpName());
        System.out.println("Employee Number: " + e1.getEmpNum());

        System.out.println("\n---- Q2: Car ----");
        Car myCar = new Car();
        myCar.setBrand("Toyota");
        myCar.setYear(2014);
        System.out.println("Car Brand: " + myCar.getBrand());
        System.out.println("Car Year: " + myCar.getYear());

        System.out.println("\n---- Q3: Book ----");
        Book book = new Book("OOP", "Jing Yi");
        book.display();

        System.out.println("\n---- Q4: Student ----");
        Student student = new Student();
        student.setName("Jing Yi");
        student.setAge(20);
        System.out.println("Student Name: " + student.getName());
        System.out.println("Student Age: " + student.getAge());

        System.out.println("\n---- Q5: Message ----");
        Message msg = new Message();
        msg.display();
        msg.display("Welcome to Java!");

        System.out.println("\n---- Q6: User Count ----");
        new User();
        new User();
        new User();
        System.out.println("Total Users: " + User.getUserCount());

        System.out.println("\n---- Q7: Employee Salary ----");
        Employee emp = new Employee();
        emp.setSalary(5000);
        System.out.println("Salary: " + emp.getSalary());
    }
}

// Q1 & Q7
class Employee {
    private int empNum;
    private String empName;
    private int salary;

    public void setEmpNum(int num) {
        empNum = num;
    }

    public int getEmpNum() {
        return empNum;
    }

    public void setEmpName(String name) {
        empName = name;
    }

    public String getEmpName() {
        return empName;
    }

    public void setSalary(int s) {
        salary = s;
    }

    public int getSalary() {
        return salary;
    }
}

// Q2
class Car {
    private String brand;
    private int year;

    public void setBrand(String brand) {
        this.brand = brand;
    }

    public String getBrand() {
        return brand;
    }

    public void setYear(int y) {
        year = y;
    }

    public int getYear() {
        return year;
    }
}

// Q3
class Book {
    private String title;
    private String author;

    public Book(String t, String a) {
        title = t;
        author = a;
    }

    public void display() {
        System.out.println("Title: " + title);
        System.out.println("Author: " + author);
    }
}

// Q4
class Student {
    private String name;
    private int age;

    public void setName(String n) {
        name = n;
    }

    public String getName() {
        return name;
    }

    public void setAge(int a) {
        age = a;
    }

    public int getAge() {
        return age;
    }
}

// Q5
class Message {
    public void display() {
        System.out.println("Hello!");
    }

    public void display(String msg) {
        System.out.println("Message: " + msg);
    }
}

// Q6
class User {
    private static int counter = 0;

    public User() {
        counter++;
    }

    public static int getUserCount() {
        return counter;
    }
}
