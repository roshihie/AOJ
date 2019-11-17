#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace  std;

void fnInput(vector<int>& rvnTrg, vector<int>& rvnSch)
{
  const string FILNAM = "C:\\Users\\roshi_000\\OneDrive\\ƒhƒLƒ…ƒƒ“ƒg\\Develop\\C++\\ALDS1_4_in8.txt";

  ifstream fin( FILNAM.c_str() );
  int nSchCnt;
  fin >> nSchCnt;

  for (int i = 0; i < nSchCnt; i++)
  {
    int nSch;
    fin >> nSch;
    rvnSch.push_back(nSch);
  }

  int nTrgCnt;
  fin >> nTrgCnt;

  for (int i = 0; i < nTrgCnt; i++)
  {
    int nTrg;
    fin >> nTrg;
    rvnTrg.push_back(nTrg);
  }
  fin.close();
}

void fnLinearSch(const vector<int>& cnrvnTrg, const vector<int>& cnrvnSch, int& rnFnd)
{
  for (auto itvnTrg = begin(cnrvnTrg); itvnTrg != end(cnrvnTrg); itvnTrg++)
    for (auto itvnSch = begin(cnrvnSch); itvnSch != end(cnrvnSch); itvnSch++)
      if (*itvnTrg == *itvnSch)
      {
        rnFnd++;
        break;
      }
}

void fnResultOut(int nFnd)
{
  cout << nFnd << endl;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  vector<int> vnTrg, vnSch;
  int nFnd = 0;

  fnInput(vnTrg, vnSch);
  fnLinearSch(vnTrg, vnSch, nFnd);
  fnResultOut(nFnd);

  return 0;
}

