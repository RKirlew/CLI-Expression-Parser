#include <stdio.h>
#include <stdlib.h>

#include <stdbool.h>

struct Expression{
	int numOp;
	int numLit;
	int numbers[100];
    char operators[100];
};
bool in(char toFind, const char* source){
	for (int i = 0; source[i] != '\0'; i++) {
        if (source[i] == toFind) {
            return true; 
        }
    }
    return false; 
	
}
int evaluateExpression(struct Expression* expr) {
    int result = expr->numbers[0];
    for (int i = 0; i < expr->numOp; i++) {
        switch (expr->operators[i]) {
            case '+':
                result += expr->numbers[i + 1];
                break;
            case '-':
                result -= expr->numbers[i + 1];
                break;
            case '*':
                result *= expr->numbers[i + 1];
                break;
            case '/':
                result /= expr->numbers[i + 1];
                break;
            
            default:
                printf("Unsupported operator: %c\n", expr->operators[i]);
                exit(1);
        }
    }
    return result;
}

int main(int argc,char *argv[]){
	struct Expression expression;
	expression.numOp=0;
	expression.numLit=0;
	char operators[] = "+-/*";

	for(int j=1;j<argc;j++){
		char *arg=argv[j];
		for(int t=0;arg[t]!='\0';t++){
			printf("Characters to eval:%c\n",arg[t]);
			if(in(arg[t],operators)){
				expression.operators[expression.numOp++]=arg[t];
			}else{
				expression.	numbers[expression.numLit++]=arg[t]-'0';
			}
		}
	}
	int result = evaluateExpression(&expression);
    printf("Result of the expression: %d\n", result);
}
