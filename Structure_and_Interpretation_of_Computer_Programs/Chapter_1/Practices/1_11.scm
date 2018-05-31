;函数f由如下规则定义：
;如果n<３，那么f(n)=n;
;如果n>=3, 那么f(n)=f(n-1)+2f(n-2)+3f(n-3)


;递归
(define (f-recursive n)
    (cond ((< n 3) n)
        (else (+ (f-recursive (- n 1))
                 (* 2 (f-recursive (- n 2)))
                 (* 3 (f-recursive (- n 3)))))))

;迭代
(define (f-iteration n)

    (define (f-iter a b c n)
        (cond ((< n 3) (+ (* a n) (* b (- n 1)) (* c (- n 2))))
              (else (f-iter (+ a b) (+ (* a 2) c) (* a 3) (- n 1)))))

    (f-iter 1 0 0 n))
