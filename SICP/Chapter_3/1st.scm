;; 3.1 Assignment and Local State

;; 3.1.1 Local state variables
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

    (define (withdraw amount)
        (if (>= balance amount)
            (begin (set! balance (- balance amount))
                        balance)
            "Insufficient funds"))

    (define (deposit amount)
        (set! balance (+ balance amount)) balance)

    (define (dispatch m)
        (cond ((eq? m (quote withdraw)) withdraw)
                  ((eq? m (quote deposit)) deposit)
                  (else (error "Unknown request -- MAKE-ACOUNT" m))))

    dispatch)


;; The Advantages of Assignment
(define (gcd a b)
  (if (= b 0)
      a
      (gcd b (remainder a b))))

(define (rand-update x)
  (let ((a 27) (b 26) (m 127))
    (modulo (+ (* a x) b) m)))

(define rand
    (let ((x rand-init))
        (lambda ()
            (set! x (rand-update x))
            x)))

(define (estimate-pi trails)
    (sqrt (/ 6 (monte-carlo trails cesaro-test))))

(define (cesaro-test)
    (= (gcd (rand) (rand)) 1))

(define (monte-carlo trails experiment)
    (define (iter trails-remaining trails-passed)
        (cond ((= trails-remaining 0)
                    (/ trails-passed trails))
                  ((experiment)
                    (iter (- trails-remaining 1) (+ trails-passed 1)))
                  (else
                    (iter (- trails-remaining 1) trails-passed))))
    (iter trails 0))

 
;; The Disadvantages of Assignment
