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
  StNode*  poParnt = nullptr;
  StNode** ppoNode = &rpoRoot;

  while (*ppoNode)
  {
    poParnt = *ppoNode;
    if (poNewMe->m_nKey < poParnt->m_nKey)
      ppoNode = &poParnt->m_poLeft;
    else
      ppoNode = &poParnt->m_poRigt;
  }
  poNewMe->m_poParnt = poParnt;
  *ppoNode = poNewMe;
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
      StNode* poNewNod = new StNode(nNo);
      fnInsert(rpoRoot, poNewNod);
    }
    if (sCmd[0] == 'f')
    {
      int nNo;
      cin >> nNo;
      if (fnFind(rpoRoot, nNo))
        cout << "yes" << endl;
      else
        cout << "no" << endl;
    }
    if (sCmd[0] == 'p')
    {
      fnInOrder(rpoRoot);
      cout << endl;
      fnPreOrder(rpoRoot);
      cout << endl;
    }
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

