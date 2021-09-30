struct ListNode {
    ListNode* next = nullptr;
    int value = 0;
    int idx = 0;
};

int rowCondNumber(ListNode** data) {
    int res = 0;
    int resCount = 0;

    for (int i = 0; i < 20; ++i) {
        int count = 0;
        ListNode* cp = data[i];
        while (cp) {
            cp = cp->next;
            ++count;
        }

        if (count < resCount) {
            resCount = count;
            res = i;
        }
    }

    return res;
}