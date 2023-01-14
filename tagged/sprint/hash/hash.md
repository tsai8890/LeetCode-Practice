# Hash 

## Note
1.  C++ 的 unordered 系列，包含 unordered_map, unordered_set 等等，
    其底層實現都是使用 hash table

## Collision

### 處理方式
#### Chaining 
在每個位置上都建立一個 linked-list，collision 就放到 linked-list 的尾巴

#### Public Pool
屬於 Chaining 的 Array 實作版本

開一個大於 modulo 的 array，其中超過 modulo 的位置稱為 public pool。
如果某個位置發生 collision，就將該位置的 next 指向目前 public pool 的第一個元素，並把值存進去。

#### Open Addressing
若 collision，就繼續往下找空的位置，直到找到第一個空的位置

#### Re-Hash
準備 n 個 hash function (1..n)，若 hash 完有 collision，則按照順序使用其它的 hash function