#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

string start()
{
	cout << "Input: ";
	string input{};
	getline(cin, input);
	return input;
}

class Math
{
public:
	string calculation = start();
	int result{};

	int calculate()
	{
		calculateStep();
		return result;
	}

	int factorial(int input)
	{
		int _result{1};
		for (int i = 1; i <= input; i++)
		{
			_result = _result * i;
		}
		return _result;
	}

	int exponent(int input, int power)
	{
		int _result{input};
		for (int i = 1; i < power; i++)
		{
			_result = _result * input;
		}
		return _result;
	}

private:
	int get(int input1, char operation, int input2)
	{
		if (operation == '+')
			return input1 + input2;
		if (operation == '-')
			return input1 - input2;
		if (operation == '*' || operation == 'x')
			return input1 * input2;
		if (operation == '/')
			return input1 / input2;
		if (operation == '^')
			return exponent(input1, input2);
		if (operation == '!' && !input2)
			factorial(input1);
		return 0;
	}

	int getIntLength(int x)
	{
		return to_string(x).length();
	}

	void calculateStep()
	{
		stringstream digit1, digit2;
		int value1{}, valueLength1{}, value2{}, valueLength2{};
		char sign{};

		// Value 1
		digit1 << calculation;
		digit1 >> value1;
		valueLength1 = getIntLength(value1);

		// Get sign / operator
		sign = calculation.substr(valueLength1, valueLength1 + 1)[0];

		// Value 2
		digit2 << calculation.substr(valueLength1 + 1);
		digit2 >> value2;
		valueLength2 = getIntLength(value2);

		result += get(value1, sign, value2);
		removeCalculated(valueLength1, valueLength2);
	}

	void removeCalculated(int valueLength1, int valueLength2)
	{
		int cutoffIndex{valueLength1 + valueLength2 + 1};
		calculation = to_string(result) + calculation.substr(cutoffIndex);
	}
};

string removeSpaces(string str)
{
	str.erase(remove(str.begin(), str.end(), ' '), str.end());
	return str;
}

main()
{
	Math Calc;
	Calc.calculation = removeSpaces(Calc.calculation);
	cout << Calc.calculate() << '\n';
	return 0;
}