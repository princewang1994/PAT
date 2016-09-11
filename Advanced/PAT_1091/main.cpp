#include <iostream>
#include <queue>

using namespace std;
int stroke[61][1287][129];
int vst[61][1287][129];
int dir[][3] = {{0, 0, -1}, {0, 0, 1}, {0, -1, 0}, {0, 1, 0}, {-1, 0, 0}, {1, 0, 0}};
int cnt = 0;
int one = 0;
int M, N, L, T;

void bfs(int ii, int jj, int kk)
{
    if(stroke[ii][jj][kk] == 0 || vst[ii][jj][kk])
        return;
    queue<int> qx, qy, qz;
    qx.push(ii);
    qy.push(jj);
    qz.push(kk);
    vst[ii][jj][kk] = 1;

    while(!qx.empty())
    {
        int i = qx.front();
        int j = qy.front();
        int k = qz.front();
        cnt++;

        qx.pop(), qy.pop(), qz.pop();

        for(int m = 0; m < 6; m++)
        {
            int x = i + dir[m][0];
            int y = j + dir[m][1];
            int z = k + dir[m][2];

            if(x < 0 || x >= L) continue;
            if(y < 0 || y >= M) continue;
            if(z < 0 || z >= N) continue;

            if(vst[x][y][z] || stroke[x][y][z] == 0)
                continue;

            qx.push(x);
            qy.push(y);
            qz.push(z);
            vst[x][y][z] = 1;
        }
    }
}
int main()
{

    cin >> M >> N >> L >> T;
    for(int i = 0 ; i < L; i++)
    {
        for(int j = 0; j < M; j++)
        {
            for(int k = 0; k < N; k++)
            {
                cin >> stroke[i][j][k];
                vst[i][j][k] = 0;
            }
        }
    }

    for(int i = 0 ; i < L; i++)
    {
        for(int j = 0; j < M; j++)
        {
            for(int k = 0; k < N; k++)
            {
                int tmp = cnt;
                bfs(i, j, k);
                int diff = cnt - tmp;
                if(diff >= T)
                {
                    one += diff;
                }
            }
        }
    }

    cout << one << endl;

    return 0;
}
