#include <iostream>
#include<string>
using namespace std;

#include <string>
using namespace std;

int keypadHelper(int num,string *output){
  if(num==0){
  	output[0] = "";
  	return 1;
  }
  if(num==2){
    output[0] = 'a';
    output[1] = 'b';
    output[2] = 'c';
    return 3;
  }
  if(num==3){
    output[0] = 'd';
    output[1] = 'e';
    output[2] = 'f';
    return 3;
  }
  if(num==4){
    output[0] = 'g';
    output[1] = 'h';
    output[2] = 'i';
    return 3;
  }
  if(num==5){
    output[0] = 'j';
    output[1] = 'k';
    output[2] = 'l';
    return 3;
  }
  if(num==6){
    output[0] = 'm';
    output[1] = 'n';
    output[2] = 'o';
    return 3;
  }
  if(num==7){
    output[0] = 'p';
    output[1] = 'q';
    output[2] = 'r';
    output[3] = 't';
    return 4;
  }
  if(num==8){
    output[0] = 't';
    output[1] = 'u';
    output[2] = 'v';
    return 3;
  }
  if(num==9){
    output[0] = 'w';
    output[1] = 'x';
    output[2] = 'y';
    output[3] = 'z';
    return 4;
  }
  
  
  //int output
  int rem = num%10; 
  int cal = num/10;
  int size = keypadHelper(cal,output);
  string *temp = new string[size];

  for (int i = 0; i < size; ++i)
  {
  	temp[i] = output[i];
  }
  if(rem == 2){
    	int i;
    	int j =0;
    	for( i=0;i<size;i++){
          output[i] = temp[j++] + 'a';
        }
        j=0;
    	for(;i<size*2;i++){
          output[i] = temp[j++] + 'b';
        }
        j=0;
    
    	for(;i<size*3;i++){
          output[i] = temp[j++] + 'c';
        }
 		return i;
  }
  if(rem == 3){
    	int i;
    	int j=0;
    	for( i=0;i<size;i++){
          output[i] = temp[j++] + 'd';
        }
        j=0;
    	for(;i<size*2;i++){
          output[i] = temp[j++] + 'e';
        }
    	j=0;
    	for(;i<size*3;i++){
          output[i] =temp[j++] + 'f';
        }
        return i;
 
  }
  if(rem == 4){
    	int i;
    	int j=0;
    	for( i=0;i<size;i++){
          output[i] = temp[j++] + 'g';
        }
        j=0;
    	for(;i<size*2;i++){
          output[i] = temp[j++] + 'h';
        }
        j=0;
    	for(;i<size*3;i++){
          output[i] = temp[j++] + 'i';
        }
        return i;
 
  }
  if(rem == 5){
    	int i;
    	int j=0;
    	for( i=0;i<size;i++){
          output[i] = temp[j++] + 'j';
        }
        j=0;
    	for(;i<size*2;i++){
          output[i] = temp[j++] + 'k';
        }
        j=0;
    
    	for(;i<size*3;i++){
          output[i] = temp[j++] + 'l';
        }
 	return i;
  }
  if(rem == 6){
    	int i;
    	int j=0;
    	for( i=0;i<size;i++){
          output[i] = temp[j++] + 'm';
        }
        j=0;
    	for(;i<size*2;i++){
          output[i] = temp[j++] + 'n';
        }
        j=0;
    
    	for(;i<size*3;i++){
          output[i] = temp[j++] + 'o';
        }
        return i;
 
  }
  if(rem == 7){
    	int i;
    	int j=0;
    	for( i=0;i<size;i++){
          output[i] = temp[j++] + 'p';
        }
        j=0;
    	for(;i<size*2;i++){
          output[i] = temp[j++] + 'q';
        }
    	j=0;
    	for(;i<size*3;i++){
          output[i] = temp[j++] + 'r';
        }
        j=0;
   		 for(;i<size*4;i++){
          output[i] = temp[j++] + 's';
        }
        return i;
 
  }
  if(rem == 8){
    	int i;
    	int j=0;
    	for( i=0;i<size;i++){
          output[i] = temp[j++] + 't';
        }
        j=0;
    	for(;i<size*2;i++){
          output[i] = temp[j++] + 'u';
        }
    	j=0;
    	for(;i<size*3;i++){
          output[i] = temp[j++] + 'v';
        }
        return i;
 
  }
  if(rem == 9){
    	int i;
    	int j=0;
    	for( i=0;i<size;i++){
          output[i] = temp[j++] + 'w';
        }
        j=0;
    	for(;i<size*2;i++){
          output[i] = temp[j++] + 'x';
        }
    	j=0;
    	for(;i<size*3;i++){
          output[i] = temp[j++] + 'y';
        }
        j=0;
    for(;i<size*4;i++){
          output[i] = temp[j++] + 'z';
        }
        return i;
    }
}



int keypad(int num, string output[]){
    	
  
  	return keypadHelper(num,output);
  
}




int main(){

	int a= 33;
	string *output  = new string[200];
	
	 int c = keypad(a,output);
	for (int i = 0; i < c; i++)
		{
			/* code */
			cout<<output[i]<<endl;
		}


	return 0;
}