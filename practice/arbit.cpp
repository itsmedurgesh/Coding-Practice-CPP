#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <tuple>

using namespace std;
tuple<string, string, int> test(){
  return make_tuple("durgesh", "choudhary", 234);
}

int main()
{
  std::vector<int> ivec = { 1, 2, 3, 4};
  std::vector<std::string> svec = { "red",
                                    "green",
                                    "blue" };
  auto adder  = [](auto op1, auto op2){ return op1 + op2; };
  std::cout << "int result : "
            << std::accumulate(ivec.begin(),
                               ivec.end(),
                               0,
                               adder )
            << "\n";
  std::cout << "string result : "
            << std::accumulate(svec.begin(),
                               svec.end(),
                               std::string(""),
                               adder )
            << "\n";



  tuple<string, string, int> t = test();

  cout<<get<int>(t)<<endl;
  cout<<get<0>(t)<<endl;    // here string type is ambiguous and hence indices are used but for int we can get using int type
  cout<<get<2>(t)<<endl;
  return 0;
}