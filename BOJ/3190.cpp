#include <iostream>
#include <queue>
#include <vector>
 
using namespace std;
 
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int board[100][100] = {{2}};
    queue<pair<int, int>> snake;
    queue<pair<int, char>> direction;
    int n, k;
    cin >> n >> k;
 
    for(int i = 0, x, y; i < k; i++)
    {
        cin >> y >> x;
        board[y - 1][x - 1] = 2;
    }
 
    int l;
    cin >> l;
 
    for(int i = 0; i < l; i++)
    {
        pair<int, char> d;
        cin >> d.first;
        cin >> d.second;
        direction.push(d);
    }
     
    for(int i = 0, x = 0, y = 0, d = 0; i <= 10000; i++)
    {
        if(x < 0 || x >= n || y < 0 || y >= n)
        {
            cout << i;
            return 0;
        }
 
        if(board[y][x] == 0)
        {
            board[snake.front().first][snake.front().second] = 0;
            snake.pop();
        }
         
        if(board[y][x] == 1)
        {
            cout << i;
            return 0;
        }
         
        board[y][x] = 1;
        pair<int, int> s;
        s.first = y;
        s.second = x;
        snake.push(s);
 
        if(i == direction.front().first)
        {
            if(direction.front().second == 'L')
                d--;
             
            else
                d++;
 
            if(d == 4)
                d = 0;
 
            if(d == -1)
                d = 3;
 
            direction.pop();
        }
 
        switch(d)
        {
            case 0: // right
                x++;
                break;
             
            case 1: // down
                y++;
                break;
             
            case 2: // left
                x--;
                break;
             
            case 3: // up
                y--;
                break;
        }
    }
}
