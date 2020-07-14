#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

struct suffix{
    int index;
    char* suff;
};

int cmp(struct suffix a, struct suffix b){
    return strcmp(a.suff,b.suff) <0 ? 1:0;
}

int *buildSuffixArray(char *text, int n){
    struct suffix suffixes[n];

    for(int i=0;i<n;i++){
        suffixes[i].index =i;
        suffixes[i].suff = (text+i);
    }
    cout <<"suffixed+n "<<suffixes+n<<endl;
    sort(suffixes,suffixes+n,cmp);

    int* suffixArray = new int[n];
    for(int i=0;i<n;i++)
        suffixArray[i] = suffixes[i].index;
    
    return suffixArray;
}

void printArr(int arr[], int n) 
{ 
    for(int i = 0; i < n; i++) 
        cout << arr[i] << " "; 
    cout << endl; 
} 

int main() 
{ 
    char txt[] = "banana"; 
    int n = strlen(txt); 
    int *suffixArr = buildSuffixArray(txt,  n); 
    cout << "Following is suffix array for " << txt << endl; 
    printArr(suffixArr, n); 
    return 0; 
} 