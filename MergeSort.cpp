#include <iostream>
#include <vector>
#include <climits>
using namespace  std;

void fnInput(vector<int>& rvnSort)
{
  int nMaxSiz;
  cin >> nMaxSiz;

  rvnSort.resize(nMaxSiz);
  for (int i = 0; i < nMaxSiz; i++)
    cin >> rvnSort[i];
}

void fnMerge(vector<int>& rvnSort, int& rnSortCnt, int nLeft, int nMid, int nRight)
{
  vector<int> vnLeft, vnRight;
  int nLeftSiz = nMid - nLeft;
  int nRightSiz = nRight - nMid;

  vnLeft.resize(nLeftSiz + 1);
  vnRight.resize(nRightSiz + 1);

  for (int i = 0; i < nLeftSiz; i++)
    vnLeft[i] = rvnSort[nLeft + i];
  for (int i = 0; i < nRightSiz; i++)
    vnRight[i] = rvnSort[nMid + i];

  vnLeft[nLeftSiz] = INT_MAX;
  vnRight[nRightSiz] = INT_MAX;
  int i = 0, j = 0;

  for (int n = nLeft; n < nRight; n++)
  {
    if (vnLeft[i] <= vnRight[j])
      rvnSort[n] = vnLeft[i++];
    else
      rvnSort[n] = vnRight[j++];
    rnSortCnt++;
  }
}

void fnMergeSort(vector<int>& rvnSort, int& rnSortCnt, int nLeft, int nRight)
{
  if (nLeft + 1 < nRight)
  {
    int nMid = (nLeft + nRight) / 2;
    fnMergeSort(rvnSort, rnSortCnt, nLeft, nMid);
    fnMergeSort(rvnSort, rnSortCnt, nMid, nRight);
    fnMerge(rvnSort, rnSortCnt, nLeft, nMid, nRight);
  }
}

void fnResult(const vector<int>& cnrvnSort, int nSortCnt)
{
  for (int i = 0; i < cnrvnSort.size(); i++)
  {
    if (i != 0)  cout << " ";
    cout << cnrvnSort[i];
  }
  cout << endl;
  cout << nSortCnt << endl;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  vector<int> vnSort;

  fnInput(vnSort);

  int nLeft = 0;
  int nRight = vnSort.size();
  int nSortCnt = 0;
  fnMergeSort(vnSort, nSortCnt, nLeft, nRight);

  fnResult(vnSort, nSortCnt);

  return 0;
}

