#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <utility>
#include <set>

using namespace std;

/*
int main()
{
	int n, m;
	int count;
	set<pair<int, int> > rs;
	set<pair<int, int> >::iterator it;

	cin >> n >> m;

	char **data = new char*[m];
	for (int i = 0; i < m; i++)
	{
		data[i] = new char[n + 1];
	}

	for (int j = 0; j < m; j++)
	{
		//std::cin.getline(data[j], n+1);
		cin >> data[j];
	}
	for (int k = 0; k < m; k++)
	{
		count = 0;
		for (int u = 0; u < n; u++)
		{
			for (int t = u + 1; t < n; t++)
			{
				if (data[k][u]>data[k][t])
				{
					count++;
				}
			}
		}
		rs.insert(make_pair(count, k));
	}

	for (it = rs.begin(); it != rs.end(); it++)
	{
		cout << data[(*it).second] << endl;
	}
	for (int ptr = 0; ptr < m; ptr++)
	{
		delete[] data[ptr];
	}
	delete[] data;

	//system("pause");
	return  0;
}
*/