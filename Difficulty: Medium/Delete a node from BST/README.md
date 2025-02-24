<h2><a href="https://www.geeksforgeeks.org/problems/delete-a-node-from-bst/1">Delete a node from BST</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given a Binary Search Tree and a node value <strong>x</strong></span><span style="font-size: 18px;">. Delete the node with the given value x from the BST. If no node with value x exists, then <strong>do not</strong> make any change.&nbsp;</span><span style="font-size: 18px;">Return the root of the BST after deleting the node with value x.</span></p>
<p><strong style="font-size: 18px;">Note:&nbsp;</strong><span style="font-size: 18px;">The generated output will be the inorder traversal of the modified tree.</span></p>
<p><span style="font-size: 18px;"><strong>Examples :</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input: </strong>root = [2, 1, 3]
      2
&nbsp;   /   \
&nbsp;  1     3
x = 12
<strong>Output: </strong>1 2 3<strong>
Explanation: </strong>In the given input there is no node with value 12 , so the tree will remain same.</span>
</pre>
<pre><span style="font-size: 18px;"><strong>Input:</strong> root = [1, N, 2, N, 8, 5, 11, 4, 7, 9, 12]<br>  &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; 1
 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp;\
 &nbsp; &nbsp;    &nbsp; &nbsp; &nbsp; 2
 &nbsp; &nbsp;&nbsp; &nbsp;       &nbsp;&nbsp;\
 &nbsp; &nbsp; &nbsp;        &nbsp;  8 
&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;/&nbsp; &nbsp; \
 &nbsp; &nbsp; &nbsp; &nbsp;     &nbsp;5&nbsp;  &nbsp;  11
 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;/&nbsp; \&nbsp; &nbsp; /  \
 &nbsp; &nbsp; &nbsp;     4 &nbsp; &nbsp;7&nbsp; 9 &nbsp;&nbsp;12
x = 11
<strong>Output: </strong>1 2 4 5 7 8 9 12<strong>
Explanation: </strong>In the given input, tree after deleting 11 will be
&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;  1
&nbsp; &nbsp; &nbsp; &nbsp;   &nbsp; &nbsp;&nbsp;\
&nbsp; &nbsp;     &nbsp;  &nbsp; &nbsp; 2
&nbsp; &nbsp;&nbsp; &nbsp;        &nbsp; &nbsp;\
&nbsp; &nbsp; &nbsp;        &nbsp;  &nbsp; 8
&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;  &nbsp;  &nbsp;/  \
&nbsp; &nbsp; &nbsp; &nbsp;        &nbsp;5&nbsp; &nbsp; 12
&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp; / \&nbsp;&nbsp; /
&nbsp; &nbsp; &nbsp;         4 &nbsp; 7 9</span>&nbsp;</pre>
<pre><span style="font-size: 18px;"><strong>Input: </strong>root = [2, 1, 3]<strong><br></strong>      2
&nbsp;   /   \
&nbsp;  1     3
x = 3
<strong>Output: </strong>1 2<br></span><strong style="font-size: 18px; font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Roboto, Oxygen, Ubuntu, Cantarell, 'Open Sans', 'Helvetica Neue', sans-serif;">Explanation: </strong><span style="font-size: 18px; font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Roboto, Oxygen, Ubuntu, Cantarell, 'Open Sans', 'Helvetica Neue', sans-serif;">In the given input, tree after deleting 3 will be<br></span>     2
&nbsp;   /   
&nbsp;  1    </pre>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 &lt;= n &lt;= 10<sup>5</sup></span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Accolite</code>&nbsp;<code>Amazon</code>&nbsp;<code>Samsung</code>&nbsp;<code>Adobe</code>&nbsp;<code>Qualcomm</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Binary Search Tree</code>&nbsp;<code>Data Structures</code>&nbsp;