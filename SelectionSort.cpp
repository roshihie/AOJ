#include <iostream>
#include <vector>
using namespace  std;

void fnInput(vector<int>& rvnSort)
{
  int nMaxSiz;
  cin >> nMaxSiz;
  
  rvnSort.resize(nMaxSiz);
  for (int i = 0; i < nMaxSiz; i++)
    cin >> rvnSort[i];
}

void fnSelectionSort(vector<int>& rvnSort, int& rnSortCnt)
{
  for (int nxed = 0; nxed < rvnSort.size() - 1; nxed++)
  {
    int nxMin = nxed;
    bool bSwap = false;

    for (int nxing = nxed + 1; nxing < rvnSort.size(); nxing++)
    {
      if (rvnSort[nxing] < rvnSort[nxMin])
      {
        nxMin = nxing;
        bSwap = true;
      }
    }
    if (bSwap)
    {
      swap(rvnSort[nxed], rvnSort[nxMin]);
      rnSortCnt++;
    }
  }
}

void fnOutput(const vector<int>& cnrvnSort, int nSortCnt)
{
  for (int i = 0; i < cnrvnSort.size(); i++)
  {
    if (i) cout << " ";
    cout << cnrvnSort[i];
  }
  cout << endl;
  cout << nSortCnt << endl;
}

int main()
{ 
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int nSortCnt = 0;
  vector<int> vnSort;

  fnInput(vnSort);
  fnSelectionSort(vnSort, nSortCnt);
  fnOutput(vnSort, nSortCnt);

  return 0;
}

