#include <iostream>
#include <vector>
using namespace  std;

void fnInput(int& rnTrkSiz, vector<int>& rvnLod)
{
  int nLodSiz;
  cin >> nLodSiz >> rnTrkSiz;

  rvnLod.resize(nLodSiz);
  for (int i = 0; i < nLodSiz; i++)
    cin >> rvnLod[i];
}

int fnSimuAlloc(const vector<int>& cnrvnLod, int nTrkSiz, int nLimLod)
{
  int nCurLod;
  int nCntTrk = 0;

  for (int i = 0; i < cnrvnLod.size(); )
  {
    if (cnrvnLod[i] > nLimLod)  return 0;

    nCntTrk++;
    nCurLod = 0;
    while (i < cnrvnLod.size())
    {
      nCurLod += cnrvnLod[i];
      if (nCurLod > nLimLod)  break;

      i++;
    }
  }
  return (nCntTrk <= nTrkSiz);
}

void fnAlloc(const vector<int>& cnrvnLod, int nTrkSiz, int& rnMinLod)
{
  int nLow  = 0;
  int nHigh = 1000000000;

  while (nLow < nHigh)
  {
    int nLimLod = (nLow + nHigh) / 2;
    if (fnSimuAlloc(cnrvnLod, nTrkSiz, nLimLod))
    {
      rnMinLod = nLimLod;
      nHigh = nLimLod;
    }
    else
      nLow = nLimLod + 1;
  }
}

void fnReSult(int nMinLod)
{
  cout << nMinLod << endl;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int nTrkSiz, nMinLod = 0;
  vector<int> vnLod;

  fnInput(nTrkSiz, vnLod);
  fnAlloc(vnLod, nTrkSiz, nMinLod);
  fnReSult(nMinLod);

  return 0;
}

