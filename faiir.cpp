#include<iostream>
#include<vector>
using namespace std;
 
const char encoder[5][5] = {{'Y','A','B','C','D'},
                      {'E','F','G','I','K'},
                      {'L','M','N','Q','S'},
                      {'U','V','W','X','Z'},
                      {'T','R','O','P','H'}};
 
void input_string(vector<char>& a)
{
    char c;
    while (1)
    {
        c=getchar();
        if (c >= 97 && c <= 122)
        c -= 32;
        if (c == '\n')
            break;
        else if (c==' ')
            continue;
        else if (c == 'J')
        a.push_back('I');
        a.push_back(c);
    }
    return;
}
 
 
 
void get_pos(char p, int& r, int& c)
{
    if (p < 'J')
    {
        r = (p - 65) / 5;
        c = (p - 65) % 5;
    }
    else if (p > 'J')
    {
        r = (p - 66) / 5;
        c = (p - 66) % 5;
    }
    return;
}
 
void same_row(int r, vector<char>& code, int c1, int c2)
{   
    cout<<r<<" "<<c1<<" "<<c2<<"\n";
    c1=c1+1;
    c2=c2+1;
    code.push_back(encoder[r][(c1 + 4) % 5]);
    code.push_back(encoder[r][(c2 + 4) % 5]);
    return;
}
 
void same_column(int c, vector<char>& code, int r1, int r2)
{   
    cout<<c<<" "<<r1<<" "<<r2<<"\n";
    code.push_back(encoder[(r1 + 4) % 5][c]);
    code.push_back(encoder[(r2 + 4) % 5][c]);
    return;
}
 
void diff_col_row(int r1, int c1, vector<char>& code, int r2, int c2)
{
    cout<<r1<<" "<<c1<<" "<<r2<<" "<<c2<<"\n";
    code.push_back(encoder[r1][c2]);
    code.push_back(encoder[r2][c1]);
    return;
}
 
 
void encode(vector<char> msgx, int len)
{
    vector<char> code;
    int i = 0, j = 0;
    int r1=-1, c1=-1, r2=-1, c2=-1;
    while (i < len)
    {
        get_pos(msgx[i], r1, c1);
        i++;
        get_pos(msgx[i], r2, c2);
        if (r1 == r2)
        {
            same_row(r1, code, c1, c2);
        }
        else if (c1 == c2)
        {
            same_column(c1, code, r1, r2);
        }
        else
        {
            diff_col_row(r1, c1, code, r2, c2);
        }
        i++;
    }
    cout<<"\nCODE: ";
    for (j = 0;j < code.size();j++)
    {
        if (code[j] == 'X')
        continue;
        cout<<code[j];
    }
    return;
}
 
 
int main()
{
    vector<char> msg;
    std::cout<<"Enter the Encrypted Message:";
    input_string(msg);
    int len=msg.size();
    encode(msg,len);
    return 0;
}