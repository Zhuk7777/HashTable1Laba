#include<iostream>
#include"HashTable.h"
#include <Windows.h>

int check();
void menu();

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::cout << "������� �������������� ���������� ������� �� ������\n";
	int kol = check();
	HashTable mas(kol);

	Product product;
	int chose = 1;
	bool flag;

	while (chose)
	{
		menu();
		chose = check();
		while (chose < 1 || chose>5)
		{
			std::cout << "����� ������ ����� �� 1 �� 5(������������)\n";
			chose = check();
		}
		
		switch (chose)
		{
		case 1:
			std::cout << "�������� �������� ������\n";
			std::cin >> product.name;
			std::cout << "�������� ��� ����������\n";
			std::cin >> product.count;
			mas.add(product);
			break;

		case 2:
			std::cout << "�������� �������� ������, ������� ����� ������� �� ������� \n";
			std::cin >> product.name;
			product.count == 0;
			mas.remove(product);
			break;

		case 3:
			std::cout << "�������� �������� ������, ������� ����� ����� \n";
			std::cin >> product.name;
			product.count == 0;
			int ind;
		    flag = mas.search(product, ind);
			if (flag)
				std::cout << "���� ����� �������� � ����������: " << mas.getCount(ind) << "��\n";
			else
				std::cout << "������ ������ �� ������ ���\n";
			break;

		case 4:
			mas.printTable();
			break;

		case 5:
			mas.clear();
			break;
		}

		std::cout << "\n";
		std::cout << "0-��������� ������ ���������, 1-����������\n";
		chose = check();

		while (chose < 0 || chose>1)
		{
			std::cout << "����� ������ 0 ��� 1\n";
			chose = check();
		}
	}
	return 0;
}


int check()
{
	int x;
	std::cin >> x;
	while (!std::cin)
	{
		std::cin.clear();
		std::cin.ignore();
		std::cout << "����� ������ �����" << std::endl;
		std::cin >> x;
	}
	return x;
}

void menu()
{
	std::cout << "1-�������� �������\n2-������� �������\n3-����� ��������\n4-������ �������\n5-������� �������\n";

}