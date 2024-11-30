//Project Calculator with functional like in engineer calculator of Windows.
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <ctime>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

using namespace std;

//#include <CalculationsFunc.h>
//#include <HeaderTEST.h>

class MathFunctions {
    int firstNum;
    int secondNum;
    char operationSymbol;
public:
    
    // Metods Accesors Get
    int GetFirstNum() {
        return this->firstNum;
    }

    int GetSecondNum() {
        return this->secondNum;
    }
    
    char GetOperationSymbol( ) {
        return this->operationSymbol;
    }

    // Metods Accesors Set
    void SetFirstNum(int firstNum) {
        this->firstNum = firstNum;
    }
    
    void SetSecondNum(int secondNum) {
        this->secondNum = secondNum;
    }

    void SetOperationChar(char operationSymbol) {
        this->operationSymbol = operationSymbol;
    }
    //---------------------
    void MathOperations(char operationSymbol , int firstNum, int secondNum) { // Math operations
        int result;

        //Можно использовать if но за условием проекта в котором желательно использовать все пройденные материалы, я сделаю с помощью оператора множественного выбора.

        switch (operationSymbol)
        {
        case '+':
            result = firstNum + secondNum;
            cout << "Result of Sum: " << result << endl;
            break;

        case '-':
            result = firstNum - secondNum;
            cout << "Result of Sum: " << result << endl;
            break;
        case '*':
            result = firstNum * secondNum;
            cout << "Result of Sum: " << result << endl;
            break;
        case '/':
            if (secondNum != 0 || firstNum != 0) {
                result = firstNum / secondNum;
                cout << "Result of Sum: " << result << endl;
                break;
            }
            else {
                cout << "Number can't be Zero , it's ruining math rules! Try again!" << endl;
            }

        case '^':
            result = firstNum ^ secondNum;
            cout << "Result of Sum: " << result << endl;
            break;


        
        case '|':
            float(result) = sqrt(firstNum);
            cout << "Result of Sum: " << result << endl;
            break;
        }
    }

};


struct FuncOperation {
public:
    /*void IfElseChooseFunc(string UserValue1) {
        if (UserValue1 == "sin") {

        }
        else( UserValue1 == "cos") {

        }
        else { UserValue1 == "tan" } {

        }
    }*/

};



int main()
{

    MathFunctions objMathFunc; // Creating object

    //declaration of variables
    int DebugNum1 = 0;
    int DebugNum2 = 0;
    string userValue1;
    string userValue2;
    char userOperation;
    //----------------
    //initialization of operator and first operand

    
    cout << "Enter your operation(+ , - , / , * , ^ , |):  ";
    cin >> userOperation;
    
    cout << "<----------------------------->" << endl;
    
    cout << "Enter your first number:  ";
    cin >> userValue1;
    cout << "Enter your Second number:  ";
    cin >> userValue2;

    //----------------
    //Cheсking is digit first operand
    
    if (!isdigit(userValue1[0]) && (userValue1[0]) != '-' || !isdigit(userValue1[0])) {
        cout << "Debug: First Number is not valid integer." << endl;
        DebugNum1 = 1;
    }
    if (!isdigit(userValue2[0]) && (userValue2[0]) != '-' || !isdigit(userValue2[0])) {
        cout << "Debug: Second Number is not valid integer." << endl;
        DebugNum2 = 1;
    }

    //---------------
    //Cheсking is first and second operand is complete cheсk
    if (DebugNum1 == 1 && DebugNum2 == 1) {
        cout << "Debug: Number is not integer." << endl;

    }
    else {
        //'|' it's sqrt operator, because there's no suitable symbol , i choosed that.
        //additionally conditional operator , because '|'
        if (userOperation == '|') {
            objMathFunc.MathOperations(userOperation, atoi(userValue1.c_str()), 0);
        }
        else {
            objMathFunc.MathOperations(userOperation, atoi(userValue1.c_str()), atoi(userValue2.c_str()));
        }

        
    }

    while (true) {
        short UserChooser;
        cout << "<------------------------------------------>" << endl
            << "Enter a number of Option to choose:" << endl
            << "1 - Calculate " << endl
            << "2 - Choose another operation" << endl
            << "3 - Recreate First Number and Second Number " << endl
            << "<------------------------------------------>" << endl;
        cin >> UserChooser;
        if (UserChooser == 1) {
            objMathFunc.MathOperations(userOperation, atoi(userValue1.c_str()), atoi(userValue2.c_str()));
        }
        else if (UserChooser == 2) {
            cout << "Enter your operation(+ , - , / , * , ^ , |):  ";
            cin >> userOperation;
        }
        else if (UserChooser == 3) {
            
            cout << "Enter your first number:  ";
            cin >> userValue1;
            cout << "Enter your Second number:  ";
            cin >> userValue2;
        }

    }
    
   

    
    

   
}

