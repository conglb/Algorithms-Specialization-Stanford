def karatsuba(x, y):
    if x == '':
        x = '0'
    if y == '':
        y = '0'
    l1 = len(x)
    l2 = len(y)

    if l1 == 1 and l2 == 1:
        return int(x) * int (y)

    a = x[0:int(l1/2)]
    b = x[int(l1/2): l1]

    c = y[0:int(l2/2)]
    d = y[int(l2/2): l2]

    return 10**int(l1/2) * 10**int(l2/2) * karatsuba(a,c) + 10**int(l1/2) * karatsuba(a, d) + 10**int(l2/2) * karatsuba(b,c) + karatsuba(b,d)

if __name__ == '__main__':
    a = input()
    b = input()
    print(karatsuba(a,b))