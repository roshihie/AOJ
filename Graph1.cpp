#include <iostream>
#include <vector>
using namespace  std;

void fnInput(vector<vector<int>>& rvvnAdjcy)
{
  int nxSiz;
  cin >> nxSiz;

  rvvnAdjcy.resize(nxSiz + 1, vector<int>(nxSiz + 1, 0));
  for (int i = 0; i < nxSiz; i++)
  {
    int nx, nySiz;
    cin >> nx >> nySiz;
    for (int j = 0; j < nySiz; j++)
    {
      int ny;
      cin >> ny;
      rvvnAdjcy[nx][ny] = 1;
    }
  }
}

void fnResult(const vector<vector<int>>& cnrvvnAdjcy)
{
  for (int i = 1; i < cnrvvnAdjcy.size(); i++)
  {
    for (int j = 1; j < cnrvvnAdjcy[i].size(); j++)
    {
      if (j != 1) cout << " ";
      cout << cnrvvnAdjcy[i][j];
    }
    cout << endl;
  }
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  vector<vector<int>> vvnAdjcy;

  fnInput(vvnAdjcy);
  fnResult(vvnAdjcy);

  return 0;
}

