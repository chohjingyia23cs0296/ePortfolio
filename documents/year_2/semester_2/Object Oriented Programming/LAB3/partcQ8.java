//Write a method named printStudentInfo(Student[] arr) to print all students’ name and age 
//using enhanced for-each loop. 
//Replace the existing print loop with a call to this method.
public class partcQ8{
    static class Student{
    String name;
    int age;

    Student(String name, int age) {
        this.name = name;
        this.age = age;
        }
}
    public static void printStudentInfo(Student[] arr) {
        for (Student s : arr) {
            System.out.println("Name: " + s.name + ", Age: " + s.age);
        }
    }
    public static void main(String[] args) {
        Student[] students = {
            new Student("Choh", 20),
            new Student("Jing Yi", 22)
        };
        
        printStudentInfo(students);
    }
}

    
