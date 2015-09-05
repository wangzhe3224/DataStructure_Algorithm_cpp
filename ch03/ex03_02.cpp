/*
 * 只提供函数，不能直接运行
 */

void swapSingleLink( Node *beforeThis )
{
    // 交换This和afterThis节点
    // beforeThis是提供的This节点的前一个节点
    
    Node *This, *afterThis;
    
    This = beforeThis -> next;
    afterThis = This -> next;

    This->next = afterThis->next;
    beforeThis->next = afterThis;
    afterThis->next = This;
}

void swapDoubleLink( Node *This )
{
    // 交换this 和 afterThis
    Node *beforeThis = This->prev;
    Node *afterThis = This->next;
    Node *af = afterThis->next;

    beforeThis->next = afterThis;
    afterThis->prev = beforeThis;
    afterThis->next = This;
    This->prev = afterThis;
    This->next = af;
    af->prev = This;
}
