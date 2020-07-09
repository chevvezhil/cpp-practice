// This algo is used to find the max contuneous sub array sum
#include<iostream>
#include<array>
#include<climits>

using namespace std;

int kadanesAlgo(int a[],int length){

    int MAX_SO_FAR=INT_MIN;
    int max_ending_here =0;

    for(int i=0;i<length;i++){

        max_ending_here += a[i];
        if(MAX_SO_FAR < max_ending_here)
            MAX_SO_FAR = max_ending_here;

        if(max_ending_here <0)
            max_ending_here =0;
    }

    return MAX_SO_FAR;
}

int main(){
    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int length  = sizeof(a) / sizeof(a[0]);

    cout << "Max sub of subarray : "<< kadanesAlgo(a,length) << endl;
}