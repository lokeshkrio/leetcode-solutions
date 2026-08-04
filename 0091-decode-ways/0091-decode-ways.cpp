#include <string>
using namespace std;

class Solution
{
public:
    int numDecodings(string s)
    {
        if (s.empty() || s[0] == '0')
            return 0;
        if (s.size() == 1)
            return 1;

        int val1 = 1, val2 = 1;
        for (int i = 1; i < s.size(); i++)
        {
            int temp = val1;
            if (s[i] == '0')
            {
                if (s[i - 1] == '1' || s[i - 1] == '2')
                {
                    val1 = val2;
                }
                else
                {
                    return 0;
                }
            }
            else if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6'))
            {
                val1 += val2;
            }
            val2 = temp;
        }

        return val1;
    }
};