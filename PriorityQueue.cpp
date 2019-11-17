#include <iostream>
#include <vector>
using namespace  std;

void fnMaxHeapifyUp(vector<int>& rvnPrtyHeap, int nx)
{
  int nParnt = nx / 2;
  int nLrge = nx;

  if (nParnt > 0  &&
      rvnPrtyHeap[nParnt] < rvnPrtyHeap[nLrge])
  {
    swap(rvnPrtyHeap[nParnt], rvnPrtyHeap[nLrge]);
    fnMaxHeapifyUp(rvnPrtyHeap, nParnt);
  }
}

void fnMaxHeapifyDown(vector<int>& rvnPrtyHeap, int nx)
{
  int nLeft = nx * 2;
  int nRigt = nLeft + 1;
  int nLrge = nx;

  if (nLeft < rvnPrtyHeap.size()  &&
      rvnPrtyHeap[nLrge] < rvnPrtyHeap[nLeft])  
    nLrge = nLeft;
  if (nRigt < rvnPrtyHeap.size()  &&
      rvnPrtyHeap[nLrge] < rvnPrtyHeap[nRigt])
    nLrge = nRigt;

  if (nx != nLrge)
  {
    swap(rvnPrtyHeap[nx], rvnPrtyHeap[nLrge]);
    fnMaxHeapifyDown(rvnPrtyHeap, nLrge);
  }
}

void fnPriorityQueue(vector<int>& rvnPrtyHeap)
{
  rvnPrtyHeap.push_back(-1);
  string sCmd;
  while (cin >> sCmd && sCmd != "end")
  {
    if (sCmd[0] == 'i')
    {
      int nNo;
      cin >> nNo;
      rvnPrtyHeap.push_back(nNo);
      int nx = rvnPrtyHeap.size() - 1;
      fnMaxHeapifyUp(rvnPrtyHeap, nx);
    }
    else if (sCmd[0] == 'e')
    {
      cout << rvnPrtyHeap[1] << endl;
      rvnPrtyHeap[1] = rvnPrtyHeap.back();
      rvnPrtyHeap.pop_back();
      if (rvnPrtyHeap.size() > 1)
        fnMaxHeapifyDown(rvnPrtyHeap, 1);
    }
    else;
  }
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  vector<int> vnPrtyHeap; 

  fnPriorityQueue(vnPrtyHeap);
  return 0;
}

