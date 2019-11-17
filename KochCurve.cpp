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

void fnPntGet(const StPnt& cnroPntL, const StPnt& cnroPntR, vector<StPnt>& rvoRtnPnt)
{
  rvoRtnPnt[0].m_nx = (2 * cnroPntL.m_nx + cnroPntR.m_nx) / 3;
  rvoRtnPnt[0].m_ny = (2 * cnroPntL.m_ny + cnroPntR.m_ny) / 3;
  rvoRtnPnt[2].m_nx = (cnroPntL.m_nx + 2 * cnroPntR.m_nx) / 3;
  rvoRtnPnt[2].m_ny = (cnroPntL.m_ny + 2 * cnroPntR.m_ny) / 3;

  rvoRtnPnt[1].m_nx =  (rvoRtnPnt[2].m_nx - rvoRtnPnt[0].m_nx) * cos60 
                     - (rvoRtnPnt[2].m_ny - rvoRtnPnt[0].m_ny) * sin60 + rvoRtnPnt[0].m_nx;
  rvoRtnPnt[1].m_ny =  (rvoRtnPnt[2].m_nx - rvoRtnPnt[0].m_nx) * sin60 
                     + (rvoRtnPnt[2].m_ny - rvoRtnPnt[0].m_ny) * cos60 + rvoRtnPnt[0].m_ny;
}

void fnResult(const StPnt& cnroPnt)
{
  cout << cnroPnt.m_nx << " " << cnroPnt.m_ny << endl;
}

void fnKoch(int nRcSiz, const StPnt& cnroPntL, const StPnt& cnroPntR)
{
  if (!nRcSiz) return;

  vector<StPnt> voRtnPnt(3);
  fnPntGet(cnroPntL, cnroPntR, voRtnPnt); 
  
  nRcSiz--;
  fnKoch(nRcSiz, cnroPntL, voRtnPnt[0]);
  fnResult(voRtnPnt[0]);

  fnKoch(nRcSiz, voRtnPnt[0], voRtnPnt[1]);
  fnResult(voRtnPnt[1]);

  fnKoch(nRcSiz, voRtnPnt[1], voRtnPnt[2]);
  fnResult(voRtnPnt[2]);

  fnKoch(nRcSiz, voRtnPnt[2], cnroPntR);
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(8);

  int nRcSiz;
  vector<StPnt> voPnt;

  fnInput(nRcSiz);
  StPnt oPntL(0, 0);
  StPnt oPntR(100, 0);

  fnResult(oPntL);
  fnKoch(nRcSiz, oPntL, oPntR);
  fnResult(oPntR);
  return 0;
}

