/// 조이스틱
/// https://school.programmers.co.kr/learn/courses/30/lessons/42860
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(string name) {
	int answer = 0;
	int sz = name.size();
	int move = sz - 1; // 처음부터 끝까지 커서 이동하는 횟수
	for (int i = 0; i < sz; i++)
	{
		answer += min(name[i] - 'A', 'Z' - name[i] + 1);
		// 1. 처음부터 i까지 이동 후, 처음으로 되돌아가서 마지막 인덱스부터 처음으로 A가 나오는 인덱스 이전까지.
		// 2. i부터 시작해 거꾸로 되돌아가서 마지막 인덱스부터 처음으로 A가 나오는 인덱스 이전까지 갔다가 
		// 다시 오른쪽으로 쭉 가서 i까지 되돌아오는 방법.
		int index = i + 1; // 더 이상 A 나오지 않는 인덱스
		while (index < sz && name[index] == 'A')
		{
			++index;
		}
		move = min({ move, 2 * i + (sz - index), 2 * (sz - index) + i });
	}

	return answer + move;
}

int main()
{

	return 0;
}