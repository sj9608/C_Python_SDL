#include "../../engine/core.h"
#include "../../engine/graph.h"

void callBackFreeAll(void *pNode, void *param)
{
    SDL_free(pNode);
}
void callBackTraverse(void *pNode, void *param)
{
    tDE_S_Node *_pnode = pNode;
    
    printf("%4d\n", _pnode->m_nID);
}

int main(int argc, char *argv[])
{
    tDE_graph_init();

    {
        tDE_S_Node *pNode = SDL_calloc(sizeof(tDE_S_Node), 1);
        tDE_graph_add_node(pNode, NULL); // 최상위에 pNode를 넣을거다  (parent가 NULL일 경우 루트노드가 됌)
    }

    // printf("%d %d\n",pNode->m_nID, pNode2->m_nID);
    tDE_graph_Traverse(NULL, callBackTraverse, NULL);

    // Find Node realization
    tDE_S_Node *pFindNode = tDE_graph_FindNodeById(NULL, 10002);
    if(pFindNode)
    {
        printf("%d\n",pFindNode->m_nID);
    }

    tDE_graph_remove_node(pFindNode);

    printf("============================================\n");
    tDE_graph_Traverse(NULL, callBackTraverse, NULL);
    
    // SDL_free(pNode2);
    // SDL_free(pNode);
    tDE_graph_Traverse(NULL, callBackFreeAll, NULL);

    tDE_graph_close();
    return 0;
}