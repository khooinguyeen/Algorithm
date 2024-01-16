#include <iostream>
using namespace std;

class Solution1 {
    public:
        string mergeAlternately(string word1, string word2) 
        {
            int size_total = word1.size() + word2.size();
            string new_word(size_total, ' ');
            int size_diff = word1.size() - word2.size();
            int j = 0, k = 0;
            size_diff = abs(size_diff);
            for (int i = 0; i < (size_total - size_diff); i++)
            {
                if (i % 2 == 0)
                {
                    new_word[i] = word1[j];
                    j++;
                }
                else
                {
                    new_word[i] = word2[k];
                    k++;
                }
            }
            if (word1.size() < word2.size())
            {
                int s = word2.size() - size_diff;
                for(int i = (size_total-size_diff); i < size_total; i++)
                {
                    new_word[i] = word2[s];
                    s++;
                }
            }
            if (word1.size() > word2.size())
            {
                int s = word1.size() - size_diff;
                for(int i = (size_total-size_diff); i < size_total; i++)
                {
                    new_word[i] = word1[s];
                    s++;
                }
            }
            return new_word;
        }
};

class Solution2 {
    public:
        string mergeAlternately(string word1, string word2) {
            int s1 = word1.size();
            int s2 = word2.size();
            string result = "";
            for (int i = 0; i < max(s1, s2); i++)
            {
                if (i < s1)
                    result.push_back(word1[i]);
                if (i < s2)
                    result.push_back(word2[i]);
            }
            return result;
        }
};

int main() 
{
    Solution1 sol1;
    Solution2 sol2;
    cout << sol1.mergeAlternately("abdl1212", "cfe9") << endl;
    cout << sol2.mergeAlternately("abdl1212", "cfe9") << endl;
    return 0;
}