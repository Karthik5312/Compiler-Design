#include <stdio.h>
#include <string.h>
#include <ctype.h>

int n;

struct expression{
    char op[2], op1[10], op2[10], res[10];
} exp[100];

void fold(){
    int res;
    char result[10];
    for(int i=0; i<n; ++i){
        if((isdigit(exp[i].op1[0]) && isdigit(exp[i].op2[0])) || exp[i].op[0]=='='){
            int op1 = atoi(exp[i].op1);
            int op2 = atoi(exp[i].op2);
            switch(exp[i].op[0]){
                case '+': res = op1 + op2;
                          break;
                case '-': res = op1 - op2;
                          break;
                case '*': res = op1 * op2;
                          break;
                case '/': res = op1 / op2;
                          break;
                case '=': res = op1;
                          break;
            }
            sprintf(result, "%d", res);
            propagate(i, result);
        }
    }
}

void propagate(int p, char *result){
    for(int i=p+1; i<n; ++i){
        if(strcmp(exp[p].res, exp[i].op1)==0){
            strcpy(exp[i].op1, result);
        }else if(strcmp(exp[p].res, exp[i].op2)==0){
            strcpy(exp[i].op2, result);
        }
    }
}

int main(){
    printf("Enter the no of expressions: ");
    scanf("%d", &n);
    printf("Enter expressions:\n");
    for(int i=0; i<n; ++i){
        scanf("%s %s %s %s", &exp[i].op, exp[i].op1, exp[i].op2, exp[i].res);
    }

    fold();
    printf("Optimized code\n");

    for(int i=1; i<n; ++i){
        printf("%s %s %s %s\n", exp[i].op, exp[i].op1, exp[i].op2, exp[i].res);
    }

    return 0;
}

/*
Ignore warnings
Sample input format 1:
= 3 - a
+ a b t1
+ a c t2
+ t1 t2 t3
Sample input format 2:
= 4 - a
+ a 3 b
* 2 b w
* 2 b w
- w a c
*/