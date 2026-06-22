//Write a method sumSubjectMarks(int[][] marks) that returns the sum of all elements in the marks 2D array 
//and print the result in main().
public class partcQ9 {
    public static int sumSubjectMarks(int[][] marks) {
        int sum = 0;
        for (int i = 0; i < marks.length; i++) {
            for (int j = 0; j < marks[i].length; j++) {
                sum += marks[i][j];
            }
        }
        return sum;
    }

    public static void main(String[] args) {
        int[][] marks = {
            {85, 90, 75, 88},    
            {92, 86, 78, 95},    
            {89, 92, 85, 90}     
        };
        int totalSum = sumSubjectMarks(marks);
        System.out.println("Sum of all marks: " + totalSum);
    }
}
