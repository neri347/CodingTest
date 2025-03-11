/// AC
/// https://www.acmicpc.net/problem/5430
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <deque>
using namespace std;

int main()
{
	int T;
	cin >> T;
	int answer = 0;
	for (int t = 0; t < T; t++)
	{
		// �Է�
		string p;
		cin >> p;

		int n;
		cin >> n;

		string arrStr;
		cin >> arrStr;
		arrStr.erase(arrStr.begin());
		arrStr.erase(arrStr.end() - 1);

		deque<int> q;
		stringstream ss(arrStr);
		string temp;
		while (getline(ss, temp, ','))
		{
			q.push_back(stoi(temp));
		}
		
		bool isReverse = false;
		bool errorFlag = false;
		// �Լ�����
		for (auto& ch : p)
		{
			if (ch == 'R')
			{
				// �迭 ������
				isReverse = !isReverse;
			}
			else
			{
				// �迭 ����ִٸ� error ��� �� ����
				if (q.empty())
				{
					errorFlag = true;
					break;
				}
				// �迭�� ù��° ��� ����
				if (isReverse)
				{
					q.pop_back();
				}
				else
				{
					q.pop_front();
				}
			}
		}

		// ��� ���
		if (errorFlag)
		{
			cout << "error" << '\n';
		}
		else
		{
			cout << "[";
			if (isReverse) // �迭�� ������������ ���ο� ���� ��¼��� �޶���
			{
				while (!q.empty())
				{
					if (q.size() == 1)
					{
						cout << q.back();
						q.pop_back();
					}
					else
					{
						cout << q.back() << ",";
						q.pop_back();
					}
				}
			}
			else
			{
				while (!q.empty())
				{
					if (q.size() == 1)
					{
						cout << q.front();
						q.pop_front();
					}
					else
					{
						cout << q.front() << ",";
						q.pop_front();
					}
				}
			}
			cout << "]\n";
		}
	}
	return 0;
}