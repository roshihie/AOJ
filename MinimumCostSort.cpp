#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <climits>
using namespace  std;

struct StCst
{
  int m_nNo;
  int m_nSeq;
  bool m_bDone;

  static bool AsdNo(const StCst& cnroLeft, const StCst& cnroRight) 
  { return cnroLeft.m_nNo < cnroRight.m_nNo; }
};

void fnInput(vector<StCst>& rvoSort)
{
  int nMaxSiz, nCnt = 0;
  cin >> nMaxSiz;

  rvoSort.resize(nMaxSiz);
  for (int i = 0; i < nMaxSiz; i++)
  {
    cin >> rvoSort[i].m_nNo;
    rvoSort[i].m_nSeq = nCnt++;
  }
}

void fnMinCostSort(vector<StCst>& rvoSort, int& rnSwpCnt)
{
  sort(begin(rvoSort), end(rvoSort), StCst::AsdNo);
  int nMinNo = rvoSort[0].m_nNo;

  int nCost;
  for (int i = 0; i < rvoSort.size(); i++)
  {
    if (rvoSort[i].m_bDone)  continue;

    int nTotal  = rvoSort[i].m_nNo;
    int nCurMin = rvoSort[i].m_nNo; 
    int nCurSize = 1;
    rvoSort[i].m_bDone = true;

    int j = rvoSort[i].m_nSeq;
    while  (rvoSort[j].m_nNo != rvoSort[i].m_nNo)
    {
      nTotal += rvoSort[j].m_nNo;
      nCurSize++;
      rvoSort[j].m_bDone = true;
      j = rvoSort[j].m_nSeq;
    }

    if (nCurSize == 1)
        nCost = 0;
    else
        nCost = min(nTotal + (nCurSize - 2) * nCurMin, 
                    nTotal + nCurMin + (nCurSize + 1) * nMinNo);
    rnSwpCnt += nCost;
  }
}

void fnResult(int nSwpCnt)
{
  cout << nSwpCnt << endl;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  vector<StCst> voSort;

  fnInput(voSort);

  int nSwpCnt = 0;
  fnMinCostSort(voSort, nSwpCnt);

  fnResult(nSwpCnt);
  return 0;
}

