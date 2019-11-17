#include <iostream>
#include <vector>
using namespace  std;

const int END = -1;
struct StNod
{
  int m_nDept;
  int m_nHigh;
  int m_nParnt;
  int m_nLeft;
  int m_nRigt;

  StNod() :
    m_nDept(END), m_nHigh(END), m_nParnt(END), m_nLeft(END), m_nRigt(END)
  { }
};

void fnInput(vector<StNod>& rvoNod)
{
  StNod oNod;
  int nMaxSiz;

  cin >> nMaxSiz;
  rvoNod.resize(nMaxSiz, oNod);

  for (int i = 0; i < nMaxSiz; i++)
  {
    int nParnt, nLeft, nRigt;
    cin >> nParnt >> nLeft >> nRigt;

    rvoNod[nParnt].m_nLeft = nLeft;
    rvoNod[nParnt].m_nRigt = nRigt;
    if (nLeft != END)  rvoNod[nLeft].m_nParnt = nParnt;
    if (nRigt != END)  rvoNod[nRigt].m_nParnt = nParnt;
  }
}

void fnSetDepth(vector<StNod>& rvoNod, int nx, int nDept)
{
  rvoNod[nx].m_nDept = nDept;
  
  if (rvoNod[nx].m_nLeft != END)
    fnSetDepth(rvoNod, rvoNod[nx].m_nLeft, nDept + 1);

  if (rvoNod[nx].m_nRigt != END)
    fnSetDepth(rvoNod, rvoNod[nx].m_nRigt, nDept + 1);
}

int fnSetHight(vector<StNod>& rvoNod, int nx)
{
  int nLHigh = 0, nRHigh = 0;

  if (rvoNod[nx].m_nLeft != END)
    nLHigh = fnSetHight(rvoNod, rvoNod[nx].m_nLeft) + 1;
  if (rvoNod[nx].m_nRigt != END)
    nRHigh = fnSetHight(rvoNod, rvoNod[nx].m_nRigt) + 1;
  
  return rvoNod[nx].m_nHigh = max(nLHigh, nRHigh);
}

void fnBinTree(vector<StNod>& rvoNod)
{
  int nx = 0;
  while (rvoNod[nx].m_nParnt != END)
    nx = rvoNod[nx].m_nParnt;

  int nDept = 0;
  fnSetDepth(rvoNod, nx, nDept);
  fnSetHight(rvoNod, nx);
}

void fnResult(const vector<StNod>& cnrvoNod)
{
  for (int i = 0; i < cnrvoNod.size(); i++)
  {
    cout << "node " << i << ": parent = " << cnrvoNod[i].m_nParnt << ", sibling = ";

    if (cnrvoNod[i].m_nParnt == END)  cout << END;
    else
    {
      int nx = cnrvoNod[i].m_nParnt;
      if (i == cnrvoNod[nx].m_nLeft)  cout << cnrvoNod[nx].m_nRigt;
      else                            cout << cnrvoNod[nx].m_nLeft;
    }
    
    cout << ", degree = ";
    int nCCnt = 0;
    if (cnrvoNod[i].m_nLeft != END)  nCCnt++;
    if (cnrvoNod[i].m_nRigt != END)  nCCnt++;
    cout << nCCnt << ", depth = " << cnrvoNod[i].m_nDept << ", height = " << cnrvoNod[i].m_nHigh;

    if (!cnrvoNod[i].m_nDept)       cout << ", root";
    else if (!cnrvoNod[i].m_nHigh)  cout << ", leaf";
    else                            cout << ", internal node";
    cout << endl;
  }
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  vector<StNod> voNod;

  fnInput(voNod);
  fnBinTree(voNod);
  fnResult(voNod);
  return 0;
}

