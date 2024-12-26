#include <iostream>

int main(){
    std::cout << "*********************************\n";
    std::cout << "Welcome to the Mini Quiz Game! \n";
    char userinput;
    int score = 0;
    std::string questions[] = {"1. What year was C++ created?: ", "2. Who invented C++?: ", "3. What is the predecessor of C++?: ", "4. Is the earth flat?: "};
    std::string options [][4] = {{"A. 1969", "B. 1975", "C. 1985", "D. 1989"}, {"A. Guido van Rossum", "B. Bjarne Stroustrup", "C. John Carmac", "D. Mark Zuckerburg"}, {"A. C","B. C+","C. C--", "D. B++"}, {"A. Yes", "B. No", "C. Sometimes", "D. Whats Earth?"}};
    char answerKey[] = {'C', 'B', 'A', 'B'};
    int size = sizeof(questions)/sizeof(questions[0]);
    
    for (int i = 0; i < size; i++){
        std::cout << "*********************************\n";
        std::cout << questions[i] << '\n';
        std::cout << "*********************************\n";
        for (int j = 0; j < sizeof(options[0])/sizeof(options[0][0]); j++){
            std::cout << options[i][j] << '\n';
        }
        
        std::cout << "Input: ";
        std::cin >> userinput;
        userinput = toupper(userinput);
        if (userinput == answerKey[i]){
            std::cout << "Correct!\n";
            score++;
        }
        else{
            std::cout << "Wrong!\n";
            std::cout << "The answer is: " << answerKey[i] << '\n';
        }
    }
    std::cout << "*********************************\n";
    std::cout << "             RESULTS             \n";
    std::cout << "*********************************\n";
    std::cout << "There were " << size << " questions\n";
    std::cout << "You have answered " << score << " questions correctly!\n";
    std::cout << "You have scored " << (score/(double) size)*100 << "%!\n";
    
}
