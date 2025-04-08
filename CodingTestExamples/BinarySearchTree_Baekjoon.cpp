/// 이진 탐색 트리
/// https://www.acmicpc.net/problem/5639
#include <stdio.h>
#include <vector>
using namespace std;

int values[10000];

void Postorder(int start, int end)
{
	if (start >= end)
	{
		return;
	}

	if (start == end - 1)
	{
		printf("%d\n", values[start]);
		return;
	}

	int mid = start + 1;
	while (mid < end)
	{
		if (values[mid] > values[start])
		{
			break;
		}
		++mid;
	}

	Postorder(start + 1, mid);
	Postorder(mid, end);
	printf("%d\n", values[start]);
}

int main()
{
	int value;
	int idx = 0;
	while (scanf("%d", &value) != EOF)
	{
		values[idx++] = value;
	}
	Postorder(0, idx);
	return 0;
}