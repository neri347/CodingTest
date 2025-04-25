/// ���� �� �ִ� ���� �κ� ����
/// https://www.acmicpc.net/problem/30805
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> vec1;
	for (int i = 0; i < N; i++)
	{
		int v;
		cin >> v;
		vec1.push_back(v);
	}

	int M;
	cin >> M;
	vector<int> vec2;
	for (int i = 0; i < M; i++)
	{
		int v;
		cin >> v;
		vec2.push_back(v);
	}

	vector<int> answer;
	bool flag = false;
	
	int maxIterIdx1;
	int maxIterIdx2;

	while (true)
	{
		// �� �迭���� ���� �ִ밪�� ã�� ������ �ݺ�
		while (true)
		{
			if (vec1.size() == 0 || vec2.size() == 0)
			{
				flag = true;
				break;
			}

			auto maxIter1 = max_element(vec1.begin(), vec1.end());
			maxIterIdx1 = maxIter1 - vec1.begin();
			int max1 = *maxIter1;

			auto maxIter2 = max_element(vec2.begin(), vec2.end());
			maxIterIdx2 = maxIter2 - vec2.begin();
			int max2 = *maxIter2;

			if (max1 == max2)
			{
				break;
			}
			else if (max1 > max2)
			{
				vec1.erase(maxIter1);
			}
			else
			{
				vec2.erase(maxIter2);
			}
		}

		if (flag)
		{
			break;
		}

		answer.push_back(*(maxIterIdx1 + vec1.begin()));

		// �ִ밪�� �� ���ʿ� �ִ� ���� ��� ����
		vector<int> temp1;
		for (int i = maxIterIdx1 + 1; i < vec1.size(); i++)
		{
			temp1.push_back(vec1[i]);
		}
		vec1 = temp1;

		vector<int> temp2;
		for (int i = maxIterIdx2 + 1; i < vec2.size(); i++)
		{
			temp2.push_back(vec2[i]);
		}
		vec2 = temp2;
	}

	cout << answer.size() << '\n';
	for (auto& e : answer)
	{
		cout << e << ' ';
	}

	return 0;
}