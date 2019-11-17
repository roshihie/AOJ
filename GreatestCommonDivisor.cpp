#include <iostream>
using namespace  std;

int main()
{
  int nDivend, nDivsor, nRest;
  int nGCD;
  
  cin >> nDivend >> nDivsor;
  if (nDivend < nDivsor)
    swap(nDivsor, nDivsor);

  while (nDivend % nDivsor != 0)
  {
    nRest = nDivend % nDivsor;
    nDivend = nDivsor;
    nDivsor  = nRest;
  }

  nGCD = nDivsor;
  cout << nGCD << endl;
  return 0;
}
