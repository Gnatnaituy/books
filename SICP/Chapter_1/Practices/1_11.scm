(define (f-recursive n)
    (cond ((< n 3) n)
          (+ (f-recursive (- n 1))
             (* 2 (f-recursive (- n 2)))
             (* 3 (f-recursive (- n 3)))
          )
    )
)



(define (f-iterate n)
    (if (< n 3)
        n
        (f-iter 1 1 n)
    )
)


(define (f-iter product counter max-count)
    (if (> counter max-count)
        product
        (+ (f-iter () (+ counter 3) (- max-count 3))
    )
)