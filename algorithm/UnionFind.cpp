#include<iostream>

using namespace std;

int count;

int root(int arr[], int ele){

    while(arr[ele] !=ele){
        arr[ele] = arr[arr[ele]];
        ele = arr[ele];
    }

    return ele;

}

bool find(int arr[], int a,int b){
    if(root(arr,a) == root(arr,b))
        return true;
    else
        return false;
}

void union_(int arr[], int a , int b){

    int rootA = root(arr,a);
    int rootB = root(arr,b);
    if(rootA !=rootB){
     arr[rootA] = rootB;
     ::count --;
    }
}

void setCount(int n){
    ::count =n;
}
int getCount(){
    return ::count;
}



int main(){

    int arr[3][3] = {{1,1,0}, {1,1,0}, {0,0,1}};

    int result[3];

    for(int i=0;i<3;i++)
        result[i] =i;
    
    setCount(3);
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){

            if(arr[i][j] ==1 && i!=j){
                union_(result,i,j);
            }
        }
    }

    cout << getCount()<<endl;

    return 0;
}