#include<iostream>

using namespace std;

int q[10000];

void merge_sort(int l,int r)
{
	if (l >= r)
		return;

	int mid = (l + r) / 2;
	merge_sort(l, mid);
	merge_sort(mid + 1, r);

	int i, j;
	i = l;
	j = mid + 1;
	int copy[10000];
	int record = l;
	while (i <= mid && j <= r)
	{
		if (q[i] > q[j])
		{
			copy[record] = q[j];
			j++;
		}
		else
		{
			copy[record] = q[i];
			i++;
		}
		record++;
	}
	while (i <= mid)
	{
		copy[record] = q[i];
		i++;
		record++;
	}
	while (j <= r)
	{
		copy[record] = q[j];
		j++;
		record++;
	}

	for (int z = l; z < r + 1; z++)
	{
		q[z] = copy[z];
	}
	return;
}
int main()
{
	int num;
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		cin >> q[i];
	}
	merge_sort(0, num - 1);
	for (int i = 0; i < num; i++)
	{
		cout << q[i] << " ";
	}
	return 0;
}