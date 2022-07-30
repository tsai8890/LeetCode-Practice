# C++ STL

## std::string
- 新增 / 刪除 (只支援從尾端)
    - push_back()
    - pop_back()
        - no return value

- 存取
    - 可用 index 隨機存取任一字元
    - 可用 front(), back() 存取頭尾字元
        - 是回傳 reference，可以直接修改

- 其它
    - length()
    - empty()

## std::vector
- 新增 / 刪除 (只支援從尾端)
    - push_back()
    - pop_back()
        - no return value

- 存取
    - 可用 vector[index] 隨機存取任一元素
    - 可用 front(), back() 存取頭尾
        - 是回傳 reference，可以直接修改

- 其它
    - size()
    - empty()

## std::deque
- 新增 / 刪除 (從前面 or 後面都可以)
    - push_front()
    - push_back()
    - pop_front()
    - pop_back()

- 存取
    - 可用 deque[index] 隨機存取任一元素
    - front()
    - back()

- 其它
    - size()
    - empty()

## std::queue
- 新增 / 刪除 (只能從前面 pop / 從後面 push)
    - push()
    - pop()

- 存取
    - front()
    - back()

- 其它
    - size()
    - empty()

## std::stack
- 新增 / 刪除 (只支援 push / pop)
    - push()
    - pop()
        - no return value

- 存取
    - top(): 回傳 stack 頂端的元素的 reference

- 其它
    - size()
    - empty()