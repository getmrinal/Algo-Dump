#include <map>
#include <iostream>
using namespace std;
using namespace std;

char* uniqueChar(char *str){
    // Write your code here
  
  map <char, int> m;
  map <char, int> :: iterator it;
  
  int size=0;
  
  for(int i=0; str[i] != '\0' ; i++){
    size++;
  }
  
  for(int i=0; i<size; i++){
   	m[str[i]]++;
  }
  
  char* output;
  int n=0;
  
  for(int i=0; i<size ; i++){
    
    it = m.find(str[i]);
    
    if(it -> second == 1){
   	  output[n] = it -> first;
   	  n++;
    }
    
  }
	
  return output;
}
int main(){
    char str[] = "abbacd";
    char *out = uniqueChar(str);
    int size = sizeof(out)/sizeof(out[0]);
    for (int i = 0; i < size; ++i)
    {
      /* code */
      cout<<out[i]<<' ';
    }
}