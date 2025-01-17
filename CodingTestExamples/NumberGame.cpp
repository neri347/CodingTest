/// 숫자 게임
/// https://school.programmers.co.kr/learn/courses/30/lessons/12987
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
	int answer = 0;
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	vector<int> vec;

	for (int i = 0; i < A.size(); ++i)
	{
		vec.push_back(A[i]);
	}

	for (int i = 0; i < B.size(); ++i)
	{
		vec.push_back(B[i]);
	}

	int left = 0;
	int right = A.size();
	while (right < vec.size() && left <= right)
	{
		if (vec[left] < vec[right])
		{
			++answer;
			++left;
			++right;
		}
		else
		{
			++right;
		}
	}

	return answer;
}

int main()
{
	int a = INT_MAX;
	a += 4;
	cout << a;
	return 0;
}