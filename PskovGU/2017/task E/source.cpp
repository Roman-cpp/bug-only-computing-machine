////////////////////////////////////////////////////////////////////////////////////////////
//					E.Число зверя(усложнённый вариант)
// Ограничение по времени : 1000 миллисекунд
// Ограничение по памяти : 65000 кибибайт
//	Василий так же увлекается нумерологией, и однажды прочитав, что сумма квадратов
// первых семи простых чисел(2, 3, 5, 7, 11, 13, 17) равно 666 (число зверя) решил найти
// другие интересные последовательности, суммы квадратов которых равны «красивым»
// числам.Вам требуется помочь Василию, напишите программу, которая будет находить
// суммы квадратов простых чисел из указанного интервала.
//		Входные данные
//	На первой строке число(1 ≤ N ≤ 104).Далее N запросов, каждый запрос на отдельной
// строке.Каждый запрос – два целых положительных числа(1 ≤ A ≤ B ≤ 1000), записанные
// через пробел – порядковые номера простых чисел в возрастающей последовательности.
// 
//		Выходные данные
// N строк, каждая из которых содержит ответ для соответствующего запроса.
//		Примеры
// Ввод		Вывод
// 3		666
// 1 7		25
// 3 3		 170
// 4 5
/////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <ios>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n = 0;
	cin >> n;
	vector<pair<int, int>> in;
	for (int i = 0; i < n; i++) {
		int a = 0; 
		int b = 0;
		cin >> a >> b;
		in.push_back(make_pair(a, b));
	}

	int max_num = 1000000;
	// sieve of eratosthenes
	bool* array = new bool[max_num]; 
	array[0] = false;
	array[1] = false;
	for (int i = 2; i < max_num; i++) {
		array[i] = true;
	}
	for (int i = 2; i * i < max_num; i++) {
		if (array[i]) {
			for (int j = i-1; j*i + i < max_num; j++) {
				array[j*i + i] = false;
			}
		}
	}

	vector<int> primes;
	for (int i = 0; i < max_num; i++) {
		if (array[i]) 
			primes.push_back(i);
	}

	// sum of squares of primes
	for (auto it : in) {
		int sum = 0;
		for (int i = it.first-1; i < it.second; i++)
			sum += primes[i] * primes[i];
		cout << sum << endl;
	}
	return 0;
}
