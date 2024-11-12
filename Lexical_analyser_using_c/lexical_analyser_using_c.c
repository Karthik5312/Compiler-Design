#include <stdio.h>
#include <ctype.h>
#include <string.h>

FILE *input, *output;
char str[100], keyword[100][100] = {"int", "main", "void", "return", "continue", "printf"};
int len = sizeof(keyword) / sizeof(keyword[0]);

int operator(char ch){
    if(ch=='+' || ch=='-' || ch=='*' || ch=='/') return 1;
    return 0;
}

int special_symbol(char ch){
    if(ch=='@' || ch=='(' || ch==')' || ch=='{' || ch=='}' || ch=='?' || ch=='!' || ch==';') return 1;
    return 0;
}

int key(char ch){
    int i = 0;
    str[i++] = ch;
    ch = fgetc(input);
    while(isalnum(ch) && ch!=' '){
        str[i++] = ch;
        ch = fgetc(input);
    }
    str[i] = '\0';
    for(int j=0; j<len; ++j){
        if(strcmp(str, keyword[j])==0){
            return 1;
        }
    }
    return 0;
}

int main(){
    
    int line = 1;
    int token = 0;
    char ch;
    input = fopen("input.txt", "r");
    output = fopen("output.txt", "w");
    fprintf(output, "Line no \t\t Token no \t\t Lexeme \t\t Token\n\n");
    
    while(!feof(input)){
        ch = fgetc(input);

        if(operator(ch)){
            fprintf(output, "%d\t\t\t\t %d\t\t\t\t %c\t\t\t Operator\n", line, token, ch);
            ++token;
        }
        else if(special_symbol(ch)){
            fprintf(output, "%d\t\t\t\t %d\t\t\t\t %c\t\t\t Special symbol\n", line, token, ch);
            ++token;
        }
        else if(isdigit(ch)){
            fprintf(output, "%d\t\t\t\t %d\t\t\t\t %c\t\t\t Digit\n", line, token, ch);
            ++token;
        }
        else if(isalpha(ch)){
            if(key(ch)) fprintf(output, "%d\t\t\t\t %d\t\t\t\t %s\t\t Keyword\n", line, token, str);
            else fprintf(output, "%d\t\t\t\t %d\t\t\t\t %s\t\t Identifier\n", line, token, str);
            ++token;
        }
        else if(ch=='\n') ++line;
    }
    
    fclose(input);
    fclose(output);
    return 0;
}