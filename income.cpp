#include <iostream>
using namespace std;

unsigned long long MOD = 1000000007;

void multiply(unsigned long long A[2][2],unsigned long long M[2][2]){
	unsigned long long fval = (((A[0][0]*M[0][0])%(MOD-1) + (A[0][1] *M[1][0])%(MOD-1))%(MOD-1));
	unsigned long long sval = (((A[0][0]*M[0][1])%(MOD-1) + (A[0][1] *M[1][1])%(MOD-1))%(MOD-1));
	unsigned long long tval = (((A[1][0]*M[0][0])%(MOD-1) + (A[1][1] *M[1][0])%(MOD-1))%(MOD-1));
	unsigned long long rval = (((A[1][0]*M[0][1])%(MOD-1) + (A[1][1] *M[1][1])%(MOD-1))%(MOD-1));

	A[0][0] = fval;
	A[0][1] = sval;
	A[1][0] =tval;
	A[1][1] = rval;

}

void power(unsigned long long A[2][2],unsigned long long n){
	if(n==0 || n==1){
		return;
	}

	power(A,n/2);
	multiply(A,A);
	if(n%2 !=0){
		unsigned long long m[2][2] ={{1,1},{1,0}};
		multiply(A,m);
	}
	
}

unsigned long long fib(unsigned long long n){ //find nth fib with modulo mod-1
	unsigned long long A[2][2] = {{1,1},{1,0}};
	if(n==0){
		return 0;
	}

	power(A,n-1);
	
	return (unsigned long long)A[0][0];
}

unsigned long long powerMod(unsigned long long a,unsigned long long b){
	if(b==0){
		return 1;
	}
	
	if(b%2==0){
		return powerMod((a*a)%MOD,b/2);
	}else{
		unsigned long long ans = powerMod((a*a)%MOD,b/2);
		return ((a%MOD)*ans)%MOD;
	}
}

int main(){

	int t;
  	cin>>t;
	while(t--){
    int a;
	int b;
	int n;
	cin>>a>>b>>n;
    unsigned long long result;
	if(n>1){
    a = a+1;
	b = b+1;
	unsigned long long f1=fib(n-1);
	unsigned long long f2 = fib(n);
	result = (powerMod(a,f1)%MOD*powerMod(b,f2))%MOD;
	
	result = result -1;
    }else{
      if(n==0){
        result = a;
      }else{
        result= b;
      }
    }
	cout<<result<<endl;
    }



	return 0;
}