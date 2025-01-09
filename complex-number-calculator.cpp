/* Complex Number Calculator - Mark Katigbak */

#include <iostream>
#include <cmath>
#include <string>

struct ComplexNumber {
    double real, imaginary;
} firstNumber, secondNumber;

ComplexNumber add(ComplexNumber& firstNumber, ComplexNumber& secondNumber) {
    ComplexNumber result;
    result.real = firstNumber.real + secondNumber.real;
    result.imaginary = firstNumber.imaginary + secondNumber.imaginary;

    return result;
}
ComplexNumber subtract(ComplexNumber& firstNumber, ComplexNumber& secondNumber) {
    ComplexNumber result;
    result.real = firstNumber.real - secondNumber.real;
    result.imaginary = firstNumber.imaginary - secondNumber.imaginary;

    return result;
}
ComplexNumber multiply(ComplexNumber& firstNumber, ComplexNumber& secondNumber) {
    ComplexNumber result;
    result.real = firstNumber.real * secondNumber.real - firstNumber.imaginary * secondNumber.imaginary;
    result.imaginary = firstNumber.real * secondNumber.imaginary + firstNumber.imaginary * secondNumber.real;

    return result;
}
ComplexNumber divide(ComplexNumber& firstNumber, ComplexNumber& secondNumber) {
    ComplexNumber result;
    double denominator = pow(secondNumber.real, 2) + pow(secondNumber.imaginary, 2);
    result.real = (firstNumber.real * secondNumber.real + firstNumber.imaginary * secondNumber.imaginary) / denominator;
    result.imaginary = (firstNumber.imaginary * secondNumber.real - firstNumber.real * secondNumber.imaginary) / denominator;
    
    return result; 
}
std::string signs(ComplexNumber number) {
    std::string temp;
    if(number.imaginary >= 0) {
        temp = " + ";
    }
    else {
        temp = " - ";
    }
    return temp;
}
void displayResult(ComplexNumber& firstNumber, ComplexNumber& secondNumber, char& operation) {
    std::cout << "\nResult: (" << firstNumber.real << signs(firstNumber) << abs(firstNumber.imaginary) << "i) " << operation << " (" << secondNumber.real << signs(secondNumber) << abs(secondNumber.imaginary) << "i) = (";
}

int main() {
    using namespace std;

    cout << "Enter the real and imaginary parts for the first complex number.\n";
    cout << "Real part: ";
    cin >> firstNumber.real;
    cout << "Imaginary part: ";
    cin >> firstNumber.imaginary;
    
    cout << "\nEnter the real and imaginary parts for the second complex number.\n";
    cout << "Real part: ";
    cin >> secondNumber.real;
    cout << "Imaginary part: ";
    cin >> secondNumber.imaginary;

    cout << "\nChoose an operation (+, -, *, /): ";
    char operation;
    cin >> operation;

    switch(operation) {
        case '+':
            displayResult(firstNumber, secondNumber, operation);
            cout << add(firstNumber, secondNumber).real << signs(add(firstNumber, secondNumber)) << abs(add(firstNumber, secondNumber).imaginary) << "i)\n";
            break;
        case '-':
            displayResult(firstNumber, secondNumber, operation);
            cout << subtract(firstNumber, secondNumber).real << signs(subtract(firstNumber, secondNumber)) << abs(subtract(firstNumber, secondNumber).imaginary) << "i)\n";
            break;
        case '*':
            displayResult(firstNumber, secondNumber, operation);
            cout << multiply(firstNumber, secondNumber).real << signs(multiply(firstNumber, secondNumber)) << abs(multiply(firstNumber, secondNumber).imaginary) << "i)\n";
            break;
        case '/':
            displayResult(firstNumber, secondNumber, operation);
            cout << divide(firstNumber, secondNumber).real << signs(divide(firstNumber, secondNumber)) << abs(divide(firstNumber, secondNumber).imaginary) << "i)\n";
            break;
        default:
            cout << "\nInvalid operator.\n";
            break;
    }

    cout << '\n';

    return 0;
}