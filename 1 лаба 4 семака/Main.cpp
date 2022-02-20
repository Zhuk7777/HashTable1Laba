#include<iostream>
#include"HashTable.h"
#include <Windows.h>

int check();
void menu();

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::cout << "введите предполагаемое количество товаров на складе\n";
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
			std::cout << "Нужно ввести число от 1 до 5(включительно)\n";
			chose = check();
		}
		
		switch (chose)
		{
		case 1:
			std::cout << "Напишите название товара\n";
			std::cin >> product.name;
			std::cout << "Напишите его количество\n";
			std::cin >> product.count;
			mas.add(product);
			break;

		case 2:
			std::cout << "Напишите название товара, который нужно удалить из таблицы \n";
			std::cin >> product.name;
			product.count == 0;
			mas.remove(product);
			break;

		case 3:
			std::cout << "Напишите название товара, который нужно найти \n";
			std::cin >> product.name;
			product.count == 0;
			int ind;
		    flag = mas.search(product, ind);
			if (flag)
				std::cout << "Этот товар хранится в количестве: " << mas.getCount(ind) << "шт\n";
			else
				std::cout << "Такого товара на складе нет\n";
			break;

		case 4:
			mas.printTable();
			break;

		case 5:
			mas.clear();
			break;
		}

		std::cout << "\n";
		std::cout << "0-завершить работу программы, 1-продолжить\n";
		chose = check();

		while (chose < 0 || chose>1)
		{
			std::cout << "Нужно ввести 0 или 1\n";
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
		std::cout << "нужно ввести число" << std::endl;
		std::cin >> x;
	}
	return x;
}

void menu()
{
	std::cout << "1-добавить элемент\n2-удалить элемент\n3-поиск элемента\n4-печать таблицы\n5-очистка таблицы\n";

}