#include <iostream>
#include <vector>
using namespace  std;

void fnInput(vector<int>& rvnPodr, vector<int>& rvnIodrSeq)
{
  int nMaxSiz;

  cin >> nMaxSiz;
  rvnPodr.resize(nMaxSiz + 1);
  rvnIodrSeq.resize(nMaxSiz + 1);

  for (int i = 1; i < nMaxSiz + 1; i++)
    cin >> rvnPodr[i];

  int nNode;
  for (int i = 1; i < nMaxSiz + 1; i++)
  {
    cin >> nNode;
    rvnIodrSeq[nNode] = i;
  }
}

void fnPostOrder(const vector<int>& cnrvnPodr, const vector<int>& cnrvnIodrSeq, int nLeft, int nRight)
{
  static int stnx = 1;
  static int stnPrt = 0;

  if (nLeft == nRight) return;

  int nNode = cnrvnPodr[stnx++];
  int nMid = cnrvnIodrSeq[nNode];

  fnPostOrder(cnrvnPodr, cnrvnIodrSeq, nLeft, nMid);
  fnPostOrder(cnrvnPodr, cnrvnIodrSeq, nMid + 1, nRight);

  if (stnPrt++) cout << " ";
  cout << nNode;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  vector<int> vnPodr, vnIodrSeq;
  fnInput(vnPodr, vnIodrSeq);

  fnPostOrder(vnPodr, vnIodrSeq, 1, vnPodr.size());
  cout << endl;
  return 0;
}

