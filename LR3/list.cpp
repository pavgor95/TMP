#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

/**
\class Class of move
*/

class list {
private:
	list* Next;
	string Data;

public:
	list() : Next(nullptr), Data("") {};
	void add(int i, string data);
	void get(int i);
	void del(int i);
	~list() { if (Next != nullptr) delete Next; }
} List;

/// \func Adding element
void list::add(int i, string data) {
	if (i == 0) {
		Data = data;
		return;
	}
	if (Next == nullptr) {
		Next = new list();
	}
	Next->add(i - 1, data);
}

/// \func Getting element
void list::get(int i) {
	if (i == 0) {
		cout << Data << endl;
		return;
	}
	if (Next == nullptr)
		Next = new list();
	Next->get(i - 1);
}

/// \func Deleting element
void list::del(int i) {
	add(i, "");
}

/**
\func Main function of application
*/
int main() {
	size_t n;
	int ind;
	string line;
	cin >> n;
	for (size_t i = 0; i < n; i++) {
		cin >> line;
		if (line == "add") {
			cin >> ind >> line;
			List.add(ind, line);
		}
		else if (line == "get") {
			cin >> ind;
			List.get(ind);
		}
		else if (line == "del") {
			cin >> ind;
			List.del(ind);
		}
		else
			return 1;

	}
	system("pause");
	return 0;
}