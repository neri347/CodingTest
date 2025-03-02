/// ���� ��� ���
/// https://school.programmers.co.kr/learn/courses/30/lessons/92341
/// ������ ����� ���� �ʾƼ� �׽�Ʈ ���̽��� Ʋ�Ȱ�,
/// �������� ���� �����ӿ��� �ð��� �������� ���� �ɷȴ�.
/// ������ �׽�Ʈ ���̽��� �� �о�鼭 ���� �䱸������ �� �ľ��ؾ� �Ѵ�.
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <sstream>
#include <cmath>
#include <iostream>

using namespace std;

int defaultTime;
int defaultFee;
int additionalTime;
int additionalFee;

int CalcTime(const string& str)
{
    int h = stoi(str.substr(0, 2));
    int m = stoi(str.substr(3, 2));
    return h * 60 + m;
}

int CalcFee(int totalTime)
{
    int totalFee = defaultFee;
    if (totalTime > defaultTime)
    {
        int addTime = totalTime - defaultTime;
        int v = static_cast<int>(ceil(static_cast<float>(addTime) / additionalTime));
        totalFee += v * additionalFee;
    }
    return totalFee;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;

    defaultTime = fees[0];
    defaultFee = fees[1];
    additionalTime = fees[2];
    additionalFee = fees[3];

    unordered_map<int, pair<string, string>> infos; // carNum, in, out
    unordered_map<int, int> timeInfos;
    map<int, int> feeInfos;

    for (auto& record : records)
    {
        stringstream ss(record);
        string time, num, state;
        ss >> time >> num >> state;
        int n = stoi(num);
        if (state == "IN")
        {
            infos[n] = { time, "23:59" };
        }
        else
        {
            infos[n].second = time;
            int startTime = CalcTime(infos[n].first);
            int endTime = CalcTime(infos[n].second);
            timeInfos[n] += endTime - startTime;
            infos.erase(n);
        }
    }

    for (auto& p : infos) // out ��� ���� ���� ���
    {
        cout << p.first << " " << p.second.first << " " << p.second.second << endl;
        int startTime = CalcTime(p.second.first);
        int endTime = CalcTime(p.second.second);
        timeInfos[p.first] += endTime - startTime;
    }

    for (auto& p : timeInfos)
    {
        int fee = CalcFee(p.second);
        feeInfos[p.first] += fee;
    }

    for (auto& p : feeInfos)
    {
        answer.push_back(p.second);
    }

    return answer;
}

int main()
{

	return 0;
}