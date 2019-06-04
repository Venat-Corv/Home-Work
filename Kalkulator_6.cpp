#include <iostream>
#include <conio.h>

using namespace std;

template <typename T>
T* Establish(int n);

template <typename T>
void Print(T* Arr, const int n);

template <typename T>
void Shift(T* Arr, const int n, const int index);

double string2num(char* str, int& Iter);

void Result_by(char* Operators, double* Operands, int start, const int n, bool check, int finish);

void Start_Finish(char* Arr, const int n, int& start, int& finish);

void Sorter(char* Operators, double* Operands, char* Foo, const int n, int& oper_counter, bool check);

double Factorial(double result);

double Power(double a, int n);


void main()
{
	setlocale(LC_ALL, "");

	const int SIZE = 256;
	char Foo[SIZE]{};
	char Buffer[SIZE]{};
	char* Operators = nullptr;
	double* Operands = nullptr;
	int n = 0;
	char key;
	bool check = true;
	bool choise = true;
	double marker = 0;
	int counter = 0;
	int oper_counter = 0;
	int sub_count = 0;
	char spelling = '\0';
	int check_counter = 0;
	do
	{
		system("CLS");
		cout << Foo;
		key = getch();
		if (key == (char)8 && counter > 0)
		{
			if (Foo[counter - 1] == '(') check_counter--;
			if (Foo[counter - 1] == ')') check_counter++;
			counter--;
			Foo[counter] = '\0';
		}
		else if (key >= '0' && key <= '9' || key == '-' || key == '+' || key == '*' || key == '/' || key == ' ' || key == '(' || key == ')' || key == '.' || key == '!' || key == '^')
		{
			choise = true;
			if (key == '-' || key == '+' || key == '*' || key == '/' || key == '(' || key == ')' || key == '!' || key == '^')
			{
				if (key == '-' && counter == 0 || Foo[counter] < '0' && Foo[counter] > '9') n--;
				else n++;
				if (key == '(') check_counter++;
				if (key == ')') check_counter--;
			}
			if (spelling != '\0' && key != ' ' && key < '0' || key > '9')
			{
				switch (spelling)
				{
				case '+':;
				case '*':;
				case '/':;
					if (key != '(' && key != ')' && Foo[counter - 1] < '0' || Foo[counter - 1] > '9')
					{
						cout << endl << "Некоректный ввод!" << endl;
						system("pause");
						counter--;
						Foo[counter] = '\0';
						spelling = '\0';
					}
					else
					{
						spelling = key;
						Foo[counter] = key;
						counter++;
					}
					choise = false;
					break;
				case '-':
					if (key == '!' || key == '^' || key == '.' && Foo[counter - 1] < '0' || Foo[counter - 1] > '9')
					{
						cout << endl << "Некоректный ввод!" << endl;
						system("pause");
						counter--;
						Foo[counter] = '\0';
						spelling = '\0';
					}
					else
					{
						spelling = key;
						Foo[counter] = key;
						counter++;
					}
					choise = false;
					break;
				case '.':
					if (key == '!')
					{
						cout << endl << "Некоректный ввод!" << endl;
						system("pause");
						counter--;
						Foo[counter] = '\0';
						spelling = '\0';
					}
					else
					{
						spelling = key;
						Foo[counter] = key;
						counter++;
					}
					choise = false;
					break;
				case '^':
					if (key == '.' || key == ')' && Foo[counter - 1] < '0' || Foo[counter - 1] > '9')
					{
						cout << endl << "Некоректный ввод!" << endl;
						system("pause");
						counter--;
						Foo[counter] = '\0';
						spelling = '\0';
					}
					else
					{
						spelling = key;
						Foo[counter] = key;
						counter++;
					}
					choise = false;
					break;
				case '!':
					if (key == ')' || key == '(' || key == '.' && Foo[counter - 1] < '0' || Foo[counter - 1] > '9')
					{
						cout << endl << "Некоректный ввод!" << endl;
						system("pause");
						counter--;
						Foo[counter] = '\0';
						spelling = '\0';
					}
					else
					{
						spelling = key;
						Foo[counter] = key;
						counter++;
					}
					choise = false;
					break;
				case '(':
					if (key == '!' || key == '^' || key == '.' || key == ')' && Foo[counter - 1] < '0' || Foo[counter - 1] > '9')
					{
						cout << endl << "Некоректный ввод!" << endl;
						system("pause");
						counter--;
						Foo[counter] = '\0';
						spelling = '\0';
					}
					else
					{
						spelling = key;
						Foo[counter] = key;
						counter++;
					}
					choise = false;
					break;
				case ')':
					if (key == '.' || key == '(' &&Foo[counter - 1] < '0' || Foo[counter - 1] > '9')
					{
						cout << endl << "Некоректный ввод!" << endl;
						system("pause");
						counter--;
						Foo[counter] = '\0';
						spelling = '\0';
					}
					else
					{
						spelling = key;
						Foo[counter] = key;
						counter++;
					}
					choise = false;
					break;
				default: choise = false; break;
				}
			}
			if (key == ' ' || key >= '0' && key <= '9' && choise == true)
			{
				Foo[counter] = key;
				counter++;
			}
			else if (spelling == '\0')
			{
				if (counter == 0 && key != '-' && key != '(' && key < '0' || key > '9')
				{
					cout << endl << "Некоректный ввод!" << endl;
					system("pause");
				}
				else
				{
					if (key == '-' || key == '+' || key == '*' || key == '/' || key == '(' || key == ')' || key == '.' || key == '!' || key == '^') spelling = key;
					Foo[counter] = key;
					counter++;
				}
			}
		}
		else if (key == '=')
		{
			if (check_counter != 0)
			{
				cout << endl << "Слишком много ";
				if (check_counter > 0) cout << "открывающих скобок!" << endl;
				if (check_counter < 0) cout << "закрывающих скобок!" << endl;
				cout << "Попробуйте еще раз..." << endl;
				system("pause");
				main();
			}
			else
			{
				Foo[counter] = '=';
				Foo[counter + 1] = '\0';
				check = false;
				n++;
			}
		}
	} while (check);
	system("CLS");
	cout << Foo << endl;
	Operators = Establish<char>(n + 1);
	Operands = Establish<double>(n + 1);
	marker = Operands[0];
	for (int i = 0; Foo[i]; i++)
	{
		if (Foo[i] != ' ')
		{
			Buffer[sub_count] = Foo[i];
			sub_count++;
		}
	}
	Buffer[sub_count] = '\0';
	cout << Buffer;
	system("Pause");
	Sorter(Operators, Operands, Buffer, n, oper_counter, check);
	Print(Operators, n);
	Print(Operands, n);
	for (int i = 0; i < n; i++)
	{
		if (Operators[i] == '!' && Operands[i] == marker)
		{
			int buffer = Operands[i];
			Operands[i] = Operands[i - 1];
			Operands[i - 1] = buffer;
		}
	}
	Print(Operators, n);
	Print(Operands, n);

	for (int i = 0; i <= oper_counter + 1; oper_counter--)
	{
		{
			int start = 0;
			int finish = 0;
			if (Operators[start] == '=') break;
			Start_Finish(Operators, n, start, finish);
			if (Operators[start] == '(')
			{
				Shift(Operators, n, start);
				Shift(Operands, n, start);
				finish--;
			}
			for (int j = start; j < finish;)
			{
				Print(Operators, n);
				Print(Operands, n);
				if (Operators[j] == ')' && Operands[j] != marker && Operators[j + 1] != '(' && Operators[j + 1] != ')' && Operands[j + 1] == marker)
				{
					char buffer = Operators[j];
					Operators[j] = Operators[j + 1];
					Operators[j + 1] = buffer;
				}
				if (Operators[j + 1] == ')' && Operands[j + 1] == marker && j + 1 <= finish)
				{
					Shift(Operators, n, j + 1);
					Shift(Operands, n, j + 1);
					finish--;
				}
				else j++;
			}
			Result_by(Operators, Operands, start, n, check, finish);
			Print(Operators, n);
			Print(Operands, n);
		}
	}
	//system("CLS");
	(Operands[0] == -0) ? cout << Foo << '0' << endl : cout << Foo << Operands[0] << endl;
	system("pause");
	delete[] Operators;
	delete[] Operands;
	return;
}

