#include <stdio.h>

int main() {
    char operation;
    float num, result = 0;
    int firstInput = 1;

    printf("Select an operation (+, -, *, /): ");
    scanf(" %c", &operation);

    printf("Enter numbers (end with =):\n");

    while (1) {
        char input[20];
        scanf("%s", input);

        if (input[0] == '=' && input[1] == '\0') {
            break;
        }

        sscanf(input, "%f", &num);

        if (firstInput) {
            result = num;
            firstInput = 0;
        } else {
            switch (operation) {
                case '+':
                    result += num;
                    break;
                case '-':
                    result -= num;
                    break;
                case '*':
                    result *= num;
                    break;
                case '/':
                    if (num != 0) {
                        result /= num;
                    } else {
                        printf("Error: Division by zero is not allowed.\n");
                        return 1;
                    }
                    break;
                default:
                    printf("Invalid operation.\n");
                    return 1;
            }
        }
    }

    printf("Result: %.2f\n", result);
    return 0;
}
