class Solution:
    def reverseWords(self, s: str) -> str:
        ans = ""
        initial = s.split(" ")
        
        for i in initial:
            for j in range(len(i) - 1, -1, -1):
                ans += i[j]
            ans += " "
            
        return ans.strip()
