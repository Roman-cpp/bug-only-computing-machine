/*
                        Счастливые билеты - 2020

                        
    Ограничение времени: 2 с
    Ограничение реального времени: 10 с
    Ограничение памяти:	256M


      Участники Кружка Информатики и Робототехники любят собирать счастливые билеты и их набралась
  уже настоящая коллекция. Счастливый билет - это такой билет, у которого сумма цифр в правой
  половине номера равна сумме цифр левой половины.

    В 2020 году многие участники Кружка оказались дома на карантине, никуда не ездили, поэтому
  коллекция счастливых билетов не пополнялась. Руководитель Кружка решил, что сейчас лучшее время
  для того, чтобы навести порядок в коллекции, и поручил эту задачу вам - новым участникам.



  Формат входных данных:
    В первой строке дано целое число N (1 ≤ N ≤ 1000) - количество билетов в коллекции. Далее в N строках
  даны шестизначные числа (по одному в строке, возможно с ведущими нулями) - номера билетов.

  Формат результата:
    Вам требуется сначала исключить из коллекции не счастливые билеты - кто-то по ошибке мог добавить
  их в коллекцию. А оставшиеся билеты отсортировать по возрастанию суммы чисел в левой (или
  правой) половине, а при равенстве сумм - по возрастанию номеров билетов.

  Выведите номера билетов по одному в строке.

  Примеры:
  Входные данные:
  5
  123321
  321222
  110101
  005202
  111003
            
  Результат работы:
  110101
  111003
  123321
  321222
*/

#include<iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main()
{
    vector<pair<int, int> > result;
    int sum1 = 0, sum2 = 0;
    int copy;
    int n;
    cin >> n;

    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        copy = x;
        
        for (int j = 0; j < 3; j++)
        {
            sum1 += x % 10;
            sum2 += x / 1000 % 10;
            x /= 10;
        }
        if (sum1 == sum2)
        {
            result.push_back(make_pair(sum1, copy));
            for(int i = result.size() - 1; i > 0; i--)
                {
                    if(result[i].first < result[i-1].first) swap(result[i], result[i-1]);
                    else if(result[i].first == result[i-1].first && result[i].second < result[i - 1].second) swap(result[i], result[i-1]);
                    else break;
                }
               
        }
        sum1 = 0;
        sum2 = 0;
    }
    for(auto in:result)
            cout << setfill('0') << setw(6) << in.second <<"\n";
}
