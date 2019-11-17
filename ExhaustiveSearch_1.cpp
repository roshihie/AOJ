#include <iostream>
#include <vector>
using namespace  std;

void fnInput(vector<int>& rvnElm, vector<int>& rvnTrg)
{
  int nElmCnt, nTrgCnt;
  cin >> nElmCnt;

  rvnElm.resize(nElmCnt);
  for (int i = 0; i < nElmCnt; i++)
    cin >> rvnElm[i];

  cin >> nTrgCnt;

  rvnTrg.resize(nTrgCnt);
  for (int i = 0; i < nTrgCnt; i++)
    cin >> rvnTrg[i];
}

int fnRcsSch(int nPos, int nTrg, const vector<int>& cnrvnElm, vector<vector<int>>& rvvnDP)
{
  if (!nTrg)                    return 1;
  if (nPos == cnrvnElm.size())  return 0;
  if (nTrg < 0)                 return 0;
  if (rvvnDP[nPos][nTrg] != -1) return rvvnDP[nPos][nTrg];

  if (fnRcsSch(nPos + 1, nTrg, cnrvnElm, rvvnDP))
    return (rvvnDP[nPos][nTrg] = 1);
  else if (fnRcsSch(nPos + 1, nTrg - cnrvnElm[nPos], cnrvnElm, rvvnDP))
    return (rvvnDP[nPos][nTrg] = 1);
  else
    return (rvvnDP[nPos][nTrg] = 0);
}

void fnExhSch(const vector<int>& cnrvnElm, const vector<int>& cnrvnTrg)
{
  vector<vector<int>> vvnDP(21, vector<int>(2001, -1));
  
  for (int i = 0; i < cnrvnTrg.size(); i++)
  {
    int nTrg = cnrvnTrg[i];

    if (fnRcsSch(0, nTrg, cnrvnElm, vvnDP))
      cout << "yes" << endl;
    else
      cout << "no" << endl;
  }
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  vector<int> vnElm, vnTrg;

  fnInput(vnElm, vnTrg);
  fnExhSch(vnElm, vnTrg);

  return 0;
}

