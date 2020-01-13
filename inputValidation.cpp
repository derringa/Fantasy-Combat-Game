/**************************************************************************
 * File: Input Validations
 * Author: Andrew Derringer
 * Last Modified: 2/16/2019
**************************************************************************/

#include <iostream>
#include <limits>
#include <chrono>
#include <thread>


using std::cout;
using std::cin;
using std::endl;
using std::max;
using std::string;



/**************************************************************************
 * Passed: Nothing
 * Returns: integer data type
 * Description: Assigns input to desired data type. If no error flags then
 * bool value set to true and value returns, otherwise flags are clearn,
 * and do while loop continuously asks for input until data type check passes.
**************************************************************************/
int integerInputValidate()
{
     int input;
     bool valid = false;

     do
     {
          cin >> input;

          if(cin.good())
          {
               valid = true;
          }
          else
          {
               cin.clear();
               cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
               cout << endl << "Error: You must enter a number from the menu.\n";
               cout << "Please try again:\n";
          }
     }
     while(!valid);

     return input;
}



/**************************************************************************
 * Passed: Min and max integer values
 * Returns: Integer of valid data type in valid range
 * Description: Calls integerInputValidate() for valid integer input. If
 * intger is within passed paramaters for range then value is returned, else
 * a loop continuously asks for input until within range.
**************************************************************************/
int integerRangeValidate(string errorMessage, int min, int max)
{
     int input = integerInputValidate();

     while(input < min || input > max)
     {
          cout << endl << errorMessage << endl;

          input = integerInputValidate();
     }

     return input;
}



/**************************************************************************
 * Passed: Nothing
 * Returns: duuble data type
 * Description: Assigns input to desired data type. If no error flags then
 * bool value set to true and value returns, otherwise flags are clearn,
 * and do while loop continuously asks for input until data type check passes.
**************************************************************************/
double doubleInputValidate()
{
     double input;
     bool valid = false;

     do
     {
          cin >> input;

          if(cin.good())
          {
               valid = true;
          }
          else
          {
               cin.clear();
               cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
               cout << endl << "Error: You must enter a decimal format (#.#).\n";
               cout << "Please enter your response again:\n";
          }
     }
     while(!valid);

     return input;
}



/**************************************************************************
 * Passed: Min and max double values
 * Returns: double of valid data type in valid range
 * Description: Calls doubleInputValidate() for valid double input. If intger
 *  is within passed paramaters for range then value is returned, else a loop
 * continuously asks for input until within range.
**************************************************************************/
double doubleRangeValidate(double min, double max)
{
     double input;

     input =  doubleInputValidate();

     while(input < min || input > max)
     {
          cout << endl;

          cout << "Error: You must enter a decimal format (#.#) between "
               << min << " and " << max <<".\n"
               << "Please enter your response again:\n";

          input = doubleInputValidate();
     }

     return input;
}



/**************************************************************************
 * Passed: Nothing
 * Returns: bool value for condtional positive negative inputs
 * Description: Provides yes or no menue for user. Choosing 1 or yes causes
 * a true return and a no causes a false return.
**************************************************************************/
bool boolValidate()
{
     int answer;
     bool output;

     cout << "1) Yes\n";
     cout << "2) No\n";
     answer = integerRangeValidate("Error: You must enter etheir 1 or 2. Try again:", 1, 2);

     if(answer == 2){
          output = false;
     }else{
          output = true;
     }

     return output;
}
