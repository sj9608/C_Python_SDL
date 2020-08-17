#include "graph.h"

tDE_S_Node *g_pRootNode;
static Uint32 __nodeID_Generator = 10000;

void tDE_graph_init()
{
    g_pRootNode = SDL_calloc(sizeof(tDE_S_Node), 1);
    // malloc 과 비슷한 calloc 하지만 calloc은 초기화를 하면서 선언 1은 블럭 개수 ( 대개 1을 씀 ) 배열이 2개면 2를써줌
    //g_pRootNode->m_pNext = NULL 써주기 싫으면 calloc 사용하는것
    g_pRootNode->m_nID = __nodeID_Generator; // 식별자 값 넣어주기.
    __nodeID_Generator++;
}

void tDE_graph_close()
{
    SDL_free(g_pRootNode);
}

Uint32 tDE_graph_add_node(tDE_S_Node *pNode, tDE_S_Node *pParent) // 노드추가
// 넣어주는 위치는 부모 밑이기 때문에 Parent 필요 , 넣어야하는 데이터는 pNode
{
    //처음으로 id값
    pNode->m_nID = __nodeID_Generator++;

    if (!pParent) // 부모위치 특정하지 않으면 맨처음 노드로
    {
        pParent = g_pRootNode;
    }

    if (!pParent->m_pChild) // 부모위치를 특정하면 자식으로 들어가야함
    {
        pParent->m_pChild = pNode;
        pNode->m_pParent = pParent; // 그리고 자식노드는 부모노드를 알아봐야함.
    }
    else
    {
        tDE_S_Node *_pChild = pParent->m_pChild; // 기존에 있던거 백업
        pParent->m_pChild = pNode;
        pNode->m_pParent = pParent;
        pNode->m_pNext = _pChild;
        _pChild->m_pPrev = pNode;
    }

    return pNode->m_nID;
}

void tDE_graph_Traverse(tDE_S_Node *pRoot, void (*callback)(void *node, void *ptr), void *param) // 노드를 만날때마다 콜백하기위한 함수 콜백함수 받아서 id값 출력해보고
{
    if (!pRoot)
    {
        pRoot = g_pRootNode;
    }
    // 자손찾기
    if (pRoot->m_pChild)
    {
        tDE_graph_Traverse(pRoot->m_pChild, callback, param);
        // 형제순회
        tDE_S_Node *_phead = pRoot->m_pChild;
        while (_phead)
        {
            void *_next = _phead->m_pNext;
            callback(_phead, param);
            _phead = _next;
        }
    }
}

tDE_S_Node *tDE_graph_FindNodeById(tDE_S_Node *pRoot, Uint32 nId)
{
    if (!pRoot)
    {
        pRoot = g_pRootNode;
    }
    if (pRoot->m_nID == nId)
    {
        
    }
}