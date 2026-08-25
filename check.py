# \u7b49\u4ef7\u590d\u73b0 main.c\uff08\u4f60\u73b0\u5728\u7684\u903b\u8f91\uff1amax_T==0 \u5df2\u4fee\u590d\uff09\uff0c\u5e76\u5bf9\u62cd\"\u6b63\u786e\u903b\u8f91\"
import sys

raw = open(r"C:\Users\81433\Doubao\chats\2026-08-26\new-chat\input.txt", encoding="utf-8").read().split()
it = iter(raw)

def run_my_algo(tokens):
    it = iter(tokens)
    T = int(next(it))
    out = []
    for _ in range(T):
        q = int(next(it))
        cntS = [0]*26; cntT = [0]*26
        cntS[0] = cntT[0] = 1
        S_len = T_len = 1
        for _ in range(q):
            d = int(next(it)); k = int(next(it)); x = next(it)
            if d == 1:
                for ch in x: cntS[ord(ch)-97] += k
                S_len += len(x)*k
            else:
                for ch in x: cntT[ord(ch)-97] += k
                T_len += len(x)*k
            max_T = 0
            for j in range(25, -1, -1):
                if cntT[j] > 0:
                    max_T = j; break
            if max_T > 0:
                out.append("YES")
            elif S_len < T_len:
                out.append("YES")
            else:
                out.append("NO")
    return out

def run_correct_algo(tokens):
    it = iter(tokens)
    T = int(next(it))
    out = []
    for _ in range(T):
        q = int(next(it))
        lenS = lenT = 1
        fS = [False, 0, '']   # [\u6709\u65e0\u975e'a', \u9996\u4e2a\u975e'a'\u7684\u4f4d\u7f6e, \u8be5\u5b57\u7b26]
        fT = [False, 0, '']
        for _ in range(q):
            d = int(next(it)); k = int(next(it)); x = next(it)
            if d == 1:
                if not fS[0]:
                    for i, ch in enumerate(x):
                        if ch != 'a':
                            fS = [True, lenS + i, ch]
                            break
                lenS += len(x)*k
            else:
                if not fT[0]:
                    for i, ch in enumerate(x):
                        if ch != 'a':
                            fT = [True, lenT + i, ch]
                            break
                lenT += len(x)*k
            if not fS[0] and not fT[0]:
                ok = lenS < lenT
            elif not fS[0] and fT[0]:
                ok = True
            elif fS[0] and not fT[0]:
                ok = False
            else:
                if fS[1] > fT[1]: ok = True
                elif fS[1] < fT[1]: ok = False
                else: ok = fS[2] < fT[2]
            out.append("YES" if ok else "NO")
    return out

mine = run_my_algo(raw)
correct = run_correct_algo(raw)

expected = ["YES","NO","YES","NO","NO",  # \u7528\u4f8b1
            "NO","NO",                    # \u7528\u4f8b2
            "NO","NO","NO"]               # \u7528\u4f8b3

print("== \u4f60\u7684\u4ee3\u7801\uff08\u590d\u73b0\uff09==")
for i, v in enumerate(mine, 1):
    print(f"{i:2d}. {v}")
print()
print("== \u6b63\u786e\u903b\u8f91 ==")
for i, v in enumerate(correct, 1):
    print(f"{i:2d}. {v}")
print()
print("== \u671f\u671b(\u6837\u4f8b\u6807\u51c6\u7b54\u6848) ==")
for i, v in enumerate(expected, 1):
    print(f"{i:2d}. {v}")
