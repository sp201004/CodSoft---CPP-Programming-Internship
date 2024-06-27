// CodSoft Internship
// Domain Name - C++ Programming
// Task - 2 (Simple Calculator)
// Intern Name - Surya Pratap Singh


#include <iostream>
using namespace std;

int main() {
    double num1, num2;
    char oper;

    cout << "\t Welcome to Simple Calculator\n" << endl;

    cout << "Enter first no.: ";
    cin >> num1;

    cout << "Enter second no: ";
    cin >> num2;


    cout << "Enter operator (+, -, *, /): ";
    cin >> oper;

    switch(oper) {
        case '+':
            cout << "Result : " << num1 << " + " << num2 << " = " << num1 + num2 << endl;
            break;
        case '-':
            cout << "Result : " << num1 << " - " << num2 << " = " << num1 - num2 << endl;
            break;
        case '*':
            cout << "Result : " << num1 << " * " << num2 << " = " << num1 * num2 << endl;
            break;
        case '/':
            if(num2 != 0) {
                cout << "Result : " << num1 << " / " << num2 << " = " << num1 / num2 << endl;
            } else {
                cout << "Error! Division by zero is not allowed." << endl;
            }
            break;
        default:
            cout << "Error! Invalid Operation." << endl;
            break;
    }

    return 0;
}