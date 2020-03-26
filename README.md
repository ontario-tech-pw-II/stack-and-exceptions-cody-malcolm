## Stack and Exception

Learning outcomes highlights: 
- How to use the stack via an interesting application
- Designing an exception class in C++

### Task1: Reverse Polish Calculator
Reverse Polish Notation (RPN) or postfix notation is a format to specify mathematical expressions.  In RPN the operator comes after the operands instead of the more common format in which the operator is between the operands (this is called infix notation). For example, PRN of ((10 – (2+3))*2)/5 is
> 10 2 3 + - 2 * 5 /

**Problem:** The goal is to use the stack template class to implement a RPN calculator. The program reads the input which is the PRN like 10 2 3 + - 2 * 5 / q (q shows the end of input) and calculates the expression. In our example, the output is:
> The answer is : 2

The algorithmm that you need to implement is as follows:

Starting with an empty stack, read the tokens (numbers and operators) in input one by one:
 - If a number is input, push it on the stack
 - If “+” is input then pop the last two operands off the stack, add them, and push the result on the stack
 - If “-“ is input then pop value1, pop value2, then push value2 - value1 on the stack
 - If “*” is input then pop the last two operands off the stack, multiply them, and push the result on the stack
 - If “/” is input them pop value1, pop value2, then push value2 / value1 on the stack
 - If “q” is input them stop inputting values, print out the top of the stack, and exit the program
Use the stack template class to implement a RPN calculator.  Output an appropriate error message if there are not two operands on the stack when given an operator.  Here is sample input and output that is equivalent to ((10 – (2+3))*2)/5:

Use the stack template class to implement a RPN calculator. Here is sample input and output that is equivalent to ((10 – (2+3))*2)/5:
10 2 3 + - 2 * 5 / q

The starter code is as follows (you need to add your code as indicted by comments):
```C++
// RPN calculator

#include <iostream> 
#include <string>
#include <stack> 

using namespace std;
bool is_str_digit(string);  // returns true if input parameter string is and integer (e.g., "127343")
bool is_str_operator(string); // returns true if the input parameter is an operator character (e.g., "+", "*")


int main() 
{
    string in;
    stack<string> st;   // stack definition

    cin >> in;

    while(in != "q")
    {
        if(is_str_digit(in)){
            // add your code here
        }
        else if(is_str_operator(in))
        {
            // add your code here 

            switch(in[0])
            {
                case '+':
                    value3 = value2 + value1;
                    break;

                case '-':
                    value3 = value2 - value1;
                    break;

                case '*':
                    value3 = value2 * value1;
                    break;

                case '/':
                    value3 = value2 / value1;
                    break;

            }

            // add your code here

        }
        cin >> in;
    }
```
## Task2: Implement exception mechanism
In the previous task, we assumed that the user input is always correct. Rewrite the program and implement exception mechanisms that can handle different errors in the input. The program should <code>throw</code> different exceptions (could be an object or just an integer), and have an appropriate catch statement to handle these cases: 
 - There are not at least two operands on the stack when given an operator.
 - There are unexpected input(s) which are not operator (+,-, *, / ) nor an integer.
 - There are more than one item on the stack when we want to print the result. 
