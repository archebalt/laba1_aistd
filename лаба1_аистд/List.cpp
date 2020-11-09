#include "List.h"
#include<iostream>
using namespace std;

// реализация методов и конструкторов класса List
List::List()
{
	head = 0;
	tail = 0;
	size = 0;
	current = 0;
}

List :: ~List()
{
	clear();  // освобождаем динамически выделенную память
}

void List::push_back(int NewElem )
{
	if (head == 0) // если элементов в списке еще нет
	{
		head = new Node;
		tail = head;
		head->data = NewElem;
		head->next = 0;
		head->prev = 0;
	}
	else
	{
		current = new Node;
		current->prev = tail;
		tail->next = current;
		current->next = 0;
		current->data = NewElem;
		tail = current;
	}
	size++;
}

void List::push_front(int NewElem)
{
	if (size == 0)
	{
		head = new Node;
		head->data = NewElem;
		tail = head;
		head->next = 0;
		head->prev = 0;
	}
	else
	{
		current = new Node;
		current->data = NewElem;
		current->next = head;
		head->prev = current;
		current->prev = 0;
		head = current;
	}
	size++;
}

void List::pop_back()
{
	if (size != 0)
	{
		if (size == 1)
		{
			delete head;
			head = 0;
			tail = 0;
			current = 0;
		}
		else
		{
			current = tail->prev;
			current->next = 0;
			delete tail;
			tail = current;
		}
		size--;
	}
}

void List::pop_front()
{
	if (size != 0)
	{
		if (size == 1)
		{
			delete head;
			head = 0;
			tail = 0;
			current = 0;
		}
		else
		{
			current = head->next;
			current->prev = 0;
			delete head;
			head = current;
		}
		size--;
	}
}

void List::insert(int NewElem, int index)
{
	if (index <= size - 1 && index >= 0)
	{
		if (index != 0)
		{
			current = head;
			for (int i = 0; i < index - 1; i++) 
			{
				current= current->next;
			}
			Node* sup = current->next;
			Node* inserted = new Node;
			inserted->data = NewElem;
			inserted->next = current->next;
			current->next = inserted;
			inserted->prev = current;
			sup->prev = inserted;
		}
		else
		{
			push_front(NewElem);
		}
		size++;
	}
}
int List::at(size_t index)
{
	if (index >= 0 && index < size)
	{
		current = head;
		for (int i = 0; i < index; i++)
		{
			current = current->next;
		}
		return current->data;
	}
}

void List::remove(size_t index)
{
	if (index >= 0 && index < size)
	{
		current = head;
		if (index == 0)
		{
			pop_front();
		}
		if (index == size - 1)
		{
			pop_back();
		}
		for (int i = 0; i < index; i++)
		{
			current = current->next;
		}
		if (index > 0 && index < size - 1)
		{
			Node* previous = current->prev;
			Node* NextElem = current->next;
			previous->next = current->next;
			NextElem->prev = current->prev;
			delete current;
			size--;
		}
	}
}
size_t List::get_size()
{
	return size;
}
void List :: print_to_console()
{
	current = head;
	for (int i = 0; i < size; i++)
	{
		cout << current->data << '|';
		current = current->next;
	}
}

void List::clear()
{
	current = head;
	for (int i = 0; i < size; i++)
	{
		Node* sup = current;
		current = current->next;
		delete sup;
	}
	head = 0;
	tail = 0;
	size = 0;
}

void List::set(size_t index, int NewElem)
{
	if (index >= 0 && index < size)
	{
		current = head;
		for (int i = 0; i < index; i++)
		{
			current = current->next;
		}
		current->data = NewElem;
	}
}

bool List::isEmpty()
{
	if (size == 0) return true;
	else return false;
}

size_t List::find_first(List* secondList)
{
	if (isEmpty() == false && secondList->isEmpty() == false)
	{
		current = head;
		for (int i = 0; i < size; i++)
		{
			if (at(i) == secondList->at(0))
			{
				for (int j = 1; j < secondList->get_size(); j++)
				{
					if (at(i + j) != secondList->at(j)) break;
					if (j == secondList->get_size() - 1) return i;
				}
			}
		}
	}
	return -1;
}