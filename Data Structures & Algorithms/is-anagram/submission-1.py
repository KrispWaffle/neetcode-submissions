class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) > len(t) or len(t) >len(s):
            return False
        s = Counter(s)
        t = Counter(t)
        
        for char in t:
            if t[char] == s[char]:
                continue
            else:
                return False
        return True