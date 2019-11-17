#include <iostream>
#include <queue>
#include <string>
using namespace  std;

typedef pair<string, int> PAIR;

void fnInput(int& rnQtm, queue<PAIR>& rqPPrc)
{
  int nMaxProc;
  cin >> nMaxProc >> rnQtm;
  
  for (int i = 0; i < nMaxProc; i++)
  {
    string sPrcNam;
    int nPrcTim;
    cin >> sPrcNam >> nPrcTim;
    rqPPrc.push(PAIR(sPrcNam, nPrcTim));
  }
}

void fnSchedule(int nQtm, queue<PAIR>& rqPPrc)
{
  int nSumTim = 0;
  while (rqPPrc.size())
  {
    PAIR PProcess = rqPPrc.front(); rqPPrc.pop(); 
    if (PProcess.second > nQtm)
    {
      PProcess.second -= nQtm;
      rqPPrc.push(PProcess);
      nSumTim += nQtm;
    }
    else
    {
      nSumTim += PProcess.second;
      cout << PProcess.first << " " << nSumTim << endl;
    }
  }
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int nQtm;
  queue<PAIR> qPPrc;
  
  fnInput(nQtm, qPPrc);
  fnSchedule(nQtm, qPPrc);

  return 0;
}

