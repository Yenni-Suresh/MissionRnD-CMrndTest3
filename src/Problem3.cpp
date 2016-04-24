/*
Given a Tree which consists of operands and operators ,Solve the Tree and return the result
The tree will have special nodes of type enode which will have 3 fields
data => String of 5 chars .which can be either a operator or operand 
If its a operator its values will be one of the 3 following strings "+" , "-" , "*".
If its a operand its values will be any number from -9999 to 99999 in its respective string format;
Left and Right pointers will point to either NULL or another enode
Only the leaf nodes will have operand values .

Example 1:
    +
   / \
  4   5 
The Result expression is : 4+5 ,Ans is 9

Example 2:
        *
       / \
      -   5
     / \
    7   2

The Result expression is : (7-2) * 5  ,Ans is 25

Example 3:
       +
     /   \
    *     -  
   / \   / \
  7   2  4  *
           / \
          2   1
  
The Result expression is : (7*2) + (4-(2*1)) =>14+2 =>16 ,Ans is 16 

Constraints : 
Total number of enodes will be <=20 for 50% of Test cases
Data value will only have "0"<=data<="99999" values for 50% of cases .
Data value for operators will have sign as first character and \0 as next character .

Input :
Root node of a Tree of type enode
Output :
Return Final answer or -1 for Null inputs

Note :
->Dont Create an Extra Array/String ,or else your solution would receive 20%-40% Cut in the Marks you got .

Difficulty : Medium
*/
#include <stdlib.h>;
#include <stdio.h>

//data can be accessed using root->data;
struct enode{
	char data[6];
	struct enode *left;
	struct enode *right;
};

/*
Helper Functions are optional to write 
*/
//Helper Functions Start
int isOperator(char *data){

	if (data[0] == '+' || data[0] == '-' || data[0] == '*') return 1;
	return 0;
}
int getOperand(char *data){

	int i = 0, digit_multiple = 1, result = 0;
	while (data[i] != '\0')
	{
		i++;
	}
	i--;
	while (i >= 0)
	{
		result = result + (data[i] - 48) * digit_multiple;
		digit_multiple = digit_multiple * 10;
		i--;
	}
	return result;
}
//Helper Functions end
int solve(int val1, int val2, char *oper)
{
	if (oper[0] == '+')
		return val1 + val2;
	if (oper[0] == '-')
		return val1 - val2;
	return val1 * val2;
}
int solve_tree(struct enode *root){

	if (root == NULL) return -1;
	int val1 = 0, val2 = 0;
	if (root->left) val1 = solve_tree(root->left);
	if (root->right) val2 = solve_tree(root->right);
	if (isOperator(root->data) == 1) return solve(val1, val2, root->data);
	return getOperand(root->data);
}

