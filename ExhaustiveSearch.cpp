//*******************************************************************************
//       Exhaustive Search                 
//*******************************************************************************
//     < 処理概要 >
//       Exhaustive Search を漸化式を使用して実装する。
//*******************************************************************************
#include <iostream>
#include <vector>
using namespace  std;

void fnInput(vector<int>& rvnElm, vector<int>& rvnTrg )
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

void fnDPtblMake(vector<vector<int>>& rvvnDP, const vector<int>& cnrvnElm, int nMaxTrg)
{
  rvvnDP[cnrvnElm.size()][0] = 1;
  for (int j = 1; j <= nMaxTrg; j++)
    rvvnDP[cnrvnElm.size()][j] = 0;

  for (int i = cnrvnElm.size() - 1; i >= 0; i--)
    for (int j = 0; j <= nMaxTrg; j++)
      if (j < cnrvnElm[i])
        rvvnDP[i][j] = rvvnDP[i + 1][j];
      else
        rvvnDP[i][j] = rvvnDP[i + 1][j] || rvvnDP[i + 1][j - cnrvnElm[i]];
}

void fnExhSch(const vector<int>& cnrvnElm, const vector<int>& cnrvnTrg)
{
  vector<vector<int>> vvnDP(21, vector<int>(2001, -1));

  int nMaxTrg = cnrvnTrg[0]; 
  for (int i = 1; i < cnrvnTrg.size(); i++)
    nMaxTrg = max(nMaxTrg, cnrvnTrg[i]);

  fnDPtblMake(vvnDP, cnrvnElm, nMaxTrg);

  for (int i = 0; i < cnrvnTrg.size(); i++)
    if (vvnDP[0][cnrvnTrg[i]])
      cout << "yes" << endl;
    else
      cout << "no" << endl;
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

