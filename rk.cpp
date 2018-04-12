#include <iostream>
using namespace std;

int * makeInput(string str,int &R){
	int * arr = new int[str.length()];
	for(int i=0;i<str.length();i++){
		char a = str[i];
		if(a == 'R'){
			R++;
			arr[i] = -1;
		}else{
				arr[i] = 1;
		
}	}


	return arr;
}
int kadine(int *arr,int size){
	int best=0;
	int curr_best =0;
	for(int i=0;i<size;i++){
	 	curr_best = curr_best +arr[i];
	 	if(best < curr_best){
	 		best = curr_best;
	 	}
	 	if(curr_best < 0){
	 		curr_best =0;
	 	}
	}

	return best;
}

int main(){
	int t;
  	cin>>t;
  	while(t--){
	
	string str;
	cin>>str;
	int r =0;
	int * input = makeInput(str,r);
	// for(int i=0;i<str.length();i++){
	// 	cout<<input[i]<<" ";
	// }
	int ans = r + kadine(input,str.length());
	cout<<ans<<endl;
	}

	return 0;
}