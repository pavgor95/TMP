#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <clocale>
using namespace std;

vector<int> res;


void AddCh(vector<int>& mas) {
	sort(mas.begin(), mas.end());
}

void GetCh(vector<int> mas) {
	res.push_back(mas.front());
}

void DelCh(vector<int>& mas) {
	mas.erase(mas.begin());
}

int main()
{
	int N, ch;
	vector<int> mas;
	string s;
	setlocale(LC_CTYPE, "Russian");
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> s;
		if (s == "add") {
			cin >> ch;
			mas.push_back(ch);
			AddCh(mas);
		}
		if (s == "get") {
			GetCh(mas);
		}
		if (s == "del") {
			DelCh(mas);
		}
	}
	cout << "Выходные данные" << endl;
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << endl;
	}
	system("pause");
	return 0;
}