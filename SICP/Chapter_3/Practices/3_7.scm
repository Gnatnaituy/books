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


(define (make-joint account account-password join-password)
    (lambda (input-password m)
        (if (eq? input-password join-password)
            (account account-password m)
            (lambda (x) "Incorrect join password !!!"))))


(define eminem (make-account 10000 'qwerty))
(define Slim-Shady (make-joint eminem 'qwerty 'asdfgh))