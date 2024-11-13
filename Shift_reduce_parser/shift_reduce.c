#include <stdio.h>
#include <string.h>

int k = 0, z = 0, i = 0, j = 0, c = 0;
char input[100], stack[100];

void shift(){
    if (input[j] == 'i' && input[j + 1] == 'd'){
        stack[i] = input[j];
        stack[i + 1] = input[j + 1];
        stack[i + 2] = '\0';
        input[j] = input[j + 1] = ' ';
        printf("\n$%s\t%s$\tSHIFT->id", stack, input);
    }
    else{
        stack[i] = input[j];
        stack[i + 1] = '\0';
        input[j] = ' ';
        printf("\n$%s\t%s$\tSHIFT->symbols", stack, input);
    }
}

void reduce(){

    // Reduce "id" to E
    for (z = 0; z < c; z++){
        if (stack[z] == 'i' && stack[z + 1] == 'd'){
            stack[z] = 'E';
            stack[z + 1] = '\0';
            printf("\n$%s\t%s$\tREDUCE TO E", stack, input);
            j++;
        }
    }

    // Reduce E + E -> E
    for (z = 0; z < c; z++){
        if (stack[z] == 'E' && stack[z + 1] == '+' && stack[z + 2] == 'E'){
            stack[z] = 'E';
            stack[z + 1] = '\0';
            stack[z + 2] = '\0';
            printf("\n$%s\t%s$\tREDUCE TO E", stack, input);
            i = i - 2;
        }
    }

    // Reduce E * E -> E
    for (z = 0; z < c; z++){
        if (stack[z] == 'E' && stack[z + 1] == '*' && stack[z + 2] == 'E'){
            stack[z] = 'E';
            stack[z + 1] = '\0';
            stack[z + 2] = '\0';
            printf("\n$%s\t%s$\tREDUCE TO E", stack, input);
            i = i - 2;
        }
    }

    // Reduce (E) -> E        
    for (z = 0; z < c; z++){
        if (stack[z] == '(' && stack[z + 1] == 'E' && stack[z + 2] == ')'){
            stack[z] = 'E';
            stack[z + 1] = '\0';
            stack[z + 2] = '\0';
            printf("\n$%s\t%s$\tREDUCE TO E", stack, input);
            i = i - 2;
        }
    }
}

int main(){

    printf("GRAMMAR is E->E+E \n E->E*E \n E->(E) \n E->id");
    printf("\nEnter input string: ");
    scanf("%s", input);
    c = strlen(input);
    printf("\nstack \t input \t action"); 

    for (k = 0, i = 0; j < c; k++, i++, j++){
        shift();
        reduce();
    }

    // Check if the entire input was parsed to a single 'E'
    if(strcmp(stack, "E") == 0 && input[j] == '\0'){
        printf("\nInput string successfully parsed!\n");
    }else printf("\nInput string cannot be parsed.\n");

    return 0;
}
