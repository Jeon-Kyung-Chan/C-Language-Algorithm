#include "SinglyLinkedList.h"

int main(void)
{
    int i = 0;
    int Count = 0;
    Node* List = NULL;
    Node* Current = NULL;
    Node* NewNode = NULL;

    //5개 노드 추가
    for (i = 0; i < 5; i++)
    {
        NewNode = SLL_CreatNode(i);
        SLL_AppendNode(&List, NewNode);
    }
    //1개 노드 추가
    NewNode = SLL_CreatNode(-1);
    SLL_InsertNewHead(&List, NewNode);

    //1개 노드 추가
    NewNode = SLL_CreatNode(-2);
    SLL_InsertNewHead(&List, NewNode);

    //노드 개수세기
    Count = SLL_GetNodeCount(List);
    for (i = 0; i < Count; i++)
    {
        //노드 탐색
        Current = SLL_GetNodeAt(List, i);
        //노드 위치와 값 출력
        printf("List[%d] : %d\n", i, Current->Data);
    }

    printf("\nInserting 3000 After[2]...\n\n");

    //노드2를 Current에 저장
    Current = SLL_GetNodeAt(List,2);
    //1개 노드 추가
    NewNode = SLL_CreatNode(3000);

    //노드 삽입
    SLL_InsertAfter(Current, NewNode);

    //노드 개수 세기
    Count = SLL_GetNodeCount(List);
    for (i = 0; i < Count; i++)
    {
        //노드 탐색
        Current = SLL_GetNodeAt(List, i);
        //노드 위치와 값 출력
        printf("List[%d] : %d\n", i, Current->Data);
    }

    printf("\nDestroy List...\n");

    for (i = 0; i < Count; i++)
    {
        Current = SLL_GetNodeAt(List, 0);

        if (Current != NULL)
        {
            //노드 삭제 및 소멸
            SLL_RemoveNode(&List, Current);
            SLL_DestroyNode(Current);
        }
    }
    return 0;
}

