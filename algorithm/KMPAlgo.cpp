#include <iostream>
#include<string>
#include<array>

using namespace std;

void computePrefix(int prefix[], string pattern){
  
  int index = 0;
       
  for(int i=1;i<pattern.length();){
    
    if(pattern[index] == pattern[i]){
      prefix[i] = index+1;
      index++;
      i++;
    }else{
      if(index !=0){
        index = prefix[index-1];
      }else{
        prefix[i] =0;
        i++;
      }
    }
  }

}

bool KMP(string text, string pattern){

 int prefix[pattern.length()];
 computePrefix(prefix,pattern);
  
  int i =0, j=0;
  while(i < text.length() && j < pattern.length()){

     if(text[i] == pattern[j]){
        i++;
        j++;
     }else {
       if(j !=0){
          j = prefix[j-1];
       }else {
         i++;
       }
     }

  }
   if(j == pattern.length())
      return true;

  return false;
}


int main(){
 
 string text, pattern;

 cin >> text ; cin >> pattern;
  
if(KMP(text,pattern))
 cout << "Pattern exists";
else 
 cout << "Pattern doesn't exists";

 return 0;

}