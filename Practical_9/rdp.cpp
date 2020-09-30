/*
    author: mr_bhishm
    created: 30-09-2020 19:49:18
    "Make it work, make it right, make it fast." 
                                                – Kent Beck  
*/

/*  :::RDP for Grammar given below:::
*
*   E->TE'
*   E'->+TE'|^
*   T->FT'
*   T'->*FT'|^
*   F->(E)|id
*
*/

#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" "<<x<<endl 

string input;
char lookahead='$';
int len = 0;

void Match();
void E();
void EDS();
void T();
void TDS();
void F();

string RecursiveDescent(){
    Match();
    E();
    if(lookahead == '$'){
        return "Valid";
    }else{
        return "Invalid";
    }
}

void Match(){
    lookahead = input[len++];
}

void E(){
    T();
    EDS();
}

void EDS(){
    if(lookahead == '+') {
        Match();
        T();
        EDS();
    }else{
        return;
    }
}

void T(){
    F();
    TDS();
}

void TDS(){
    if(lookahead == '*') {
        Match();
        F();
        TDS();
    }else{
        return;
    }
}

void F(){
    if(lookahead == '('){
        Match();
        E();
        if(lookahead == ')'){
            Match();
        }
    }else{
        if(isalpha(lookahead)){
            Match();
        }else{
            lookahead = -1;
        }   
    }
}

int main(){
    cout<<"Give input string : "<<endl;
    cout<<"String will be something like a+b, a+(b+c*d), etc."<<endl;
    cin>>input;
    input = input+"$";
    string ans = RecursiveDescent();
    cout<<ans<<endl;
}