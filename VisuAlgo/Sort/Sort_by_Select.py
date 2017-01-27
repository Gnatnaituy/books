# 交换法


def select(alist):

    for i in range(0, len(alist)-1):
        min_element = alist[i]
        for j in range(i+1, len(alist)):
            if alist[j] < min_element:
                min_element = alist[j]
                min_element_index = j
                alist[i], alist[min_element_index] = alist[min_element_index], alist[i]
    return alist


if __name__ == '__main__':
    random_list = [33, 5, 23, 12, 456, 678, 2, 12345, 45]
    print('random_list : ', random_list)
    sorted_list = select(random_list)
    print('sorted_list : ', sorted_list)