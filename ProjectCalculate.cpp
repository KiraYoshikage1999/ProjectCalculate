//Project Calculator with functional like in engineer calculator of Windows.
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <ctime>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <string>
#include <cmath>
//#include <HeaderFuncFile.h>

using namespace std;

bool IsDigit(const string& other) {
	for (char ch : other) {
		if (ch < '0' || ch > '9') {
			return false;
		}


	}
	return true;
}


class MathFunctions {
	//Creating Varuebles 
	int amountOfValues;
	int amountOfNumbers;
	int amountOfOpsPriority;
	int amountOfOperators;
	string* memoryArrey = new string[amountOfValues]; //General Array for User's String
	int* numberArrey = new int[amountOfNumbers]; // Array for user operands from strings in memoryArray
	string* charOperatorArrey = new string[amountOfOperators]; // Array for all operators from memoryArray
	int* strOpsPriorityArr = new int[amountOfOpsPriority]; // Array for prioritiers for operators



public:

	MathFunctions() { // Constructor with parameters
		amountOfValues = 0;
		amountOfOpsPriority = 0;
		amountOfNumbers = 0;
		amountOfOperators = 0;
	}

	//---------------------

	void MathOperations() { // Math operations
		double result = 0.0;

		while (amountOfOpsPriority > 0) {
			
			
			int maxPriorityIndex = 0;
			//checking and identifying the most important priority
			for (int i = 0; i < amountOfOpsPriority; i++) {
				if (strOpsPriorityArr[i] < strOpsPriorityArr[maxPriorityIndex]) {
					maxPriorityIndex = i;
				}
			}


			// Using the index, we determine the operator with the highest priority and the required operands on the left and right (first and second)
			if (charOperatorArrey[maxPriorityIndex][0] == '|') {
				string OperationSymbol = charOperatorArrey[maxPriorityIndex];
				float FirstOperand = numberArrey[maxPriorityIndex];
				result = MakingOperation(FirstOperand, 0 , OperationSymbol[0]);
				cout << result << endl;
			}
			else {
				string OperationSymbol = charOperatorArrey[maxPriorityIndex];
				float FirstOperand = numberArrey[maxPriorityIndex];
				float SecondOperand = numberArrey[maxPriorityIndex + 1];
				result = MakingOperation(FirstOperand, SecondOperand, OperationSymbol[0]);
				cout << result << endl;
			}
			
			

			numberArrey[maxPriorityIndex] = result; // Writing result in array
			for (int i = maxPriorityIndex + 1; i < amountOfNumbers - 1; i++) {
				numberArrey[i] = numberArrey[i + 1];
			}
			amountOfNumbers--;

			for (int i = maxPriorityIndex; i < amountOfOpsPriority - 1; i++) {
				strOpsPriorityArr[i] = strOpsPriorityArr[i + 1];
			}
			amountOfOpsPriority--;

			/*for (int i = maxPriorityIndex + 1; i < amountOfValues - 1; i++) {
				memoryArrey[i] = memoryArrey[i + 1];
			}
			amountOfValues--;*/

			/*for (int i = maxPriorityIndex + 1; i < amountOfOperators - 1; i++) {
				charOperatorArrey[i] = charOperatorArrey[i + 1];
			}
			amountOfOperators--;*/

			DeleteFromOperatorArray(maxPriorityIndex);
		}

		cout << "Final Result = " << result << endl;

	}

	//Function that takes First and Second Operand and operation , than solves the expression and return it.
	float MakingOperation(float firstOperand, float secondOperand, char operation) {
		switch (operation) {
		case '+':
			return firstOperand + secondOperand;
		case '-':
			return firstOperand - secondOperand;
		case '*':
			return firstOperand * secondOperand;
		case '/':
			if (firstOperand == 0 || secondOperand == 0) {
				cout << "<--------{Message}------------->\n Some of operands become zero, you can't divide on zero! \n <------------------->" << endl;
				return 0;
			}
			else {

				return firstOperand / secondOperand;
			}
			
		case '^':
			return pow(firstOperand, secondOperand);
		case '|':
			if (firstOperand == 0 ) {
				cout << "<--------{Message}------------->\n The operand that you want sqrt is zero, you can't do that! \n <------------------->" << endl;
				return 0;
			}
			else {
				return sqrt(firstOperand);
			}
			
		default: 
			cout << "<--------{Message}------------->\n Unsupported operation \n <------------------->" << endl;
			return 0;

		}
	}

	//Adding all user's cin values , no matter what is that operand , operator or function.
	void AddOperandOrOperatorInMemory(string userCinValue) {


		string* tempArr = new string[this->amountOfValues];
		for (int i = 0; i < this->amountOfValues; i++) {
			tempArr[i] = this->memoryArrey[i];

		}

		delete[] this->memoryArrey;
		this->amountOfValues++;

		this->memoryArrey = new string[this->amountOfValues];

		for (int i = 0; i < this->amountOfValues - 1; i++) {
			this->memoryArrey[i] = tempArr[i];

		}

		delete[] tempArr;

		this->memoryArrey[this->amountOfValues - 1] = userCinValue;
	}