template <typename T>
T* Establish(int n)
{
	return new T[n];
}

template <typename T>
void Print(T* Arr, const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << Arr[i] << "  ";
	}
	cout << endl;
}

double string2num(char* str, int& Iter)
{
	double num = 0;
	double d_num = 0;
	int d_count = 0;
	bool test = true;
	bool test_signet = true;
	for (; str[Iter]; Iter++)
	{
		if (str[Iter] == '.') test = false;
		if (test)
		{
			while (str[Iter] == '(' || str[Iter] == ')') Iter++;
			if (str[Iter] == '-' && test_signet == true)
			{
				if (str[Iter - 1] == '+' || str[Iter - 1] == '-' || str[Iter - 1] == '*' || str[Iter - 1] == '/' || str[Iter - 1] == '(' ||
					str[Iter - 1] == '!' || str[Iter - 1] == '^' || Iter == 0)
				{
					Iter++;
					test_signet = false;
				}
			}
			if (str[Iter] == '-' || str[Iter] == '+' || str[Iter] == '*' || str[Iter] == '/' || str[Iter] == '=' || str[Iter] == '!' || str[Iter] == '^')
			{
				num += d_num;
				if (!test_signet) num = 0 - num;
				return num;
			}
			num *= 10;
			num += str[Iter] - '0';
		}

		if (!test)
		{
			while (str[Iter] == '.' || str[Iter] == '(' || str[Iter] == ')') Iter++;
			if (str[Iter] == '-' || str[Iter] == '+' || str[Iter] == '*' || str[Iter] == '/' || str[Iter] == '=' || str[Iter] == '!' || str[Iter] == '^')
			{
				for (int i = 0; i < d_count; i++)
				{
					d_num /= 10;
				}
				d_num += 0.000000000000001;
				num += d_num;
				if (!test_signet) num = 0 - num;
				return num;
			}
			d_num *= 10;
			d_num += str[Iter] - '0';
			d_count++;
		}
	}
	num += d_num;
	if (!test_signet) num = 0 - num;
	return num;
}

