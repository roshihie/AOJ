#include <iostream>
#include <vector>
using namespace  std;

void fnMaxProfit(const vector<int>& cnrvnValue, int& rnMinval, int& rnMaxProfit)
{
  for (int i = 1; i < cnrvnValue.size(); i++)
  {
    rnMinval = min(rnMinval, cnrvnValue[i-1]);
    int nMaxProfit = cnrvnValue[i] - rnMinval; 
    rnMaxProfit = max(rnMaxProfit, nMaxProfit);
  }
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  vector<int> vnVal;
  int nMaxSiz;
  
  cin >> nMaxSiz;
  for (int i = 0; i < nMaxSiz; i++)
  {
    int nVal;
    cin >> nVal;
    vnVal.push_back(nVal);
  }

  int nMinVal = vnVal[0];
  int nMaxPft = -1000000000;
  fnMaxProfit(vnVal, nMinVal, nMaxPft);
  cout << nMaxPft << endl;

  return 0;
}

