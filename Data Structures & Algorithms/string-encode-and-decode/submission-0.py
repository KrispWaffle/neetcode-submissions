class Solution:

    def encode(self, strs: List[str]) -> str:
        final_string = ""
        for i in strs:
            final_string+=str(len(i))
            final_string +="#"
            final_string+=i
            
        return final_string

    def decode(self, s: str) -> List[str]:
      
        final_list= []
        d = 0
        while d < len(s):
            j=d
            while s[j] !='#':
                j+=1
            length = int(s[d:j])
            d = j+1
            j = d+length
            final_list.append(s[d:j])
            d=j
            
        return final_list