//Q7
    //Create a static method named findHighestScore(int[] scores) that returns the highest value in the scores
    //array. Call it from the main() method and print the result.
public class partcQ7 {
    public static int findHighestScore(int[] scores) {
        int highest = scores[0];
        for (int i=0; i<scores.length; i++) {
            if (scores[i] > highest) 
                highest = scores[i];
        }
        return highest;
    }

    public static void main(String[] args) {
        int[] scores = {88, 92, 79, 95, 87};
        System.out.println("Highest score: " + findHighestScore(scores));
    }
}
