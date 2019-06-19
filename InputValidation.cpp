//
// Created by Richard Joseph on 2019-06-01.
//

/*Input Validation function to make sure user enters an integer value of either
 Source:learncpp.com/cpp-tutorial/5-10-stdcin-extraction-and-dealing-with-invalid-text-input/
 */

#include "InputValidation.h"

int inputValidation(int start, int end)
{
    while (true)
    {
        int userInput;
        std::cin >> userInput;


        if (userInput >= start && userInput <= end)
        {
            std::cin.ignore(10000, '\n');
            return userInput;
        }

        else
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "The input is invalid. Please enter a new value." << std::endl;
        }
    }
}
