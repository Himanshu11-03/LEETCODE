
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for (char ch : tasks) {
            freq[ch - 'A']++;
        }
        sort(freq.begin(), freq.end());
        int maxFreq = freq[25];
        int gaps = maxFreq - 1;
        int emptySlots = gaps * n;
        for (int i = 24; i >= 0 && freq[i] > 0; i--) {
            emptySlots -= min(gaps, freq[i]);
        }
        return tasks.size() + max(0, emptySlots);
    }
};
