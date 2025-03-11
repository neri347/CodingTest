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
		// 입력
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
		// 함수실행
		for (auto& ch : p)
		{
			if (ch == 'R')
			{
				// 배열 뒤집기
				isReverse = !isReverse;
			}
			else
			{
				// 배열 비어있다면 error 출력 후 종료
				if (q.empty())
				{
					errorFlag = true;
					break;
				}
				// 배열의 첫번째 요소 삭제
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

		// 결과 출력
		if (errorFlag)
		{
			cout << "error" << '\n';
		}
		else
		{
			cout << "[";
			if (isReverse) // 배열이 뒤집어졌는지 여부에 따라 출력순서 달라짐
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