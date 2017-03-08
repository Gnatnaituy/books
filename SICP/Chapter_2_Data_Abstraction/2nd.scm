;;2017/3/7 Horo
(define one-through-four (list 1 2 3 4))
(car one-through-four)
(cdr one-through-four)

(define (list-ref items n)
    (if (= n 0)
        (car items)
        (list-ref (cdr items) (- n 1))))

(define squares (list 1 4 9 16 25 36 49))

(list-ref squares 3)

(define (length items)
    (if (null? items)
        0
        (+ 1 (length (cdr items)))))

(define odds (list 1 3 5 7 9 11 13 15 17))
(length odds)

(define (append list1 list2)
    (if (null? list1)
        list2
        (cons (car list1) (append (cdr list1) list2))))


;;map the table
(define (scale-list items factor)
    (if (null? items)
        nil
        (cons (* (car items) factor)
                  (scale-list (cdr items) factor))))

(define (map proc items)
    (if (null? items)
         nil
         (cons (proc (car items))
                    (map proc (cdr items))))

(map abs (list 1 2 -3 -4 -33.33))
(map (lambda (x) (* x x))
          (list 1 2 3 4 5 6 7 8 9))

;;Map the tree
(define (scale-tree tree factor)
    (cond ((null? tree) nil)
              ((not (pair? tree)) (* tree factor))
              (else (cons (scale-tree (car tree) factor)
                                 (scale-tree (cdr tree) factor)))))

(scale-tree (list 1 (list 2 (list 3 4) 5 ) (list 6 7)) 10)

(define (scale-tree-2 tree factor)
    (map (lambda (sub-tree)
                    (if (pair? sub-tree)
                        (scale-tree sub-tree factor)
                        (* sub-tree factor)))
              tree))
