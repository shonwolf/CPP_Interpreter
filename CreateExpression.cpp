/***********************
* shon wolf
* 208581660
* 8921004
* project_part_1
**********************/
#include "CreateExpression.h"

/****************************************************************************************************
* function name: this is constructor.
* The Input: nothing.
* The output: nothing.
* The Function operation: initialize the members with the data.
****************************************************************************************************/
CreateExpression::CreateExpression() {
    this->m_stepsForward = 0;
}

/****************************************************************************************************
* function name: fromExpression.
* The Input: vector<string> expression, const VariablesData* variablesData.
* The output: the expression made from the prefix representation.
* The Function operation: this function return the expression made from the prefix representation.
****************************************************************************************************/
Expression* CreateExpression::fromExpression(vector<string> expression, VariablesData* variablesData) {
    // if it's number or variable just return the value
    if (expression.size() == 1) {
        if (variablesData->getSymbolTable().count(expression[0]) == 0) {
            return new Number(stod(expression[0]));
        } else {
            return new Number(variablesData->getSymbolTable().at(expression[0]));
        }
    }
    vector<string> translateExpression = {};
    // convert all the variables to there values
    for (auto &curString : expression) {
        if (variablesData->getSymbolTable().count(curString) == 1) {
            translateExpression.push_back(to_string(variablesData->getSymbolTable().at(curString)));
        } else {
            translateExpression.push_back(curString);
        }
    }
    translateExpression = this->convertUnaryPartsToBinary(translateExpression);
    // get the postfix of the expression (when looking from the left side)
    queue<string> q = this->getPostfixUsingShuntingYardAlgorithm(translateExpression);
    // put the queue in vector
    vector<string> postfix = {};
    // put all the variables from the queue into the vector
    while (!q.empty()) {
        postfix.push_back(q.front());
        q.pop();
    }
    Expression* exp = this->createExpression(postfix, postfix.size() - 1);
    return exp;
}

/****************************************************************************************************
* function name: getPostfixUsingShuntingYardAlgorithm.
* The Input: vector<string> expression.
* The output: the postfix of expression in queue.
* The Function operation: this function calculate the postfix of the expression that she gets using
*                         Shunting Yard Algorithm and return it in a queue.
****************************************************************************************************/
queue<string> CreateExpression::getPostfixUsingShuntingYardAlgorithm(vector<string> expression) {
    queue<string> q;
    stack<string> s;
    int i = 0;
    int size = expression.size();
    // here I am executing Shunting Yard Algorithm to get the Expression
    while (i < size) {
        if (isdigit(expression[i][0])) {
            // if this is number
            q.push(expression[i]);
        } else if (this->isOperator(expression[i])) {
            // if this is operator
            // while there is operator at the top of the stack with greater precedence
            while ((!s.empty()) && this->fromStackHasGreaterPrecedence(expression[i], s.top())) {
                q.push(s.top());
                s.pop();
            }
            s.push(expression[i]);
        } else if (expression[i] == "(") {
            // start of expression
            s.push(expression[i]);
        } else {
            // end of expression
            // while there is not a "(" at the top of the stack
            while ((!s.empty()) && s.top() != "(") {
                q.push(s.top());
                s.pop();
            }
            // pop the "("
            s.pop();
        }
        i++;
    }
    // while there is an operator at the top of the stack
    while ((!s.empty()) && this->isOperator(s.top())) {
        q.push(s.top());
        s.pop();
    }
    return q;
}

/****************************************************************************************************
* function name: isOperator.
* The Input: string s.
* The output: true if s is operator, false otherwise.
* The Function operation: this function return yes if s is operator, else otherwise.
****************************************************************************************************/
bool CreateExpression::isOperator(string s) {
    if (s == "+" || s == "-" || s == "/" || s == "*") {
        return true;
    }
    return false;
}

/****************************************************************************************************
* function name: fromStackHasGreaterPrecedence.
* The Input: string curOperator, string operatorFromStack.
* The output: yes if the operator at the top of the stack has greater precedence, else otherwise.
* The Function operation: this function return yes if the operator at the top of the stack has
*                         greater precedence, else otherwise.
****************************************************************************************************/
bool CreateExpression::fromStackHasGreaterPrecedence(string curOperator, string operatorFromStack) {
    if ((curOperator == "+" || curOperator == "-") && (operatorFromStack == "+" || operatorFromStack == "-")) {
        return false;
    } else if ((curOperator == "*" || curOperator == "/") && (operatorFromStack == "*" || operatorFromStack == "/")) {
        return false;
    } else if ((curOperator == "+" || curOperator == "-") && (operatorFromStack == "*" || operatorFromStack == "/")) {
        return true;
    } else {
        return false;
    }
}

