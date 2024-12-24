#include <iostream>

int main(){
    
    std::string foods[5];
    std::string temp;
    int size = sizeof(foods)/sizeof(foods[0]);
    
    for (int i = 0; i < size; i++){
        std::cout << "Enter in a food that you like (enter q to quit) #" << i+1 << ": ";
        std::getline(std::cin, temp);
        if (temp == "q" || temp == "Q"){
            break;
        }
        else{
            foods[i] = temp;
        }
    }
    std::cout << "You like the following foods\n";
    
    for (int i = 0; !foods[i].empty(); i++){
        std::cout << foods[i] <<'\n';
    }
    return 0;
}