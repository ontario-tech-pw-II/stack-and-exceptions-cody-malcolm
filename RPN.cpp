// Cody Malcolm
// March 28th, 2020
// CSCI 1061U - Stack and Exceptions Activity

/* In addition to the required exceptions, also caught exceptions where the user
tries to divide by zero, and where the user immediately enters "q" */

// Program continues running (user can fix stack and terminate normally)

// RPN calculator

#include <iostream>
#include <string>
#include <stack>

using namespace std;
bool is_str_digit(string);  // returns true if input parameter string is and integer (e.g., "127343")
bool is_str_operator(string); // returns true if the input parameter is an operator character (e.g., "+", "*")

class DivideByZeroError {};
class TooFewElementsError {};
class TooManyOperandsError {};
class InvalidInputError {};
class EmptyStackError {};

int main()
{
    string in;
    stack<string> st;   // stack definition

    try {
      cin >> in;
      if (in == "q") throw EmptyStackError();
    } catch (EmptyStackError) {
      do {
        cout << "Please enter an operator or operand: " << endl;
        cin >> in;
      } while (in == "q");
    }

    int value1, value2, value3;

    while(in != "q")
    {
      try {
        if(is_str_digit(in)){
          // add your code here
          st.push(in);
        }
        else if(is_str_operator(in))
        {
          // add your code here
          try {
            if (st.size() < 2) throw TooFewElementsError();
            value1 = stoi(st.top());
            st.pop();
            value2 = stoi(st.top());
            st.pop();

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
              try {
                if (value1 == 0) throw DivideByZeroError();
                value3 = value2 / value1;
              } catch (DivideByZeroError) {
                cout << "Cannot divide by zero...removing last entered operand and operator." << endl;
                value3 = value2;
              }
              break;

            }

            // add your code here
            st.push(to_string(value3));

          } catch (TooFewElementsError) {
            cout << "Please add more operands before adding an operator." << endl;
          }
        } else {
          throw InvalidInputError();
        }

      } catch (InvalidInputError) {
        cout << "That input was not valid" << endl;
      }
      try {
        cin >> in;
        if (in == "q" && st.size() != 1) throw TooManyOperandsError();
      } catch (TooManyOperandsError) {
        do {
          cout << "There are still multiple operands on the stack." << endl;
          cout << "Please enter an operator or operand: ";
          cin >> in;
        } while (in == "q");
      }
    }

    cout << "The answer is : " << st.top() << endl;

    return 0;
}

bool is_str_digit(string s)
{
    for (int i = 0; i < s.length(); ++i)
    {
            if(!isdigit(s[i]))
                return false;
    }
    return true;
}
bool is_str_operator(string s)
{
    return (s.length()==1 && (s[0] == '+' || s[0] == '-' || s[0] == '*' || s[0]== '/'));
}
