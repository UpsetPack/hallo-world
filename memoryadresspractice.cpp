#include <iostream>

int main(){
    std::string name = "dude";
    int age = 28;
    bool student = true;
    
    std::cout << &name << '\n';
    std::cout << &age << '\n';
    std::cout << &student << '\n';
}
