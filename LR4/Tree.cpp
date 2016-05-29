#include <iostream>
using namespace std;

void reverse(int i, int* a, int N)
{
	for (int z = 0; z<N; z++)
	if (a[z] == i)
	{
		reverse(z, a, N);
	}
	if (i != -1) cout << i << " ";
}

void simmet(int i, int* a, int N)
{
	int x = 0;
	for (int z = 0; z<N; z++)
	if (a[z] == i)
	{
		simmet(z, a, N);
		if ((i != -1) && (!x)) cout << i << " ";
		x++;
	}
	if (x == 0) cout << i << " ";
}

void pryam(int i, int* a, int N)
{
	for (int z = 0; z<N; z++)
	if (a[z] == i)
	{
		cout << z << " ";
		pryam(z, a, N);
	}
}

int main()
{
	int N; cin >> N;
	int* tree = new int[N];

	for (int i = 0; i<N; i++) cin >> tree[i];

	pryam(-1, tree, N); cout << endl;
	reverse(-1, tree, N); cout << endl;
	simmet(-1, tree, N); cout << endl;

	delete[] tree;

	system("pause");
	return 0;
}