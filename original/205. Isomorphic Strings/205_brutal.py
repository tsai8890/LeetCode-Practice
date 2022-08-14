class Solution:
    """
        Title: 205. Isomorphic Strings
        Time Complexity: O(N^2)
        Algorithm: 
            1. Brutally check
        
        Date: 2021.7.12 21:00
        Time: 376 ms  -- beat 5.04%
        Memory: 14.3 MB  -- beat 71.11%
    """

    def isIsomorphic(self, s: str, t: str) -> bool:
        while s != '' and t != '':
            tar_s = s[0]
            tar_t = t[0]
            
            s_ch_pos = [i for i in range(len(s)) if s[i] == tar_s]
            t_ch_pos = [i for i in range(len(t)) if t[i] == tar_t]
            
            if s_ch_pos == t_ch_pos:
                s = s.replace(tar_s, '')
                t = t.replace(tar_t, '')
            else:
                return False
            
        return True if s == t else False