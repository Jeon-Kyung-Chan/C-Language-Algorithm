#include "SinglyLinkedList.h"

Node* SLL_CreatNode(ElementType NewData)
{
    //포인터NewNode에 Node구조체크기 동적 메모리 할당
    Node* NewNode = (Node*)malloc(sizeof(Node));

    NewNode->Data = NewData;     //데이터 저장
    NewNode->NextNode = NULL;    //테일

    return NewNode;
}

void SLL_DestroyNode(Node* Node)
{
    //동적 메모리 해제 -> 노드 소멸
    free(Node);
}

void SLL_AppendNode(Node** Head, Node* NewNode)
{
    //헤드가 없다면 헤드에 NewNode추가
    if ((*Head) == NULL)
    {
        *Head = NewNode;
    }
    else
    {
        Node* Tail = (*Head);
        //헤드의 테일나올 때까지 반복
        while (Tail->NextNode != NULL)
        {
            Tail = Tail->NextNode;
        }
        //헤드의 테일에 NewNode삽입
        Tail->NextNode = NewNode;
    }
}

void SLL_InsertAfter(Node* Current, Node* NewNode)
{
    //기존Current의 테일을 NewNode의 테일로 저장
    NewNode->NextNode = Current->NextNode;
    //NewNode의 헤더를 기존Current의 테일에 저장
    Current->NextNode = NewNode;
}

void SLL_InsertNewHead(Node** Head, Node* NewHead)
{
    //헤드가 없다면 헤드노드 삽입
    if (*Head == NULL)
    {
        (*Head) = NewHead;
    }
    else
    {
        //헤드를 NowNode의 테일에 저장
        NewHead->NextNode = (*Head);
        //헤드에 NewHead의 헤드 저장
        (*Head) = NewHead;
    }
}

void SLL_RemoveNode(Node** Head, Node* Remove)
{
    //헤드가 노드삭제 대상이면 삭제
    if (*Head == Remove)
    {
        *Head = Remove->NextNode;
    }
    else
    {
        Node* Current = *Head;
        //Current가 마지막 테일이거나 , 테일이 Remove일때까지 반복
        while (Current != NULL && Current->NextNode != Remove)
        {
            Current = Current->NextNode;
        }
        //Current테일이 NULL이 아니면
        if (Current != NULL)
            //Remove의 테일을 Current의 테일로 저장시켜 삭제
            Current->NextNode = Remove->NextNode;
    }
}

Node* SLL_GetNodeAt(Node* Head, int Location)
{
    Node* Current = Head;
    //Current가 마지막 테일이거나 Location이 음수일때 까지 반복
    while (Current != NULL && (--Location) >= 0)
    {
        //탐색 노드의 전 노드테일로 이동
        Current = Current->NextNode;
    }
    //탐색 노드 반환
    return Current;
}

int SLL_GetNodeCount(Node* Head)
{
    int Count = 0;
    Node* Current = Head;
    //NULL이 나올때 까지 반복
    while (Current != NULL)
    {
        //NextNode숫자 카운트
        Current = Current->NextNode;
        Count++;
    }
    return Count;
}