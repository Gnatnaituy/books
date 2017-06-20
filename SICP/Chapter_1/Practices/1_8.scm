;利用公式(x/y^2+2y)/3用牛顿逼近法求立方根

(define (curt x)

    (define (square a) (* a a))
    
    (define (cube a) (* a a a))

    (define (abs a) (if (< a 0) (- a) a))

    (define (good-enough? guess)
        (< (abs (- (cube guess) x)) 0.00001)
    )

    (define (improve guess)
        (/ (+ (/ x (square guess)) (* guess 2)) 3)
    )

    (define (curt-iter guess)
        (if (good-enough? guess)
            guess
            (curt-iter (improve guess))
        )
    )

    (curt-iter 1.0)
)