/*
Steps to apply Luhn's Algorithm
1.Flip the values, from right to left: 123456789 --> 987654321
2.Starting from the 2nd number in order, multiply by 2: 9 16 7 12 5 8 3 4 1
3.For any values with 2 digits (greater than 9), split the 2 digits and find the sum of the two digits and replace the doubled value with the sum: 1+6 1+2 --> 7 3
4.Find the sum of all the values: 9 + 7 + 7 + 3 + 5 + 8 + 3 + 4 + 1 --> 47
5.If the sum is divisible by 10, the given values is valid. If it is not, it is not valid: 47/10 = 4.7 --> not valid

The algorithm would also work without flipping the values, but performing the same actions from furthest right value to the left
*/

#include <iostream>

void spacecheck(std::string &ccnum);
int checkEven(const std::string &ccnum);
int checkOdd(const std::string &ccnum);
int splitAdd (int digit);

int main(){
    
    std::string ccnum;
    int result;
    
    std::cout << "--==+ Credit Card Validity Checker +==--\n";
    std::cout << "Please enter your Credit Card Number\n";
    std::cout << "Input: ";
    std::getline(std::cin, ccnum); //gets entire input, without stopping at whitespaces
    
    spacecheck(ccnum);
    
    result = checkOdd(ccnum) + checkEven(ccnum); //sums the total odd and even values
    
    if (result % 10 == 0){ //checks if the result is divisible by 10
            std::cout << '\n' << "Your Credit Card Number is Valid\n";
    }
    else{
            std::cout << '\n' << "Your Credit Card Number is Invalid\n";
    }
    
    return 0;
}

void spacecheck(std::string &ccnum){ //loop checks for any whitespaces in the string, only if there aren't any whitespaces, the character is added into a temp string and accumulated
    std::string temp;
    for (char c: ccnum){
        if (c != ' '){
            temp+=c;
        }
    }
    ccnum = temp; //As function argument &ccnum is pass by reference, result of variable ccnum will update inside of main automatically
}

int splitAdd (int digit){
    return (digit % 10) + (digit / 10); //splits the two digits apart and sum the two values. 
}

int checkOdd(const std::string &ccnum) {
    int result = 0;
    for (int i = ccnum.size()-2; i >= 0; i-=2){ //run through every odd array position, like (1,3,5)
        int digit = ccnum[i] - '0'; //Since ccnum[i] retrieves a char value from position i, it will be in ASCII code. Therefore by doing -'0' and subtracting the base value of 0, the right value would be the result
        digit*=2; 
        
        if (digit > 9){ //checks if value has 2 digits, like (10). Therefore (> 9) argument can be used
            result += splitAdd(digit); 
            
        }
        else{
            result += digit;
        }
    }
    return result;
}

int checkEven(const std::string &ccnum) {
    int result = 0;
    for (int i = ccnum.size()-1; i >= 0; i-=2){ //run through every even array position, like (0,2,4)
        int digit = ccnum[i] - '0';
        result += digit;
        
    }
    return result;
}