	//Adding operands from memoryArray to this array
	void AddInArrayNumber(int userNumber) {
		int* tempArr = new int[this->amountOfNumbers];
		for (int i = 0; i < this->amountOfNumbers; i++) {
			tempArr[i] = this->numberArrey[i];
		}

		delete[] this->numberArrey;
		this->amountOfNumbers++;

		this->numberArrey = new int[this->amountOfNumbers];

		for (int i = 0; i < this->amountOfNumbers - 1; i++) {
			this->numberArrey[i] = tempArr[i];
		}

		delete[] tempArr;

		this->numberArrey[this->amountOfNumbers - 1] = userNumber;
	}

	//Adding priority of each operator here
	void AddInStrOpsPriorityArray(int priorityValue) {
		int* tempArr = new int[this->amountOfOpsPriority];
		for (int i = 0; i < this->amountOfOpsPriority; i++) {
			tempArr[i] = this->strOpsPriorityArr[i];
		}

		delete[] this->strOpsPriorityArr;
		this->amountOfOpsPriority++;

		this->strOpsPriorityArr = new int[this->amountOfOpsPriority];

		for (int i = 0; i < this->amountOfOpsPriority - 1; i++) {
			this->strOpsPriorityArr[i] = tempArr[i];
		}

		delete[] tempArr;

		this->strOpsPriorityArr[this->amountOfOpsPriority - 1] = priorityValue;
	}
	
	//Function to delete operator from array
	void DeleteFromOperatorArray(int maxPriorityIndex) {
		string* tempArr = new string[this->amountOfOperators - 1];
		int tempIndex = 0;

		for (int i = 0; i < this->amountOfOperators; i++) {
			if (i != maxPriorityIndex) {
				tempArr[tempIndex++] = this->charOperatorArrey[i];
			}
		}

		delete[] this->charOperatorArrey;
		this->amountOfOperators--;

		this->charOperatorArrey = new string[this->amountOfOperators];

		for (int i = 0; i < this->amountOfOperators; i++) {
			this->charOperatorArrey[i] = tempArr[i];
		}

		delete[] tempArr;

	}

	//Adding operator from memoryArrey here.
	void AddInCharOperatorsArray(string userOperator) {

		string* tempArr = new string[this->amountOfOperators];
		for (int i = 0; i < this->amountOfOperators; i++) {
			tempArr[i] = this->charOperatorArrey[i];

		}

		delete[] this->charOperatorArrey;
		this->amountOfOperators++;

		this->charOperatorArrey = new string[this->amountOfOperators];

		for (int i = 0; i < this->amountOfOperators - 1; i++) {
			this->charOperatorArrey[i] = tempArr[i];

		}

		delete[] tempArr;

		this->charOperatorArrey[this->amountOfOperators - 1] = userOperator;
	}

	// this function is made for extract from memoryArrey operands , operators(+, - ,* , /, ^, |) and strings(sin,log functions).
	void RecreatingOperandsOperators() {
		int userNumber;
		string userOperator;



		for (int i = 0; i < this->amountOfValues; i++) {
			if ((memoryArrey[i] == "+") || (memoryArrey[i] == "-") || (memoryArrey[i] == "*") || (memoryArrey[i] == "/") || (memoryArrey[i] == "^") || (memoryArrey[i] == "|")) {

				userOperator = memoryArrey[i];

				// sort operators by priority , information take from https://ru.wikipedia.org/wiki/%D0%9F%D1%80%D0%B8%D0%BE%D1%80%D0%B8%D1%82%D0%B5%D1%82_%D0%BE%D0%BF%D0%B5%D1%80%D0%B0%D1%86%D0%B8%D0%B8

				if ((memoryArrey[i] == "+") || (memoryArrey[i] == "-")) {
					AddInStrOpsPriorityArray(5);
					AddInCharOperatorsArray(userOperator);


				}
				else if ((memoryArrey[i] == "*") || (memoryArrey[i] == "/")) {
					AddInStrOpsPriorityArray(4);
					AddInCharOperatorsArray(userOperator);
				}
				else if ((memoryArrey[i] == "^") || (memoryArrey[i] == "|")) {
					AddInStrOpsPriorityArray(3);
					AddInCharOperatorsArray(userOperator);
				}
				/*else if ((memoryArrey[i] == "(") || (memoryArrey[i] == ")")) {
					AddInStrOpsPriorityArray(2);
					AddInCharOperatorsArray(userOperator);
				}*/

			}
			else if (IsDigit(memoryArrey[i])) {
				userNumber = atoi(memoryArrey[i].c_str());


				AddInArrayNumber(userNumber);
			}
			else {


			}

		}

	}

