#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> count(100005, 0);
    vector<int> answer;
    for (auto &i: arr) count[i]++;
    for (int i = 0; i < 100005; i++) if (count[i] == 1) answer.push_back(i);
    if (answer.size() == 0) answer.push_back(-1);
    return answer;
}