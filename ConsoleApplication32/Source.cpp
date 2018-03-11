#include <iostream>
#include <stdio.h>
#include <time.h>
#include <locale.h>
#include <string.h>
using namespace std;
void simple(int *num)
{
	cout << "������� �����: " << endl;
	cin >> *num;
	cout << "������ ��������� ����������: " << endl;
	for (int i = 2; i < sqrt(*num); i++)
	{
		if (*num % i == 0)
		{
			cout << "����� ���������. " << endl;
		}
		else
		{
			cout << "����� �������. " << endl;
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
	cout << "������� ����: ";
	cin >> key;
	for (i = 0; i < 19; i++)
	{
		if (k[i] == key)
		{
			cout << i << endl;
			break;
		}
	}
	cout << "������� �� ������ �� " << i << " �����" << endl;
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
	cout << "������� ����: ";
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
		cout << "������� �� ������!" << endl;
	else
		cout << "k[" << search << "]=" << k[search] << " (�� " << count << " ��������)" << endl;
	cout << endl;
}
void main()
{
	system("cls");
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	short int w;
	cout << "������� ����� �������: " << endl;
	cin >> w;
	switch (w)
	{
	case 1:
	{
		//1.�������� ��������� �� ����� �����, ���������� �������.
		int *pointer, var = 154;
		pointer = &var;
		printf("%x - ����� ����� var.\n", &var);
	}
	break;
	case 2:
	{
		//2.��������� �������� ������� 'W' ����������, 
		//�� ������� ��������� ��������� ���������.
		char W = 'W';
		char *pointer;
		pointer = &W;
		printf("���� ���������� W = %x\n", &W);
	}
	break;
	case 3:
	{
		//3.�������� ��������� �� ��������� ������ � ���������� �Hello�
		char *string = "Hello";
		printf("%x - ����� ������ Hello.\n", &string);
		cout << string << endl;
	}
	break;
	case 4:
	{
		//4.�������� �������, ������� ���������, �������� �� ���������� �� ����� ������� ? 
		//����� ���������� �������, ���� ��� ������� ��� ������� ������ �� ���� � �� �������.
		int num;
		simple(&num);
	}
	break;
	case 5:
	{
		//5.�������� �������, ����������� �������� ��������� ������ ��������� ����� � ���������� �������.
		LineSearch();
	}
	break;
	case 6:
	{
		//6.�������� �������, ����������� �������� ��������� ������ ��������� ����� � ���������� �������.
		BinarySearch();
	}
	break;
	case 7:
	{
		//7.�������� ���� ����� � �������. ��������� "����������" ������������� ����� � �������� ������ ������� ���.
		//����� ����� ������������� ����� ��������� ��������, ������� ���� ����� �������(����) � ������� ���� ������� � ����� �� ������ �����(������).
		//����� ����������� ����� �� ����� ���������� ������� ���������� ��������� ������������� �������. � ��������� ���������� ������������ ��������.
		int number = 1000 + rand() % 8999;
		cout << "������������� ����� �������� �����������. " << endl;
		int hint;
		cout << "������� 4 �����, ������� ���������������� ���� � �����, ������� � �������: " << endl;
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
		cout << "�� ����� - " << number << endl;
	}
	break;
	case 8:
	{
		//8.����� ��������� ���������� �������� ���������?
		int  count = 10, *temp, sum = 0;
		temp = &count;
		*temp = 20;
		temp = &sum;
		*temp = count;
		printf("count = %d, *temp = %d, sum = %d\n", count, *temp, sum);
		//������� �� � ��������� ������� ����� count'a, ����� ����� ����� 20 � ���������, ����� ������� � ��������� ����� sum, ����� ����� ������������ � 20, ������� ��� �������� 20.
	}
	break;
	}
}