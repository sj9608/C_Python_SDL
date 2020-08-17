#include "../../engine/core.h"
#include "../../engine/entity/sprite.h"
#include "../../engine/graph.h"

SDL_Rect g_sheet_rects[] = {
    {730, 640, 75, 70},
    {671, 0, 75, 70},
    {671, 70, 75, 70}};

tDE_S_Core *g_pEngineCore;

void callBack_render(void *pNode, void *param)
{
    tDE_S_Node *_pNode = pNode;
    tDE_S_ObjectBase *pEntity = _pNode->m_pEntity;

    pEntity->m_fpRender(pEntity, g_pEngineCore->m_pRender);
}

void callBack_event(void *pNode, void *param)
{
    tDE_S_Node *_pNode = pNode;
    tDE_S_ObjectBase *pEntity = _pNode->m_pEntity;

    pEntity->m_fpDoEvent(pEntity, param);
}

//메모리 해제 콜백
void callBack_freeNode(void *pNode, void *param)
{
    tDE_S_Node *_pNode = pNode;
    tDE_S_ObjectBase *pEntity = _pNode->m_pEntity;
    pEntity->m_fpDestroy(pEntity);
    SDL_free(pNode);
}

void mouseDownCallback(void *ptr)
{
    tDE_S_ObjectBase *pEntity = ptr;
    tDE_S_Node *pFindNode = tDE_graph_FindNodeById(NULL, pEntity->m_nId);
    // 그래프에서 삭제
    tDE_graph_remove_node(pFindNode);
    printf("[%8d]\r", pEntity->m_nId);
    // 메모리에서 삭제
    pEntity->m_fpDestroy(pEntity);
    SDL_free(pFindNode);
}

int main(int argc, char *argv[])
{
    tDE_S_Core *pEngineCore = tDE_setup_1("example2", 640, 480, 0);
    SDL_Texture *pSprTex = tDE_util_loadTexture(pEngineCore, "../../res/tanks/sheet_tanks.png");

    for (int i = 0; i < 100; i++)
    {
        tDE_S_ObjectBase *pSprEntity = tDE_Entity_createSprite(rand() % 600, rand() % 480, 0,
                                                               g_sheet_rects[0], pSprTex,
                                                               mouseDownCallback, NULL, NULL); // 엔티티
        tDE_S_Node *pNode = SDL_calloc(sizeof(tDE_S_Node), 1);
        pNode->m_pEntity = pSprEntity;
        pSprEntity->m_nId = tDE_graph_add_node(pNode, NULL); // 노드를 만들어줌

        // 노드추가
    }

    SDL_bool bLoop = SDL_TRUE;
    while (bLoop)
    {
        SDL_SetRenderDrawColor(pEngineCore->m_pRender, 0, 0, 0, 0xff);
        SDL_RenderClear(pEngineCore->m_pRender);

        // pSpr->m_fpRender(pSpr, pEngineCore->m_pRender);
        tDE_graph_Traverse(NULL, NULL, NULL);

        SDL_RenderPresent(pEngineCore->m_pRender);

        SDL_Event _event;
        while (SDL_PollEvent(&_event))
        {
            tDE_graph_Traverse(NULL, callBack_event, &_event);
            switch (_event.type)
            {
            case SDL_MOUSEBUTTONDOWN:
                printf("%4d", 4);
                break;
            case SDL_QUIT:
                bLoop = SDL_FALSE;
                break;

            default:
                break;
            }
        }
    }
    tDE_graph_Traverse(NULL, callBack_freeNode, NULL);

    SDL_DestroyTexture(pSprTex);
    tDE_closeCore(pEngineCore);
    tDE_graph_close();

    return 0;
}