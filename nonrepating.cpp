#include <iostream>
#include<map>
#include <vector>
#include<cstring>
using namespace std; 
char *uniqueChar(char *str){
    vector<char> v;
    std::vector<char> out;
    map<char,int>m;
    vector<char>::iterator vt;
    map<char,int>::iterator mt;
    int size = strlen(str); 
    for (int i = 0; i <size ; ++i)
    {
      mt = m.find(str[i]);
        if (mt!=m.end())
        {
          m[str[i]] =m[str[i]]+ 1; 
        }else{
          m.insert(std::pair<char,int>(str[i],1));
        }
        v.push_back(str[i]);
    }
   

     for (vt = v.begin();vt!=v.end(); vt++)
      {
         mt = m.find(*vt);
         
         if (mt->second != -1)
         {
          // cout<<mt->first<<' ';
           out.push_back(mt->first);
           mt->second = -1;
         }
     }
     char *output = new char();
     int i;
     for (i = 0; i < out.size(); i++)
     {
       /* code */
       output[i] = out[i];
     }
     output[i] = '\0';
    return output;

}
int main(){
    char str[] = "jbfjbgrieughuighabbacd";
    char *out= uniqueChar(str);
    int i=0;
    while(out[i]!='\0'){
        cout<<out[i]<<' ';
        i++;
    }
}