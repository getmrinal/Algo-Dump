#include<bits/stdc++.h>
using namespace std;
int weight=0;
int knapSackH(int *val,int *wt,int n,int W){
	    int mat[2][W+1];
    for(int i=0;i<2;i++){
        for(int j=0;j<=W;j++){
            mat[i][j] = 0;
        }
    }
 
    // iterate through all items
    int i = 0;
    while (i < n) // one by one traverse each element
    {
        int j = 0; // traverse all wieghts j <= W
 
        // if i is odd that mean till now we have odd
        // number of elements so we store result in 1th
        // indexed row
        if (i%2!=0)
        {
            while (++j <= W) // check for each value
            {
                if (wt[i] <= j) {// include elemen
                       int a = val[i] + mat[0][j-wt[i]];
                        int b = mat[0][j];
                        if(a>b){    
                            weight= weight + wt[i];
                            mat[1][j] = max(a,b);
                        }
                    }
                else    {
                    mat[1][j] = mat[0][j];
                }       // exclude element
            }
 
        }
 
        // if i is even that mean till now we have even number
        // of elements so we store result in 0th indexed row
        else
        {
            while(++j <= W)
            {
                if (wt[i] <= j){
                    int a = val[i] + mat[1][j-wt[i]];
                    int b = mat[1][j];
                    if(a>b){
                        weight= weight + wt[i];
                    }
                    mat[0][j] = max(a,b);
                }
                else{
                    mat[0][j] = mat[1][j];
                }
            }
        }
        i++;
    }
 
    // Return mat[0][W] if n is odd, else mat[1][W]
    return (n%2 != 0)? mat[0][W] : mat[1][W];

}


int knapsack(int* weights, int* values, int n, int maxWeight){


  return knapSackH(values,weights,n,maxWeight);
  

}


int main(){
    int maxW;
    cin>>maxW;
    int n;
    cin>>n;
    int *val = new int[n];
    int *wt = new int[n];
    for(int i=0;i<n;i++){
        cin>>val[i]>>wt[i];
    }
    cout<<knapsack(val,wt,n,maxW)<<" ";
    cout<<weight;
}

