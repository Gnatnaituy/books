(define (sqrt x)

    ;; 内存占用飙升,系统卡得一笔
    (define (new-if predicate then-clause else-clause)
        (cond (predicate then-clause)
                  (else else-clause)))

    (define (square a) (* a a))

    (define (average a b) (/ (+ a b) 2))

    (define (abs a) (if (< a 0) (- a) a))

    (define (good-enough? guess)
        (< (abs (- (square guess) x)) 0.0001))
        
    (define (improve guess)
        (average guess (/ x guess)))

    (define (sqrt-iter guess)
        (new-if (good-enough? guess)
            guess
            (sqrt-iter (improve guess))))

    (sqrt-iter 1.0))
