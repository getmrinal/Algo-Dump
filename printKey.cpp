#include <iostream>
#include <string>

using namespace std;
void pKey(int num,string output){
	if(num==0){
		cout<<output<<endl;
		return;
	}
	int use = num%10;
	int send = num/10;
	if (use == 2)
	{
		/* code */
		pKey(send, 'a' + output);
		pKey(send, 'b' + output);
		pKey(send, 'c' + output);
	}else if (use == 3)
	{
		/* code */
		pKey(send, 'd' + output);
		pKey(send, 'e' + output);
		pKey(send, 'f' + output);

	}else if (use == 4)
	{
		/* code */
		pKey(send, 'g' + output);
		pKey(send, 'h' + output);
		pKey(send, 'i' + output);
		
	}else if (use == 5)
	{
		/* code */
		pKey(send, 'j' + output);
		pKey(send, 'k' + output);
		pKey(send, 'l' + output);
		
	}else if (use == 6)
	{
		/* code */
		pKey(send, 'm' + output);
		pKey(send, 'n' + output);
		pKey(send,'o' + output);
		
	}else if (use == 7)
	{
		/* code */
		pKey(send, 'p' + output);
		pKey(send, 'q' + output);
		pKey(send, 'r' + output);
		pKey(send, 'S' + output);
		
	}else if (use == 8)
	{
		/* code */
		pKey(send, 't' + output);
		pKey(send, 'u' + output);
		pKey(send, 'v' + output);
		
	}else if (use == 9)
	{
		/* code */
		pKey(send, 'w' + output);
		pKey(send, 'x' + output);
		pKey(send, 'y' + output);
		pKey(send, 'z' + output);
		
	}

}
int main(){

	int a= 23;
	
	string output = "";
	
	 pKey(a,output);
	



	return 0;
}