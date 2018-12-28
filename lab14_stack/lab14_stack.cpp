// 
//

#include "pch.h"
#include <iostream>
#include <string>
#include <stack> // подключаем библиотеку для использования стека 
#include <queue> // подключили библиотеку для использования очереди 
#include <deque> // подключили библиотеку для использования дека 
#include <list> // подключили библиотеку для использования списка
#include <set> // подключили библиотеку для использования множества
#include <map> // подключили библиотеку для использования ассоциативного массива
using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	/*
	Стек — это структура данных, которая работает
	по принципу FILO(first in — last out; первый пришел — последний ушел).
	В стеке нет индексов,т.е. нельзя обратиться к определенному элементу.
	Каждый элемент имеет указатель на следующий элемент.
	Головной элемент указывает на NULL.
	Достоинство: операции удаления и добавления элемента делаются за const время.
	*/
	/*
		stack<int> stackInt;//stack <тип данных> <имя>; -создание стека
		int i = 0, a = 0;
		cout << "Введите 5 целых чисел: "<< endl;
		while (i != 5) {
			cin>> a;
			stackInt.push(a); // добавляем введенное число
			i++;
		}
		if (stackInt.empty()) // проверяем пуст ли стек (нет)
			cout <<"Стек не пуст";
		cout <<"Верхний элемент стека: "<< stackInt.top() << endl;
		stackInt.pop(); // удаляем верхний элемент
		cout << "Новый верхний элемент: " << stackInt.top()<< endl;
		*/
		// ЗАДАНИЕ 1 
		/*
		Проверить правильность расстановки скобок (,),[,],{,}
		в введенном пользователем выражении за линейное время
		(один просмотр выражения).
		2+4-5(87192479_7348){72648]76823[] -> no
		({}) -> yes
		({)} -> no
		*/

		//решение 
		/*
		Считываем элемент.
		Если это (,[ или {, то помещаем ее в стек.
		Если это ),] или }, то сравниваем с верхним элементом стека.
		Если образовалась пара, то верхний элемент стека удаляем.
		Иначе - выражение неправильное.
		Когда все элементы считали, то проверяем стек на пустоту.
		Если стек пуст, то выражение правильное.
		Иначе - выражение неправильное.
		*/
		
