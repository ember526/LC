# LC
My leetcode sulotions
### 5.Longest Palindromic Substring
1. The general idea is to expand the substring from one position to two sides.
2. Also notice that, there are actually two kinds of palindrome : those with one centre and those with two centres. So before expanding the substring outwards, we deal with the central part first.
### 7.Reverse Integer
### 13.Roman to Integer
1. One rule to decide when a roman charactor should be added to or subtracted from the sum : when it denotes a smaller number than the next one, it should be subtracted; otherwise added.
### 15.3 Sum
1. Fix one number, then find the other two numbers. The time complexity is n square, while the brute force solution (fix two numbers and search for the third one) is n cube. Since we need to find all the solutions without duplicates, we can sort the array before the search work.
2. As we move two iterators inward, we can expect that we don't miss out any cases. It can be proven easily.
3. An important issue is to make sure that the result does not contain any duplicates (the array may have identical elements). It is easy to ignore that the fixed number may find its duplicate.
4. It seems that using sort() on empty vector leads to error.
### 20.Valid Parentheses
1. Attemp to use top() or pop() on an empty stack would result in runtime error.
### 36.Valid Sudoku
1. The general idea is to keep three "check lists" : rows, columns and 3*3 boxes. Actually, this is how human beings would check if the sudoku is valid.
2. The takeaway : ponder on how humans would do the job
3. Bug : Index out of bounds. The array's max index is 8 instead of nine. Do not use the numbers in the sudoku as indexes of the array. 
### 46.Permutation
1. The general idea is to estimate the way humans would produce all the permutations.
2. Notice that we have to swap the current position with itself.
### 70.Climbint Stairs
0. Very basic dynamic programming problem, 
1. First question to think about : is the question of a smaller scale and that of a bigger scale *essentially*the same. If they are, we would call the one of a smaller scale 'the subproblem'; then we have more questions to ask based on the principles of DP:
3. We need a handy data structure to store the number of solutions to the  solved subproblems. And we would need to look it up later. In this case, we only need constant storage for this purpose actually, since one subprolem only contributes to exactly two problems in all and it would become useless after 2 consequtive iterations.
### 75.Sort Colors
1. It is easy to assume that we can always move the i forward in every iteration, while there would be a  problem when nums[i] == 2.
2. Partition, quick sort;
### 78.Subsets
1.Typical backtracking problem, refer to No.46 permutations.
### 88.Merge Sorted Array
1. Fill the array from the back of nums1. Very interesting operations on the array.
### 94.Binary Tree Inorder Traversal (iterative)
1. Morris Traversal : a)Do as humans would do : always go to the most left leaf and push every node on the way into the todo stack. b)For every node that we visit, we clime on its right subtree and take the right node as the new root, then repeat the above actions.
### 103.Binary Tree Zigzag Level Order Traversal
1. Nearly same thing as normal level order traversal : use a queue to keep all the nodes that we are going to visit, and for every iteration , first put every node's value into a vector and then enqueue their child nodes for the next iteration.
2. The only trick here is to have a bool variable to indicate which direction we are going and it only affects the position in the vector that we put the node's value (i or size - 1 - i).
### 125.Valid Palindrome
1. Good helpers with strings : isalpha, isalnum and tolower.
2. "Ignoring cases" means "a==A", rather than "there are no upper case letters".
### 155.Min Stack
1. Notice that this question requires a stack, which can give its min in O(1) time.
 It gets to do that by pushing its old MIN into stack (again) every time a same or smaller MIN comes in; and when MIN pops out, the next element on the stack is the second smallest which then serves as the new MIN. Notice that we would "update" MIN even the new comer is equal to the MIN; we do this because such new comers have the rightful claim to the MIN and this value would still be the MIN even if one of such values pops out.
### l69.Majority Element
1. Boyer-Moore Voting Algorithm https://leetcode.com/articles/majority-element/
### 172.Factorial Trailing Zeroes
1. We have much more 2s than 5s, so we only need to count 5s.
2. Notice that the calculation would take 25 twice.
### 191.Number of 1 Bits
1. Given n, if we let n & n - 1, then we have exactly one less 1 bit in n. If we keep doing it until n is zero, we have the number of 1 bits.
2. It is rather to prove that. Just use the basic conditions.
### 202.Happy Number
1. Use slow and fast to detect circle.
2. Notice that slow and fast may equal to 1 after iterations
### 215.Kth Largest Element in an Array
TODO. Use heap to solve the problem
1. Partitioning is the right tool to achieve this.

### 230.Kth Smallest Element in a BST
1. Very typical iterative inorder traversal with stack. Such format has been widely used.
### 237.Delete Node in a Linked List
1. The idea of this "wield" solution is to make THIS node become its NEXT node. Normally, the annoying part of removing a node from a linked list is that the predecessor has to be found and the predecessor should point to another node. But in this solution, we can ignore the predecessor.
### 242.Valid Anagram 
1. The concept of the anagram is having same numbers of all the letters, and that is how the work is done.
2. An alternative is to sort both of the strings and use operator == to check if they are the same.

### 268.Missing Number
1. Very simple solution : if we know a series of consecutive integers starting from 0 and its length, then we know the sum of them; after taking one of them away, the sum changes and we know which one.
2. We can use this solution because the condition given is very special : starting from 0, consequtive integers.
### 334.Increasing Triplet Subsequence
1. The question does not require that we should find all such subsequences. We only need to tell if such things do exist.
2. We need to look at things from a different perspective. Ask the question : what is an increasing triplet subsequence?
3. The interesting thing about this solution is that it amazingly integrate the If-Else Block with the inner nature of increasing subsequence.
4. PS : what is the thing that we can only go forward and cannot go back? Is there any other answer but time? Well, I am trying to work out a metophor to this question.
### 384.Shuffle an Array
1. As for the data members, we should always keep the original version as it is required by reset();
2. To generate a random permutation of a array, we have Fisher-Yates algorithms here : swap every element with a random element before it (or with itself);
3. When srand() is called to initialize the pseudo random number generator, the sequence of random numbers has been decided. 
### 387.First unique character in a string
1. We cannot tell if a character is unique unless we have checked it against the whole string; and we also need to find the first unique one. So in the first round, we can record the occurence of every charactor; and in the second round, we find the first unique one.
### 461. Hamming Distance
1. The exclusive-or of two numbers can indicate on which bits they differ. Then the number of 1 bits is the hamming distance of the two numbers (using question 191).

