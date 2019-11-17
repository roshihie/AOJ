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

void fnBubbleSort(vector<int>& rvnSort, int& rnSortCnt)
{
  int nxMax = rvnSort.size() - 1;
  int nxStop = 0;
  while (nxStop != nxMax)
  {
    int nxMin = nxMax;
    for (int i = nxMax; i > nxStop; i--)
    {
      if (rvnSort[i] < rvnSort[i - 1])
      {
        swap(rvnSort[i], rvnSort[i - 1]);
        rnSortCnt++;
        nxMin = i;
      }
    }
    nxStop = nxMin;
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
  fnBubbleSort(vnSort, nSortCnt);
  fnOutput(vnSort, nSortCnt);

  return 0;
}

