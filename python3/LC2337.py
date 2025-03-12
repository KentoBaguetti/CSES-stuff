from collections import deque


def canChange(start, target):
    # sq = deque()  # queue of tuples of "L" or "R" and its index
    # tq = deque()

    sq = []
    tq = []

    sa = list(start)
    ta = list(target)

    n = len(start)

    for i in range(n):  # store the tuples
        if sa[i] != "_":
            sq.append((sa[i], i))
        if ta[i] != "_":
            tq.append((ta[i], i))

    n = len(sq)

    if len(sq) != len(tq):
        return False

    for i in range(n):
        if (
            sq[i][0] != tq[i][0]
        ):  # non "_" elements should be in the same relative order
            return False

        if sq[i][0] == "L" and tq[i][0] == "L":
            if tq[i][1] > sq[i][1]:
                return False

        if sq[i][0] == "R" and tq[i][0] == "R":
            if tq[i][1] < sq[i][1]:
                return False

    return True


def canChangeTP(start, target):
    i = 0
    j = 0

    while i < len(start) and j < len(target):
        while j < len(target) and target[j] == "_":
            j += 1
        while i < len(target) and start[i] == "_":
            i += 1

        if j < len(target) and i < len(start) and start[i] != target[j]:
            return False
        if j < len(target) and i < len(start) and start[i] == "L" and target[j] == "L":
            if i < j:
                return False
        if j < len(target) and i < len(start) and start[i] == "R" and target[j] == "R":
            if i > j:
                return False
        i += 1
        j += 1

    return True


if __name__ == "__main__":
    x = "_L__R__R_L"
    y = "L______RR_"

    print(canChangeTP(x, y))
