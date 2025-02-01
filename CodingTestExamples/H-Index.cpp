/// H-Index
/// https://school.programmers.co.kr/learn/courses/30/lessons/42747
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
	int counts[10001] = { 0, };
	int answer = 0;

	for (int i = 0; i < citations.size(); i++)
	{
		counts[citations[i]]++;
	}

	int sum = citations.size();
	// i 인용횟수
	for (int i = 0; i < 10000; i++)
	{
		// i번 이상 인용된 논문 갯수 = sum
		// i번 이상 인용된 논문 갯수가 i편 미만이면 중단
		if (sum < i) break;
		// i번 이상 인용되지 않은 논문 개수가 i편 이하라면 h값 갱신
		if ((citations.size() - sum) <= i)
		{
			answer = i;
		}
		// sum 값 갱신
		sum -= counts[i];
	}

	return answer;
}

int main()
{

	return 0;
}