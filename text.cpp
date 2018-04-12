#include <iostream>
using  namespace std;
// arr - input array
// n - size of array

void sort012(int arr[], int n)  {  
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * No need to print or return the output.
     * Taking input and printing output is handled automatically.
     */
		
  	int i =0;
  	int j = n-1;
  	while(i<=j){
      if(arr[i]== 0){
        i++;
      }else if(arr[j] == 2){
        j--;
      }else if(arr[j] == 1){
        int temp = arr[i+1];
        arr[i+1] = arr[j];
        arr[j] = temp;
        i++;
        j--;
      }else{
      	int temp = arr[i];
      	arr[i] = arr[j];
      	arr[j] = temp;
      	i++;
      	j--;
      }
    }
}


int main(){
	int arr[] = {0,1,2,0,2,0,1};
	int size = 7;

	sort012(arr,size);
	for(int i=0;i<size;i++){
		cout<<arr[i]<<'\n';
	}
}