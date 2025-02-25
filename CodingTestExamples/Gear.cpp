/// Åé´Ï¹ÙÄû
/// https://www.acmicpc.net/problem/14891
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	vector<vector<int>> gears(4);
	for (int i = 0; i < 4; i++)
	{
		string str;
		cin >> str;
		for (char ch : str)
		{
			gears[i].push_back(ch - '0');
		}
	}

	int N;
	cin >> N;
	vector<pair<int, int>> rotate; // index, dir
	for (int i = 0; i < N; i++)
	{
		int index, dir; // dir 1 ½Ã°è¹æÇâ, -1 ¹Ý½Ã°è¹æÇâ
		cin >> index >> dir;
		rotate.push_back({ index - 1, dir });
	}

	// Ç®ÀÌ
	for (int i = 0; i < N; i++)
	{
		queue<pair<int, int>> q; // index, dir
		vector<bool> isVisited(4, false);
		q.push({ rotate[i].first, rotate[i].second });
		isVisited[rotate[i].first] = true;

		while (!q.empty())
		{
			int index = q.front().first;
			int dir = q.front().second;
			int right = gears[index][2];
			int left = gears[index][6];
			q.pop();

			// Åé´Ï È¸Àü
			if (dir == 1) // ½Ã°è¹æÇâ È¸Àü
			{
				int v = gears[index][7];
				// ¿ø¼Ò µÚ·Î ¹Ð±â
				for (int i = 6; i >= 0; i-- )
				{
					gears[index][i + 1] = gears[index][i];
				}
				gears[index][0] = v;
			}
			else
			{
				int v = gears[index][0];
				// ¿ø¼Ò ¾ÕÀ¸·Î ¶¯±â±â
				for (int i = 0; i < 7; i++)
				{
					gears[index][i] = gears[index][i + 1];
				}
				gears[index][7] = v;
			}

			// ¿ÞÂÊ Åé´Ï Ã¼Å©
			if (index - 1 >= 0)
			{
				if (!isVisited[index - 1])
				{
					// ÇöÀç Åé´Ï¿Í ¿ÞÂÊ Åé´Ï°¡ ±ØÀÌ °°À¸¸é È¸ÀüÇÏÁö ¾ÊÀ½
					if (left != gears[index - 1][2])
					{
						isVisited[index - 1] = true;
						if (dir == 1)
						{
							q.push({ index - 1, -1 });
						}
						else
						{
							q.push({ index - 1, 1 });
						}
					}
				}
			}

			// ¿À¸¥ÂÊ Åé´Ï Ã¼Å©
			if (index + 1 <= 3)
			{
				if (!isVisited[index + 1])
				{
					// ÇöÀç Åé´Ï¿Í ¿ÞÂÊ Åé´Ï°¡ ±ØÀÌ °°À¸¸é È¸ÀüÇÏÁö ¾ÊÀ½
					if (right != gears[index + 1][6])
					{
						isVisited[index + 1] = true;
						if (dir == 1)
						{
							q.push({ index + 1, -1 });
						}
						else
						{
							q.push({ index + 1, 1 });
						}
					}
				}
			}
		}
	}

	//1¹ø Åé´Ï¹ÙÄûÀÇ 12½Ã¹æÇâÀÌ N±ØÀÌ¸é 0Á¡, S±ØÀÌ¸é 1Á¡
	//2¹ø Åé´Ï¹ÙÄûÀÇ 12½Ã¹æÇâÀÌ N±ØÀÌ¸é 0Á¡, S±ØÀÌ¸é 2Á¡
	// 3¹ø Åé´Ï¹ÙÄûÀÇ 12½Ã¹æÇâÀÌ N±ØÀÌ¸é 0Á¡, S±ØÀÌ¸é 4Á¡
	// 4¹ø Åé´Ï¹ÙÄûÀÇ 12½Ã¹æÇâÀÌ N±ØÀÌ¸é 0Á¡, S±ØÀÌ¸é 8Á¡
	int answer = 0;
	int value = 1;
	for (int i = 0; i < 4; i++)
	{
		if (gears[i][0] == 1)
		{
			answer += value;
		}
		value *= 2;
	}
	cout << answer;

	return 0;
}