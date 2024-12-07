#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//Linked List implementation of stack

/*

struct stackInfo{
    char data;
    struct stackInfo* next;
    struct stackInfo* prev;
};

typedef struct stackInfo* TopPtr;
typedef struct stackInfo* stackNode;

TopPtr TopNode=NULL;

stackNode createNode(char ch){
    stackNode newNode=(stackNode)malloc(sizeof(struct stackInfo));
    newNode->data=ch;
    newNode->next=NULL;
    newNode->prev=NULL;
    return newNode;
}

void Push(char ch){
    stackNode newTop=createNode(ch);
    TopNode->next=newTop;
    newTop->prev=TopNode;
    TopNode=newTop;
}

char Pop(){
    stackNode temp=TopNode;
    char tempChar=TopNode->data;
    TopNode=TopNode->prev;
    temp->prev=NULL;
    TopNode->next=NULL;
    free(temp);
    return tempChar;
}

char Top(){
    return TopNode->data;
}

bool IsEmpty(){
    return TopNode==NULL;
}

*/

//array implementation of stack

struct stackInfo{
    int capacity;
    char* stackElems;
    int topIdx;
};

typedef struct stackInfo* Stack;

int strLen(const char* str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

Stack InitStack(int maxElems){
    Stack S=(Stack)malloc(sizeof(struct stackInfo));
    S->stackElems=(char*)malloc(sizeof(char)*maxElems);
    S->capacity=maxElems;
    S->topIdx=-1;
    return S;
}

bool IsEmpty(Stack S){
    return (S->topIdx==-1);
}

void Push(Stack S, char ch){
    S->topIdx++;
    S->stackElems[S->topIdx]=ch;
}

char Top(const Stack S){
    if(IsEmpty(S)){
        return '\0';
    }
    return S->stackElems[S->topIdx];
}

char Pop(Stack S){
    if(IsEmpty(S)){
        return '\0';
    }
    char topChar=Top(S);
    S->topIdx--;
    return topChar;
}

bool any_bracket_present=false;

bool IsMatching(char BracketLeft, char BracketRight){

    if(BracketLeft=='(' && BracketRight==')'){
        return true;
    }
    else if(BracketLeft=='{' && BracketRight=='}'){
        return true;
    }
    else if(BracketLeft=='[' && BracketRight==']'){
        return true;
    }
    return false;
}

bool PalindromeCheck(char* inputStr, int lenStr){
    Stack ReverseStack=InitStack(lenStr);
    for(int i=0; i<lenStr; i++){
        Push(ReverseStack, inputStr[i]);
    }
    bool IsPalindrome=false;
    for(int i=0; i<lenStr; i++){
        char topChar=Pop(ReverseStack);
        if(inputStr[i]==topChar){
            IsPalindrome=true;
        }
        else{
            IsPalindrome=false;
            break;
        }
    }
    if(IsPalindrome){
        return true;
    }
    return false;
}

bool BalancedBracketCheck(char* inputStr, int lenStr){
    Stack Balanced=InitStack(lenStr);
    for(int i=0; i<lenStr; i++){
        if(inputStr[i]=='(' || inputStr[i]=='{' || inputStr[i]=='['){
            any_bracket_present=true;
            Push(Balanced, inputStr[i]);
        }
        else if(IsEmpty(Balanced) && (inputStr[i]==')' || inputStr[i]=='}' || inputStr[i]==']')){
            any_bracket_present=true;
            return false;
        }
        else if(IsMatching(Top(Balanced), inputStr[i])){
            any_bracket_present=true;
            char ch=Pop(Balanced);
        }
    }
    if(IsEmpty(Balanced) && any_bracket_present){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    int t;
    scanf("%d", &t);
    for(int i=0; i<t; i++){
        char sampleStr[100001];
        // for(int i=0; i<100001; i++){
        //     sampleStr[i]='\0';
        // }
        scanf("%s", sampleStr);
        int length=strLen(sampleStr);
        if(!PalindromeCheck(sampleStr, length) && BalancedBracketCheck(sampleStr, length)){
            printf("Balanced\n");
        }        
        else if(PalindromeCheck(sampleStr, length) && !BalancedBracketCheck(sampleStr, length)){
            printf("Palindromic\n");
        }
        else if(PalindromeCheck(sampleStr, length) && BalancedBracketCheck(sampleStr, length)){
            printf("Balanced and Palindromic\n");
        }
        else{
            printf("-1\n");
        }
        any_bracket_present=false;
    }
}