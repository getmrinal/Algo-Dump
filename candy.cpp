#include<iostream>
#include <algorithm>
using namespace std;

/**	shky have N(1<N<50000){comes under int} candy boxes each
	contain n candies(1<n<10^9){long long} he wants to distribte 
	it wth his k friends (1<k<10^9){long long}

	>all will get equal no of candies
	>all the candies for single student comes from single box

input 
	>N(no of candy boxes) , k(his friends)
	>list of candies in N boxes.(n)
output
	>max number of candies given

**/
bool checkBox(long long *c,long long mid,int n,long long f){
	int i =0;
	while(i<n&& f>0){
			int a;
			if(mid!=0){
			 a = c[i]/mid;
			}else{
				a = f;
			}
		// cout<<"num"<<num<<endl;
		// cout<<"c[i]"<<c[i]<<endl;
		// cout<<"a"<<a<<endl;
		// cout<<"f"<<f<<endl;
		 f = f-a;
		i++;
	}
	if(f<=0){
	
		return true;
	}
	
	return false;
}

void helper(long long f,long long* c,long long si,long long ei,int boxes,int &max){
	if(si>ei){
		return;
	}

	long long mid = si + (ei-si)/2;

	if(checkBox(c,mid,boxes,f)){
		
		si = mid+1;
		max = mid;
		helper(f,c,si,ei,boxes,max);
	}else{
		
		ei = mid-1;
		helper(f,c,si,ei,boxes,max);
	}

	return;
}



int main(){

		int boxes;
		long long friends;
		cin>>boxes>>friends;
		long long *candies = new long long[boxes];
		for (int i = 0; i < boxes; i++){
			cin>>candies[i];
		}

		sort(candies,candies+boxes);
			for (int i = 0; i < boxes; i++){
			cout<<candies[i]<<' ';
		}
		long long max = candies[boxes-1];
		// long long *range = new long long [max+1];
		// for(int i=0;i<=max;i++){
		// 	range[i] = i;
		// }
		cout<<endl;
		int m =0;
		helper(friends,candies,0,max,boxes,m);
		cout<<m<<endl;

}