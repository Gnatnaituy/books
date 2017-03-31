;; Example1: Symbolic Differentiation
(define (variable? x) (symbol? x))  ;;is x a symbol?
(define (same-variable? v1 v2) (and (variable? v1) (variable? v2) (eq? v1 v2))) ;; is v1 equal to v2?
(define (=number? expression number) (and (number? expression) (eq? expression number)))

(define (make-sum v1 v2)    ;; add
    (cond ((=number? v1 0) v2)
              ((=number? v2 0) v1)
              ((and (number? v1) (number? v2)) (+ v1 v2))
              (else (list (quote +) v1 v2))))

(define (make-product v1 v2)     ;; product
    (cond ((or (=number? v1 0) (=number? v2 0)) 0)
               ((=number? v1 1) v2)
               ((=number? v2 1) v1)
               ((and (number? v1) (number? v2)) (* v1 v2))
               (else (list (quote *) v1 v2))))

(define (sum? x) (and (pair? x) (eq? (car x) (quote +))))   ;; if the list is started with a symbol +
(define (addend s) (cadr s))    ;; the second item of the sum list
(define (augend s) (caddr s))   ;; the third item of the sum list

(define (product? x) (and (pair? x) (eq? (car x) (quote *))))   ;; if the list started with a symbol *
(define (multiplier p) (cadr p))
(define (multiplicand p) (caddr p))

(define (derive expression variety)
    (cond ((number? expression) 0)  ;; expression is a number
               ((variable? expression) (if (same-variable? expression variety) 1 0))    ;; expression is s variety
               ((sum? expression) (make-sum (derive (addend expression) variety)    ;;    add expression
                                                                    (derive (augend expression) variety)))
               ((product? expression)  ;; product expression
                    (make-sum   (make-product (multiplier expression)
                                                                    (derive (multiplicand expression) variety))
                                           (make-product (derive (multiplier expression) variety)
                                                                     (multiplicand expression))))
               (else (error "unknwon expression type:DERIVE" expression))))


;; Example2: Representing Sets
;; Set as unordered list
(define (element-of-set? x set)     ;; if x is set's element
    (cond ((null? set) false)
               ((equal? x (car set)) true)
               (else (element-of-set? x (cdr set)))))

(define (adjoin-set x set)      ;; add x to the set
    (if (element-of-set? x set) set (cons x set)))

(define (intersection-set set1 set2)     ;; intersection of set1 and set2
    (cond ((or (null? set1) (null? set2)) (quote ()))
               ((element-of-set? (car set1) set2)
                    (cons (car set1) (intersection-set (cdr set1) set2)))
               (else (intersection-set (cdr set1) set2))))

;; Set as ordered list
(define (element-of-set-ordered? x set)
    (cond ((null? set?) false)
               ((= x (car set)) true)
               ((< x (car set)) false)
               (else (element-of-set-ordered? x (cdr set)))))

(define (intersection-set-ordered set1 set2)
    (if (or (null? set1) (null? set2))
         (quote ())
         (let ((x1 (car set1)) (x2 (car set2)))
                (cond ((= x1 x2) (cons x1 (intersection-set-ordered (cdr set1) (cdr set2))))
                          ((< x1 x2) (intersection-set-ordered (cdr set1) set2))
                          ((< x2 x1) (intersection-set-ordered set1 (cdr set2)))))))

;; Set as binary trees
(define (entry tree) (car tree))
(define (left-branch tree) (cadr tree))
(define (right-branch tree) (caddr tree))
(define (make-tree entry left right) (list entry left right))

(define (element-of-set-tree? x set)
    (cond ((null? set) false)
              ((= x (entry set)) true)
              ((< x (entry set))
                       (element-of-set-tree? x (left-branch set)))
              ((> x (entry set)
                        (element-of-set-tree? x (right-branch set))))))

(define (adjoin-set-tree x set)
    (cond ((null? set) (make-tree x (quote ()) (quote ())))
              ((= x (entry set)) set)
              ((< x (entry set))
                        ((make-tree (entry set)
                                             (adjoin-set-tree x (left-branch set))
                                             (right-branch set))))
              ((> x (entry set))
                        ((make-tree (entry set)
                                             (left-branch set)
                                             (adjoin-set-tree x (right-branch set)))))))


;; Example3: Huffman Encoding Trees
(define (make-leaf symbol weight) (list (quote leaf) symbol weight))
(define (leaf? object) (eq? (car object) (quote leaf)))
(define (symbol-leaf x) (cadr x))
(define (weight-leaf x) (caddr x))

(define (make-code-tree left right)
    (list left
            right
            (append (symbols left) (symbols right))
            (+ (weight left) (weight right))))

(define (left-branch tree) (car tree))
(define (right-branch tree) (cdar tree))

(define (symbols tree)
    (if (leaf? tree)
         (list (symbol-leaf tree))
         (caddr tree)))

(define (weight tree)
    (if (leaf? tree)
         (weight-leaf tree)
         (cadddr tree)))

;; The decoding procedure
(define (decode bits tree)
    (define (decode-1 bits current-branch)
        (if (null? bits)
            (quote ())
            (let ((next-branch (choose-branch (car bits) current-brance)))
                (if (leaf? next-branch)
                     (cons (symbol-leaf next-branch)
                               (decode-1 (cdr bits) tree))
                     (decode-1 (cdr bits) next-branch)))))
    (decode-1 bits tree))

(define (choose-branch bit branch)
    (cond ((= bit 0) (left-branch branch))
              ((= bit 1) (right-branch branch))
              (else (error "bad bit: CHOOSE-BRANCH" bit))))

;; Sets of weighted elements
(define (adjoin-set-code x set)
    (cond ((null? set) (list x))
               ((< (weight x) (weight (car set))) (cons x set))
               (else (cons (car set) (adjoin-set-code x (cdr set))))))

(define (make-leaf-set-code pairs)
    (if (null? pairs)
        (quote ())
        (let ((pair (car pairs)))
            (adjoin-set-code (make-leaf (car pair)
                                                            (cadr pair))
                                        (make-leaf-set-code (cdr pairs))))))