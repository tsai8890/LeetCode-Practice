[Stack & Queue]

## 思考模式
- 必須練習的
    - 模擬(雖然沒什麼工程價值，但是可以培養思維)
        - 用 stack 來模擬 queue
        - 用 queue 來模擬 stack

- 通常「相撞、消除相鄰、對稱性」等等的題目都可以很漂亮地使用 stack 解掉
    - LC 20. Valid Palindromes
        - 對稱的括號
    - LC 1047. Remove All Adjacent Duplicates In String
        - 相鄰的重複字母消除

## 刷題筆記
- LC 20. Valid Palindromes
    - Resource Analysis
        - Time: O(N)
        - Space: O(N)

    - Tips
        - Definition
            - 有兩種最小單元
                1. U: 連續的n個左括號 + 連續的n個右括號 
                2. (Uk) = (xn Uxk )xn : 連續的n個左括號 + k個U + 連續的n個右括號 

            - palindromes
                - valid: 全部都是由「最小單元」組成
                - invalid: 無法全部都用「最小單元」表示
          
        - Observations #1
            - 如果是 valid palindromes，一定可以在 stack 裡全部消掉
            - Proof
                - 任何一個 valid palindromes，都是由若干個「最小單元」組成的
                - 而每個最小單元進到 stack，一定可以被消乾淨 
                    - 所以任何一個 valid palindromes，一定都可以在 stack 裡被消乾淨

        - Observation #2
            - 如果是 invalid palindromes，在 stack 裡一定消不掉
            - Proof by Contradiction
                - 若有一個 invalid palindromes，且可以在 stack 裡完全消掉
                    - 每次 stack 裡完全清空時，代表上一段在 stack 裡的片段一定是一個「最小單元」
                      所以，代表該 invalid palindromes 全部都是由「最小單元」組成，矛盾產生
                - 所以，invalid palindromes 在 stack 裡消不掉    

- LC 1047. Remove All Adjacent Duplicates In String
    - Resource Analysis
        - Time: O(N)
        - Space: O(N)

    - Tips
        - 使用 reverse() 來將字串反轉
            - 是 in-place 的

        - 可以使用 string 代替 stack，省去從 stack 拿出 char 的時間
            - string 也可以 push_back / pop_back

- LC 150. Evaluate Reverse Polish Notation
    - Resource Analysis
        - Time: O(N)
        - Space: O(N)

    - Background Knowledge
        - RPN (Reverse Polish Notation)
            - RPN 就是後綴表達式，這種表達式非常方便電腦處理
                - Ex: "35+2*"

            - 我們生活中常見的都是中綴表達式，但是電腦不好處理
                - Ex: "(3+5)*2"
        - RPN 使用 stack 就可以輕鬆解決了
    
    - Tips
        - 可以直接用 string 比較，不用一個字元一個字元比較
            - if (token == "+")...
        
        - 用 std::stoi 幫忙把字串轉成 integer
        
        - 150_2.cpp 是精簡過的 code，不一定要用 switch，如果敘述只有一可以考慮這樣寫

- LC 239. Sliding Window Maximum
    - Resource Analysis
        - Time: O(N)
        - Space: O(N)

    - Tips
        - 要使用 "單調隊列 Monotonic Queue"，即維護一個單調遞增/遞減的 queue
            - 是遞增還是遞減要看題目需求，這題是使用遞減的單調隊列
    
        - 單調隊列在將元素移出 sliding window 的時候有兩種做法
            1. 記錄單調隊列每個元素在原本 vector 的 index
                - 需要多使用一個 deque 存 index
            
            2. 透過比對 單調隊列.front() 與 nums[i-k]
                - 一樣就 pop，反之就不 pop
                   - 這種作法更有效率，很聰明

                - 重要的事
                    - 這種作法要調整 pop 的條件，只有在 push_element 大於(沒有等於) deque
                      頂端時才會把 deque 頂端 pop 出來，否則會出錯。

    - Solutions
        - 239_1.cpp
            - 記錄單調隊列每個元素在原本 vector 的 index
                - 需要多使用一個 deque 記錄 index
             
        - 239_2.cpp
            - 透過比對 單調隊列.front() 與 nums[i-k]

- LC 347. Top K Frequent Elements
    - Resource Analysis
        - Time: O(NlogK)
        - Space: O(N)
    
    - Tips
        - 先使用 unordered_map(hashMap) 統計出現次數，
          再使用 Min-Heap 找出前 K 高頻率的數字

        - 會強迫熟悉 priority_queue & unordered_map 的用法

    - Solutions
        - 347_1.cpp 
            - 在 traverse unordered_map 時又創建了新的 vector，是時間的 bottleneck
            - beat 5.13% on time
             
        - 347_2.cpp 
            - 直接將原本 unordered_map 的 pair<int, int> 推進 priority_queue，
              省下創建的時間
            - beat 95.91% on time
         
- LC 921. Minimum Add to Make Parentheses Valid
    - Resource Analysis
        - Time: O(N)
        - Space: O(N)

    - Tips
        - 套用 LC 20. Valid Palindromes 的精神  
    
- LC 856. Score of Parentheses
    - Resource Analysis
        - Time: O(N)
        - Space: O(N)

    - Tips
        - 典型的 stack 題目
         

- LC 394. Decode String
    - Resource Analysis
        - Time: O(K)
        - Space: O(K)
        - K = max length of result
    
    - Tips
        - 很經典的 stack 題目
            - 使用 stack 儲存字元，碰到右方括號 "]" 後便不斷 pop 至出現左方括號 "["
            - 可以直接用 string 代替 stack，節省轉換的時間
