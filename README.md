# LC
My leetcode sulotions

##36 Valid Sudoku
1. The general idea is to keep three "check lists" : rows, columns and 3*3 boxes. Actually, this is how human beings would check if the sudoku is valid.
2. The takeaway : ponder on how humans would do the job.
3. Bug : Index out of bounds. The array's max index is 8. Do not use the numbers in the sudoku as indexes of the array. 

