#include <iostream>
#include <stdio.h>
#include <time.h>
#include <locale.h>
#include <string.h>
using namespace std;
void simple(int *num)
{
	cout << "Введите число: " << endl;
	cin >> *num;
	cout << "Первый результат правильный: " << endl;
	for (int i = 2; i < sqrt(*num); i++)
	{
		if (*num % i == 0)
		{
			cout << "Число составное. " << endl;
		}
		else
		{
			cout << "Число простое. " << endl;
		}
	}
}
void LineSearch()
{
	int k[20];
	int key, i;
	for (i = 0; i < 20; i++)
	{
		k[i] = 1 + rand() % 40;
	}
	for (i = 0; i < 20; i++)
	{
		cout << "k[" << i << "] = " << k[i] << endl;
	}
	cout << "Введите ключ: ";
	cin >> key;
	for (i = 0; i < 19; i++)
	{
		if (k[i] == key)
		{
			cout << i << endl;
			break;
		}
	}
	cout << "элемент не найден за " << i << " шагов" << endl;
}
void BinarySearch()
{
	int count = 0;
	int k[20];
	int r[20];
	int key, i;
	for (i = 0; i < 20; i++)
	{
		k[i] = 1 + rand() % 20;
	}
	for (i = 0; i < 20; i++)
	{
		cout << "k[" << i << "]=" << k[i] << endl;
	}
	cout << "Введите ключ: ";
	cin >> key;
	int left = 0;
	int right = 19;
	int search = -1;
	while (left <= right)
	{
		count++;
		int mid = (left + right) / 2;
		if (key == k[mid])
		{
			search = mid;
			break;
		}
		if (key < k[mid])
			right = mid - 1;
		else
			left = mid + 1;
	}
	if (search == -1)
		cout << "Элемент не найден!" << endl;
	else
		cout << "k[" << search << "]=" << k[search] << " (за " << count << " проходов)" << endl;
	cout << endl;
}
void main()
{
	system("cls");
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	short int w;
	cout << "Введите номер задания: " << endl;
	cin >> w;
	switch (w)
	{
	case 1:
	{
		//1.Объявите указатель на целое число, называемое адресом.
		int *pointer, var = 154;
		pointer = &var;
		printf("%x - адрес числа var.\n", &var);
	}
	break;
	case 2:
	{
		//2.Назначьте значение символа 'W' переменной, 
		//на которую указывает буквенная указатель.
		char W = 'W';
		char *pointer;
		pointer = &W;
		printf("Арес переменной W = %x\n", &W);
	}
	break;
	case 3:
	{
		//3.Объявить указатель на текстовую строку с сообщением «Hello»
		char *string = "Hello";
		printf("%x - адрес строки Hello.\n", &string);
		cout << string << endl;
	}
	break;
	case 4:
	{
		//4.Написать функцию, которая проверяет, является ли переданное ей число простым ? 
		//Число называется простым, если оно делится без остатка только на себя и на единицу.
		int num;
		simple(&num);
	}
	break;
	case 5:
	{
		//5.Написать функцию, реализующую алгоритм линейного поиска заданного ключа в одномерном массиве.
		LineSearch();
	}
	break;
	case 6:
	{
		//6.Написать функцию, реализующую алгоритм бинарного поиска заданного ключа в одномерном массиве.
		BinarySearch();
	}
	break;
	case 7:
	{
		//7.Написать игру «Быки и коровы». Программа "загадывает" четырёхзначное число и играющий должен угадать его.
		//После ввода пользователем числа программа сообщает, сколько цифр числа угадано(быки) и сколько цифр угадано и стоит на нужном месте(коровы).
		//После отгадывания числа на экран необходимо вывести количество сделанных пользователем попыток. В программе необходимо использовать рекурсию.
		int number = 1000 + rand() % 8999;
		cout << "Четырёхзначное число загадано компьютером. " << endl;
		int hint;
		cout << "Введите 4 цифры, которые предположительно есть в числе, которое я загадал: " << endl;
		cin >> hint;
		if (hint == (number / 1000))
			cout << "bull" << endl;
		else
			cout << "cow" << endl;
		cin >> hint;
		if (hint == (number / 100) % 10)
			cout << "bull" << endl;
		else
			cout << "cow" << endl;
		cin >> hint;
		if (hint == (number / 10) % 10)
			cout << "bull" << endl;
		else
			cout << "cow" << endl;
		cin >> hint;
		if (hint == (number % 10))
			cout << "bull" << endl;
		else
			cout << "cow" << endl;
		cout << "Моё число - " << number << endl;
	}
	break;
	case 8:
	{
		//8.Каков результат следующего сегмента программы?
		int  count = 10, *temp, sum = 0;
		temp = &count;
		*temp = 20;
		temp = &sum;
		*temp = count;
		printf("count = %d, *temp = %d, sum = %d\n", count, *temp, sum);
		//Сначала мы в указатель передаём адрес count'a, потом задаём число 20 в указатель, затем передаём в указатель адрес sum, потом опять приравниваем к 20, выводим все значения 20.
	}
	break;
	}
}