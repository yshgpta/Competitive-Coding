#include <iostream>
#include <ctime>

using namespace std;

int R, C, D;

bool av[305][305];
int ans[305][305][305][2] = { };

int main()
{
        cin >> R >> C >> D;

        for(int i = 1; i <= R; ++i)
        {
                for(int j = 1; j <= C; ++j)
                {
                        cin >> av[i][j];
                }
        }

        for(int d = 0; d <= D; d++)
        {
                ans[R][C][d][0] = ans[R][C][d][1] = 1;
        }

        for(int r = R; r > 0; r--)
        {
                for(int c = C; c > 0; c--)
                {
                        if(r == R && c == C) continue;
                        if(av[r][c])
                        {
                                ans[r][c][D][0] = ans[r + 1][c][1][1];
                                ans[r][c][D][1] = ans[r][c + 1][1][0];
                                for(int d = 0; d < D; d++)
                                {
                                        ans[r][c][d][0] = (ans[r][c + 1][d + 1][0] + ans[r + 1][c][1][1]) % 20011;
                                        ans[r][c][d][1] = (ans[r][c + 1][1][0] + ans[r + 1][c][d + 1][1]) % 20011;
                                }
                        }
                }
        }

        cout << ans[1][1][0][0];
}
