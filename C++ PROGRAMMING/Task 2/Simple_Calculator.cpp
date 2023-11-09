/*TASK 2
SIMPLE CALCULATOR
• Develop a calculator program that performs basic arithmetic
operations such as addition, subtraction, multiplication, and
division. Allow the user to input two numbers and choose an
operation to perform.*/

#include <iostream>
using namespace std;

int main()
{
   cout << "-----SIMPLE CALCULATOR-----" << endl;
   cout << endl;
   int num1;
   int num2;
   cout << "Enter first number\n";
   cin >> num1;
   cout << "Enter second number\n";
   cin >> num2;

   cout << endl;

   cout << "Enter '+', '-', '*', or '/' for the operation you want to perform" << endl;

   char opt;
   cin >> opt;
   cout << endl;

   switch (opt)
   {
   case '+':
      cout << "The Sum of the Two Numbers is : " << num1 + num2 << endl;
      break;

   case '-':
      cout << "The Result of Subtraction is : " << num1 - num2 << endl;
      break;

   case '*':
      cout << "The Product of the Two Numbers is : " << num1 * num2 << endl;
      break;

   case '/':
      cout << "The Result of Division is : " << num1 / num2 << endl;
      break;

   default:
      cout << "Enter Valid Operator\n";
      break;
   }
}
