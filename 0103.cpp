#include <iostream>
#include <vector>
#include <string>
#include <cctype>
using namespace std;

void StrangeBasebal(string& Input)
{
	vector<int> Numbers;

	size_t a = 0;

	while (a < Input.size())
	{
		if (isdigit(Input[a]) || (Input[a] == '-' && isdigit(Input[a + 1])))
		{
			size_t b = a;

			while (b < Input.size() && (isdigit(Input[b]) || (Input[b] == '-' && isdigit(Input[b + 1]))))
			{
				b++;
			}

			int Number = stoi(Input.substr(a, b - a));

			if (Number >= -333 && Number <= 333)
			{
				Numbers.emplace_back(Number);
			}
			else
			{
				cout << "Число " << Number << " не додано до вектору, воно виходить за діапазон від -333 до 333." << endl;
			}
			Input = Input.substr(0, a) + Input.substr(b);
		}
		if (Input[a] == 'c')
		{
			if (Numbers.empty())
			{
				cout << endl << "У векторі недостатньо чисел для видалення" << endl;
				return;
			}
			Numbers.pop_back();
			Input = Input.substr(0, a) + Input.substr(a + 1);
		}
		if (Input[a] == 'd')
		{
			if (Numbers.empty())
			{
				cout << "У векторі немає числа для його подвоєння." << endl;
				return;
			}
			int Num = Numbers.back();
			Numbers.emplace_back(Num * 2);
			Input = Input.substr(0, a) + Input.substr(a + 1);
		}
		if (Input[a] == '+')
		{
			if (Numbers.size() < 2)
			{
				cout << "Дія '+' не може бути застосована тому що чисел менше 2." << endl;
				return;
			}
			int Num1 = Numbers[Numbers.size() - 1];
			int Num2 = Numbers[Numbers.size() - 2];
			Numbers.emplace_back(Num1 + Num2);
			Input = Input.substr(0, a) + Input.substr(a + 1);
		}
		a++;
	}

	int Result = 0;

	cout << "------------------------------------------------------------------------------------------------------------------------";
	cout << "Числа у векторі: ";

	for (int a = 0; a < Numbers.size(); a++)
	{
		cout << Numbers[a] << " ";
		Result += Numbers[a];
	}
	cout << endl << "Сума всіх чисел: " << Result << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------";
}


int main()
{
	system("chcp 1251 > nul");
	string Temp, Input;
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "Ця гра називається Дивний бейсбол:" << endl << "Символ '+' виконує запис сум двох попередніх чисел" << endl << "Символ 'd' виконує запис вдвічі більшого числа за попереднє." << endl << "Символ 'c' скасовує попереднє введене число.";
	cout << endl << "------------------------------------------------------------------------------------------------------------------------" << endl;
	do
	{
		const string Symbols = "01234567890cd+- ";
		cout << endl << "Введіть рядок символів через пробіли, які містять в собі цілі числа у діапазоні від -333 до 333 та символи '+','d','c':" << endl;
		cout << endl;
		getline(cin, Temp);

		for (char symbol : Temp)
		{
			if (Symbols.find(symbol) == string::npos)
			{
				cout << endl << "Помилка. Ваш рядок містить недопустимі символи. Спробуйте знову." << endl;
				cout << endl << "Введіть рядок символів через пробіли, які містять в собі цілі числа у діапазоні від -333 до 333 та символи '+','d','c':" << endl;
				cout << endl;
				getline(cin, Temp);
			}
			else
			{
				Input = Temp;
				cout << "------------------------------------------------------------------------------------------------------------------------";
				cout << endl << "Введений рядок: " << Input << endl;
				cout << "------------------------------------------------------------------------------------------------------------------------";
				break;
			}
		}
	} while (false);

	StrangeBasebal(Input);

	return 0;
}
