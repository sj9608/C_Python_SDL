#ifndef __GRAPH_H__
#define __GRAPH_H__

#include "core.h"

typedef struct __graph_node
{
    Uint32 m_nID;

    struct __graph_node *m_pNext;
    struct __graph_node *m_pPrev; // 여기까지 링크드 리스트

    struct __graph_node *m_pChild;
    struct __graph_node *m_pParent; // 여기까지 추가하면 트리구조

    // 데이터를 실제로 집어넣을 수 있는 포인터형 선언
    void *m_pEntity; //버튼 , 텍스트라벨 등등 모든것을 집어넣을 수 있음. 대부분의 엔진에서 엔티티라는 포인터형 변수를 사용
} tDE_S_Node;

void tDE_graph_init();
void tDE_graph_close();
Uint32 tDE_graph_add_node(tDE_S_Node *pNode, tDE_S_Node *pParent);
void tDE_graph_Traverse(tDE_S_Node *pRoot, void (*callback)(void *node, void *ptr), void *param);
tDE_S_Node *tDE_graph_FindNodeById(tDE_S_Node *pRoot, Uint32 nId);
void tDE_graph_remove_node(tDE_S_Node *pNode);

#endif