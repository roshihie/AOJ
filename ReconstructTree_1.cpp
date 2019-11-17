#include <iostream>
#include <vector>
using namespace  std;

const int END = -1;
struct StNod
{
  int m_nParnt;
  int m_nLeft;
  int m_nRigt;

  StNod() :
     m_nParnt(END), m_nLeft(END), m_nRigt(END)
  { }
};

enum EnDir
{
  D_Left,
  D_Right,
};

void fnInput(vector<int>& rvnPodr, vector<int>& rvnIodrSeq)
{
  int nMaxSiz;

  cin >> nMaxSiz;
  rvnPodr.resize(nMaxSiz);
  rvnIodrSeq.resize(nMaxSiz + 1);

  for (int i = 0; i < nMaxSiz; i++)
    cin >> rvnPodr[i];

  int nNode;
  for (int i = 1; i < nMaxSiz + 1; i++)
  {
    cin >> nNode;
    rvnIodrSeq[nNode] = i;
  }
}

void fnStructTree(const vector<int>& cnrvnPodr, const vector<int>& cnrvnIodrSeq, vector<StNod>& rvoNod)
{
  for (int i = 1; i < cnrvnPodr.size(); i++)
  {
    int nParnt = END;
    int nx = cnrvnPodr[0];
    EnDir enDir;
    while (nx != END)
    {
      nParnt = nx;
      if (cnrvnIodrSeq[ cnrvnPodr[i] ] < cnrvnIodrSeq[nx])
      {
        nx = rvoNod[nx].m_nLeft;
        enDir = D_Left;
      }
      else
      {
        nx = rvoNod[nx].m_nRigt;
        enDir = D_Right;
      }
    }

    rvoNod[ cnrvnPodr[i] ].m_nParnt = nParnt;
    if (enDir == D_Left)
      rvoNod[nParnt].m_nLeft = cnrvnPodr[i];
    else
      rvoNod[nParnt].m_nRigt = cnrvnPodr[i];
  }
}

void fnPostOrder(const vector<StNod>& cnrvoNod, int nx)
{
  static int stnPrt = 0;
  if (nx == END)  return;

  fnPostOrder(cnrvoNod, cnrvoNod[nx].m_nLeft);
  fnPostOrder(cnrvoNod, cnrvoNod[nx].m_nRigt);

  if (stnPrt++) cout << " ";
  cout << nx;
}

void fnResult(const vector<StNod>& cnrvoNod)
{
  int nx = 1;
  while (cnrvoNod[nx].m_nParnt != END)
    nx = cnrvoNod[nx].m_nParnt;

  fnPostOrder(cnrvoNod, nx);
  cout << endl;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  vector<int> vnPodr, vnIodrSeq;
  fnInput(vnPodr, vnIodrSeq);

  StNod oNod;
  vector<StNod> voNod(vnIodrSeq.size(), oNod);
  fnStructTree(vnPodr, vnIodrSeq, voNod);
  
  fnResult(voNod);
  return 0;
}

