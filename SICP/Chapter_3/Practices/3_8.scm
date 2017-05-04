(define y 1)
(define (f x)
    (if (eqv? x y)
        1
        (begin (set! y 0) y)))

(+ (f 0) (f 1))
;; 0
(+ (f 1) (f 0))
;; 1