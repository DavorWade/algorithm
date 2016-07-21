#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int cnt, aim_depth;
int vis[10];
int record[10][10];
int map[10][10];
int total_edge;

void init()
{
	record[1][3] = record[3][1] = record[1][7] = record[7][1] = 1;
	record[1][9] = record[9][1] = record[3][7] = record[7][3] = 1;
	record[9][3] = record[3][9] = record[9][7] = record[7][9] = 1;
	record[2][8] = record[8][2] = record[4][6] = record[6][4] = 1;
}

void dfs(int num, int depth, int edge)
{
	//找到符合条件的案例是深度，其次我们找到的边要包括已看到的边 
	if (depth == aim_depth && edge == total_edge)
	{
		cnt++;
		return;
	}

	for (int i = 1; i < 10; i++)
	{
		if (!vis[i])
		{
			if (record[num][i] && !vis[(num + i) / 2]) continue;  //中间点划过，则不找 
			vis[i] = 1;
			if (map[num][i])   //看看是否是已存在的边 
				dfs(i, depth + 1, edge + 1);
			else
				dfs(i, depth + 1, edge);
			vis[i] = 0;
		}
	}
}

int main()
{
	int t, n, uu, vv;
	cin >> t;
	init();
	while (t--)
	{
		cin >> n;

		memset(vis, 0, sizeof(vis));
		memset(map, 0, sizeof(map));

		for (int i = 0; i < n; i++)
		{
			cin >> uu >> vv;
			map[uu][vv] = map[vv][uu] = 1;
		}
		cnt = 0;
		total_edge = n;
		for (aim_depth = max(4, n + 1); aim_depth <= 9; aim_depth++)
		{
			for (int i = 1; i <= 9; i++)
			{
				vis[i] = 1;
				dfs(i, 1, 0);
				vis[i] = 0;
			}
		}
		cout << cnt << endl;
	}
}
