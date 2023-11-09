/* TASK 2
STUDENT GRADE CALCULATOR
Input: Take marks obtained (out of 100) in each subject.(DONE)
Calculate Total Marks: Sum up the marks obtained in all subjects.(DONE)
Calculate Average Percentage: Divide the total marks by the total number of subjects to get the3Ä
average percentage.(DONE)
Grade Calculation: Assign grades based on the average percentage achieved.
Display Results: Show the total marks, average percentage, and the corresponding grade to the use*/

import java.util.Scanner;

public class Grade_Calculator {

    String[] subjects = { "Maths", "Physics", "Chemistry", "Biology", "DSA" };
    int[] marks = new int[5];
    int total_marks;
    int percentage;
    char grade;

    Scanner input = new Scanner(System.in);

    void input_marks() {
        System.out.println("----Enter your marks----");
        System.out.println();
        for (int i = 0; i < 5; i++) {
            System.out.println("Enter the marks of " + subjects[i]);
            marks[i] = input.nextInt();
        }
        System.out.println();
    }

    void total_marks() {
        for (int mark : marks) {
            total_marks += mark;
        }
    }

    void avg_percentage() {
        percentage = total_marks / 5;
    }

    void grade() {
        if (percentage >= 90) {
            grade = 'A';
        } else if (percentage >= 80) {
            grade = 'B';
        } else if (percentage >= 70) {
            grade = 'C';
        } else if (percentage >= 60) {
            grade = 'D';
        } else {
            grade = 'F';
        }

    }

    void display_result() {
        System.out.println("-----RESULT-----");
        System.out.println("Total Marks : " + total_marks+"/500");
        System.out.println("Percentage : " + percentage+" %");
        System.out.println("Grade : " + grade);

    }

    public static void main(String[] args) {
        Grade_Calculator student = new Grade_Calculator();
        student.input_marks();
        student.total_marks();
        student.avg_percentage();
        student.grade();
        student.display_result();

    }
}
