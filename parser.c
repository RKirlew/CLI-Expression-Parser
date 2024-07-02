#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Expression {
    int numbers[100];
    char operators[100];
    int numCount;
    int opCount;
};

// Function to check if a character is in a string
bool in(char target, const char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == target) {
            return true; 
        }
    }
    return false; 
}

// Function to evaluate the expression
int evaluateExpression(struct Expression* expr) {
    int result = expr->numbers[0];
    for (int i = 0; i < expr->opCount; i++) {
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
            // Add other operators as needed
            default:
                printf("Unsupported operator: %c\n", expr->operators[i]);
                exit(1);
        }
    }
    return result;
}

int main(int argc, char *argv[]) {
    char operators[] = "+-/*";
    struct Expression expression;
    expression.numCount = 0;
    expression.opCount = 0;

    for (int i = 1; i < argc; i++) {  // Start from 1 to skip the program name
        char *arg = argv[i];
        for (int j = 0; arg[j] != '\0'; j++) {
            printf("Character: %c\n", arg[j]);
            if (in(arg[j], operators)) {
                expression.operators[expression.opCount++] = arg[j];
            } else {
                expression.numbers[expression.numCount++] = arg[j] - '0';
            }
        }
    }

    printf("Numbers: ");
    for (int i = 0; i < expression.numCount; i++) {
        printf("%d ", expression.numbers[i]);
    }
    printf("\nOperators: ");
    for (int i = 0; i < expression.opCount; i++) {
        printf("%c ", expression.operators[i]);
    }
    printf("\n");

    int result = evaluateExpression(&expression);
    printf("Result of the expression: %d\n", result);

    return 0;
}

