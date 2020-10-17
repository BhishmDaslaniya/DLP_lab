/*
    author: mr_bhishm
    created: 17-10-2020 21:36:01
    "Make it work, make it right, make it fast." 
                                                – Kent Beck  
*/
#include<stdio.h>
int main(){
    char quar[20][4];
    char str[10];                   
    int i=0,q_i=0,j,temp=65;
    printf("Enter the string:");
    scanf("%s",&str[i]);
    while(str[i]!='\0'){
        if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/'){
            quar[q_i][0]=str[i];
            quar[q_i][1]=str[i-2];
            quar[q_i][2]=str[i-1];
            quar[q_i][3]=temp;
            str[i-2]=temp;
            temp++;
            q_i++;
            j=i;
            i=0;
            j++;
            while(str[j]!='\0'){  
                str[j-2]=str[j];
                j++;
            }
            str[j-2]='\0';
        }
        else
            i++;
    }
    printf("\noprtr\top1\top2\tresult\n");
    for(i=0;i<q_i;i++)
        printf("\n%c\t%c\t%c\t%c\n",quar[i][0],quar[i][1],quar[i][2],quar[i][3]);

    return 0;
}
