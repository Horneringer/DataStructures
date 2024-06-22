#pragma once

//класс для связного списка. В приватной секции содержит класс узла, который не
//будет доступен напрямую без класса List

//класс шаблонный, чтобы при создании объяета узла не привязываться к
//конкретному типу
template<typename T>
class List
{
private:

	//класс шаблонный, чтобы не привязываться к конкретному типу данных узла
	//имя шаблонного параметра должно быть другим, чтобы избежать конфликта имён
	template<typename N>
	class Node
	{
		//класс узла защищен, поэтому все его методы можно сделать публичными

	public:

		//указатель на следующий элемент
		Node<N>* next;

		//данные
		N data;

		//конструктор узла принимает данные и указатель на следующий
		//элемент(по-умолчанию nullptr). Чтобы в data изначально не лежал мусор,
		//вызывается конструктор по умолчанию.

		//необходимо явно указывать типы, при
		//объявлении параметров конструктора и методов
		Node(N data = N(), Node<N>* next = nullptr)
			: data(data),
			  next(next)
		{}
	};

	//указатель на начальный узел списка
	Node<T>* head;

	//количество элементов в списке
	int sizeList;

public:

	List();
	~List();

	//метод добавления элемента
	void pushBack(T);

	//метод взятия по индексу
	//возвращает ссылку на элемент
	T& operator[](const int index)
	{
		//счётчик элементов
		int counter = 0;

		//указатель на первый
		Node<T>* current = head;

		//обход списка
		while (current != nullptr)
		{
			//если нужный индекс найден
			if (counter == index)
				//возврат даннх элемента
				return current->data;

			//запрашиваем адрес следующего элемента
			current = current->next;
			//увеличиваем счетчик
			counter++;
		}
	}

	//возвращает размер списка
	int getSize();

	//удалить элемент с начала списка
	void pop_front();

	//очистить данные списка
	void clear();

	//добавить элемент c данными в начало списка
	void push_front(T data);

	//вставить элемент с данными по индексу
	void insert(T data, int index);

	//удалить элемент по индексу
	void removeAt(int index);

	//удалить элемент с конца списка
	void pop_back();
};

//подключение реализации из файла tpp должно быть строго ПОСЛЕ объявления
//шаблона
#include "linked_list.tpp"