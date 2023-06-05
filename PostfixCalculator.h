
#ifndef POSTFIX_CALCULATOR_POSTFIXCALCULATOR_H
#define POSTFIX_CALCULATOR_POSTFIXCALCULATOR_H

#endif  // POSTFIX_CALCULATOR_POSTFIXCALCULATOR_H

#include <string>

#include "ExprParser.h"
#include "Stack.h"

class PostfixCalculator {
 public:
  PostfixCalculator();
  double calculate(std::string expression);

 private:
  Stack<double> st_double;
  bool isOperator(char symbol);
  void PushBinOperationResult(char op);
};

PostfixCalculator::PostfixCalculator() = default;
;

double PostfixCalculator::calculate(std::string expression) {
  std::string postfix = ExprParser::parseExpr(expression); // парсим пришедшую строку
  for (int i = 0; i < postfix.size(); i++) {
    if (postfix.at(i) <= '9' && postfix.at(i) >= '0') { // если очередной символ - цифра, то считываем число и кладём его на стек
      // считывание числа целиком, а не по одной цифре 
      size_t ind;
      double num = std::stod(&postfix.at(i), &ind);
      st_double.push(num);
      i += ind - 1;
      continue;
    }

    if (ExprParser::isOperator(postfix.at(i))) { // если очередной символ оператор, то выполняем операцию и кладём её на стек
      PushBinOperationResult(postfix.at(i));
      continue;
    }
  }
  return st_double.pop(); // результат хранится на стеке
}
bool PostfixCalculator::isOperator(char symbol) {
  char operators[] = {'+', '-', '*', '/'};
  int size = 4;

  for (int i = 0; i < size; i++)
    if (symbol == operators[i]) return true;

  return false;
}
void PostfixCalculator::PushBinOperationResult(char op) {
  if(st_double.size() < 2) {    
    throw std::runtime_error("Incorrect format of expression\n");
  } 
  double b = st_double.pop();
  double a = st_double.pop();
  
  // если оператор, то достаём два операнда и результат кладём на стек
  switch (op) {
    case '+': {
      st_double.push(a + b);
      break;
    }
    case '-': {
      st_double.push(a - b);
      break;
    }
    case '*': {
      st_double.push(a * b);
      break;
    }
    case '/': {
      if (b == 0) {
        throw std::runtime_error("Division by zero!");
      }
      st_double.push(a / b);
      break;
    }
  }
}
