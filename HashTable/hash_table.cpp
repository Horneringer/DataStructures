#include "hash_table.hpp"

#include <iostream>
#include <vector>

HashTable::HashTable(int size)
	: hashSize(size)
{
	//таблица меняет размер на указанный
	hashTable.resize(size, nullptr);
}

HashTable::~HashTable()
{
	//проход по всем ячейкам
	for (int i = 0; i < hashSize; ++i)
	{
		// 		{
		//создание узла для текущего индекса
		Node* current = hashTable.at(i);
		//проход по связному списку пар
		while (current != nullptr)
		{
			//запоминаем текущий
			Node* tmp = current;

			//перемещение указателя на следующий
			current = current->next;

			//удаление текущего
			delete tmp;
		}
	}
}

int HashTable::hashF(std::string key, int size)
{
	//вычисляемый индекс элемента. Равен остатку от деления суммы значений
	//символов ключа и размера таблицы
	int index;
	int hash = 0;

	for (char ch : key)
		hash = hash + ch;
	index = hash % size;

	return index;
}

void HashTable::insert(const std::string& key, const std::string& value)
{
	//индекс элемента
	int index = hashF(key, hashSize);

	//новый узел для хранения элемента
	Node* node = new Node(key, value);

	//если по данному индексу элемента нет
	if (hashTable.at(index) == nullptr)

		//добавляем туда наш узел
		hashTable.at(index) = node;

	//если уже есть такой ключ(коллизия)
	else
	{
		//существующий элемент смещаем на следующую позицию в связном
		//списке node->next = hashTable.at(index);
		//на его позицию записываем добавляемый элемент
		hashTable.at(index) - node;
	}
}

std::string HashTable::search(const std::string& key)
{
	//вычисление индекса искомого элемента
	int index = hashF(key, hashSize);

	//инициализация указателя на начало связного списка, который находится
	// в данной ячейке
	Node* current = hashTable.at(index);

	//проход по связному списку
	while (current != nullptr)
	{
		//если ключи совпадают
		if (current->key == key)
			//возврат значения
			return current->value;
		//иначе переход к следующему элементу списка
		current = current->next;
	}
	//если достигнут конец списка, то ключа в списке нет
	return "Key not found";
}

void HashTable::deleteNode(std::string& key)
{
	//индекс элемента таблицы
	int index = hashF(key, hashSize);

	//инициализация указателя на начало связного списка, стоящего в index
	Node* current = hashTable.at(index);

	//указатель на элемент перед удаляемым устанавливаем в nullptr, так как
	//начинаем с первого элемента списка
	Node* prev = nullptr;

	//проходим по списку
	while (current != nullptr)
	{
		//если нужный ключ найден
		if (current->key == key)
		{
			//если удаляемый элемент первый в списке
			if (prev == nullptr)
				// в первый элемент записываем следующий, тем самым удаляя его
				hashTable.at(index) = current->next;
			//если удаляемы элемент в середине или конце
			else
				//предыдущий элемент теперь будет указывать на слудующий за
				//текущим
				prev->next = current->next;
			//освобождаем память
			delete current;
			return;
		}
		//если ключ пока не найден, в предыдущий записываем текущий
		prev	= current;
		//в текущий записываем следующий
		current = current->next;
	}
}
