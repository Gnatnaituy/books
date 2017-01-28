def insert(alist):
    # 插入法
    for i in range(0, len(alist)-1):
        for j in range(i+1, len(alist)):
            while alist[j] < alist[j-1] and j >= i:
                alist[j], alist[j-1] = alist[j-1], alist[j]
                j -= 1
    return alist

if __name__ == '__main__':
    random_list = [1, 23, 12, 456, 678, 2, 12345]
    print('random_list : ', random_list)
    sorted_list = insert(random_list)
    print('sorted_list : ', sorted_list)