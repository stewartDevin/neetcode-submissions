class Solution {
public:
    string reorganizeString(string s) {
        int size = s.size();

        vector<int> freq(26, 0);
        for (char c : s) {
            if (++freq[c - 'a'] > (size + 1) / 2) {
                return "";
            }
        }

        priority_queue<pair<int, char>> pq;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) { 
                pq.push({freq[i], char(i + 'a')});
            }
        }

        string output = "";
        pair<int, char> prev({-1, '#'});

        while (!pq.empty()) {
            auto [count, c] = pq.top();
            pq.pop();

            output += c;
            count--;

            if (prev.first > 0) pq.push(prev);

            prev = {count, c};
        }

        return output.size() == size ? output : "";
    }
};