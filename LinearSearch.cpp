#include <iostream>
#include <vector>
using namespace  std;

void fnInput(vector<int>& rvnTrg, vector<int>& rvnSch)
{
  int nTrgCnt;
  cin >> nTrgCnt;

  rvnTrg.resize(nTrgCnt + 1);
  for (int i = 0; i < nTrgCnt; i++)
    cin >> rvnTrg[i];

  int nSchCnt;
  cin >> nSchCnt;

  rvnSch.resize(nSchCnt);
  for (int i = 0; i < nSchCnt; i++)
    cin >> rvnSch[i];
}

void fnLinTrg(vector<int>& rvnTrg, const vector<int>& cnrvnSch, int& rnFnd)
{
  int nMaxSiz = rvnTrg.size() - 1;
  for (int nxSch = 0; nxSch < cnrvnSch.size(); ++nxSch)
  {
    rvnTrg[nMaxSiz] = cnrvnSch[nxSch];
    int nxTrg;
    for (nxTrg = 0; cnrvnSch[nxSch] != rvnTrg[nxTrg]; ++nxTrg);
    if (nxTrg != nMaxSiz)
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

  vector<int> vnSch, vnTrg;
  int nFnd = 0;

  fnInput(vnTrg, vnSch);
  fnLinTrg(vnTrg, vnSch, nFnd);
  fnResult(nFnd);

  return 0;
}

