KeyT dfs(node* n, KeyT &val, KeyT &imb) {
    if (n == NULL) return -1;
    KeyT L = dfs(n->left, val, imb);
    KeyT R = dfs(n->right, val, imb);
    int ans = abs(L - R);
    if (ans >= imb) {
        if (ans > imb) {
            val = n->data.first;
            imb = ans;
        } else {
            if (n->data.first < val) val = n->data.first;
        }
    }
    return std::max(L, R) + 1;
}

KeyT getValueOfMostImbalanceNode() {
    KeyT res = mRoot->data.first;
    KeyT mxImb = 0;
    dfs(mRoot, res, mxImb);

    return res;
}
