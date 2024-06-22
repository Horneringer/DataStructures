#include "linked_list.hpp"

#include <iostream>

//для конструкторов/деструкторов тоже необходимо указывать, что они шаблонные
template<typename T>
List<T>::List()
{
	//при создании списка его раззмер 0, и указатель на первый элемент указывает
	//на nullptr
	sizeList = 0;

	head = nullptr;
}

template<typename T>
List<T>::~List()
{
	std::cout << "Destructor ";
	clear();
}

template<typename T>
void List<T>::pushBack(T data)
{
	//если указатель на голову nullptr, то список пуст
	if (head == nullptr)
		//создаём новый элемент, у которого после конструирования next ==
		// nullptr
		head = new Node<T>(data);
	//если список не пуст
	else
	{
		//создаём узел и присваиваем ему значение головы
		Node<T>* current = head;

		//проходим по всем существующим узлам в поисках последнего
		while (current->next != nullptr)
			//в текущий записываем указатель на следующий
			current = current->next;

		//когда доршили до конца, создаём новый узел с данными
		//указатель на nullptr теперь указывает на него
		current->next = new Node<T>(data);
	}

	//увеличиваем счётчик размера
	sizeList++;
}

template<typename T>
int List<T>::getSize()
{
	return sizeList;
}

template<typename T>
void List<T>::pop_front()
{
	//сохраняем адрес первого элемента во временый объект
	Node<T>* tmp = head;

	//в первым элементом делаем следующий
	head = head->next;

	//удвляем временный элемент
	delete tmp;

	//уменьшаем размер списка
	sizeList--;
}

template<typename T>
void List<T>::clear()
{
	//пока празмер списка не 0
	while (sizeList)
		//удаляем элемент
		pop_front();
}

template<typename T>
void List<T>::push_front(T data)
{
	//вызывается конструктор узла с данными и указателем на текущий head
	Node<T>* newNode = new Node<T>(data, head);

	//переменная head теперь будет содержать адрем нового элемента
	head = newNode;

	//увеличение размера списка
	sizeList++;
}

template<typename T>
void List<T>::insert(T data, int index)
{
	//если index 0
	if (index == 0)
		//вызов вставки в начало
		push_front(data);
	else
	{
		//создаём временный указатель и сохраняем в него адрес первого элемента
		Node<T>* prev = head;

		//необходимо найти элемент, предшествующий тому элементу, индекс
		//которого мы ищем
		//к этому моменту prev будет копией узла, после которого производится
		//вставка
		for (int i = 0; i < index - 1; i++)
			prev = prev->next;

		//создание нового объекта, его next указывает на элемент, перед которым
		//вставляем
		Node<T>* newNode = new Node<T>(data, prev->next);

		// next для элемента, после которого вставляем обновляется и
		// указывает на новый созданный элемент
		prev->next = newNode;

		//увеличение размера списка
		sizeList++;
	}
}

template<typename T>
void List<T>::removeAt(int index)
{
	//если index 0
	if (index == 0)
		//вызов удаления с гачала списка
		pop_front();

	else
	{
		Node<T>* prev = head;

		//перебираем элементы
		// prev является элементом перед удаляемым
		for (int i = 0; i < index - 1; ++i)
			prev = prev->next;

		//сохраняем указатель на удаляемый элемент
		Node<T>* removable = prev->next;

		//элемент перед удаляемым теперь указывает на элемент после удаляемого
		prev->next = removable->next;

		//удаляем нужный элемент
		delete removable;

		//уменьшаем размер списка
		sizeList--;
	}
}

template<typename T>
void List<T>::pop_back()
{
	//вызов удаления по индексу;
	//указывается индекс последнего элемента, размер списка - 1
	removeAt(sizeList - 1);
}