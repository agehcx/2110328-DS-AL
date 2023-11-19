void splitList(list<T>& l1, list<T>& l2) {
    int mid = (mSize + 1) / 2;
    iterator it = begin();
    for (int i = 0;i < mid;i++) it++;
    node* cur = it.ptr;
    l1.mHeader->prev->next = mHeader->next;
    mHeader->next->prev = l1.mHeader->prev;
    cur->prev->next = l1.mHeader;
    l1.mHeader->prev = cur->prev;
    l1.mSize = l1.mSize + mid;
    l2.mHeader->prev->next = cur;
    cur->prev = l2.mHeader->prev;
    l2.mHeader->prev = mHeader->prev;
    mHeader->prev->next = l2.mHeader;
    l2.mSize = l2.mSize + mSize - mid;
    mSize = 0;
    mHeader->next = mHeader->prev = mHeader;
}