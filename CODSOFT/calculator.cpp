#include <iostream>

int main() {
    double num1, num2;
    char operation;

    std::cout << "Enter the first number: ";
    std::cin >> num1;

    std::cout << "Enter the second number: ";
    std::cin >> num2;

    std::cout << "Enter the operation (+, -, *, /): ";
    std::cin >> operation;

    double result;

    switch (operation) {
        case '+':
            result = num1 + num2;
            std::cout << "The sum is: " << result << std::endl;
            break;
        case '-':
            result = num1 - num2;
            std::cout << "The difference is: " << result << std::endl;
            break;
        case '*':
            result = num1 * num2;
            std::cout << "The product is: " << result << std::endl;
            break;
        case '/':
            if (num2 != 0) {
                result = num1 / num2;
                std::cout << "The quotient is: " << result << std::endl;
            } else {
                std::cout << "Error: Division by zero is not allowed." << std::endl;
            }
            break;
        default:
            std::cout << "Invalid operation." << std::endl;
            break;
    }

    return 0;
}
