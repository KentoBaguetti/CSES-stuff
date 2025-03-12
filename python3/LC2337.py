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


if __name__ == "__main__":
    x = "_L__R__R_"
    y = "L______RR"

    print(canChange(x, y))
