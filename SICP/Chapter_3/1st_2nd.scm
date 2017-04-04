;; 3.1 Assignment and Local State
 (define new-withdraw
    (let ((balance 100))
        (lambda (amount)
            (if (>= balance amount)
                (begin (set! balance (- balance amount)) balance)
                "Insufficient funds"))))


(define (make-withdraw balance)
    (lambda (amount)
        (if (>= balance amount)
            (begin (set! balance (- balance amount)) balance)
            "Insufficient funds")))


(define (make-acount balance)
    ;; withdraw
    (define (withdraw amount)
        (if (>= balance amount)
            (begin (set! balance (- balance amount))
                        balance)
            "Insufficient funds"))
    ;; deposit
    (define (deposit amount)
        (set! balance (+ balance amount)) balance)

    (define (dispatch m)
        (cond ((eq? m (quote withdraw)) withdraw)
                  ((eq? m (quote deposit)) deposit)
                  (else (error "Unknown request -- MAKE-ACOUNT" m))))
    dispatch)


;; 引进赋值带来的利益
;; 引进赋值的代价
