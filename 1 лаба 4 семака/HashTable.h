#pragma once
#include<string>
#include<iostream>
struct Product
{
	std::string name;
	int count;
	bool operator==(const Product& obj)
	{
		return name == obj.name;
	}
};

enum Status{empty,filled,removed};

struct Item {
	Product data;
	Status status;
};

class HashTable
{
	Item* table;
	int size;
	int count;

	int hashFunc(Product k);
	int randomConst(int k);

public:
	HashTable(int s);
	~HashTable();

	void add(Product elem);
	bool search(Product obj, int& ind);
	void remove(Product obj);

	void printTable();
	void clear();
	int getCount(int ind);
};