//*******************************************************************************
//       DoublyLinkedList                 
//*******************************************************************************
//     < 処理概要 >
//       DoublyLinkedList を struct を使用して実装し、STL の list は使用しない
//*******************************************************************************
#include <iostream>
#include <string>
using namespace  std;

struct StList
{
  int  m_nKey;
  StList* m_poPrev;
  StList* m_poNext;
  
  StList() :
    m_nKey(0), m_poPrev(nullptr), m_poNext(nullptr)
  { }

  StList(int nNum, StList& roHead) :
    m_nKey(nNum), m_poPrev(&roHead), m_poNext(roHead.m_poNext)
  { }

  ~StList() { }
};

void fnLinkedListSet(StList& roHead, StList& roTrail)
{
  string sCmd;
  int nMaxCmd, nNum;

  cin >> nMaxCmd;
  for (int i = 0; i < nMaxCmd; i++)
  {
    cin >> sCmd;
    if (sCmd[0] == 'i')
    {
      cin >> nNum;
      StList* poList = new StList(nNum, roHead);
      roHead.m_poNext->m_poPrev = poList;
      roHead.m_poNext = poList;
    }
    else if (sCmd[6] == 'F')
    {
      StList* poList = roHead.m_poNext;
      if (poList != &roTrail)
      {
        poList->m_poNext->m_poPrev = poList->m_poPrev;
        roHead.m_poNext = poList->m_poNext;
        delete poList;
      }
    }
    else if (sCmd[6] == 'L')
    {
      StList* poList = roTrail.m_poPrev;
      if (poList != &roHead)
      {
        roTrail.m_poPrev = poList->m_poPrev;
        poList->m_poPrev->m_poNext = poList->m_poNext;
        delete poList;
      }
    }
    else if (sCmd[0] == 'd')
    {
      cin >> nNum;
      StList* poList = roHead.m_poNext;
      while (poList != &roTrail)
      {
        if (poList->m_nKey == nNum)
        {
          poList->m_poNext->m_poPrev = poList->m_poPrev;     
          poList->m_poPrev->m_poNext = poList->m_poNext;
          delete poList;
          break;
        }
        poList = poList->m_poNext;
      }
    }
  }
}

void fnLinkedListGet(StList& roHead, StList& roTrail)
{
  StList* poList = roHead.m_poNext;
  while (poList != &roTrail)
  {
    if (poList != roHead.m_poNext) cout << " ";
    cout << poList->m_nKey;
    poList = poList->m_poNext;
    delete poList->m_poPrev;
  }
  cout << endl;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
 
  StList oHead, oTrail;
  oHead.m_poNext  = &oTrail;
  oTrail.m_poPrev = &oHead;
 
  fnLinkedListSet(oHead, oTrail);
  fnLinkedListGet(oHead, oTrail);

  return 0;
}

