Node* SLL_CreatNode(ElementType NewNode)
{
    Node* NewNode = (Node*)malloc(sizeof(Node));

    NewNode->Data = NewData;  //데이터를 저장한다.
    NewNode->NextNode = NULL;  //다음 노드에 대한 포인터는 NULL로 초기화한다.

    return NewNode;  //노드의 주소를 반환한다.
}

void SLL_DestroyNode(Node* Node)
{
    free(Node);
}

void SLL_AppendNode(Node** Head, Node* NewNode)
{
    if((*Head)==NULL)  //헤드 노드가 NULL이라면
    {
        *Head = NewNode;  //새로운 노드가 Head가 된다
    }
    else  //헤드 노드가 있다면
    {
        Node* Tail = (*Head);  
        while (Tail->NextNode !=NULL)  //NULL이 나올때까지 while문 반복
        {
            Tail = Tail->NextNode;
        }
        Tail->NextNode = NewNode;  //테일을 찾아 NewNode와 연결한다.
    }
}

Node* List = NULL;
Node* NewNode = NULL;

NewNode = SLL_CreatNode(117);  //자유저장소에 노드 생성
SLL_AppendNode(&List,NewNode);  //생성한 노드를 List에 추가

NEwNode = SLL_CreatNode(119);  //자유저장소에 또 다른 노드 생성
SLL_AppendNode(&List, NewNode);  //생성한 노드를 List에 추가 연결

Node* SLL_GetNodeAt(Node* Head, int Location)
{
    Node* Current = Head;

    while (Current != NULL && (--Location >= 0))
    {
        Current = CCurrent->NewxNode;
    }
    return Current;
}

SLL_AppendNode(&List, SLL_CreatNode(117) );
SLL_AppendNode(&List, SLL_CreatNode(119) );

MyNode = SLL_GetNodeAt(List,1); //두 번째 노드의 주소를 MyNode에 저장
printf("%d\n", MyNode->Data);  //119출력


void SLL_RemoveNode(Node** Head, Node* Remove)
{
    if(*Head == Remove)  
    {
        *Head = Remove->NextNode;
    }
    else
    {
        Node* Current = *Head;
        while(Current != NULL && Current->NextNode != Remove)  
        {   
            Current = Current->NextNode;
        }//Current가 NULL이거나 Head의 NextNode가 Remove일때 빠져나옴
        if(Current != NULL)
            Current->NextNode = Remove->NextNode;
            //Head의 테일과 삭제 노드의 테일을 연결해줌
    }
}

void SLL_InsertAfter(Node* Current, Node* NewNode)
{
    NewNode->NextNode = Current->NextNode;  //새 노드의 NextNode 포인터가 뒤 노드를 가리키게 하고
    Current->NextNode = NewNode;  //앞 노드의 NextNode 포인터가 새 노드를 가리키게 한다.
}

int SLL_GetNodeCout(Node* Head)
{
    int Count = 0;
    Node* Current = Head;
    while(Current != NULL)
    {
        Current = Current->NextNode;  //NextNode가 다음 노드의 Data를 가리킨다.
        count++;
    }  //NextNode가 NULL이라면 노드가 끝이 난것이다.
    return Count;

}