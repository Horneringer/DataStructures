#include <iostream>
#include <vector>

/*Пример хэш-таблицы, хранящей пары ключ-значение типа string
Коллизии разрешаются методом цепочек*/

//структура одного элемента
struct Node
{
	//ключ
	std::string key;

	//значение
	std::string value;

	// флаг для отметки удаленных элементов
	bool deleted;

	//указатель на следующий элемент
	Node* next;

	Node(const std::string& k, const std::string& val)
		: key(k),
		  value(val),
		  next(nullptr),
		  deleted(false)
	{}
};

//класс таблицы
class HashTable
{
private:

	//таблица элементов
	std::vector<Node*> hashTable;

	//размер таблицы
	int hashSize;

public:

	//конструктор таблицы принимает заданный размер
	HashTable(int size);
	~HashTable();

	//хэш-функция вычисления индекса таблицы
	int hashF(std::string key, int size);

	//метод вставки в таблицу
	void insert(const std::string& key, const std::string& value);

	//поиск элемента по ключу
	std::string search(const std::string& key);

	//удаление пары по ключу
	void deleteNode(std::string& key);
};