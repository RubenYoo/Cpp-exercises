#include <iostream>
#include <string>
#include "Stack.h"
#include "StackList.h"

using namespace std;

//prototypes
string infixToPostfix(string str);
int calcPostfix(string postfix);

int main()
{
    //declaring new string
	string exp;

	cout << "enter an infix expression as a string" << endl;

    //read the infix expression into the string
	cin >> exp;

    //declaring new variable that content the postfix expression
	string postfix = infixToPostfix(exp);

    //print the postfix expression
	cout << postfix<<endl;

    //calculate and print the result
	cout << calcPostfix(postfix)<<endl;
	return 0;
}

//this func, receive a string, transform into postfix and the return the new string
string infixToPostfix(string exp)
{
    //declaring variables
    string str;
    StackList stk;

    int length = exp.length();
    int i = 0;
    char ch = exp[i];

    while(i < length)
    {
        if(ch == '(')                                               //if ch == ( push it into the stack
            stk.push(ch);
        else if(ch == ')')                                           //if ch == ) pop all the members in the stack
        {
            str += ' ';
            char tmp = stk.top();
           
            while(tmp != '(' )
            {
                str+= tmp;
                stk.pop();
                tmp = stk.top();
            }
            stk.pop();
        }
        else if(ch == '+' || ch == '-' || ch == '*' || ch == '/')       //if ch is an operator, check the priority and move the operators 
        {                                                               //at the end of the string
            str += ' ';
            if(!stk.isEmpty())
            {
                char tmp2 = stk.top();
                while(tmp2 != '(')
                {
                    if((ch == '+' || ch == '-') && (tmp2 == '*' || tmp2 == '/'))
                    {
                        str += stk.pop();
                        tmp2 = stk.top();
                    }
                }
            }
            stk.push(ch);
        }
        else if(ch >= '0' && ch <= '9')                                 //if ch is a num, push it into the stack
            str += ch;

        i++;
        ch = exp[i];
    }

    while(!stk.isEmpty())                                               //pop all the operators of the satck into the string
    {
        str += ' ';
        str += stk.top();
        stk.pop();
    }
    return str;
}
//this func receive a string in a postfix expression and then calculate the sum, and return the result
int calcPostfix(string postfix)
{
    //declaring the variables
    StackList stk;
    int length = postfix.length();
    int i = 0;

    while (i < length)
    {
        //if postfix[i] is a num, push it into a stack
        if(postfix[i] != '+' && postfix[i] != '-' && postfix[i] != '*' && postfix[i] != '/' &&  postfix[i] != ' ')
           {
               string tmp;
               tmp += postfix[i];
               while (postfix[i] != ' ')
               {
                   i++;
                   tmp += postfix[i];
               }
              
                stk.push(stoi(tmp));
           }
           //if postfix[i] is an operator, calculate the operation and push the result into the stack
           else if( postfix[i] != ' ')
           {
               int tmp1, tmp2;
               tmp1 = stk.pop();
               tmp2 = stk.pop();
               switch (postfix[i])
               {
               case '+':
                   stk.push(tmp2+tmp1);
                   break;
               case '-': 
                    stk.push(tmp2-tmp1);
                    break;
                case '*':
                    stk.push(tmp2*tmp1);
                    break;
                case '/':
                    stk.push(tmp2/tmp1);
                    break; 
               default:
                   break;
               }
           }
           i++;
    }

    return stk.top();
}
/*
enter an infix expression as a string
(5+3)*((20/10)+(8-6)) 
5 3 + 20 10 / 8 6 - + *
32
*/
