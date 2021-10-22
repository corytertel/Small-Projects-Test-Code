;;;; Describe program

;;; Basic comment

;; comment indented with your code

; comment after your line of code

#||
multiline
||#

;;; Basic hellow world, ~% is newline
(format t "Hello world ~%")
;;; Another way to output text
(print "What's your name?")

;;; You can use almost anything as a variable name, not case sensitive
;;; global variables are often surrounded by astericks
;;; reads input from the console and stores it in a variable called name
(defvar *name* (read))

;;; Basic function
(defun hello-you (*name*)
  (format t "Hello ~a! ~%" *name*))

;;; By default Lisp outputs all data in upper case letters
;;; Set only the first letter to be capitalized
;;; everything in lowercase = :downcase
;;; everything in uppercase = :upcase
(setq *print-case* :capitalize)

(hello-you *name*)

