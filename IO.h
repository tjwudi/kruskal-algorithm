#include <string>

using namespace std;

#ifndef IO_H
#define IO_H

class IO {
public:
  static void greet();
  static string prompt(string message);
  static void put(string message);
};

#endif