#include <iostream>
#include <vector>
using namespace  std;

void fnInput(vector<int>& rvnTrg, vector<int>& rvnSch)
{
  int nSchCnt;
  cin >> nSchCnt;

  rvnSch.resize(nSchCnt + 1);
  for (int i = 0; i < nSchCnt; i++)
    cin >> rvnSch[i];

  int nTrgCnt;
  cin >> nTrgCnt;

  rvnTrg.resize(nTrgCnt);
  for (int i = 0; i < nTrgCnt; i++)
    cin >> rvnTrg[i];
}

void fnLinSch(const vector<int>& cnrvnTrg, vector<int>& rvnSch, int& rnFnd)
{
  int nMaxSiz = rvnSch.size() - 1;
  for (int nxTrg = 0; nxTrg < cnrvnTrg.size(); ++nxTrg)
  {
    rvnSch[nMaxSiz] = cnrvnTrg[nxTrg];
    int nxSch = 0;
    while (cnrvnTrg[nxTrg] !=rvnSch[nxSch])
      ++nxSch;
    if (nxSch != nMaxSiz)
      ++rnFnd;
  }
}

void fnResult(int nFnd)
{
  cout << nFnd << endl;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  vector<int> vnTrg, vnSch;
  int nFnd = 0;

  fnInput(vnTrg, vnSch);
  fnLinSch(vnTrg, vnSch, nFnd);
  fnResult(nFnd);

  return 0;
}

