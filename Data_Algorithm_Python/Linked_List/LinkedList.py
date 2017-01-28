# usr/bin/env python
# -*- coding: utf-8 -*-


def search(element, linked_list):

    i = 0
    while element != linked_list[i]:
        i += 1

    print(element, ' is at the position ', i, ' in ', linked_list)


def insert(element, position, linked_list):

    if 0 <= position <= len(linked_list):
        if position == len(linked_list):
            linked_list.append(element)
        else:
            current_position = len(linked_list)
            linked_list.append(linked_list[len(linked_list)-1])
            while current_position > position:
                linked_list[current_position] = linked_list[current_position-1]
                current_position -= 1
            linked_list[position] = element

    print('Linked list after inserted: ', linked_list)


def delete(element, linked_list):

    if element not in linked_list:
        print(element, ' not in ', linked_list)
    else:
        for i in range(0, len(linked_list)-1):
            if element == linked_list[i]:
                while i < len(linked_list)-1:
                    linked_list[i] = linked_list[i+1]
                    i += 1
                del linked_list[len(linked_list)-1]

    print('Linked list after deleted : ', linked_list)


if __name__ == '__main__':
    linked_list_ex = [1, 2, 3, 4, 5, 6, 7, 8, 9]
    search(5, linked_list_ex)
    insert(123, 3, linked_list_ex)
    delete(2, linked_list_ex)