	//Function to print Info about memory Array
	void PrintInfoMemoryArr() {
		RecreatingOperandsOperators();
		for (int i = 0; i < amountOfValues; i++) {
			cout << "[" << i << "] -- " << memoryArrey[i] << endl;
		}
	}

	//Function to print Info about number Array
	void PrintInfoNumberArr() {

		for (int i = 0; i < this->amountOfNumbers; i++) {
			cout << "[" << i << "] -- " << this->numberArrey[i] << endl;
		}
	}

	//Function to print Info about Priority Array
	void PrintInfoPriorityArr() {

		for (int i = 0; i < this->amountOfOpsPriority; i++) {
			cout << "[" << i << "] -- " << this->strOpsPriorityArr[i] << endl;
		}
	}

	//Function to print Info about operators Array
	void PrintInfoOperatorArr() {

		for (int i = 0; i < this->amountOfOperators; i++) {
			cout << "[" << i << "] -- " << this->charOperatorArrey[i] << endl;
		}
	}

	//Function to clear Dinamyc arrays.
	void Clear() {
		delete[] this->memoryArrey;
		this->memoryArrey = nullptr;

		delete[] this->numberArrey;
		this->numberArrey = nullptr;

		delete[] this->charOperatorArrey;
		this->charOperatorArrey = nullptr;

		delete[] this->strOpsPriorityArr;
		this->strOpsPriorityArr = nullptr;

		this->amountOfValues = 0;
		this->amountOfNumbers = 0;
		this->amountOfOpsPriority = 0;
		this->amountOfOperators = 0;

		this->charOperatorArrey = new string[this->amountOfOperators];
		this->strOpsPriorityArr = new int[this->amountOfOpsPriority];
		this->memoryArrey = new string[this->amountOfValues];
		this->numberArrey = new int[this->amountOfNumbers];
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
	char userOperation;
	string userCinValue;
	string tempVaruable;
	char userChooseOption = '0';
	//----------------
	//initialization of operator and first operand






	while (true) {
		cout << "<------------{Menu}------------->" << endl
			<< "Choose option: " << endl
			<< "1 - Enter your exspression;" << endl
			<< "2 - show your mathematical expression;" << endl
			<< "3 - Show all Array Information;" << endl
			<< "4 - Clear exspresion;" << endl
			<< "5 - Calculate;" << endl
			<< "<-------------------------------->" << endl;



		cin >> userChooseOption;
		if (userChooseOption == '1') { // User enters his exspression with space after each operand or operator.

			string tempVaruable = "";
			cout << "<------------{Menu}------------->" << endl << "Enter your exspression with operands (0-9) , operators(+,-,*,/,^,| <-sqrt() , ( , ) )" << endl;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			getline(cin, userCinValue);
			for (int i = 0; i < userCinValue.length(); i++) {
				if (userCinValue[i] == ' ') {
					objMathFunc.AddOperandOrOperatorInMemory(tempVaruable);
					tempVaruable = "";
				}
				else {

					//For the this moment there's no checking for incompatible operators.
					/*if (((tempVaruable[i] == '+') || (tempVaruable[i] == '-') || (tempVaruable[i] == '*') || (tempVaruable[i] == '/') ) || ( (userCinValue[i] == '+') || (userCinValue[i] == '*') || (userCinValue[i] == '/'))) {
						cout << "<--------{ERROR}------>" << endl << "You entering two incompatible operators" << endl;
						userCinValue = "";
						tempVaruable = "";
						cout << "Enter again your exspression from the error!" << endl << "<---------------------->" << endl;
					}*/


					tempVaruable += userCinValue[i];
				}

			}
			if (!tempVaruable.empty()) {
				objMathFunc.AddOperandOrOperatorInMemory(tempVaruable);
				tempVaruable.clear();
			}

		}
		else if (userChooseOption == '2') {
			cout << userCinValue << endl;
		}
		else if (userChooseOption == '3') {
			cout << "------First Array-----" << endl;
			objMathFunc.PrintInfoMemoryArr();
			cout << "------Next Array-----" << endl;
			objMathFunc.PrintInfoNumberArr();
			cout << "------Next Array-----" << endl;
			objMathFunc.PrintInfoOperatorArr();
			cout << "------Next Array-----" << endl;
			objMathFunc.PrintInfoPriorityArr();
		}
		else if (userChooseOption == '4') {
			userCinValue.clear();
			tempVaruable.clear();

			objMathFunc.Clear();
		}
		else if (userChooseOption == '5') {
			objMathFunc.RecreatingOperandsOperators();
			objMathFunc.MathOperations();
		}

	}






	/*objMathFunc.PrintInfoMemoryArr();*/













}

