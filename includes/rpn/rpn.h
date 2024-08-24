
#ifndef RPN_H
#define RPN_H

#include <iostream>
#include <cmath>

#include "../../includes/token/token.h"
#include "../../includes/queue/MyQueue.h"
#include "../../includes/stack/MyStack.h"
#include "../../includes/shunting_yard/shunting_yard.h"
#include "../../includes/node/node.h"
#include "../../includes/linked_list_functions/linked_list_functions.h"

using namespace std;


class RPN {
public:
    RPN() {}
  
    RPN(const Queue<Token*>& postfix) : postf_(postfix) {}

    Queue<Token*> set_input(Queue<Token*>& input) {
        postf_ = input;
        return postf_;
    }

    double rpn(double value) {
        Stack<double> s;
        Queue<Token*>::Iterator walker = postf_.begin();
        while (walker != nullptr) {
            int type = (*walker)->type();

            if (type == 1) {
                double answer = static_cast<Integer*>(*walker)->int_only();
                s.push(answer);
            }
            else if (type == 2 && static_cast<Operator*>(*walker)->Prece_Type() == 6) {
                s.push(value);
            }

            else if (type == 2 && static_cast<Operator*> (*walker)->Prece_Type() == 7){
                double int1 = s.pop();
                Token* operators = *walker;
                Token* result = static_cast<Operator*>(operators)->eval_trig(int1);
                double opresult = static_cast<Integer*>(result)->int_only();
                s.push(opresult);
            }

            else if (type == 2) {
                double int2 = s.pop();
                double int1 = s.pop();
                Token* operators = *walker;
                Token* result = static_cast<Operator*>(operators)->eval(int1, int2);
                double opresult = static_cast<Integer*>(result)->int_only();
                s.push(opresult);
            }
            walker++;
        }
        double answer = s.pop();
        return answer;
    }

    double operator()(double value = 0) {
        return rpn(value);  
    }

private:
    Queue<Token*> postf_;
};

#endif