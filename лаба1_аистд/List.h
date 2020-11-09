#pragma once
class List
{
private:

	class Node
	{
	public:
		int data;
		Node* prev;
		Node* next;
	};
	Node* head;
	Node* tail;
	Node* current;
	size_t size;
public:
	List();
	~List();
	void push_back(int); // добавление в конец списка
	void push_front(int); // добавление в начало списка
	void pop_back(); // удаление последнего элемента
	void pop_front(); // удаление первого элемента
	void insert(int, int); // добавление элемента по индексу (вставка перед элементом, который был ранее доступен по этому индексу)
	int at(size_t); // получение элемента по индексу. ћожно сделать типа size_t
	void remove(size_t); // удаление элемента по индексу
	size_t get_size(); // получение размера списка
	void print_to_console(); // вывод элементов списка в консоль через разделитель, не использовать at
	void clear(); // удаление всех элементов списка
	void set(size_t, int); // замена элемента по индексу на передаваемый элемент
	bool isEmpty(); // проверка на пустоту списка
	size_t find_first(List*);
};

