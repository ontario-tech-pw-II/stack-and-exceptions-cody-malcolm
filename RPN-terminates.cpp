// Cody Malcolm
// March 29th, 2020
// CSCI 1061U - Stack and Exceptions Activity

/* In addition to the required exceptions, also caught exceptions where the user
tries to divide by zero, and where the user immediately enters "q" */

// Program terminates if an error is found

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

    cin >> in;
    try {
      if (in == "q") throw EmptyStackError();

      int value1, value2, value3;

      while(in != "q")
      {
        if(is_str_digit(in)){
          // add your code here
          st.push(in);
        }
        else if(is_str_operator(in))
        {
          // add your code here
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
            if (value1 == 0) throw DivideByZeroError();
            value3 = value2 / value1;
            break;

          }

          // add your code here
          st.push(to_string(value3));

        } else {
          throw InvalidInputError();
        }

        cin >> in;
        if (in == "q" && st.size() != 1) throw TooManyOperandsError();
      }

      cout << "The answer is : " << st.top() << endl;
    } catch (DivideByZeroError) {
      cout << "Cannot divide by zero!" << endl;
    } catch (TooFewElementsError) {
      cout << "Not enough operands!" << endl;
    } catch (TooManyOperandsError ) {
      cout << "There are too many operands on the stack!" << endl;
    } catch (InvalidInputError) {
      cout << "Please enter an operator, operand, or \"q\"!" << endl;
    } catch (EmptyStackError) {
      cout << "Aborting program without input!" << endl;
    }

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
