public class Solution {
    public bool IsValid(string s) {
        List<char> chars = new List<char>();
        foreach(char c in s)
        {
            if ( c == '{' || c == '[' || c == '(' )
            {
                chars.Add(c);
            }
            else
            {
                if (chars.Count == 0) return false;

                char check = chars[chars.Count-1];
                chars.RemoveAt(chars.Count-1);
                if (check == '{' && c == '}') continue;
                if (check == '(' && c == ')') continue;
                if (check == '[' && c == ']') continue;
                return false;
            }
        }
        if (chars.Count > 0) return false;

        return true;
    }
}
