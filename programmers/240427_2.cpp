#include <string>
#include <vector>
using namespace std;

long long solution(string block, int pos) {
    long long answer = 0;
    pos -= 1;
    char left_ch = '>', right_ch = '<';
    int left = pos - 1, right = pos + 1;
    int len = block.length();
    for (; left >= 0 && block[left] != left_ch; left--);
    for (; right < len && block[right] != right_ch; right++);
    while (pos >= 0 && pos < len) {
        if (block[pos] == left_ch) {
            answer += right - pos;
            pos += right - pos;
            right++;
            for (; right < len && block[right] != right_ch; right++);
        }
        else {
            answer += pos - left;
            pos -= pos - left;
            for (; left >= 0 && block[left] != left_ch; left--);
        }
    }
    return answer;
}