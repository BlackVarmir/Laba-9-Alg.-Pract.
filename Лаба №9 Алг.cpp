#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

unsigned long long factorial(int n)  // Завдання 1
{
	if (n <= 1)
		return 1;
	return n * factorial(n - 1);
}

int fib(int n)  // Завдання 2
{
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	return fib(n - 1) + fib(n - 2);
}

void fillDigitsVector(int n, vector<int>& digits)  // Завдання 3
{
	if (n == 0)
		return;
	digits.push_back(n % 10);
	fillDigitsVector(n / 10, digits);
}

int reverseNumberFromVector(const vector<int>& digits, int index = 0) // Завдання 3
{
	if (index >= digits.size())
		return 0;
	return digits[index] * pow(10, digits.size() - index - 1) + reverseNumberFromVector(digits, index + 1);
}

int reverseNumber(int n)  // Завдання 3
{
	vector<int> digits;
	fillDigitsVector(n, digits);
	return reverseNumberFromVector(digits);
}

double power(int a, int b)  // Завдання 4
{
	if (b == 0)
		return 1;
	if (b > 0)
		return a * power(a, b - 1);
	else return 1.0 / power(a, -b);
}

int gcd(int a, int b)  // Завдання 5
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

void generateSubsets(const vector<int>& set, vector<int>& subset, int index)  // Завдання 6
{
	if (index == set.size())
	{
		cout << "{ ";
		for (int elem : subset) {
			cout << elem << " ";
		}
		cout << "}" << endl;
		return;
	}

	generateSubsets(set, subset, index + 1);

	subset.push_back(set[index]);
	generateSubsets(set, subset, index + 1);

	subset.pop_back();
}

int main()
{
	system("chcp 1251");
	system("cls");

	int in;

	int number1;

	int n2;

	int number3;
	int reversedNumber;
	
	int a4, b4;
	double result4;

	int num1_5, num2_5;
	int result5;

	int n6;
	vector<int> set6(n6);
	vector<int> subset6;

	while (true)
	{
		cout << "1. Рекурсивна функція, яка обчислює факторіал заданого натуруального числа" << endl;
		cout << "2. Вивід n-те число Фібоначчі." << endl;
		cout << "3. Функція повинна приймати як аргумент число і повертати нове число, де цифри йдуть у зворотному порядку." << endl;
		cout << "4. Програма що обчислює a піднесене до степеня b" << endl;
		cout << "5. НСД" << endl;
		cout << "6. Програма яка генерує та виводить всі підмножини заданої множини чисел." << endl;
		cout << "0. Вихід" << endl;
		cout << "\nВведіть номер завдання: ";
		cin >> in;

		if (in == 0) {
			break;
		}

		switch (in) {
		case 1:
			cout << "Введіть натуральне число ";	
			cin >> number1;

			if (number1 < 0) {
				cout << "Факторіал не визначений для від'ємних чисел." << endl;
			}
			else {
				cout << "Факторіал " << number1 << " = " << factorial(number1) << endl;
			}
			cout << endl;
			break;
		case 2:
			cout << "Введіть номер числа Фібоначчі: ";
			cin >> n2;

			if (n2 < 0) {
				cout << "Число Фібоначчі не визначене для від'ємних чисел." << endl;
			}
			else {
				cout << n2 << "-те число Фібоначчі: " << fib(n2) << endl;
			}
			cout << endl;
			break;
		case 3:
			cout << "Введіть число для перевертання: ";
			cin >> number3;

			reversedNumber = (number3 < 0) ? -reverseNumber(-number3) : reverseNumber(number3);

			cout << "Перевернуте число: " << reversedNumber << endl;
			cout << endl;
			break;
		case 4:
			cout << "Введіть число a: ";
			cin >> a4;
			cout << "Введіть степінь b: ";
			cin >> b4;

			result4 = power(a4, b4);

			cout << a4 << " в степені " << b4 << " = " << result4 << endl;
			cout << endl;
			break;
		case 5:
			cout << "Введіть перше число: ";
			cin >> num1_5;
			cout << "Введіть друге число: ";
			cin >> num2_5;

			result5 = gcd(num1_5, num2_5);

			cout << "НСД ("<< num1_5 << ", " << num2_5 << ") = " << result5 << endl;
			cout << endl;
			break;
		case 6:
			cout << "Введіть розмір множини: ";
			cin >> n6;

			cout << "Введіть елементи множини: " << endl;
			for (int i = 0; i < n6; ++i) {
				cin >> set6[i];
			}

			cout << "Усі підмножини: " << endl;
			generateSubsets(set6, subset6, 0);
			break;
		default:
			cout << "Невірний ввід" << endl;
			break;
		}
	}
}

