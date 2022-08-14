class Solution:
    def customSortString(self, order: str, str_: str) -> str:
        char_order = {}
        for i in range(26):
            char_order[chr(ord('a')+i)] = 26
            
        for i, ch in enumerate(order):
            char_order[ch] = i
        
        res = sorted(list(str_), key=lambda x: char_order[x])
        return ''.join(res)