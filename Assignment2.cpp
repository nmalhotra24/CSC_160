/*                                                                                                                                                                                   
Nikita Malhotra                                                                                                                                                                      
CSC 160: Assign #2                                                                                                                                                                  
Purpose: To develop a program that computes the prime divisor of an integer number between 2 and 10,000.                                                                             
Last Updated: Oct 12th, 2012                                                                                                                                                         
*/

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  int number;
  int sqrt_num;
  int original_num;

  //Prompting the user to enter an integer number.                                                                                                                                   
  cout << "Please enter an integer number in the range of 2 to 10,000:\n";
  cin >> number;

  //Making sure that the integer number is in the given range.                                                                                                                       
  while (number < 2 || number > 10000){
    cout << "The integer number must be in the range of 2 to 10,000.\n";
    cout << "Please enter an integer number in the range of 2 to 10,000:\n";
    cin >> number;
  }

  //Variable, sqrt_num, stores sqrt(number) to avoid getting changed in the for loop.                                                                                                
  sqrt_num = sqrt(number);

  //Variable, original_num, stores number and gets used if the number is prime.                                                                                                      
  original_num = number;

  cout << "You have entered " << number << " and " << endl;
  cout << number << " = ";

  //Finding the prime divisors of the number                                                                                                                                         
  for (int i = 2; i <= sqrt_num; ++i){
    while (number % i == 0){
      number = number/i;
      if (number !=1){                                              
      cout << i << " * ";
      } else {
        cout << i;
      }
    }
  }

  //If the number is prime, the factors will be the number itself and 1.                                                                                                             
  if (number == original_num){
    cout << " 1 * " << number;
  } else if (number != 1){
    cout << number;
  }

  cout << endl;
  return 0;
}

