#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int key;
string type;
bool compare(string i,string j){
    if(type.compare("lexicographic") == 0){

    }else{
        
    }
}

int main() {
    
    int n;
    cin>>n;
    string *input = new string[n];
    for(int i=0;i<n;i++){
        cin>>input[i];
    }
    cin>>key;
    bool reversed;
    cin>>reversed;
    cin>>type;
    sort(input,input+n,compare);

    return 0;
}