/****************************************************************************************************
* function name: convertUnaryPartsToBinary.
* The Input: vector<string> expression.
* The output: the update expression witch every unary part converted to binary part.
* The Function operation: this function return the update expression witch every unary part
*                         converted to binary part.
****************************************************************************************************/
vector<string> CreateExpression::convertUnaryPartsToBinary(vector<string> expression) {
    vector<string> tempUpdate = {};
    int i = 0;
    int size = expression.size();
    // if -num coming in as one string - "-5" for example and not {"-", "5"}, than make it {"-", "5"}
    for (; i < size; i++) {
        if (!isOperator(expression[i]) && expression[i][0] == '-') {
            tempUpdate.push_back("-");
            tempUpdate.push_back(expression[i].substr(1, expression[i].length()));
        } else {
            tempUpdate.push_back(expression[i]);
        }
    }
    expression = tempUpdate;
    tempUpdate = {};
    i = 0;
    size = expression.size();
    // if see --(num) make it (num)
    for (; i < size; i++) {
        if (expression[i] == "-" && expression[i + 1] == "-") {
            if (i != 0) {
                tempUpdate.push_back("+");
            }
            i += 2;
        }
        tempUpdate.push_back(expression[i]);
    }
    expression = tempUpdate;
    tempUpdate = {};
    i = 0;
    // if there is (+ or -)(num) than make it (0 (+ or -) num)
    if (this->isOperator(expression[0])) {
        i++;
        tempUpdate.push_back("(");
        tempUpdate.push_back("0");
        tempUpdate.push_back(expression[0]);
        i++;
        tempUpdate.push_back(expression[1]);
        tempUpdate.push_back(")");
    }
    size = expression.size();
    // if there is (+ or -)(num) than make it (0 (+ or -) num)
    for (; i < size; i++) {
        tempUpdate.push_back(expression[i]);
        if (this->isOperator(expression[i]) && this->isOperator(expression[i + 1])) {
            i++;
            tempUpdate.push_back("(");
            tempUpdate.push_back("0");
            tempUpdate.push_back(expression[i]);
            i++;
            tempUpdate.push_back(expression[i]);
            tempUpdate.push_back(")");
        }
    }
    return tempUpdate;
}

/****************************************************************************************************
* function name: createExpression.
* The Input: vector<string> prefix, int start.
* The output: the Expression to make from the prefix representation in the vector.
* The Function operation: this function create the Expression made from the prefix representation
*                         in the vector and return it.
****************************************************************************************************/
Expression* CreateExpression::createExpression(vector<string> postfix, int end) {
        BinaryExpression* binExp = this->getNewBinaryExpression(postfix[end]);
        Expression* left;
        Expression* right;
        // get the right expression
        if (!(this->isOperator(postfix[end - 1]))) {
            right = new Number(stod(postfix[end - 1]));
            this->m_stepsForward = end - 1;
        } else {
            // recursive call to this function to get the expression
            right = this->createExpression(postfix, end - 1);
        }
        // get the left expression
        if (!(this->isOperator(postfix[this->m_stepsForward - 1]))) {
            left = new Number(stod(postfix[this->m_stepsForward - 1]));
            this->m_stepsForward--;
        } else {
            // recursive call to this function to get the expression
            left = this->createExpression(postfix, this->m_stepsForward - 1);
        }
        binExp->setLeft(left);
        binExp->setRight(right);
        return binExp;
}

/****************************************************************************************************
* function name: getNewBinaryExpression.
* The Input: string op.
* The output: the BinaryExpression by the operator.
* The Function operation: this function return the BinaryExpression by the operator.
****************************************************************************************************/
BinaryExpression* CreateExpression::getNewBinaryExpression(string op) {
    char c = op[0];
    switch (c) {
        case '+':
            return new Plus(nullptr, nullptr);
        case '-':
            return new Minus(nullptr, nullptr);
        case '/':
            return new Div(nullptr, nullptr);
        case '*':
            return new Mul(nullptr, nullptr);
        default:
            return nullptr;
    }
}
