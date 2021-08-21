#include<iostream>

using namespace std;

void getInformation(int array[], int size);
void insertionSort(int array[], int size);

int main(){
    int number;
    cin>>number;
    int array[100];
    getInformation(array, number);
    insertionSort(array, number);
    for(int i = 0; i < number; i++)
        cout<<array[i]<<" ";
    return 0;
}

void getInformation(int array[], int size){
    for(int i = 0; i < size; i++)
        cin>>array[i];
}
void insertionSort(int array[], int size){
    for(int i = 1; i < size; i++){
        int pos = i - 1, x = array[i];
        while(pos >= 0 && array[pos] >= x ){
            array[pos + 1] = array[pos];
            pos--;
        }
        array[pos + 1] = x;
    }
}