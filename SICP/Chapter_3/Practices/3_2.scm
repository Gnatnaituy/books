;; make-monitored
;; input how-many-calls? return called times
;; input reset-count
;; other 

(define (make-monitored func)
    (let ((acc 0))
        (lambda (m) (cond ((eq? m 'how-many-calls?) acc)
                                        ((eq? m 'reset-count) (set! acc 0))
                                        (else (begin (set! acc (+ 1 acc)) (func m)))))))

(define a (make-monitored sqrt))