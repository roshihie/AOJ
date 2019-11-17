#include <iostream>
using namespace  std;

struct StNode
{
  StNode* m_poParnt;
  StNode* m_poLeft;
  StNode* m_poRigt;
  int m_nKey;

  StNode(int nNo) :
    m_poParnt(nullptr), m_poLeft(nullptr), m_poRigt(nullptr), m_nKey(nNo)
  { }
};

void fnInsert(StNode*& rpoRoot, StNode* poNewMe)
{
  StNode* poParnt = nullptr;
  StNode* poNode = rpoRoot;

  while (poNode)
  {
    poParnt = poNode;
    if (poNewMe->m_nKey < poNode->m_nKey)
      poNode = poNode->m_poLeft;
    else
      poNode = poNode->m_poRigt;
  }

  poNewMe->m_poParnt = poParnt;
  if (!poParnt)
    rpoRoot = poNewMe;
  else if (poNewMe->m_nKey < poParnt->m_nKey)
    poParnt->m_poLeft = poNewMe;
  else
    poParnt->m_poRigt = poNewMe;
}

StNode* fnFind(StNode* poRoot, int nNo)
{
  StNode* poNode = poRoot;
  while (poNode)
    if (nNo == poNode->m_nKey)
      return poNode;
    else if (nNo < poNode->m_nKey)
      poNode = poNode->m_poLeft;
    else
      poNode = poNode->m_poRigt;

  return nullptr;
}

void fnDelete(StNode*& rpoRoot, StNode* poDelMe)
{
  StNode** ppoPrToMe;
  if (poDelMe == rpoRoot)
    ppoPrToMe = &rpoRoot;
  else
    if (poDelMe->m_nKey < poDelMe->m_poParnt->m_nKey)
      ppoPrToMe = &poDelMe->m_poParnt->m_poLeft;
    else
      ppoPrToMe = &poDelMe->m_poParnt->m_poRigt;

  int nDegr = 0;
  StNode* poMeToCd;
  if (poDelMe->m_poLeft)
  {
    ++nDegr;
    poMeToCd = poDelMe->m_poLeft;
  }
  if (poDelMe->m_poRigt)
  {
    ++nDegr;
    poMeToCd = poDelMe->m_poRigt;
  }

  if (!nDegr)
  {
    *ppoPrToMe = nullptr;
    delete poDelMe;
  }
  else if (nDegr == 1)
  {
    *ppoPrToMe = poMeToCd;
    poMeToCd->m_poParnt = poDelMe->m_poParnt; 
    delete poDelMe;
  }
  else if (nDegr == 2)
  {
    StNode* poNext = poDelMe->m_poRigt;
    while (poNext->m_poLeft)
      poNext = poNext->m_poLeft;

    poDelMe->m_nKey = poNext->m_nKey;
    fnDelete(rpoRoot, poNext);
  }
}

void fnInOrder(StNode* poNode)
{
  if (!poNode)  return;

  fnInOrder(poNode->m_poLeft);
  cout << " " << poNode->m_nKey;
  fnInOrder(poNode->m_poRigt);
}

void fnPreOrder(StNode* poNode)
{
  if (!poNode)  return;

  cout << " " << poNode->m_nKey;
  fnPreOrder(poNode->m_poLeft);
  fnPreOrder(poNode->m_poRigt);
}

void fnBinSchTree(StNode*& rpoRoot)
{
  int nMaxSiz;
  cin >> nMaxSiz;

  for (int i = 0; i < nMaxSiz; ++i)
  {
    string sCmd;
    cin >> sCmd;
    if (sCmd[0] == 'i')
    {
      int nNo;
      cin >> nNo;
      StNode* poNewMe = new StNode(nNo);
      fnInsert(rpoRoot, poNewMe);
    }
    else if (sCmd[0] == 'f')
    {
      int nNo;
      cin >> nNo;
      if (fnFind(rpoRoot, nNo))
        cout << "yes" << endl;
      else
        cout << "no" << endl;
    }
    else if (sCmd[0] == 'd')
    {
      int nNo;
      cin >> nNo;
      StNode* poDelMe;
      if (poDelMe = fnFind(rpoRoot, nNo))
        fnDelete(rpoRoot, poDelMe);
      else;
    }
    else if (sCmd[0] == 'p')
    {
      fnInOrder(rpoRoot);
      cout << endl;
      fnPreOrder(rpoRoot);
      cout << endl;
    }
    else;
  }
}

void fnPstOrder(StNode* poNode)
{
  if (!poNode)  return;

  fnPstOrder(poNode->m_poLeft);
  fnPstOrder(poNode->m_poRigt);
  delete poNode;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  StNode* poRoot = nullptr;

  fnBinSchTree(poRoot);
  fnPstOrder(poRoot);
  return 0;
}

