(define (make-acount balance secret)

    (define wrong-count 0)

    (define (call-the-cops)
        (lambda (x) "The police is coming, run !!!"))

    (define (withdraw amount)
        (if (>= balance amount)
            (begin (set! balance (- balance amount))
                        balance)
            "Insufficient funds"))

    (define (deposit amount)
        (set! balance (+ balance amount)) balance)

    (define (dispatch input-secret m)
        (if (eq?  input-secret secret)
             (cond ((eq? m (quote withdraw)) withdraw)
                        ((eq? m (quote deposit)) deposit)
                        (else (error "Unknown request -- MAKE-ACOUNT" m)))
             (begin (set! wrong-count (+ 1 wrong-count))
                        (if (>= wrong-count 7) 
                             (call-the-cops)
                             (lambda (x) "Incorrect Password!!!")))))
    dispatch)


(define acc (make-acount 100 'abc))
