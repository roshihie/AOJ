#include <iostream>
#include <climits>
#include <vector>
using namespace  std;

void fnInput(vector<int>& rvnMtrx)
{
  int nMaxSiz;
  cin >> nMaxSiz;
  rvnMtrx.resize(nMaxSiz + 1);

  for (int i = 0; i < nMaxSiz; ++i)
    cin >> rvnMtrx[i] >> rvnMtrx[i + 1];
}

int fnMtrxChainMultpl(vector<vector<int>>& rvvnDetDP, const vector<int>& cnrvnMtrx)
{
  const int nMAXSIZ = cnrvnMtrx.size() - 1;
  for (int i = 1; i <= nMAXSIZ; ++i)  rvvnDetDP[i][i] = 0;

  for (int nDif = 1; nDif <= nMAXSIZ - 1; ++nDif)
    for (int nFrt = 1; nFrt <= nMAXSIZ - nDif; ++nFrt)
    {
      int nBak = nFrt + nDif;
      for (int nx = nFrt; nx <= nBak - 1; ++nx)
        rvvnDetDP[nFrt][nBak] =
          min(rvvnDetDP[nFrt][nBak],
              rvvnDetDP[nFrt][nx] + rvvnDetDP[nx + 1][nBak] 
                                  + cnrvnMtrx[nFrt - 1] * cnrvnMtrx[nx] * cnrvnMtrx[nBak]);
    }
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  vector<vector<int>> vvnDetDP; 
  vector<int> vnMtrx;

  fnInput(vnMtrx);
  vvnDetDP.resize(vnMtrx.size(), vector<int>(vnMtrx.size(), INT_MAX));

  fnMtrxChainMultpl(vvnDetDP, vnMtrx);
  cout << vvnDetDP[1][vnMtrx.size() - 1] << endl;
  return 0;
}

