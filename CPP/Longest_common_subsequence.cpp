#include <bits/stdc++.h>
using namespace std;
#define int long long
#define float double
void LCS(string S1, string S2, int m, int n)
{
    int dp[m + 1][n + 1];
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (S1[i - 1] == S2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    int idx = dp[m][n];
    char lcs[idx + 1];
    lcs[idx] = '\0';
    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        if (S1[i - 1] == S2[j - 1])
        {
            lcs[idx - 1] = S1[i - 1];
            i--;
            j--;
            idx--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }
    cout << "S1 : " << S1 << "\nS2 : " << S2 << "\n";
    cout << "The Longest Common Subsequence is " << lcs << "\n";
    cout << "The Lenght of  Longest Common Subsequence is " << dp[m][n] << "\n";
}
signed main()
{
    string S1, S2;
    cout << "Enter Two Strings : \n";
    cin >> S1 >> S2;
    int m = S1.length();
    int n = S2.length();
    LCS(S1, S2, m, n);
    return 0;
}