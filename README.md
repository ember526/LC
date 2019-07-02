# LC
My leetcode sulotions
### 7.Reverse Integer
1. When implementing %d in vprintf, we do the job in the same way. It works like two stacks : push every element poped out from the original stack into a new stack, but without extra data structures.
2. Notice how to check overflow : check before pushing elements into the new stack.
### 36.Valid Sudoku
1. The general idea is to keep three "check lists" : rows, columns and 3*3 boxes. Actually, this is how human beings would check if the sudoku is valid.
2. The takeaway : ponder on how humans would do the job.
3. Bug : Index out of bounds. The array's max index is 8 instead of nine. Do not use the numbers in the sudoku as indexes of the array. 
### 125.Valid Palindrome
1. Good helpers with strings : isalpha, isalnum and tolower.
2. "Ignoring cases" means "a==A", rather than "there are no upper case letters".
### 237.Delete Node in a Linked List
1. The idea of this "wield" solution is to make THIS node become its NEXT node. Normally, the annoying part of removing a node from a linked list is that the predecessor has to be found and the predecessor should point to another node. But in this solution, we can ignore the predecessor.
### 242.Valid Anagram 
1. The concept of the anagram is having same numbers of all the letters, and that is how the work is done.
2. An alternative is to sort both of the strings and use operator == to check if they are the same.

### 387.First unique character in a string
1. We cannot tell if a character is unique unless we have checked it against the whole string; and we also need to find the first unique one. So in the first round, we can record the occurence of every charactor; and in the second round, we find the first unique one.

