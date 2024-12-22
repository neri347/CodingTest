/// 동영상 재생기
/// https://school.programmers.co.kr/learn/courses/30/lessons/340213
#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {

	int endMinute = stoi(video_len.substr(0, 2));
	int endSecond = stoi(video_len.substr(3, 2));

	int opStartMinute = stoi(op_start.substr(0, 2));
	int opStartSecond = stoi(op_start.substr(3, 2));

	int opEndMinute = stoi(op_end.substr(0, 2));
	int opEndSecond = stoi(op_end.substr(3, 2));

	// 오프닝 구간이면 오프닝 끝나는 시간으로 변경
	int posMinute = stoi(pos.substr(0, 2));
	int posSecond = stoi(pos.substr(3, 2));
	if (((opStartMinute * 60 + opStartSecond) <= (posMinute * 60 + posSecond)) &&
		((posMinute * 60 + posSecond) <= (opEndMinute * 60 + opEndSecond)))
	{
		pos = op_end;
	}

	// 이동가능 구간 00:00~video_len
	for (const auto& command : commands)
	{
		int currentMinute = stoi(pos.substr(0, 2));
		int currentSecond = stoi(pos.substr(3, 2));

		if (command == "prev")
		{
			currentSecond -= 10;
			if (currentSecond < 0)
			{
				currentMinute -= 1;
				if (currentMinute < 0)
				{
					currentMinute = 0;
					currentSecond = 0;
				}
				else
				{
					currentSecond += 60;
				}
			}
		}
		else // command == "next"
		{
			currentSecond += 10;
			if (currentSecond > 60)
			{
				currentMinute += 1;
				currentSecond -= 60;
			}
			// 비디오 길이를 초과하는 시간이 되었다면 비디오 끝나는 시간으로 변경
			// 분은 같은데 초가 초과되었을 때와
			// 분이 더 클때            
			if ((currentMinute > endMinute) || ((currentMinute == endMinute) && (currentSecond > endSecond)))
			{
				currentMinute = endMinute;
				currentSecond = endSecond;
			}
		}

		// 빼거나 더한 값이 오프닝 구간인지 확인
		// 오프닝 구간이면 오프닝 끝나는 시간으로 변경
		if (((opStartMinute * 60 + opStartSecond) <= (currentMinute * 60 + currentSecond)) &&
			((currentMinute * 60 + currentSecond) <= (opEndMinute * 60 + opEndSecond)))
		{
			currentMinute = opEndMinute;
			currentSecond = opEndSecond;
		}
		// 최종 값 pos에 string으로 저장
		// 분이나 초가 한 자리면 앞에 0 붙여줌
		string resultMinute = "";
		string resultSecond = "";
		if (currentMinute < 10)
		{
			resultMinute = "0" + to_string(currentMinute);
		}
		else
		{
			resultMinute = to_string(currentMinute);
		}
		if (currentSecond < 10)
		{
			resultSecond = "0" + to_string(currentSecond);
		}
		else
		{
			resultSecond = to_string(currentSecond);
		}

		pos = resultMinute + ":" + resultSecond;
	}

	return pos;
}

int main()
{

	return 0;
}