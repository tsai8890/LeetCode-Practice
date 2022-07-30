[Stack & Queue]

## 刷題筆記
- LC 20. Valid Palindromes

- LC 1047. Remove All Adjacent Duplicates In String
    - 使用 reverse() 來將字串反轉
        - 是 in-place 的

    - 可以使用 string 代替 stack，省去從 stack 拿出 char 的時間
        - string 也可以 push_back / pop_back

- LC 150. Evaluate Reverse Polish Notation
    - Background Knowledge
        - RPN (Reverse Polish Notation)
            - RPN 就是後綴表達式，這種表達式非常方便電腦處理
                - Ex: "35+2*"

            - 我們生活中常見的都是中綴表達式，但是電腦不好處理
                - Ex: "(3+5)*2"
        - RPN 使用 stack 就可以輕鬆解決了
    
    - 可以直接用 string 比較，不用一個字元一個字元比較
        - if (token == "+")...
    
    - 用 std::stoi 幫忙把字串轉成 integer
    
    - 150_2.cpp 是精簡過的 code，不一定要用 switch，如果敘述只有一可以考慮這樣寫

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



    