#include "hash_table.hpp"

#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
	//создание таблицы на 10 элементов
	HashTable fruits(10);

	//добавление пар
	fruits.insert("apple", "red");
	fruits.insert("banana", "yellow");
	fruits.insert("malon", "green");

	//удаление элемента
	std::string deletedFruit = "malon";
	fruits.deleteNode(deletedFruit);

	//поиск элемента
	std::cout << "Color of apple: " << fruits.search("apple") << std::endl;
	std::cout << "Color of malon: " << fruits.search("malon") << std::endl;

	//поиск несуществующего элемента
	std::cout << "Color of grape: " << fruits.search("grape") << std::endl;

	return 0;
}