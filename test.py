def evaluate(c1,c2):
    if c2==0:
        return [3*int(c1/3),0]
    d = c1-c2
    excess = d%3
    if excess==2:
        return [c1,c2-1]
    elif excess == 1:
        return [c1-1,c2]
    else:
        return [c1,c2]

def return_arr(mp, lst):
    c1, c2 = lst
    res_lst = mp[0]
    if c1==0 and c2==0:
        return res_lst
    if c1!=0:
        arr = mp[1]
        arr.sort(reverse=True)
        res_lst.extend(arr[:c1])
    if c2!=0:
        arr=mp[2]
        arr.sort(reverse=True)
        res_lst.extend(arr[:c2])
    return res_lst


def solution(l):
    if sum(l)%3==0:
        return int(''.join(map(str,sorted(l,reverse=True))))

    mp = {0:[],1:[],2:[]}
    for i in l:
        mp[i%3].append(i)
    c1 = len(mp[1])
    c2 = len(mp[2])
    res = []
    if c1==c2:
        res = l
    elif c1>c2:
        c1,c2 = evaluate(c1,c2)
        res = return_arr(mp,[c1,c2])
    elif c2>c1:
        c2,c1 = evaluate(c2,c1)
        res = return_arr(mp,[c2,c1])

    res.sort(reverse=True)
    r = ''.join(list(map(str,res)))
    if len(r)==0:
        return 0
    return int(r)

    

print(solution([3, 1, 4, 1, 5, 9]))

