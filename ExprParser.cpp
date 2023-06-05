#include "ExprParser.h"

#include "Stack.h"

std::string ExprParser::parseExpr(const std::string& expr) {
  CheckBracketsNum(expr);
  std::string infix = '(' + expr + ')';
  std::string postfix = "";

  Stack<std::string> st_string;

  for (int i = 0; i < infix.size(); i++) {
    if (infix.at(i) == ' ') continue;

    if (infix.at(i) <= '9' && infix.at(i) >= '0') {
      // считывание числа целиком, а не по одной цифре
      size_t ind;
      double num = std::stod(&infix.at(i), &ind);
      postfix += std::to_string(num);
      postfix += ' ';
      i += ind - 1;
      continue;
    }

    if (infix.at(i) == '(') {
      st_string.push("(");
      continue;
    }

    if (infix.at(i) == ')') {
      while (st_string.top() != "(") {
        postfix += st_string.pop() + " ";
      }
      st_string.pop();
      continue;
    }

    if (isOperator(infix.at(i))) { // если попался оператор, то выяснить его приоритет
      while (Priority(st_string.top().at(0)) >= Priority(infix.at(i))) {
        postfix += st_string.pop(); // все операции из стека с приоритетом выше и равным записываем в постфиксную строку
        postfix += " ";
      }

      st_string.push(std::string(1, infix.at(i))); // кладём операцию на стек
      continue;
    }
  }
  return postfix;
}

// метод для проверки правильного количества скобок. количество закрываюищих и
// открывающих скобок должно быть равно
bool ExprParser::CheckBracketsNum(const std::string& expr) {
  int size = expr.size();
  int brackets_num = 0;  // переменная увеличивается на 1, если встретилась (,
                         // иначе уменьшается на 1.
  // в итоге прохода по всему выражению, эта переменная должно хранить ноль

  for (int i = 0; i < size && brackets_num >= 0; i++) {
    if (expr.at(i) == '(') {
      ++brackets_num;
    } else if (expr.at(i) == ')') {
      --brackets_num;
    }
  }

  if (brackets_num > 0) {
    throw std::runtime_error("Invalid expression. '(' more than ')'\n");
  } else if (brackets_num < 0) {
    throw std::runtime_error("Invalid expression. ')' more than '('\n");
  }

  return 1;
}

bool ExprParser::isOperator(char symbol) {
  char operators[] = {'+', '-', '*', '/'};
  int size = 4;

  for (int i = 0; i < size; i++)
    if (symbol == operators[i]) return true;

  return false;
}

char ExprParser::Priority(char op) {
  if (op == '(') return 0;
  if (op == '+' || op == '-') return 1;
  if (op == '*' || op == '/') return 2;
}
