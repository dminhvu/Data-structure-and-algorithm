#include<iostream>

using namespace std;

void getInformation(int array[], int size);
void selectionSort(int array[], int size);

int main(){
    int number;
    cin>>number;
    int array[100];
    getInformation(array, number);
    selectionSort(array, number);
    for(int i = 0; i < number; i++)
        cout<<array[i]<<" ";
    return 0;
}

void getInformation(int array[], int size){
    for(int i = 0; i < size; i++)
        cin>>array[i];
}
void selectionSort(int array[], int size){
    for(int i = 0; i < size; i++) {
        int min = i;
        for(int j = i + 1; j < size; j++) {
            if(array[j] < array[min]) min = j;
        }
        if(array[i] > array[min]) swap(array[i], array[min]);
    }
}