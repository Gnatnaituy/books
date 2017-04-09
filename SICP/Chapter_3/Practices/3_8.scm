(define (f x)
    (if (eq? x 0)
        0
        1))

(+ (f 0) (f 1))
(+ (f 1) (f 0))