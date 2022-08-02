[Stack & Queue]

## 思考模式
- 必須練習的
    - 模擬(雖然沒什麼工程價值，但是可以培養思維)
        - 用 stack 來模擬 queue
        - 用 queue 來模擬 stack

- 經典題型
- stack: 「相撞、消除相鄰、對稱性、後綴計算式」
    - 對稱的括號
        - LC 20. Valid Palindromes
        - LC 921. Minimum Add to Make Parentheses Valid

    - 相鄰的重複字母消除
        - LC 1047. Remove All Adjacent Duplicates In String
        - LC 1209. Remove All Adjacent Duplicates in String II

    - 後綴計算式
        - LC 394. Decode String
        - LC 150. Evaluate Reverse Polish Notation
        - LC 856. Score of Parentheses

- Monotonic Queue (單調隊列)
    - LC 239. Sliding Window Maximum

- Monotonic Stack (單調棧): 「下一個較大/較小元素」， 
    - 下一個較大/較小元素
        - LC 739. Daily Temperatures
        - LC 496. Next Greater Element I
        - LC 503. Next Greater Element II
        - LC 901. Online Stock Span
        - LC 42. Trapping Rain Water

- Priority Queue
    - LC 347. Top K Frequent Elements

## 刷題筆記
### LC 20. Valid Palindromes
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

### LC 1047. Remove All Adjacent Duplicates In String
- Resource Analysis
    - Time: O(N)
    - Space: O(N)

- Tips
    - 使用 reverse() 來將字串反轉
        - 是 in-place 的

    - 可以使用 string 代替 stack，省去從 stack 拿出 char 的時間
        - string 也可以 push_back / pop_back

### LC 150. Evaluate Reverse Polish Notation
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

### LC 239. Sliding Window Maximum
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

### LC 347. Top K Frequent Elements
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
         
### LC 921. Minimum Add to Make Parentheses Valid
- Resource Analysis
    - Time: O(N)
    - Space: O(N)

- Tips
    - 套用 LC 20. Valid Palindromes 的精神  

### LC 856. Score of Parentheses
- Resource Analysis
    - Time: O(N)
    - Space: O(1)

- Tips
    - 這題有兩種解法
        - 使用 stack 來解
            - 856_1.cpp

        - 將 string 拆成一個一個的 core(=連續n個左括號+連續n個右括號) 
            - 856_2.cpp

- Solutions
    - 856_1.cpp
        - Resource Analysis
            - Time: O(N)
            - Space: O(N)
        
        - Tips
            - 使用和「處理 RPN(後綴表達式)」一樣的技巧
             
    - 856_2.cpp
        - Resource Analysis
            - Time: O(N)
            - Space: O(1)
        
        - Tips
            - core: 連續n個左括號+連續n個右括號
                - 如果可以把原字串分解成數個 core，就只需要把每個 core 的分數相加即可
                - Ex:
                    - (()()) -> (()) + (())
                    - ((())()) -> ((())) + (())
            
            - 作法
                - 使用「變數bal」記錄「目前的左括號深度」
                    - 碰到 '(' -> bal += 1
                    - 碰到 ')' -> bal -= 1
                
                - 每次碰到一個 ')'，且前一個是 '('，代表找到了一個新的 core
                    - 根據目前的「左括號深度 bal」來計算 core 的分數
                        - 因為是 2 的冪次，所以可以直接寫 "1 << bal" 
                    - 將分數加到 totalScore 
                    - 之後連續的 ')' 都不會再觸發這個部分
                        - 只會讓 bal 減少

                - 最後回傳 totalScore 即可

### LC 394. Decode String
- Resource Analysis
    - Time: O(K)
    - Space: O(K)
    - K = max length of result

- Tips
    - 很經典的 stack 題目
        - 使用 stack 儲存字元，碰到右方括號 "]" 後便不斷 pop 至出現左方括號 "["
        - 可以直接用 string 代替 stack，節省轉換的時間

### LC 1209. Remove All Adjacent Duplicates in String II
- Resource Analysis
    - Time: O(N)
    - Space: O(N)

- Tips
    - 用 pair<char, int>去記錄出現的字元以及連續的次數
        - 其它都跟 LC 1047. Remove All Adjacent Duplicates In String 一樣

### LC 739. Daily Temperatures
- Resource Analysis
    - Time: O(N)
    - Space: O(N)

- Tips
    - 這題有兩種解法，兩者時間複雜度都是線性，但是後者的時間常數小很多
        - 遞減的單調棧
            - 739_1.cpp, 739_2.cpp
        - 利用 DP (optimal substructure)
            - 739_3.cpp
         