template <typename T>
void Shift(T* Arr, const int n, const int index)
{
	for (int i = index; i < n; i++)
	{
		int Buffer = Arr[i];
		Arr[i] = Arr[i + 1];
		Arr[i + 1] = Buffer;
	}
}

void Result_by(char* Operators, double* Operands, int start, const int n, bool check, int finish)
{
	for (int i = start; i < finish;)
	{
		Operators[i + 1];
		if (Operators[i] == '!')
		{
			{
				Operands[i] = Factorial(Operands[i]);
				Shift(Operators, n, i);
				Shift(Operands, n, i + 1);
				finish--;
			}
		}
		if (Operators[i] == '^')
		{
			{
				Operands[i] = Power(Operands[i], Operands[i + 1]);
				Shift(Operators, n, i);
				Shift(Operands, n, i + 1);
				finish--;
			}
		}
		if (Operators[i] != '!' && Operators[i] != '^' && Operators[i + 1] == ')') break;
		if (Operators[i] != '!' && Operators[i] != '^') i++;
	}

	for (int i = start; i < finish;)
	{
		Operators[i + 1];
		if (Operators[i] == '*')
		{
			{
				Operands[i] *= Operands[i + 1];
				Shift(Operators, n, i);
				Shift(Operands, n, i + 1);
				finish--;
			}
		}
		if (Operators[i] == '/')
		{
			{
				Operands[i] /= Operands[i + 1];
				Shift(Operators, n, i);
				Shift(Operands, n, i + 1);
				finish--;
			}
		}
		if (Operators[i] != '*' && Operators[i] != '/' && Operators[i + 1] == ')') break;
		if (Operators[i] != '*' && Operators[i] != '/') i++;
	}

	for (int i = start; i < finish;)
	{
		if (Operators[i] == '+')
		{
			{
				Operands[i] += Operands[i + 1];
				Shift(Operators, n, i);
				Shift(Operands, n, i + 1);
				finish--;
			}
		}
		if (Operators[i] == '-')
		{
			Operands[i] -= Operands[i + 1];
			Shift(Operators, n, i);
			Shift(Operands, n, i + 1);
			finish--;
		}
		if (Operators[i] != '+' && Operators[i] != '-' && Operators[i + 1] == ')') break;
		if (Operators[i] != '+' && Operators[i] != '-') i++;
	}
}

void Start_Finish(char* Arr, const int n, int& start, int& finish)
{
	bool test = true;
	for (int i = start; i < n; i++)
	{
		if (Arr[i] == '(')
		{
			start = i;
			(start == 0 && Arr[i] != '(') ? test = true : test = false;
		}
		if (Arr[i] == ')' && Arr[i - 1] != ')' && Arr[i - 1] != '(') finish = i;
		if (Arr[i] == '=')
		{
			finish = i;
			return;
		}
		if (finish > start && test == false) return;
		if (finish > start && test == true)
		{
			test = false;
			finish = 0;
		}
	}
}

void Sorter(char* Operators, double* Operands, char* Foo, const int n, int& oper_counter, bool check)
{
	int counter = 0;
	int counter_num = 0;
	int Iter = 0;
	check = true;
	for (int i = 0; Foo[i]; i++)
	{
		if (Foo[i] == '+' || Foo[i] == '*' || Foo[i] == '/' || Foo[i] == '=' || Foo[i] == '(' || Foo[i] == ')' || Foo[i] == '!' || Foo[i] == '^')
		{
			if (Foo[i] == '(' || Foo[i] == ')')
				do
				{
					if (Foo[i] == '(') oper_counter++;
					Operators[counter] = Foo[i];
					counter++;
					counter_num++;
					i++;
				} while (Foo[i] == '(' || Foo[i] == ')');
				if (Foo[i] == '+' || Foo[i] == '*' || Foo[i] == '/' || Foo[i] == '=' || Foo[i] == '!' || Foo[i] == '^')
				{
					Operators[counter] = Foo[i];
					counter++;
					Iter++;
				}
				check = true;
		}
		if (Foo[i] == '-' && i != 0)
		{
			if (Foo[i - 1] >= '0' && Foo[i - 1] <= '9' || Foo[i - 1] == ')')
			{
				Operators[counter] = Foo[i];
				counter++;
				Iter++;
				check = true;
			}
		}
		if (Foo[i] >= '0' && Foo[i] <= '9' && check == true)
		{
			Operands[counter_num] = string2num(Foo, Iter);
			counter_num++;
			check = false;
		}
	}
}

double Factorial(double result)
{
	if (result > 1) return result * Factorial(result - 1);
	else return 1;
}

double Power(double a, int n)
{
	if (n == 0)return 1;
	if (n < 0)
	{
		a = 1 / a;
		n = -n;
	}
	return a * Power(a, n - 1);
}