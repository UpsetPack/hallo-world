
#include <iostream>
void sort(int array[], int size);
int sum(int array[],int size);

int main(){
    int array[] = {13, 9 , 20, 4, 17, 10, 1, 15, 3, 5, 11, 16, 8, 14, 7, 2, 18, 6, 12, 19};
    int size = sizeof(array)/sizeof(array[0]);
    
    sort(array, size);
    std::cout << sum(array, size) << std::endl;
    
    for (int i = 0; i < size; i++){
        std::cout << array[i] << ' ';
    }
    
}

void sort(int array[], int size){
    int temp;
    for (int i = 0; i < size -1; i++){
        for (int j = 0; j < size - 1; j++){
            if (array[j] > array[j+1]){
                std::swap(array[j], array[j+1]);
            }
            
        }
    }
}

int sum(int array[],int size){
    int ret = 0;
    for (int i = 0; i < size; i++) {
        if (i == size-1){
        std::cout << array[i] << " = ";
        }
        else{
            std::cout << array[i] << "+";
        }
    }
    for (int i = 0; i < size; i++) {
        ret += array[i];
    }
    std::cout << ret << std::endl;
    return ret;
}