#include <iostream>
#include <vector>
#include <iomanip>
#define _USE_MATH_DEFINES
#include <cmath>
using namespace  std;

const double cos60 = cos(M_PI / 3);
const double sin60 = sin(M_PI / 3);

struct StPnt
{
  double m_nx;
  double m_ny;

  StPnt() :
    m_nx(0), m_ny(0)
  { }

  StPnt(double nx, double ny) :
    m_nx(nx), m_ny(ny)
  { }
};

void fnInput(int& rnRcSiz)
{
  cin >> rnRcSiz;
}

void fnKochCrv(const StPnt& cnroPnt1, const StPnt& cnroPnt2, vector<StPnt>& rvoRtnPnt)
{
  rvoRtnPnt[0] = cnroPnt1;
  rvoRtnPnt[1].m_nx = (2 * cnroPnt1.m_nx + cnroPnt2.m_nx) / 3;
  rvoRtnPnt[1].m_ny = (2 * cnroPnt1.m_ny + cnroPnt2.m_ny) / 3;
  rvoRtnPnt[3].m_nx = (cnroPnt1.m_nx + 2 * cnroPnt2.m_nx) / 3;
  rvoRtnPnt[3].m_ny = (cnroPnt1.m_ny + 2 * cnroPnt2.m_ny) / 3;

  rvoRtnPnt[2].m_nx =  (rvoRtnPnt[3].m_nx - rvoRtnPnt[1].m_nx) * cos60 
                     - (rvoRtnPnt[3].m_ny - rvoRtnPnt[1].m_ny) * sin60 + rvoRtnPnt[1].m_nx;
  rvoRtnPnt[2].m_ny =  (rvoRtnPnt[3].m_nx - rvoRtnPnt[1].m_nx) * sin60 
                     + (rvoRtnPnt[3].m_ny - rvoRtnPnt[1].m_ny) * cos60 + rvoRtnPnt[1].m_ny;

  rvoRtnPnt[4] = cnroPnt2;
}

void fnKochCtl(int nRcSiz, vector<vector<StPnt>>& rvvoPnt)
{
  StPnt oPntB(0.0, 0.0);
  StPnt oPntE(100.0, 0.0);

  rvvoPnt.resize(7);
  rvvoPnt[0].clear();
  rvvoPnt[0].push_back(oPntB);
  rvvoPnt[0].push_back(oPntE);

  for (int nRc = 0; nRc < nRcSiz; nRc++)
  {
    rvvoPnt[nRc + 1].clear();
    rvvoPnt[nRc + 1].push_back(oPntB);
    for (int i = 0; i < rvvoPnt[nRc].size() - 1; i++)
    {
      StPnt oPnt1 = rvvoPnt[nRc][i];
      StPnt oPnt2 = rvvoPnt[nRc][i + 1];
      vector<StPnt> voRtnPnt(5);

      fnKochCrv(oPnt1, oPnt2, voRtnPnt);
      for (int j = 1; j < 5; j++)
        rvvoPnt[nRc + 1].push_back(voRtnPnt[j]);
    }
  }
}

void fnResult(int nRcSiz, const vector<vector<StPnt>>& cnrvvoPnt)
{
  for (int i = 0; i < cnrvvoPnt[nRcSiz].size(); i++)
    cout << cnrvvoPnt[nRcSiz][i].m_nx << " " << cnrvvoPnt[nRcSiz][i].m_ny << endl;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(8);

  int nRcSiz;
  vector<vector<StPnt>> vvoPnt;

  fnInput(nRcSiz);
  fnKochCtl(nRcSiz, vvoPnt);

  fnResult(nRcSiz, vvoPnt);

  return 0;
}

