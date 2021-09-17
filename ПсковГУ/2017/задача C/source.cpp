/*
					C. Римские числа
			Ограничение по времени: 1000 миллисекунд
			Ограничение по памяти: 65000 кибибайт

	  Василий упражняется в умножении чисел в римской системе счисления. Для проверки
  своих навыков он просит Вас написать программу, которая будет проверять таблицу
  умножения в римской системе счисления.

  Входные данные:
  	Два целых положительных числа (1 ≤ A ≤ B ≤ 9), записанные в римской системе
  счисления через пробел.
  
  Выходные данные:
  	Результат умножения двух данных чисел, записанный в римской системе счисления.

Пример
  Ввод: III V
  
  Вывод: XV 

*/

#include <iostream>
#include <chrono>
#include <map>
#include <string>

using namespace std;

int intsize(int x)
{
	int i = 1;
	while (x / 10)
	{
		x /= 10;
		i++;
	}
	return i;
}

string str_in_extent(const string str, const int x)
{
	string result;
	for (int i = 0; i < x; i++)
		result += str;
	return result;
}

string char_string(const char str)
{
	string str1;
	str1 = str;
	return str1;
}

int roman_to_arabic(const string str)
{
	map <string, int> integers = { {"I", 1},
								  {"V", 5},
		                          {"X", 10}
								};
	int result = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if (i + 1 < str.size() && integers[char_string(str[i])] < integers[char_string(str[i + 1])])
			result -= integers[char_string((str[i]))];
		else 
			result += integers[char_string(str[i])];
	}
	return result;
}

string arabic_to_roman(int x)
{
	string integers[7] = { "I", "V", "X", "L", "C", "D", "M"};
	string str = "";
	int romans_pointer = 0;
	int n;
	for (int i = 0; i <= intsize(x); i++) {
		n = x % 10;
		if (0 <= n && n <= 3)
			str = str_in_extent(integers[romans_pointer], n) +str;
		else if (n == 4)
			str = integers[romans_pointer] + integers[romans_pointer + 1] + str;
		else if (5 <= n && n <= 8)
			str = integers[romans_pointer + 1] + str_in_extent(integers[romans_pointer], n - 5) + str;
		else if (n == 9)
			str = integers[romans_pointer] + integers[romans_pointer + 2] + str;
		romans_pointer += 2;
		x /= 10;
	}

	return str;
}


int main() {
	string roman1, roman2;
	cin >> roman1 >> roman2;
	
	//Преобразование римских в арабские числа
	int x1 = roman_to_arabic(roman1);
	int x2 = roman_to_arabic(roman2);
	//cout << roman1 << " = " << x1 << endl;
	
	//выполняем расчеты
	int y = x1 * x2;

	//Преобразование арабских в римские числа
	
	string roman = arabic_to_roman(y);
	cout << roman <<"\n";

	return 0;
}
