void shift(int k) {
	// TODO: Add your code here
	while (k < 0) k += mSize;
	k = k % mSize;
	auto cur = begin();
	for (int i = 0;i < k; i++) cur++;
	auto it = cur.ptr;

	mHeader->next->prev = mHeader->prev;
	mHeader->prev->next = mHeader->next;
	it->prev->next = mHeader;
	mHeader->prev = it->prev;
	it->prev = mHeader;
	mHeader->next = it;

}