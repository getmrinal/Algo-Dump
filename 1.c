#include<stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    int c = 0;
    int sum =0;
    for (int i = 0; i < n; i++)
    {
      scanf("%d",arr[i]);
      if(arr[i] >0){
        c++;
        sum = sum+ arr[i];
      }
      /* code */
    }
    printf("%d",c);
    printf("%d",sum);

}