stack <char> stack1;
char a;
	while (1)
		{
	cin >> a;
			if (a == 'e')
			{
			cout << "Yes";
				break;
			}
			if (a == '(' || a == '{' || a == '[') stack1.push(a);
			if (a == ')')
			{
				if ('(' == stack1.top())
				{
					stack1.pop();
				}
				else
				{
			cout << "No";
					break;
				}
			}
			if (a == '}')
			{
				if ('{' == stack1.top())
				{
					stack1.pop();
				}
				else
				{
			cout << "No";
					break;
				}
			}
			if (a == ']')
			{
				if ('[' == stack1.top())
				{
					stack1.pop();
				}
				else
				{
			cout << "No";
					break;
				}
			}
		}
		if (stack1.empty() == true) 
			cout << "OK";
		else 
			cout << "\nall bad!";
		
		/*
		Очередь — это структура данных, которая построена по принципу
		LILO (last in — last out: последним пришел — последним вышел).
		*/
		/*
			queue <int> MyQueue; // создали очередь
			cout << "Введите 7 чисел: " << endl;
			for (int i = 0; i < 7; i++) {
				cin >> a;
				MyQueue.push(a); // добавляем в очередь элементы
			}
			cout << endl;
			cout << "Первый элемент в очереди: " << MyQueue.front() << endl;
			MyQueue.pop(); // удаляем элемент из очереди
			cout << "Первый элемент (после удаления): " << MyQueue.front() << endl;
			if (!MyQueue.empty()) // проверяем пуста ли очередь (нет)
				cout << "Очередь не пуста!";
			*/
			/*
			Очередь с приоритетом (priority_queue) — это обычная очередь,
			но в ней новый элемент добавляется в такое место,
			чтобы очередь была отсортирована по убыванию.
			*/
			/*
			priority_queue <int> priority_q; // объявляем приоритетную очередь
			cout << "Введите 7 чисел: " << endl;
			for (int i = 0; i < 7; i++) {
				cin >> a;
				priority_q.push(a); // добавляем элементы в очередь
			}
			// выводим первый
			cout << "Первый элемент очереди: " << priority_q.top();
			*/
			// ЗАДАНИЕ 2 
			/*
			Программа на вход получает список школьников.
			В каждой строке сначала записан номер класса (число, равное 9, 10 или 11),
			затем (через пробел) – фамилия.
			Необходимо вывести список по классам:
			сначала всех учащихся 9 класса, затем – 10, затем – 11.
			Внутри одного класса порядок вывода должен быть таким же, как на входе.
			*/
			/*
			Создаем 3 очереди (свою для каждого класса).
			Считываем очередную строку. В зависимости от класса
			добавляем фамилию в соответствующую очередь
			Когда все считали, выводим очереди последовательно:
			сначала для 9 класса, затем очередь 10 класса,
			а в самом конце очередь 11 класса.
			*/
			/*
			queue <string> q9, q10, q11;
				string cl, name;
				while (1)
				{
					getline(cin, cl);
					if (cl == "0") break; // стопает нулём
					if (cl[0] == '9')
					{
						name.assign(cl.begin() + 2, cl.end());
						q9.push(name);
					};
					if (cl[0] == '1')
					{
						if (cl[1] =='0')
						{
							name.assign(cl.begin() + 3, cl.end());
							q10.push(name);
						}
						if (cl[1] == '1')
						{
							name.assign(cl.begin() + 3, cl.end());
							q11.push(name);
						}
					};
				}
				cout << "9 class" << endl;
				while (!q9.empty())
				{
					cout << q9.front()<< endl;
					q9.pop();
				}
				cout << "10 class" << endl;
				while (!q10.empty())
				{
					cout << q10.front() << endl;
					q10.pop();
				}
				cout << "11 class" << endl;
				while (!q11.empty())
				{
					cout << q11.front() << endl;
					q11.pop();
				}
					*/

					/*
					Деком (англ. deque – аббревиатура от double-ended queue, двухсторонняя очередь)
					называется структура данных, в которую можно
					удалять и добавлять элементы
					как в начало, так и в конец.
					Дек хранится в памяти так же, как и очередь.
				*/

				//ЗАДАЧА 3 
				/*
				Проверить, является ли введенная строка палиндромом
				(читается одинаково слева направо и справа налево). Использовать дек.
				*/
				/*
			deque<int> deq1;
				int w, k=0,  b=0, r=0;
				cout << "size=";
				cin >> w; //size
				while (k != w) {
					cin >> b;
					deq1.push_front(b);
					k++;
				}
				while (1) {
					if (deq1.back() == deq1.front())
					{
						deq1.pop_back();
						deq1.pop_front();
					}
					else { cout << "not polendrom"; break; }
					if (deq1.size() == 1 || deq1.size() == 0) { cout << "polendrom"; break; }
				}
				*/
				/*
				Считываем строку посимвольно. каждый символ добавляем в хвост дека.
				Далее сравниваем первый и последний символ дека.
				*/

				//ЗАДАЧА 4 
				/*
				Описать структуру данных List.
				Продемонстрировать работу с этой структурой:
				ввод, вывод,
				добавление элемента и удаление,
				сортировка.
				*/
				/*Список (list) представляет собой контейнер, который поддерживает
				быструю вставку и удаление элементов из любой позиции в контейнере.
				Быстрый произвольный доступ не поддерживается. Он реализован в виде двусвязного списка.
				В отличие от std::forward_list этот контейнер обеспечивает
				возможность двунаправленного итерирования,
				являясь при этом менее эффективным в отношении используемой памяти.*/
				/*
				list<int> mylist;
				cout << "Введите 5 чисел: " << endl;
				int a;
				for (int i = 0; i < 5; i++)
				{
					cin >> a;
					mylist.push_back(a); // добавляем в список элементы
				}
				cout << std::endl;
				cout << "Первый элемент в списке: " << mylist.front() << endl;
				mylist.pop_front(); // удаляем элемент из списка
				cout << "Первый элемент (после удаления): " << mylist.front() << endl;
				list<int>::iterator it1; //указатель
				it1 = mylist.begin();//приравниваем его первому элементу
				it1++; // сдвигаем на один назад
				mylist.insert(it1, 10); // вставляем 10 со сдигом вправо
				std::cout << "список после добавления 10:";
				for (it1 = mylist.begin(); it1 != mylist.end(); ++it1)
				cout << ' ' << *it1;
				cout << '\n';
				if (!mylist.empty()) // проверяем пуст ли список (нет)
				cout << "Список не пуст!";*/
				//ЗАДАЧА 5 
				/*
				Описать структуру данных Set.
				Продемонстрировать работу с этой структурой:
				ввод, вывод,
				добавление элемента и удаление.
				*/
				/*Порядок ввода и реальный порядок элементов в множестве — разный,
				это связано с тем, что элементы множества автоматически сортируются.
				Еще одной очень важной деталью является то, что в множество не сохранились дубликаты,
				хотя дубликаты были при добавлении элементов в множество. Как видно в выводе программы,
				каждый элемент множества уникален.*/
				/*
				set<char> mySet; // объявили пустое множество
				// добавляем элементы в множество
				mySet.insert('I');
				mySet.insert('n');
				mySet.insert('f');
				mySet.insert('i');
				mySet.insert('n');
				mySet.insert('i');
				mySet.insert('t');
				mySet.insert('y');
				for (auto it = mySet.begin(); it != mySet.end(); ++it)
				{
					cout << *it <<" ";
				}
				cout << endl;
				*/
				//ЗАДАЧА 6 
				/*
				Описать структуру данных map.
				Продемонстрировать работу с этой структурой:
				ввод, вывод,
				добавление элемента и удаление.
				*/
				/*std::map — отсортированный ассоциативный контейнер,
				который содержит пары ключ-значение с неповторяющимися ключами.*/

				/*
				char c;
				std::map <char, int> myMap;
				std::map<char, int>::iterator mm;
				for (int i = 0, c = 'a'; i < 5; ++i, ++c)
				{
					myMap.insert(std::pair<char, int>(c, i));
				}
				///вывод не явно инициализированной map на экран
				for (auto it = myMap.begin(); it != myMap.end(); ++it)
				{
					cout << (*it).first << " : " << (*it).second << endl;
				}
				cout << endl;
				mm = myMap.find('b');
				cout <<"заменим с-й элемент  " << endl;
				myMap.erase('c'); //удаление
				myMap.insert(mm, pair<char, int>('c', 200)); //добавление
				for (auto it = myMap.begin(); it != myMap.end(); ++it)
				{
					cout << (*it).first << " : " << (*it).second << endl;
				}*/

				// ЗАДАЧА 7 
				/*
				Составить таблицу сравнения по времени выполнения операций
				для дека, стека, очереди, списка, множества, массива из n элементов.
				Список операций:
				добавление в начало
				добавление в конец
				добавление в середину
				удаление из начала
				удаление с конца
				удаление из середины
				значение элемента из начала
				значение элемента с конца
				значение элемента из середины
				*/
	system("pause");
	return 0;
}


