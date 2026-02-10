#include<stdio.h>
#include<string.h>

#define SIZE 100

char stk[SIZE];
int stackTop=-1;

void add(char ch){
    stackTop++;
    stk[stackTop]=ch;
}

char removeTop(){
    if(stackTop==-1)
        return '\0';
    char ch=stk[stackTop];
    stackTop--;
    return ch;
}

int match(char a,char b){
    if(a=='('&&b==')')return 1;
    if(a=='{'&&b=='}')return 1;
    if(a=='['&&b==']')return 1;
    return 0;
}

int isBalanced(char str[]){
    stackTop=-1;
    int len=strlen(str);

    for(int i=0;i<len;i++){
        char ch=str[i];

        if(ch=='('||ch=='{'||ch=='['){
            add(ch);
        }
        else if(ch==')'||ch=='}'||ch==']'){
            if(stackTop==-1){
                return 0;
            }
            char top=removeTop();
            if(!match(top,ch)){
                return 0;
            }
        }
    }

    if(stackTop==-1)
        return 1;
    return 0;
}

int main(){
    printf("Parentheses Balance Checker\n");
    printf("===========================\n\n");

    char test1[]="a+(b-c)*(d";
    char test2[]="m+[a-b*(c+d*{m)]";
    char test3[]="a+(b-c)";

    printf("Test 1:%s\n",test1);
    printf("Status:%s\n\n",isBalanced(test1)?"Balanced":"Not Balanced");

    printf("Test 2:%s\n",test2);
    printf("Status:%s\n\n",isBalanced(test2)?"Balanced":"Not Balanced");

    printf("Test 3:%s\n",test3);
    printf("Status:%s\n\n",isBalanced(test3)?"Balanced":"Not Balanced");

    return 0;
}