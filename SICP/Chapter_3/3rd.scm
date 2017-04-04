; 一维表格
(define (lookup key table)
    (let ((record (assoc key (cdr table))))
        (if record (cdr record) false)))
(define (assoc key records)
    (cond ((null? records) false)
              ((equal? key (caar records)) (car records))
              (else (assoc key (cdr records)))))
(define (insert! key value table)
    (let ((record (assoc key (cdr table))))
        (if record
            (set-cdr! record value)
            (set-cdr! table (cons (cons key value) (cdr table)))))
    (quote ok))


; 二维表格
(define (make-table)
    (let ((local-table (list (quote *table*))))

    (define (lookup key-1 key-2)
        (let ((subtable (assoc key-1 (cdr local-table))))
            (if subtable
                (let ((record (assoc key-2 (cdr subtable))))
                    (if record 
                        (cdr record)
                        false))
                false)))

    (define (insert! key-1 key-2 value)
        (let ((subtable (assoc key-1 (cdr local-table))))
            (if subtable
                (let ((record (assoc key-2 (cdr subtable))))
                    (if record
                        (set-cdr! record value)
                        (set-cdr! subtable (cons (cons key-2 value) (cdr subtable)))))
                (set-cdr! local-table
                            (cons (list key-1 (cons key-2 value))
                                        (cdr local-table)))))
        (quote ok))

    (define (dispatch m)
        (cond ((eq? m (quote lookup-proc)) lookup)
                  ((eq? m (quote insert-proc!)) insert!)
                  (else (error "Unknwon operation -- TABLE" m))))
    dispatch))

(define operation-table (make-table))
(define get (operation-table (quote lookup-proc)))
(define put (operation-table (quote insert-proc!)))


(define (adder a1 a2 sum)
    (define (process-new-value)
        (cond ((and (has-value? a1) (has-value? a2))
                    (set-value! sum
                                       (+ (get-value a1) (get-value a2))
                                       me))
                   ((and (has-value? a1) (has-value? sum))
                    (set-value! a2
                                       (- (get-value sum) (get-value a1))
                                       me))
                   ((and (has-value? a2) (has-value? sum))
                    (set-value! a1
                                       (- (get-value sum) (get-value a2))
                                       me))))
    (define (process-forget-value)
        (forget-value! sum me)
        (forget-value! a1 me)
        (forget-value a2 me)
        (process-new-value))
    (define (me request)
        (cond ((eq? request (quote I-have-a-value))
                    (process-new-value))
                  ((eq? request (quote I-lost-my-value))
                    (process-forget-value))
                  (else
                    (error "Unknown request -- ADDER" request))))
    (connect a1 me)
    (connect a2 me)
    (connect sum me)
    me)