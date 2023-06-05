#pragma once

#include <string>

class ExprParser {
 public:
  static std::string parseExpr(const std::string&); // ������� ��������� �� ��������� ����� � �����������
  static bool isOperator(char symbol);  // ���������, �������� �� ������ ���������� +, -, / ��� *
 private:
  static bool CheckBracketsNum(const std::string&); // ��������� ���������� ������ (������ ��� ���)  
  static char Priority(char op); // ���������� ��������� ���������
};
