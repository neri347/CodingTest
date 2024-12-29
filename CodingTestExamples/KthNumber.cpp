/// K번째 수
/// https://school.programmers.co.kr/learn/courses/30/lessons/42748
/// sort() 사용
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for (const auto& command : commands)
    {
        int begin = command[0];
        int end = command[1];
        int index = command[2];
        vector<int> temp;
        for (int i = begin - 1; i < end; ++i)
        {
            temp.push_back(array[i]);
        }
        sort(temp.begin(), temp.end());
        answer.push_back(temp[index - 1]);
    }
    return answer;
}

int main()
{

	return 0;
}