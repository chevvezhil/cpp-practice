#include<iostream>

using namespace std;

int getMax(int arr[],int size){
    int max =arr[0];

    for(int i=0;i<size;i++){
        if(arr[i] > max)
            max = arr[i];
    }
    return max;
}


void countSort(int arr[], int size,int place){

    int output[size+1];

    int max = getMax(arr,size);

    int count[max+1];

    for(int i=0;i<=max;i++)
        count[i]=0;

    for(int i=0;i<size;i++)
        count[(arr[i]/place) %10]++;

    for(int i=1;i<10;i++)
        count[i] +=count[i-1];

    for(int i=size-1; i >=0;i--){
        output[count[(arr[i]/place)%10]-1] = arr[i];
        count[(arr[i]/place)%10]--;
    }

    for (int i = 0; i < size; i++)
      arr[i] = output[i];
}


void radixSort(int arr[] , int size){

    int max = getMax(arr,size);

    for(int place=1; max/place >0 ;place *=10)
        countSort(arr,size,place);

}
void print(int arr[], int size){

for(int i=0;i<size;i++)
    cout<<arr[i]<<endl;

}

int main(){

    int arr[] = {121, 432, 564, 23, 1, 45, 788};
    int size = sizeof(arr) / sizeof(arr[0]);
    radixSort(arr,size);
    print(arr,size);

    return 0;

}