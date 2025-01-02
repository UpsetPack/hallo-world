#include <iostream>

/*
Steps to apply Luhn's Algorithm
1.Flip the values, from right to left: 123456789 --> 987654321
2.Starting from the 2nd number in order, multiply by 2: 9 16 7 12 5 8 3 4 1
3.For any values with 2 digits (greater than 9), split the 2 digits and find the sum of the two digits and replace the doubled value with the sum: 1+6 1+2 --> 7 3
4.Find the sum of all the values: 9 + 7 + 7 + 3 + 5 + 8 + 3 + 4 + 1 --> 47
5.If the sum is divisible by 10, the given values is valid. If it is not, it is not valid: 47/10 = 4.7 --> not valid

The algorithm would also work without flipping the values, but performing the same actions from furthest right value to the left
*/

int main()
{
    std::string ccnum;
    std::string ccnuminpt;
    int result = 0;
    std::cout<<"Please enter your credit card number\n";
    std::cout<<"Input: ";
    std::getline(std::cin, ccnuminpt);
    
    for (char c : ccnuminpt) { //for loop goes through every character in the string and checks for whitespaces ' ', if there are no whitespaces, it adds the character into a string variable
        if (c != ' ') {
            ccnum += c;
        }
    }


    for (int i = ccnum.size()-1; i >= 0; i--){ 
        int digit = ccnum[i] - '0'; //Since ccnum[i] retrieves a char value from position i, it will be in ASCII code. Therefore by doing -'0' and subtracting the base value of 0, the right value would be the result
        
        if ((ccnum.size() -1 -i) % 2 == 1){ //goes through the ccnum values and checks if the value is ODD (in terms of value index position in the string)
            digit*=2;
        }
        if (digit >= 10){ //checks for any value with double digits
            result += (digit % 10) + (digit / 10); //splits the two digits apart and sum the two values. 
        }
        else{
            result += digit; //adds all Even and Odd values together into a single sum
        }
        
    }
    if (result % 10 == 0){ //checks if the result is divisible by 10
        std::cout << "The Credit Card number is Valid\n";
    }
    else{
        std::cout << "The Credit Card number is not valid\n";
    }
    return 0;
}