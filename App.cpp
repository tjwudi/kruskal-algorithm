#include "App.h"
#include "IO.h"
#include <string>
#include <iostream>
#include <map>
#include <set>

using namespace std;

const int MAX_EDGE = 100;
int cnt_vertex = 0, cnt_edge = 0;
bool terminated = false;

struct edge
{
  string a;
  string b;
  int len;
};
bool operator<(const edge& lhs, const edge& rhs)
{
  return lhs.len < rhs.len;
}

set<edge> edges;
set<string> names;


App::App()
{
  // 显示欢迎信息
  IO::greet();

  while (!terminated)
  {
    this->step();
  }
};


void App::step()
{
  string t = IO::prompt("请选择步骤：");
  if (t == "A")
  {
    // 输入顶点
    this->input_vertex();
  }
  else if (t == "B")
  {
    // 输入边
    this->input_edge();
  }
  else if (t == "C")
  {
    // 计算生成树
    this->run();
  }
  else if (t == "D") {
    terminated = true;
  }
};

void App::input_vertex()
{
  IO::put("请依次输入每个节点的名称，每行一个，每个名称间不能有空格，输入0代表结束输入：");
  string v_name;
  while (cin >> v_name)
  {
    if (v_name == "0")
    {
      // 结束输入
      break;
    }
    names.insert(v_name);   
  }
};

void App::input_edge()
{
  IO::put("请依次输入每条边的两端顶点及长度（非负整数），比如a b 10，每行一条边，输入0 0 0结束输入：");
  string v_a, v_b;
  int len;
  edge new_edge;
  while (cin >> v_a >> v_b >> len)
  {
    if (v_a == "0" && v_b == "0" && len == 0)
    {
      break;
    }
    if (names.find(v_a) == names.end() ||
      names.find(v_b) == names.end())
    {
      IO::put("有未定义顶点，请重新输入");
      continue;
    }
    new_edge.a = v_a;
    new_edge.b = v_b;
    new_edge.len = len;
    edges.insert(new_edge);
  }
};

map<string, string> father; // 并查集
string find_fa(string cur)
{
  if (father[cur] == cur)
  {
    return cur;
  }
  else
  {
    return father[cur] = find_fa(father[cur]);
  }
};
void init_fa()
{
  father.clear();

  set<string>::iterator it;
  for (it = names.begin(); it != names.end(); it++)
  {
    string name = *it;
    father[*it] = *it;
  }
};

void App::run()
{
  init_fa();
  set<edge>::iterator it;
  int total_len = 0;

  for (it = edges.begin(); it != edges.end(); it++) {
    edge cur = *it;
    string fa = find_fa(cur.a), fb = find_fa(cur.b);
    if (fa != fb) {
      // 不在一个连通集合
      // 是一条MST边
      total_len += cur.len;
      cout << cur.a << "--(" << cur.len << ")-->" << cur.b << endl;
      // 合并
      father[fa] = fb;
    }
  }
  cout << "总长度：" << total_len << endl;
};
