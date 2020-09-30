/*
    author: mr_bhishm
    created: 30-09-2020 13:12:46
    "Make it work, make it right, make it fast." 
                                                – Kent Beck  
*/

// This is a temporary code for testing (fial code : left_factoring.cpp)
// this code takes input as multiple line it not takes input in BNF form
// for give input through BNF show left_factoring.cpp

//this code also takes input from multiple non-terminal that is not perfectly working!!!

//::::::::Alert::::::: Not prefectly working code!!!


// input in not BNF form
// eg.  A->ab
//      A->abc // working

// eg. A->ab|abc // not working(BNF form)

#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" "<<x<<endl 

int main(){
    int n;
    cout<<"Enter number of productions:";
    cin>>n;
    cout<<"Enter production rules: "<<endl;
    cout<<"[use CAPITAL for non-terminal and small case for terminal and ~ for NULL]"<<endl;
    cout<<"Exmaple: S->aB without space"<<endl;
    string del = "->";
    vector< string > left_side, right_side; 
    string  input;
    while(n--){
        cin>>input;
        unsigned int index = input.find(del);
        left_side.push_back(input.substr(0,index));
        right_side.push_back(input.substr(index+2,input.length()));
    }
    vector< string > result,temp;
    char c = right_side[0][0];
    for(int i  = 0 ; i < right_side.size() ; i++){
        if(c!= right_side[i][0]){
            result.push_back(left_side[i]+"->"+right_side[i]);
        }else{
            temp.push_back(right_side[i]);
        }   
    }
    int len = temp[0].length();
    int smallest = 0;

    for(int i = 1 ; i < temp.size() ; i++){
        if(temp[i].length() < len){
            len = temp[i].length();
            smallest = i;
        }
    }
    // debug(temp[smallest].length());
    string str="";
    int ptr = 0;
    for(int i = 0; i < temp[smallest].length(); i++){
        char c = temp[smallest][i];
        // debug(c);
        int flag = 0;
        for(int j=0;j < temp.size();j++){
            if(temp[j][i] == c){
                // whole smallest stirng matches...
                if(j == temp.size()-1 && temp[smallest].length()-1 == i){
                    str = temp[smallest].substr(0,i+1);
                    flag = 1;
                    ptr = i+1;
                    break;
                }
                continue;
            }else{
                // debug(i);
                str = temp[smallest].substr(0,i);
                flag = 1;
                ptr = i;
                break;
            }
        }
        if(flag == 1)
            break;
    }

    // debug(str);
    result.push_back(left_side[0]+"->"+str+left_side[0]+"'");
    for(int i=0;i<temp.size();i++){
        if(ptr==temp[i].length()){
            result.push_back(left_side[i]+"'->"+(char)238);
        }else{
            result.push_back(left_side[i]+"'->"+temp[i].substr(ptr,temp[i].length()));
        }
    }
    cout<<"---------------------------------------"<<endl;
    cout<<"Grammar After Left factoring"<<endl;
    for(auto i = result.begin() ; i!= result.end() ; i++){
        string s = *i;
        cout<<s<<endl;
    }
}