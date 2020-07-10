#include<iostream>

using namespace std;    
void countingSort(int arr[],int size){
    
    int output[size+1];

    int max = arr[0];
   
    for(int i=1;i<size;i++){
        if(arr[i] >max)
          max = arr[i];
    }

    int count[max+1];

    for(int i=0;i<max;i++)
        count[i] = 0;

 // Count the value in array
    for(int i=0;i<size;i++)
        count[arr[i]]++;

 //store the cummulative of each element

 for(int i=1;i<=max;i++)
    count[i] +=count[i-1];
// Find the index of each element and place it in o/p array

for (int i = size - 1; i >= 0; i--) {
    output[count[arr[i]] - 1] = arr[i];
    count[arr[i]]--;
  }


//copy the o/p array to original array
for(int i=0;i<size;i++)
    arr[i] = output[i];
}

void print(int arr[], int size){

for(int i=0;i<size;i++)
    cout<<arr[i]<<endl;


}

int main(){

    int arr[] = {2,8,1,7,10,1};
    int size = sizeof(arr)/sizeof(arr[0]);
    countingSort(arr,size);
    print(arr,size);
}