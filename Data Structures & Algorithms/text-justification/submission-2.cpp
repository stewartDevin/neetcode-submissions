class Solution {
private:
    vector<string> getWords(vector<string>& words, int index, int maxWidth) {
        vector<string> result;
        int length = 0;
        for (int i = index; i < words.size(); i++) {
            string word = words[i];
            if (length + word.size() <= maxWidth) {
                result.push_back(word);
                length += word.size() + 1;
            } else {
                break;
            }
        }
        return result;
    }

public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;

        int i = 0;
        while (i < words.size()) {
            string line;
            vector<string> lineWords = getWords(words, i, maxWidth);

            int length = 0;
            for (string word : lineWords) length += word.size();
            
            int extraSpace = maxWidth - length;
            int space = extraSpace / max(1, (int)(lineWords.size() - 1));
            int remainder = extraSpace % max(1, (int)(lineWords.size() - 1));
            
            // left justified
            if (i + lineWords.size() == words.size() || lineWords.size() == 1)
            {
                if (lineWords.size() == 1) {
                    line = lineWords[0];
                    if (extraSpace > 0) line += string(extraSpace, ' ');
                } else {
                    for (string word : lineWords) {
                        line += word;
                        if (extraSpace > 0) {
                            line += " ";
                            extraSpace--;
                        }
                        
                    }
                    if (extraSpace > 0) line += string(extraSpace, ' ');
                }
            } 
            // center justify
            else {
                for (int j = 0; j < lineWords.size(); j++) {
                    line += lineWords[j];
                    if (j != lineWords.size() - 1)
                    {
                        if (space > 0) line += string(space, ' ');
                        if (remainder > 0) {
                            line += " ";
                            remainder--;
                        }
                    }
                }
            }

            result.push_back(line);
            i += lineWords.size();
        }
        return result;
    }
};