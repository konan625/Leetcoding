https : // leetcode.com/problems/reverse-words-in-a-string-iii/?envType=daily-question&envId=2023-10-01
        Given a string s,
        reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

        Example 1 :

    Input : s = "Let's take LeetCode contest" Output : "s'teL ekat edoCteeL tsetnoc" Example 2 :

    Input : s = "God Ding" Output : "doG gniD"

                                    Constraints :

                                    1 <= s.length <= 5 * 104 s contains printable ASCII characters.s does not contain any leading or
                trailing spaces.There is at least one word in s.All the words in s are separated by a single space.

                class Solution
{
public:
    string reverseWords(string s)
    {
        string ans = "";
        int i = 0;
        while (i < s.size())
        {
            string temp = "";
            while (i < s.size() && s[i] != ' ')
            {
                temp += s[i];
                i++;
            }
            reverse(temp.begin(), temp.end());
            if (ans.size() == 0)
            {
                ans += temp;
            }
            else
            {
                ans += " ";
                ans += temp;
            }

            i++;
        }
        cout << ans;
        return ans;
    }
};