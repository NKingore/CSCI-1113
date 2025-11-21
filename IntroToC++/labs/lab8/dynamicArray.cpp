#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

//create dynamic array
int* create_array (int size){
    int* dynamicArray = new int[size];
    return dynamicArray;
}

//insert a value into dynamic array
void insert(int* data, int index, int value){
    data[index] = value;
}

int main(){
//random number generator between 300 and 800
    int min = 300, max = 800;
    srand(static_cast<unsigned int>(time(NULL)));
    int n = rand() % (max - min + 1) + min;
    
//create initial array
    int size = 2, current_index, current_size;
    int* arr = create_array(size);
    int count = 0;

    cout << "Initial size:" << size << endl;

    for (int i = 0; i < n; i++){
        if (count == size) {
            int newSize = size * 2;
            int* newArr = create_array(newSize);

            for (int j = 0; j < size; j++){
                newArr[j] = arr[j];
            }
        delete[] arr;

        arr = newArr;
        size = newSize;

        cout << "Array expanded: new size = " << size << endl;
        }

        insert(arr, count, i + 1);
        count++;
    }

    cout << "Finished inserting " << n << " integers." << endl;
    cout << "Final size = " << size << endl;

    delete[] arr;
    
    return 0;
}