#include "HashTable.h"

int HashTable::hashFunc(Product k)
{
	int result = 0;
	int s = k.name.size();
	for (int i = 0; i < s; i++)
	{
		result += ((s - i) * (int)k.name[i]) % size;
	}
	result %= size;
	return result;
}

int HashTable::randomConst(int k)
{
	return k % (size / 2);
}

HashTable::HashTable(int s)
{
	s *= 2;
	table = new Item[s];
	size = s;
	count = 0;
	for (int i = 0; i < size; i++)
		table[i].status = empty;
}

HashTable::~HashTable()
{
	delete[]table;
}

void HashTable::add(Product elem)
{
	if (count == size)
		return;
	else {
		int k = hashFunc(elem);
		if (table[k].status == empty || table[k].status == removed) {
			table[k].data = elem;
			table[k].status = filled;
			count++;
		}
		else {
			int i = 0;
			int p = randomConst(k);
			while (table[(k + i * p) % size].status == filled)
				i++;
			table[(k + i * p) % size].data = elem;
			table[(k + i * p) % size].status = filled;
		}
	}
}

bool HashTable::search(Product obj, int& ind)
{
	int k = hashFunc(obj);
	if (table[k].status == removed || table[k].status == empty) {
		ind = -1;
		return false;
	}
	else
	{
		if (table[k].data == obj) {
			ind = k;
			return true;
		}
		else
		{
			int i = 1;
			int p = randomConst(k);
			while (table[(k + i * p) % size].status != empty)
				if (table[(k + i * p) % size].status == filled && table[(k + i * p) % size].data == obj) {
					ind = (k + i * p) % size;
					return true;
				}
		}
	}
	ind = -1;
	return false;
}

void HashTable::remove(Product obj)
{
	int ind;
	bool flag = search(obj, ind);
	if (flag) {
		table[ind].status = removed;
		count--;
	}
}

void HashTable::printTable()
{
	for (int i = 0; i < size; i++)
		if (table[i].status != filled)
			std::cout << "empty  ";
		else
			std::cout << table[i].data.name << "(" << table[i].data.count << ")  ";
}

void HashTable::clear()
{
	for (int i = 0; i < size; i++)
		table[i].status = empty;
}

int HashTable::getCount(int ind)
{
	if (table[ind].status == filled)
		return table[ind].data.count;
}


