class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        res = defaultdict(list)
        for s in strs:
            x = [0] * 26
            for c in s:
                x[ord(c)-ord('a')] +=1
            res[tuple(x)].append(s) 
        return list(res.values())