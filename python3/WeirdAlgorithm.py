def WeirdAlgorithm(n: int) -> str:
    res = ""
    res += str(n)
    while n != 1:
        if n % 2 == 0:
            n //= 2
        else:
            n = n * 3 + 1
        res += " " + str(n)
    return res


num = int(input())
res = WeirdAlgorithm(num)
print(res)
