class Solution {
public:
    string reorganizeString(string s) {
        vector<int> freq(26, 0);
        int size = s.size();
        // store freq of characters in s
        for (char c : s) {
            freq[c - 'a']++;
            // check if any char count is > ((s.size() + 1) / 2) ?? return ""
            if (freq[c - 'a'] > (size + 1) / 2) return "";
        }

        // add freq of characters to max heap
        priority_queue<pair<int, char>> maxHeap;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) maxHeap.push({freq[i], 'a' + i});
        }

        string result;
        pair<int, char> prev({-1, '#'});

        // loop through each element in max heap, 
        // greedy pick highest count char, 
        // store last picked char in prev 
        while (!maxHeap.empty()) {
            auto [count, c] = maxHeap.top();
            maxHeap.pop();

            result += c;
            count--;

            if (prev.first > 0) maxHeap.push(prev);

            prev = {count, c};
        }

        // return result
        return result.size() == size ? result : "";
    }
};