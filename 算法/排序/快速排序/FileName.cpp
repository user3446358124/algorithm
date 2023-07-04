#include<iostream>
#include <vector>

using namespace std;

int v[10000];

void quick_sort(int l, int r)
{
	if (l >= r)
		return;
	int x = v[(l + r + 1) / 2];
	int backl = l;
	int backr = r;
	while (l < r)
	{
		while (l < r && v[l] < x)
			l++;
		while (l < r && v[r] > x)
			r--;
		if (l < r)
		{
			swap(v[l], v[r]);
			l++;
			r--;
		}
	}

	quick_sort(backl, l-1);
	quick_sort(r, backr);
	return;
}
int main()
{
	int num;
	cin >> num;


	for(int i=0;i<num;i++)
	{
		cin >> v[i];
	}
	quick_sort(0, num - 1);

	for(int i=0;i<num;i++)
	{
		cout << v[i] << " ";
	}
	return 0;
}