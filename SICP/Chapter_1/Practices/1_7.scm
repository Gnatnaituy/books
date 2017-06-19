(define (sqrt x)

    (define (square a) (* a a))

    (define (average a b) (/ (+ a b) 2))

    (define (abs a) (if (< a 0) (- a) a))

    (define (good-enough? guess)
        (< (/ (abs (- x guess)) guess) 0.0001))
        ;;(< (abs (- (square guess) x)) 0.0001))

    (define (improve guess)
        (average guess (/ x guess)))

    (define (sqrt-iter guess)
        (if (good-enough? guess)
            guess
            (sqrt-iter (improve guess))))

    (sqrt-iter 1.0))
