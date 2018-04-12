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
	//cout<<n<<"n"<<endl;
	multiply(A,A);
	if(n%2 !=0){
		int m[2][2] ={{1,1},{1,0}};
		multiply(A,m);
	}
	//cout<<A[0][0]<<endl;
}

int fib(int n){
	int A[2][2] = {{1,1},{1,0}};
	if(n==0){
		return 0;
	}

	power(A,n-1);

	return A[0][0];
}
int main(){

	int n;
	cin>>n;
	cout<<fib(n);



	return 0;
}