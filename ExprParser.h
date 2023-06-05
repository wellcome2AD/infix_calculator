#pragma once

#include <string>

class ExprParser {
 public:
  static std::string parseExpr(const std::string&); // перевод выражения из инфиксной формы в постфиксную
  static bool isOperator(char symbol);  // проверяет, является ли символ оператором +, -, / или *
 private:
  static bool CheckBracketsNum(const std::string&); // проверяет количество скобок (верное или нет)  
  static char Priority(char op); // возвращает приоритет оператора
};
