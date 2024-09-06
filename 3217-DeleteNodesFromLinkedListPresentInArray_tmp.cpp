class Solution {
public:
    ListNode* modifiedList(vector<int>& excludeValues, ListNode* head) {
        bitset<100001> excludeSet; 
        for (int val : excludeValues) {
            excludeSet.set(val);
        }
        
        ListNode dummy(0);
        dummy.next = head;
        ListNode* curr = &dummy;
        
        while (curr->next) {
            if (excludeSet[curr->next->val]) {
                curr->next = curr->next->next;  
            } else {
                curr = curr->next;  
            }
        }
        
        return dummy.next;
    }
};

static const int speedup = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
