
/*Task 1: Number Guessing Game in Java

This Java program has been developed as part of the internship program at CODSOFT, serving as Task 1. 
The purpose of this code is to create an interactive number guessing game. 
In this game, a random number is generated within a specified range,
and the player's task is to guess the correct number within a limited number of attempts.
 
 */

import java.util.Random;
import java.util.Scanner;

public class Number_Game {
  
  String player_name ;
  int random_num;
  int wins = 0;
  int maxattempts = 7;
  int rounds = 1;

  Scanner input = new Scanner(System.in);

  public int randomnum() {
    Random random = new Random();
    random_num = random.nextInt(51);

    return random_num;
  }

  public void game() {
    
    System.out.println("-----Round " + rounds+"-----");
    System.out.println("GUESS THE NUMBER FROM 1 TO 50");
    while (true) {
      if (maxattempts == 0) {
        System.out.println();
        System.out.println("SORRY!! YOU ARE OUT OF MOVES");
        break;
      }
      int num = input.nextInt();
      if (num == random_num) {
        System.out.println("CONGRATS "+ player_name+" !! YOU GUESSED CORRECTLY");
        wins++;
        break;
      }

      if (num <= random_num + 5 && num >= random_num - 5) {
        if (num <= random_num + 5 && num >=random_num) {
          System.out.println("Your guess is slightly high. Keep going!");
          System.out.println("Attempts left: " + --maxattempts);
          System.out.println("Guess Again");
          continue;
        }
        else if (num >= random_num - 5 && num <= random_num) {
          System.out.println("Your guess is slightly low. Keep going!");
          System.out.println("Attempts left: " + --maxattempts);
          System.out.println("Guess Again");
          continue;
        }
        

     
      } else if (num <= random_num + 10 && num >= random_num - 10) {
        if (num <= random_num + 10 && num >= random_num) {
          System.out.println("Your guess is slightly high. Keep going!");
          System.out.println("Attempts left: " + --maxattempts);
          System.out.println("Guess Again");
          continue;

        }
        if (num >= random_num - 10 && num <= random_num) {
          System.out.println("Your guess is slightly low. Keep going!");
          System.out.println("Attempts left: " + --maxattempts);
          System.out.println("Guess Again");
          continue;

        }
      } else {
        if (num > random_num) {
          System.out.println("Your guess is too high. Try a smaller number");
          System.out.println("Attempts left: " + --maxattempts);
          System.out.println("Guess Again");
          continue;

        }

        if (num < random_num) {
          System.out.println("Your guess is too low. Try a larger number");
          System.out.println("Attempts left: " + --maxattempts);
          System.out.println("Guess Again");
          continue;

        }
      }

    }
  }

  public void Greet(){
    System.out.println("Enter your name");
    player_name = input.nextLine();
    System.out.println("HELLO "+ player_name+" !!!");
    System.out.println("WELCOME TO GUESS THE NUMBER GAME!!!");
    System.out.println("LETS BEGIN!!!");
    System.out.println();

  }

  public void play() {
    Greet();
    while (true) {
      randomnum();
      game();
      System.out.println();
      System.out.println("You played "+rounds+" Round");
      System.out.println("Your Score is "+wins);
      System.out.println();
      System.out.println("Do you wanna play another round?");
      System.out.println("Enter 1 for Yes");
      System.out.println("Enter 0 for No");
      int yes_no = input.nextInt();
      if (yes_no == 1) {
        rounds++;
        maxattempts = 7;
        System.out.println();
        continue;
      } else {
        System.out.println();
        System.out.println("You played "+rounds+" Round");
        System.out.println("Your Score is "+wins);
        break;
      }

    }

  }

  public static void main(String args[]) {

    Number_Game obj1 = new Number_Game();
    obj1.play();

  }
}
