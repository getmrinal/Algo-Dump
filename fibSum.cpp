#include <iostream>
using namespace std;
void multiply(int A[2][2],int M[2][2]){
	int fval = A[0][0]*M[0][0] + A[0][1] *M[1][0];
	int sval = A[0][0]*M[0][1] + A[0][1] *M[1][1];
	int tval = A[1][0]*M[0][0] + A[1][1] *M[1][0];
	int rval = A[1][0]*M[0][1] + A[1][1] *M[1][1];

	A[0][0] = fval;
	A[0][1] = sval;
	A[1][0] =tval;
	A[1][1] = rval;

}

void power(int A[2][2],int n){
	if(n==0 || n==1){
		return;
	}

	power(A,n/2);
	multiply(A,A);
	if(n%2 !=0){
		int m[2][2] ={{1,1},{1,0}};
		multiply(A,m);
	}
	//cout<<A[0][0]<<endl;
}

int fib(int n,int &s){
	int A[2][2] = {{1,1},{1,0}};
	if(n==0){
		return 0;
	}

	power(A,n-1);
	if(s!=0){
		s= A[0][1];
	}
	return A[0][0];
}
int fibSum(int n,int m){
	int s=1;
	int f1 = fib(n,s);
	int r=0;
	int f2 = fib(m,r);
	
	int sum =0;
	while(f1<=f2){
		int t = f1;
		sum = sum+f1;
		f1 = f1+ s;
		s = t;
	
	}
	return sum;
}
int main(){

	int n;
	int m;
	cin>>n>>m;
	cout<<fibSum(n,m);	



	return 0;
}