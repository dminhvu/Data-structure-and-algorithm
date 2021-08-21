#include<iostream>

using namespace std;

void getInformation(int array[], int size);
void mergeSort(int array[], int left, int right);
void merge(int array[], int left, int mid, int right);

int main(){
    int number;
    cin>>number;
    int array[100];
    getInformation(array, number);
    mergeSort(array, 0, number - 1);
    for(int i = 0; i < number; i++)
        cout<<array[i]<<" ";
    return 0;
}

void getInformation(int array[], int size){
    for(int i = 0; i < size; i++)
        cin>>array[i];
}
void mergeSort(int array[], int left, int right){
    if(left < right){
        int mid = left + (right - left) / 2;
        mergeSort(array, left, mid);
        mergeSort(array, mid + 1, right);
        merge(array, left, mid, right);
    }
}
void merge(int array[], int left, int mid, int right){
    //  initialize temporary arrays' sizes
    int firstSubArraySize = mid - left + 1, secondSubArraySize = right - mid;
    
    //create temp arrays to store values 
    int *leftArray = new int[firstSubArraySize];
    int *rightArray = new int[secondSubArraySize];

    //copy values from the main array to the sub arrays
    for(int i = 0; i < firstSubArraySize; i++)
        leftArray[i] = array[left + i];
    for(int j = 0; j < secondSubArraySize; j++)
        rightArray[j] = array[mid + 1 + j];

    //initialize sub arrays' indexes and main array's index
    int leftArrayIndex = 0, rightArrayIndex = 0, mainArrayIndex = left;

    //comparing values from each sub arrays then store in main array
    while(leftArrayIndex < firstSubArraySize && rightArrayIndex < secondSubArraySize) {
        if(leftArray[leftArrayIndex] < rightArray[rightArrayIndex]) {
            array[mainArrayIndex] = leftArray[leftArrayIndex];
            leftArrayIndex++;
        }
        else {
            array[mainArrayIndex] = rightArray[rightArrayIndex];
            rightArrayIndex++;
        }
        mainArrayIndex++;
    }

    //if sub arrays still contain values, we will store the rest of them in main array
    while(leftArrayIndex < firstSubArraySize){
        array[mainArrayIndex] = leftArray[leftArrayIndex];
        leftArrayIndex++;
        mainArrayIndex++;
    }

    while(rightArrayIndex < secondSubArraySize){
        array[mainArrayIndex] = rightArray[rightArrayIndex];
        rightArrayIndex++;
        mainArrayIndex++;
    }
    delete leftArray, rightArray;
}