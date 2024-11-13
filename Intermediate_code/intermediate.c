#include <stdio.h>
#include <ctype.h>
#include <string.h>

char stack[100], infix[100], postfix[100];
int top = -1;

int precedence(char op){
    switch(op){
        case '^': return 4;
        case '*': 
        case '/': return 3;
        case '+': 
        case '-': return 2;
        default : return 0;
    }
}

void push(char ch){
    stack[++top] = ch;
}

char pop(){
    if(top==-1) return '\0';
    else return stack[top--];
}

int isOperator(char ch){
    return ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^';
}

void post(char infix[], char postfix[]){
    char symbol, next;
    int j = -1;
    for(int i=0; i<strlen(infix); ++i){
        symbol = infix[i];
        switch(symbol){
            case '(':
                    push(symbol);
                    break;
            case ')':
                    next = pop();
                    while(next!='('){
                        postfix[++j] = next;
                        next = pop();
                    }
                    break;
            default:
                    if(isOperator(symbol)){
                        while(top!=-1 && precedence(symbol)<=precedence(stack[top])){
                            postfix[++j] = pop();
                        }
                        push(symbol);
                    }else postfix[++j] = symbol;
                    break;
        }
    }
    while(top!=-1) postfix[++j] = pop();
}

int main(){

    char inter[100];
    int j=0, k=-1;
    printf("Enter infix expression: ");
    scanf("%s", infix);
    post(infix, postfix);
    printf("Postfix expression: %s", postfix);

    for(int i=0; i<strlen(postfix); ++i){
        char ch = postfix[i];
        if(!isalpha(ch)){
            if(isdigit(inter[j-2])) printf("\n%c\tt%c\t%c\tt%d", ch, inter[j-2], inter[j-1], ++k);
            else printf("\n%c\t%c\t%c\tt%d", ch, inter[j-2], inter[j-1], ++k);
            j -= 2;
            inter[j++] = k + '0';
        }else inter[j++] = ch;
    }

    return 0;
}