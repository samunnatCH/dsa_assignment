#include<stdio.h>
#include<ctype.h>
#include<string.h>

#define SIZE 100

char opStack[SIZE];
int opTop=-1;

void pushOp(char c){
    opStack[++opTop]=c;
}

char popOp(){
    if(opTop==-1)return '\0';
    return opStack[opTop--];
}

char topOp(){
    if(opTop==-1)return '\0';
    return opStack[opTop];
}

int isOpStackEmpty(){
    return opTop==-1;
}

int isOp(char c){
    return(c=='+'||c=='-'||c=='*'||c=='/');
}

int priority(char c){
    if(c=='*'||c=='/')return 2;
    if(c=='+'||c=='-')return 1;
    return 0;
}

void convertToPostfix(char* input,char* output){
    int j=0;

    for(int i=0;input[i]!='\0';i++){
        char c=input[i];

        if(isalnum(c)){
            output[j++]=c;
        }
        else if(c=='('){
            pushOp(c);
        }
        else if(c==')'){
            while(!isOpStackEmpty()&&topOp()!='('){
                output[j++]=popOp();
            }
            popOp();
        }
        else if(isOp(c)){
            while(!isOpStackEmpty()&&priority(topOp())>=priority(c)){
                output[j++]=popOp();
            }
            pushOp(c);
        }
    }

    while(!isOpStackEmpty()){
        output[j++]=popOp();
    }

    output[j]='\0';
}

int calculate(char* postfix){
    int numStack[SIZE];
    int numTop=-1;

    for(int i=0;postfix[i]!='\0';i++){
        if(isdigit(postfix[i])){
            numStack[++numTop]=postfix[i]-'0';
        }
        else{
            int val2=numStack[numTop--];
            int val1=numStack[numTop--];
            int res;

            if(postfix[i]=='+')res=val1+val2;
            else if(postfix[i]=='-')res=val1-val2;
            else if(postfix[i]=='*')res=val1*val2;
            else if(postfix[i]=='/')res=val1/val2;

            numStack[++numTop]=res;
        }
    }
    return numStack[numTop];
}

int main(){
    printf("Infix to Postfix Conversion\n");
    printf("===========================\n\n");

    char input[SIZE],output[SIZE];

    strcpy(input,"A+B*C");
    opTop=-1;
    convertToPostfix(input,output);
    printf("Infix:%s\nPostfix:%s\n\n",input,output);

    strcpy(input,"(A+B)*C");
    opTop=-1;
    convertToPostfix(input,output);
    printf("Infix:%s\nPostfix:%s\n\n",input,output);

    strcpy(input,"5+3*2");
    opTop=-1;
    convertToPostfix(input,output);
    int result=calculate(output);
    printf("Infix:%s\nPostfix:%s\nResult:%d\n\n",input,output,result);

    strcpy(input,"(5+3)*2");
    opTop=-1;
    convertToPostfix(input,output);
    result=calculate(output);
    printf("Infix:%s\nPostfix:%s\nResult:%d\n\n",input,output,result);

    return 0;
}
