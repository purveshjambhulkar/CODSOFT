/*TASK 4
QUIZ APPLICATION WITH TIMER
1. Quiz Questions and Options: Store quiz questions along with multiple-choice options and correct
answers.(DONE)
2. Timer: Implement a timer for each question to limit the time to answer.
3. Question Display: Present one question at a time with multiple-choice options.
4. Answer Submission: Allow users to select an option and submit their answer within the given
time.
5. Score Calculation: Keep track of the user's score based on correct answers.
Result Screen: Display the final score and a summary of correct/incorrect answers. */

import java.util.Scanner;
import java.util.concurrent.Executors;
import java.util.concurrent.ScheduledExecutorService;
import java.util.concurrent.TimeUnit;

public class Quiz_game {

    String[] quizQuestions = {
        "1. What is the capital of France?\n" +
            "a) Berlin\n" +
            "b) Madrid\n" +
            "c) Paris\n" +
            "d) Rome",
        
        "2. Which programming language is known as the 'mother of all languages'?\n" +
            "a) Java\n" +
            "b) C\n" +
            "c) Python\n" +
            "d) Fortran",
        
        "3. What is the largest mammal in the world?\n" +
            "a) Elephant\n" +
            "b) Giraffe\n" +
            "c) Blue Whale\n" +
            "d) Gorilla",
    };

    String[] correctAnswers = {"c", "b", "c"};

    private int userScore = 0;

    public static void main(String[] args) {
        Quiz_game quizApp = new Quiz_game();
        quizApp.startQuiz();
    }

    public void startQuiz() {
        Scanner scanner = new Scanner(System.in);

        for (int i = 0; i < quizQuestions.length; i++) {
            displayQuestionWithTimer(quizQuestions[i], correctAnswers[i]);

            String userAnswer = scanner.nextLine();

            if (userAnswer.equalsIgnoreCase(correctAnswers[i])) {
                System.out.println("Correct!\n");
                userScore++;
            } else {
                System.out.println("Incorrect! The correct answer is: " + correctAnswers[i] + "\n");
            }
        }

        System.out.println("Your final score: " + userScore);
    }

    private void displayQuestionWithTimer(String question, String correctAnswer) {
        System.out.println("\n" + question);
        System.out.println("You have 10 seconds to answer.\n");

        ScheduledExecutorService scheduler = Executors.newScheduledThreadPool(1);

        scheduler.schedule(() -> {
            System.out.println("Time's up! The correct answer is: " + correctAnswer + "\n");
        }, 10, TimeUnit.SECONDS);

        Scanner scanner = new Scanner(System.in);
        String userAnswer = scanner.nextLine();

        scheduler.shutdownNow();

        if (!userAnswer.equalsIgnoreCase(correctAnswer)) {
            System.out.println("Incorrect! The correct answer is: " + correctAnswer + "\n");
        }
    }
}
