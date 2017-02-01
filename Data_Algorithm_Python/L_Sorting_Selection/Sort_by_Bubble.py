def bubble(alist):
    # 冒泡法
    swapped = True

    while swapped:
        swapped = False
        for i in range(0, len(alist)-1):
            if alist[i] > alist[i+1]:
                alist[i], alist[i+1] = alist[i+1], alist[i]
                swapped = True
    return alist


if __name__ == '__main__':
    random_list = [1, 23, 12, 456, 678, 2, 12345]
    print('random_list : ', random_list)
    sorted_list = bubble(random_list)
    print('sorted_list : ', sorted_list)
