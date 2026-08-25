# c-practice

我的 **C 语言 / Codeforces 刷题练习**仓库，按题归档练过的题解，均为纯 C 实现（gcc / Dev-C++ / Codeforces GNU C++ 均可编译）。

## 题目列表

### 1. Codeforces 1742F — F. Smaller（Round 827, Div. 4，rating 1500）

**题意**：维护两个字符串 S、T（初始均为 `"a"`）。每次操作向 S 或 T 追加一个字符串若干次，判断是否**能通过重新排列字符**使 S 的字典序小于 T。

**关键思路**：
- T 中出现任意非 `'a'` 字符 → 一定可行（S 用 `'a'` 打头，T 用更大的字符打头即可）；
- T 全为 `'a'` → 只有 S 也全为 `'a'` 且长度更短时才可行。

**文件**：

| 文件 | 说明 |
|---|---|
| `main_submit.c` | 最终 AC 版本（long long 用 `%lld`，跨平台） |
| `input.txt` | 样例输入 |

**编译运行**：

```bash
gcc main_submit.c -o main
./main < input.txt
```

## 计划

持续把后续练习（选拔赛、专题训练）的代码归档到这里。
