#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
vector<int> findLongestConseqSubseq(int arr[], int n)
{
    unordered_set<int> S;
    int ans = 0;
    vector<int>v;
    vector<int>f;
 
    // Hash all the array elements
    for (int i = 0; i < n; i++)
        S.insert(arr[i]);
 
    // check each possible sequence from the start
    // then update optimal length
    for (int i=0; i<n; i++)
    {
        // if current element is the starting
        // element of a sequence
        if (S.find(arr[i]-1) == S.end())
        {
            // Then check for next elements in the
            // sequence
            int j = arr[i];
           
            while (S.find(j) != S.end()){
           		 v.push_back(j);     
                j++;
            }
 
            // update  optimal length if this length
            // is more
            // ans = max(ans, j - arr[i]);
            if(ans<(j-arr[i])){
            	ans = j-arr[i];
            	f = v;
            }
        }
    }
    return f;
}
 
// Driver program
int main()
{
    int arr[] =  {693, 697, 299, 662, 290 ,288, 925, 234, 257, 192, 687 ,144, 142, 710 ,66 ,955, 321, 629 ,989, 621 };
    int n = sizeof arr/ sizeof arr[0];
    vector<int> e = findLongestConseqSubseq(arr, n);
    vector<int>::iterator i;
    for(i=e.begin();i!=e.end();i++){
    	cout<<*i<<' ';
    }
    return 0;
}
