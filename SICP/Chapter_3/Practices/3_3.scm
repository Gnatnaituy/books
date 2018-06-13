(define (make-account balance secret)
    ;; withdraw
    (define (withdraw amount)
        (if (>= balance amount)
            (begin (set! balance (- balance amount))
                        balance)
            "Insufficient funds"))
    ;; deposit
    (define (deposit amount)
        (set! balance (+ balance amount)) balance)

    (define (dispatch input-secret m)
        (if (eq?  input-secret secret)
            (cond ((eq? m (quote withdraw)) withdraw)
                      ((eq? m (quote deposit)) deposit)
                      (else (error "Unknown request -- MAKE-ACOUNT" m)))
            "Incorrect password!"))

    dispatch)


(define acc (make-account 100 'abc))
