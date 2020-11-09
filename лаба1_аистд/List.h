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
	void push_back(int); // ���������� � ����� ������
	void push_front(int); // ���������� � ������ ������
	void pop_back(); // �������� ���������� ��������
	void pop_front(); // �������� ������� ��������
	void insert(int, int); // ���������� �������� �� ������� (������� ����� ���������, ������� ��� ����� �������� �� ����� �������)
	int at(size_t); // ��������� �������� �� �������. ����� ������� ���� size_t
	void remove(size_t); // �������� �������� �� �������
	size_t get_size(); // ��������� ������� ������
	void print_to_console(); // ����� ��������� ������ � ������� ����� �����������, �� ������������ at
	void clear(); // �������� ���� ��������� ������
	void set(size_t, int); // ������ �������� �� ������� �� ������������ �������
	bool isEmpty(); // �������� �� ������� ������
	size_t find_first(List*);
};

