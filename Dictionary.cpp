#include <iostream>
#include <string>
#include <vector>
using namespace  std;

using llong = long long;
const int nARRYSIZ = 3000017;

llong fnStrToLL(string sKey)
{
  int nBase = 1;
  llong nKey = 0;
  for (int i = sKey.size() - 1; i >= 0; i--)
  {
    int nElm;
    switch (sKey[i])
    {
      case  'A': nElm = 1;
                 break;
      case  'C': nElm = 2;
                 break;
      case  'G': nElm = 3;
                 break;
      case  'T': nElm = 4;
                 break;
      default:   nElm = 0;
    }
    nKey += nBase * nElm;
    nBase *= 5;
  }
  return nKey;
}

int fnHash1st(llong nKey) { return (nKey % nARRYSIZ); }
int fnHash2nd(llong nKey) { return (1 + (nKey % (nARRYSIZ - 1))); }

void fnDic(vector<string>& rvsDic)
{
  int nCmdCnt;
  cin >> nCmdCnt;

  for (int i = 0; i < nCmdCnt; i++)
  {
    string sCmd, sKey;
    cin >> sCmd >> sKey;
    llong nKey = fnStrToLL(sKey);

    for (int nCnt = 0; ;nCnt++)
    {
      int ix = (fnHash1st(nKey) + nCnt * fnHash2nd(nKey)) % nARRYSIZ;
      if (rvsDic[ix] == sKey)
      {
        if (sCmd[0] == 'i')
          continue;
        else if (sCmd[0] == 'f')
        {
          cout << "yes" << endl;
          break;
        }
      }
      else if (rvsDic[ix].size() == 0)
      {
        if (sCmd[0] == 'i')
        {
          rvsDic[ix] = sKey;
          break;
        }
        else if (sCmd[0] == 'f')
        {
          cout << "no" << endl;
          break;
        }
      }
    }
  }
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  vector<string> vsDic(nARRYSIZ);
  fnDic(vsDic);
  
  return 0;
}

