// Infix to Postfix then Evaluating Postfix using c++

#include <iostream>
#include <cmath>
#include <string>
#include "stacktype.cpp"

double evaluate(char c, double a, double b)
{
    if(c == '+')
    {
        return a + b;
    }
    else if(c == '-')
    {
        return a - b;
    }
    else if(c == '*')
    {
        return a * b;
    }
    else if(c == '/')
    {
        return a / b;
    }
    else return (std::pow(b, a));
}
bool is_operator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

bool is_number(char c)
{
    int temp = c - '0';

    return (temp >= 0 && temp <= 9);
}

int precedence(char c)
{
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}


int main()
{
    StackType<char> operands = StackType<char>();

    std::string equation;
    std::getline(std::cin, equation);

    std::string postFix = "";
    std::string temp = "";

    bool unbalance = false;

    // Infix to Postfix

    for(char c: equation)
    {
        if(is_number(c))
        {
            temp += c;
        }
        else
        {
            if(temp != "")
            {
                postFix += temp;
                temp = "";
                postFix += '.';
            }

            if(is_operator(c))  // Appending to postfix until the top precedence is lower
            {
                while(!operands.IsEmpty() && precedence(c) <= precedence(operands.Top()))
                {
                    postFix += operands.Top();
                    operands.Pop();
                }

                operands.Push(c);
            }
            else if(c == '(')
            {
                operands.Push('(');
            }
            else if(c == ')')
            {
                bool found = false;

                while(!operands.IsEmpty() && operands.Top() != '(') // Appending until we find the open paran
                {
                    postFix += operands.Top();
                    operands.Pop();

                    if(operands.Top() == '(')
                    {
                        found = true;
                    }
                }

                if(found == false)
                {
                    unbalance = true;
                    break;
                }else operands.Pop();
            }
            else continue;
        }
    }

    if(temp != "")
    {
        postFix += temp;
    }
    if(!operands.IsEmpty())
    {
        while(!operands.IsEmpty())
        {
            postFix += operands.Top();
            operands.Pop();
        }
    }

    //std::cout << "Postfix = " << postFix <<"\n";

    // interpreting Postfix

    double res = 0;
    StackType<double> values = StackType<double>();

    int idx = 0;
    while(idx < postFix.length())
    {
        if(is_number(postFix[idx]))     // For checking for number with multiple digits and converting to int
        {
            std::string temp = "";

            while(is_number(postFix[idx]))
            {
                temp += postFix[idx];
                idx++;
            }

            int t = std::stoi(temp);
            values.Push(t);
        }
        else if(is_operator(postFix[idx]))  // Pop the first two item and evaluate expression, error if empty
        {
            if(values.IsEmpty()){
                unbalance = true;
                break;
            }
            double t1 = values.Top();
            values.Pop();
            if(values.IsEmpty()){
                unbalance = true;
                break;
            }
            double t2 = values.Top();
            values.Pop();

            double t = evaluate(postFix[idx], t2, t1);
            values.Push(t);
            idx++;
        }
        else idx++;
    }

    if(unbalance || values.IsEmpty()){
        std::cout << "Invalid expression\n";
    }else std::cout << values.Top();

    return 0;
}
