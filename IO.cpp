#include "IO.h"
#include <iostream>

using namespace std;

/**
 * 显示欢迎信息
 */
void IO::greet() {
  cout << "============= 电网建设造价模拟系统 =============" << endl;
  cout << "=               A --- 创建顶点               " << endl;
  cout << "=               B --- 添加边                 " << endl;
  cout << "=               C --- 构造并显示最小生成树     " << endl;
  cout << "=               D --- 退出程序               " << endl;
  cout << "============================================" << endl;
};


/**
 * 提示输入
 * @param  message 要显示的提示信息
 * @return         用户输入数据
 */
string IO::prompt(string message) {
  string result;
  cout << message;
  cin >> result;
  return result;
};

/**
 * 输出一行消息
 * @param message 要显示的信息
 */
void IO::put(string message) {
  cout << message << endl;
};