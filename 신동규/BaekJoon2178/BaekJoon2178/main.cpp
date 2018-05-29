#include<iostream>
#include<string>
#include<queue>
#include <vector>// 사용법좀 알아보자

using namespace std;

class xy{
public: int x,y;
};

int main() {
    
    int n, m;
    
    char map[100][100];//전체 미로를 받아올 이차
    int sum[100][100];
    bool check[100][100];
    int dir[4][2] = { { -1,0 },{ 1,0 },{ 0,-1 },{ 0,1 } };
    queue<xy> q;

    
    cin >> n >> m;
    string s = "";
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < m; j++)
            map[i][j] = s.at(j);// string 값이므로 at 함수로 인덱스의 char 값을 가져온다!
        
    }
   
    q.push({0,0});
    check[0][0] = true;// 지나온 길을 체크
    sum[0][0] = 1;
    
    while (!q.empty()) {
        
        int x = q.front().x;
        int y = q.front().y;
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || check[nx][ny] || map[nx][ny] == '0'){
                //판별  다음xy 좌표가 0보다 작거나 받아온 맵 크기보다 클때, 이미 다녀온 곳일때, 가지못하는곳일때 다음 for문으로 진행한다.
                continue;
                
            }
            q.push({nx, ny});
            check[nx][ny] = true;
            sum[nx][ny] = sum[x][y] + 1;
        }
    }
    cout << sum[n - 1][m - 1] << endl;
    return 0;
}



