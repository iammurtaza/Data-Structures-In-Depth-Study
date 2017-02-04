#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    string s;
    stack<char> S;
    getline(cin,s);
    for(int i=0;i<s.length();i++){
        if(s[i]=='(' || s[i]=='{' || s[i]=='[')
            S.push(s[i]);
        else if((s[i]==')' || s[i]=='}' || s[i]==']') && S.empty()){
            //goto a;
            S.push('a');
            break;
        }
        else if(s[i]==')' && S.top()=='(' || s[i]=='}' && S.top()=='{' || s[i]==']' && S.top()=='[')
            S.pop();
    }
    if(S.empty())
        cout<<"Balanced";
    else
        //a:
        cout<<"Unbalanced";
}
