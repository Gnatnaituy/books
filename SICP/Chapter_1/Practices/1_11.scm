;函数f由如下规则定义：
;如果ｆ＜３，那么f(n)=n;
;如果f>=3, 那么f(n)=f(n-1)+2f(n-2)+3f(n-3)


(define (f-recursive n)
    (cond ((< n 3) n)
          (else (+ (f-recursive (- n 1))
                   (* 2 (f-recursive (- n 2)))
                   (* 3 (f-recursive (- n 3)))
                )
          )
    )
)


(define (f-iteration n)
    (f-iter 1 2 3 n))

(define (f-iter a b c n)
    (cond ((= n 1) 1)
          ((= n 2) 2)
          ((= n 3) 4)
          ((= n 4) (+ (* a 4) (* b 2) c))
          (else (f-iter (+ a b) (+ (* a 2) c) (* a 3) (- n 1)))
    )
)
