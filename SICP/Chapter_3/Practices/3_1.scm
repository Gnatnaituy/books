(define (make-accumulator number)
    (lambda (sum)
        (set! number (+ number sum))
        number)) ;; 先把number设置位sum+number, 再将number的值赋给sum, 程序返回sum