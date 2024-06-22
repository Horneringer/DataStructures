#include "linked_list.hpp"

#include <iostream>

int main(int argc, char* argv[])
{
	List<int> lst;

	//заполнение списка
	int elemCount;

	std::cin >> elemCount;

	//вывод элементов списка в цикле
	for (int i = 0; i < elemCount; i++)
	{
		lst.pushBack(rand() % 10);
		std::cout << lst[i] << ' ';
	}

	std::cout << "Current size " << lst.getSize() << "\n";

	std::cout << "===================================="
			  << "\n";

	std::cout << "Вставка в начало "
			  << "\n";
	lst.push_front(8);

	/* lst.clear();
	 */
	/* lst.pop_front();

	for (int i = 0; i < lst.getSize(); i++)
		std::cout << lst[i] << ' '; */

	for (int i = 0; i < lst.getSize(); i++)
		std::cout << lst[i] << ' ';

	std::cout << "\n";

	std::cout << "Current size " << lst.getSize() << "\n";

	std::cout << "===================================="
			  << "\n";

	std::cout << "Вставка в середину "
			  << "\n";
	lst.insert(88, 4);

	for (int i = 0; i < lst.getSize(); i++)
		std::cout << lst[i] << ' ';

	std::cout << "\n";

	std::cout << "Current size " << lst.getSize() << "\n";

	std::cout << "===================================="
			  << "\n";

	std::cout << "Удаление элемента "
			  << "\n";

	lst.removeAt(2);

	for (int i = 0; i < lst.getSize(); i++)
		std::cout << lst[i] << ' ';

	std::cout << "\n";

	std::cout << "Current size " << lst.getSize() << "\n";

	std::cout << "===================================="
			  << "\n";

	std::cout << "Удаление элемента с конца"
			  << "\n";

	lst.pop_back();

	for (int i = 0; i < lst.getSize(); i++)
		std::cout << lst[i] << ' ';

	std::cout << "\n";

	std::cout << "Current size " << lst.getSize() << "\n";

	return 0;
}