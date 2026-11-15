class Solution {
    vector<string> getWords(int i, const vector<string>& words, int maxWidth) {
        vector<string> lineWords;
        int n = words.size();
        int length = 0;
        while (i < n && words[i].size() + length <= maxWidth) {
            lineWords.push_back(words[i]);
            length += words[i].size() + 1;
            i++;
        }
        return lineWords;
    }

    string join(const vector<string>& lineWords, string delimiter) {
        if (lineWords.empty()) return "";
        string line(lineWords[0]);
        for (int i = 1; i < lineWords.size(); ++i) {
            line += delimiter + lineWords[i];
        }
        return line;
    }

    string createLine(vector<string>& lineWords, int i, const vector<string>& words, int maxWidth) {
        int baseLength = -1;
        for (const string& word : lineWords) {
            baseLength += word.size() + 1;
        } 

        int spaces = maxWidth - baseLength;

        // handle left justify
        if (lineWords.size() == 1 || i == words.size()) {
            string line = join(lineWords, " ");
            line += string(spaces,  ' ');
            return line;
        }
            
        int gaps = lineWords.size() - 1;
        int gapSpaces = spaces / gaps;
        int gapSpacesRemainder = spaces % gaps;

        // add spaces to each word
        for (int i = 0; i < gapSpacesRemainder; ++i) {
            lineWords[i] += " ";
        }
        for (int i = 0; i < gaps; ++i) {
            lineWords[i] += string(gapSpaces, ' ');
        }

        return join(lineWords, " ");
    }

public:
    vector<string> fullJustify(const vector<string>& words, int maxWidth) {
        vector<string> res;
        // get words that will fit on one line
        int i = 0;
        while (i < words.size()) {
            vector<string> lineWords = getWords(i, words, maxWidth);
            i += lineWords.size();
            res.push_back(createLine(lineWords, i, words, maxWidth));
        }
        return res;
        // create a line by conditionally adding spaces to words and then joining them together

        // add each line to result and return it
    }
};