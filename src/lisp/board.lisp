(ql:quickload "cl-utilities")
(defun process-subfen (fen) (car fen))
(defun separate-fen (fen)
  (butlast (cl-utilities:split-sequence #\/ fen)))
(defun fen-to-board (fen)
  (loop for x in (nreverse (separate-fen fen))
       collect (process-subfen x)))
 

