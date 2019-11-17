#include <iostream>
#include <string>
#include <vector>
using namespace  std;

struct StCrd
{
  string m_sMrk;
  int    m_nNum;
  int    m_nSeq;
};

void fnInput(vector<StCrd>& rvoCrd)
{
  int nMaxSiz;
  cin >> nMaxSiz;

  rvoCrd.resize(nMaxSiz);
  for (int i = 0; i < nMaxSiz; i++)
  {
    cin >> rvoCrd[i].m_sMrk >> rvoCrd[i].m_nNum;
    rvoCrd[i].m_nSeq = i + 1;
  }
}

int fnPartition(vector<StCrd>& rvoCrd, int nFront, int nBack)
{
  int nMid = nFront;

  for (int i = nFront; i < nBack; i++)
    if (rvoCrd[i].m_nNum <= rvoCrd[nBack].m_nNum)
      swap(rvoCrd[nMid++], rvoCrd[i]);

  swap(rvoCrd[nMid], rvoCrd[nBack]);
  return nMid;
}

void fnQuickSort(vector<StCrd>& rvoCrd, int nFront, int nBack)
{
  if (nFront < nBack)
  {
    int nMid = fnPartition(rvoCrd, nFront, nBack);
    fnQuickSort(rvoCrd, nFront, nMid - 1);
    fnQuickSort(rvoCrd, nMid + 1, nBack);
  }
}

void fnResult(const vector<StCrd>& cnrvoCrd)
{
  bool bStable = true;
  for (int i = 0; i < cnrvoCrd.size();    )
  {
    int j = i;
    while (cnrvoCrd[i].m_nNum == cnrvoCrd[++j].m_nNum)
      if (cnrvoCrd[i].m_nSeq < cnrvoCrd[j].m_nSeq);
      else
      {
        bStable = false; 
        goto LOOP_END;
      }

    i = j;
  }

LOOP_END:
  if (bStable)  cout << "Stable" << endl;
  else          cout << "Not stable" << endl;

  for (int i = 0; i < cnrvoCrd.size(); i++)
    cout << cnrvoCrd[i].m_sMrk << " " << cnrvoCrd[i].m_nNum << endl;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  vector<StCrd> voCrd;

  fnInput(voCrd);
  fnQuickSort(voCrd, 0, voCrd.size() - 1);
  fnResult(voCrd);

  return 0;
}

