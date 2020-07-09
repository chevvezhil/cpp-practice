#include<iostream>
#include<array>

using namespace std;


void seive(int n){
 bool visited[n];

  for(int i=0;i<=n;i++)
      visited[i] = true;

    for(int i=2 ; i*i <=n ;i++){
        
        if(visited[i] == true){
            for( int p =i*i ; p<=n ; p +=i){
                visited[p] = false;
            }
        }

    }

    for(int i=0;i <=n ;i++){
        if(visited[i] == true)
          cout <<i <<endl;
    }
}

int main(){
    int n;
    cin >>n;
    seive(n);
}
