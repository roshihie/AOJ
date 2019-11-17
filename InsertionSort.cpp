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

void fnTrace(const vector<int>& cnrvnSort)
{
  for (int i = 0; i < cnrvnSort.size(); i++)
  {
    if (i) cout << " ";
    cout << cnrvnSort[i];
  }
  cout << endl;
}

void fnInsertionSort(vector<int>& rvnSort)
{
  for (int nxing = 1; nxing < rvnSort.size(); nxing++)
  {
    int nTrg = rvnSort[nxing];
    int nxed = nxing - 1;

    while (nxed >= 0          &&
           nTrg  < rvnSort[nxed])
    {
      rvnSort[nxed + 1] = rvnSort[nxed];
      nxed--;
    }
    rvnSort[nxed + 1] = nTrg;
    fnTrace(rvnSort);
  }
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  vector<int> vnSort;

  fnInput(vnSort);
  fnTrace(vnSort);
  fnInsertionSort(vnSort);

  return 0;
}