- Solutions
    - 739_1.cpp
        - 在 stack 裡使用 pair 來存 index & 溫度
        - 會多花時間 & 空間
    
    - 739_2.cpp
        - 在 stack 裡直接存 index
            - 透過 index 來拿溫度
            - 比 739_1.cpp 節省空間 & 時間

    - 739_3.cpp
        - 利用 optimal substructures
            - 如果temperatures[i] > temperatures[j], 
              那麼只需要考慮 第 j + daysToWait[j] 天之後，
              這就是核心精神。

        - 時間複雜度是線性的，空間複雜度會少一倍(少了 stack)

### LC 496. Next Greater Element I
- Resource Analysis
    - Time: O(N)
    - Space: O(N)
  
- Tips
    - 先用 hashTable 儲存 nums2 各個數字的位置
        - 接下來就是解 LC 739. Daily Temperatures
            - 一樣有兩種作法
                - Stack 
                    - 使用 Monotonic Stack
                - DP
    
    - 如果使用 stack，要記得裡面存的是 index 還是 nums[index]，不然很容易
      有意想不到的小 bug 出現

- Solutions
    - 496_1.cpp
        - 使用 stack 來解   
            - 會多使用 stack 的空間

    - 496_2.cpp
        - 使用 DP 來解
            - 空間複雜度少一倍

### LC 503. Next Greater Element II
- Resource Analysis
    - Time: O(N)
    - Space: O(N)

- Tips
    - 維護一個遞減的單調棧
        - 把原本的 array 複製一遍，就可以解 circular 的問題了
        - 剩下的就是解 LC 739. Daily Temperatures

- Solutions
    - 503_1.cpp
        - 每個元素都會 push 進去，總共會 push 2xN 次
        - 需要檢查 pop 出來的是屬於「原本array的部分」還是「circular的部分」
     
    - 503_2.cpp
        - 只有前 n 個元素會 push 進去
            - 這樣仍然可以保證正確性
     
### LC 901. Online Stock Span
- Resource Analysis
    - Time: O(N)
        - Ammortized Cost of "next(price)": O(1)
      
    - Space: O(N)

- Tips
    - 要定義 member variables
        - nextId: 儲存下一個元素要放的位置
            - 等同於 prices.size()
             
        - stack: 用來算 span 的 stack
            - stack.size() <= prices.size()
             
        - prices: 用來儲存所有原始的 price 資料
     
    - 維護一個遞減的單調棧 (即 stack)
        - 手法和 LC 739. Daily Temperatures 幾乎一樣
    
### LC 42. Trapping Rain Water
- Resource Analysis
    - Time: O(N)
    - Space: O(1)

- Tips
    - 這題有很多解法，包含 DP、Monotonic Stack、Two Pointer 等等
        - 其中 DP & Two Pointer 的核心精神是一樣的
            - 核心精神
                - 給定任一柱子，其上方能盛的水量 = min(leftMax, rightMax)
                    - leftMax: 該柱子左邊最高柱子的高度
                    - rightMax: 該柱子右邊最高柱子的高度

            - DP:  
                - Resource Analysis
                    - Time: O(N)
                    - Space: O(N)
                
                - Tips
                    利用兩次 O(N) 的時間建立 leftMax、rightMax 的陣列，
                    接下來就可以以 O(1) 的時間得到每個柱子上方能盛的水量

            - Two Pointer: 
                - Resource Analysis
                    - Time: O(N)
                    - Space: O(1) 
                       
                - Tips
                    利用兩個 pointer: left & right 來 traverse，
                    並使用 leftMax, rightMax 兩個數值來記錄目前左邊和右邊碰到的最大值

                    分成兩個 case:
                        1. leftMax > rightMax
                            if left->val > leftMax: 
                                - left上方不可能有水
                                - 更新 leftMax
                            else:
                                - left 上方恰有 leftMax 量的水 

                            final: 
                                - left 往右移一格

                        2. leftMax <= rightMax
                            if right->val > rightMax: 
                                - right上方不可能有水
                                - 更新 rightMax
                            else:
                                - right 上方恰有 rightMax 量的水 

                            final: 
                                - left 往右移一格
        
        - Monotonic Stack 的做法就不贅述了，是這部分的重點，和前幾題的做法都差不多
            - Monotonic Stack
                - Resource Analysis
                    - Time: O(N)
                    - Space: O(N)
                
                - Tips  
                    - 維護一個遞減的單調棧
                    - 只需要注意實作上的細節
                        - 每次 pop 出來 top的值時，要再看一次 stack.top() 拿到上上個高度，
                          才能決定盛水量 
