/// 나는야 포켓몬 마스터 이다솜
/// https://www.acmicpc.net/problem/1620
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cctype>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	unordered_map<string, int> nameAndNumberMap;
	unordered_map<int, string> numberAndNameMap;
	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		string str;
		cin >> str;
		nameAndNumberMap[str] = i;
		numberAndNameMap[i] = str;
	}

	for (int i = 0; i < M; i++)
	{
		string str;
		cin >> str;
		if (isdigit(str[0]))
		{
			int num = stoi(str);
			cout << numberAndNameMap.find(num)->second;
		}
		else
		{
			cout << nameAndNumberMap.find(str)->second;
		}
		cout << '\n';
	}
	return 0;
}