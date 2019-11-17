#include <iostream>
#include <vector>
using namespace  std;

void fnInput(vector<int>& rvnTrg, vector<int>& rvnSch)
{
  int nTrgCnt;
  cin >> nTrgCnt;

  rvnTrg.resize(nTrgCnt);
  for (int i = 0; i < nTrgCnt; i++)
    cin >> rvnTrg[i];

  int nSchCnt;
  cin >> nSchCnt;

  rvnSch.resize(nSchCnt);
  for (int i = 0; i < nSchCnt; i++)
    cin >> rvnSch[i];
}

void fnBinSch(const vector<int>& cnrvnTrg, const vector<int>& cnrvnSch, int& rnFnd)
{
  for (int i = 0; i < cnrvnSch.size(); i++)
  {
    int nLow  = 0;
    int nHigh = cnrvnTrg.size();
    while (nLow < nHigh)
    {
      int nMid = (nLow + nHigh) / 2;
      if (cnrvnSch[i] == cnrvnTrg[nMid])
      {
        rnFnd++;
        break;
      }
      else if (cnrvnSch[i] < cnrvnTrg[nMid])
        nHigh = nMid;
      else
        nLow  = nMid + 1;
    }
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
  fnBinSch(vnTrg, vnSch, nFnd);
  fnResult(nFnd);

  return 0;
}

