#include <iostream>
#include <vector>
#include <string>
using namespace  std;

void fnInput(vector<string>& rvsSortBbl, vector<string>& rvsSortSel)
{
  int nMaxSiz;
  cin >> nMaxSiz;
  
  rvsSortBbl.resize(nMaxSiz);
  rvsSortSel.resize(nMaxSiz);
  for (int i = 0; i < nMaxSiz; i++)
  {
    cin >> rvsSortBbl[i];
    rvsSortSel[i] = rvsSortBbl[i];
  }
}

void fnBubbleSort(vector<string>& rvsSortBbl)
{
  int nxMax = rvsSortBbl.size() - 1;
  int nxStop = 0;
  while (nxStop != nxMax)
  {
    int nxMin = nxMax;
    for (int i = nxMax; i > nxStop; i--)
    {
      if (rvsSortBbl[i].at(1) < rvsSortBbl[i - 1].at(1))
      {
        swap(rvsSortBbl[i], rvsSortBbl[i - 1]);
        nxMin = i;
      }
    }
    nxStop = nxMin;
  }
}

void fnOutputBbl(const vector<string>& cnrvsSortBbl)
{
  for (int i = 0; i < cnrvsSortBbl.size(); i++)
  {
    if (i) cout << " ";
    cout << cnrvsSortBbl[i];
  }
  cout << endl;
  cout << "Stable" << endl;
}

void fnSelectionSort(vector<string>& rvsSortSel)
{
  for (int nxed = 0; nxed < rvsSortSel.size() - 1; nxed++)
  {
    int nxMin = nxed;
    bool bSwap = false;
    for (int nxing = nxed + 1; nxing < rvsSortSel.size(); nxing++)
    {
      if (rvsSortSel[nxing].at(1) < rvsSortSel[nxMin].at(1))
      {
        nxMin = nxing;
        bSwap = true;
      }
    }
    if (bSwap)
      swap(rvsSortSel[nxed], rvsSortSel[nxMin]);
  }
}

void fnOutputSel(const vector<string>& cnrvsSortSel, const vector<string>& cnrvsSortBbl)
{
  string sSortEnd = "Stable";

  for (int i = 0; i < cnrvsSortSel.size(); i++)
  {
    if (i) cout << " ";
    cout << cnrvsSortSel[i];
    
    if (cnrvsSortSel[i] != cnrvsSortBbl[i]) sSortEnd = "Not stable";
  }
  cout << endl;
  cout << sSortEnd << endl;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  vector<string> vsSortBbl, vsSortSel;

  fnInput(vsSortBbl, vsSortSel);
  fnBubbleSort(vsSortBbl);
  fnOutputBbl(vsSortBbl); 

  fnSelectionSort(vsSortSel);
  fnOutputSel(vsSortSel, vsSortBbl);

  return 0;
}

