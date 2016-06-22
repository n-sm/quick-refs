(defun raiz-de-a-a-la-n (a n)
  (expt a (/ 1.0 n)))


(defun tabla (func a)
  (insert"\n"
	 (number-to-string a)
	 " a la 1/n\n")
  (dotimes (n 10)
    (insert 
     "n = "   (number-to-string (1+ n)) 
     ", 1/n = " (number-to-string (/ 1.0 (1+ n)))
     "\n     --> "
     (number-to-string  (funcall func a (1+ n))) "\n" )))

;;;;

(defun n-para (a epsilon)
  (/ 1 (log (- 1.0 epsilon) a)))

(n-para 0.2 0.0007)
2298.39220488992

(- 1 (raiz-de-a-a-la-n 0.2 2299))
0.0006998150031876094


(tabla 'raiz-de-a-a-la-n 1.1)


1.1 a la 1/n
n = 1, 1/n = 1.0
     --> 1.1
n = 2, 1/n = 0.5
     --> 1.0488088481701516
n = 3, 1/n = 0.3333333333333333
     --> 1.0322801154563672
n = 4, 1/n = 0.25
     --> 1.0241136890844451
n = 5, 1/n = 0.2
     --> 1.0192448764914566
n = 6, 1/n = 0.16666666666666666
     --> 1.0160118677733874
n = 7, 1/n = 0.14285714285714285
     --> 1.0137088562954681
n = 8, 1/n = 0.125
     --> 1.0119850241403996
n = 9, 1/n = 0.1111111111111111
     --> 1.0106462927075108
n = 10, 1/n = 0.1
     --> 1.009576582776887
