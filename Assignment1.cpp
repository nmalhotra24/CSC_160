// Author: Nikita Malhotra                                                                                                                                                           
// CSC 160: Assignment #1                                                                                                                                                           
// Purpose: To design a program to help the BC government calculate the propery                                                                                                      
// tax.                                                                                                                                                                              
// Last Updated Monday Oct 1st, 2012                                                                                                                                                 

#include <iostream>
using namespace std;

const double tax1=0.01;
const double tax2=0.02;

int main()
{
  double propertyvalue;
  double taxpayable;
  double exemption;
  double finalvalue;
  char answer;
  int location;
  int qv; //QV = qualification value                                                                                                                                                 

  cout << "Please enter the Fair Market Value of the property:\n";
  cin >> propertyvalue;

  while (propertyvalue <= 0){ //The property value cannot be a negative number.                                                                                                      
    cout << "Property value must be greater than zero.\n";
    cout << "Please enter Again:";
    cin >> propertyvalue;
  }

  cout << "Are you a first time home buyer?\n";
  cout << "Y/N/y/n?\n";
  cin >> answer;

  //Making sure the user's answer is either yes or no.                                                                                                                               
  if (answer!= 'Y' && answer!= 'N'&& answer!= 'y' && answer!= 'n'){
    cout << "Invalid answer.\n"
         << "Please enter again: ";
    cin >> answer;
  }

  if (answer == 'N'|| answer == 'n'){
    if (propertyvalue <= 200000){
      taxpayable = tax1 * propertyvalue;
    } else if (propertyvalue > 200000){
      taxpayable = ((tax1 * 200000) + (tax2 * (propertyvalue - 200000)));
    }
    cout << "Your Property Tax is " << taxpayable << endl;
  } else if (answer == 'Y' || answer == 'y'){
    cout << "Where is this property located?\n"
         << "Enter 1 for the Capital Regional District\n"
         << "2 for the Greater Vancouver Regional Distrtict\n"
         << "3 for the Fraser Valley Regional District\n"
         << "And 4 if located elsewhere in the province: ";
    cin >> location; //The property can only be located in these districts.                                                                                                          

  while (location < 1 || location > 4){                                                                    
    cout << "Invalid entry.\n"
         << "Please re-enter the property location:";
    cin >> location;
  }

  if (location == 1 || location == 2 || location == 3){
    qv = 325000; //The qualifying value if located in either 1,2, or 3.                                                                                                              
  } else if (location == 4){
    qv = 265000; //The qualifying value if located in 4.                                                                                                                             
  }

  if (propertyvalue <= 200000){
      taxpayable = tax1 * 200000;
  } else if (propertyvalue > 200000){
    taxpayable = ((tax1 * propertyvalue) + (tax2 * (propertyvalue - 200000)));
  }


  if (propertyvalue < 325000){
    exemption = taxpayable;
  } else if (propertyvalue > (325000 + 25000) || propertyvalue > 325000){
    exemption = (qv + 25000 - propertyvalue)/25000 * taxpayable;
  }

  finalvalue = propertyvalue - exemption;

  cout << "Your Property tax is: " << finalvalue << endl;
  }

  return 0;
}
