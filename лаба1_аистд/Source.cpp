#include<iostream>
#include "List.h"
using namespace std;

int main()
{
	List a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(17);
	a.print_to_console();
	a.remove(1);
	cout << endl;
	a.print_to_console();
	cout << endl;
	cout << a.get_size();
	return 0;
	
}