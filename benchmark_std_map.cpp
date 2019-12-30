#include <map>
#include <iostream>
#include <chrono>
#include <math.h>
#include <bitset>
#include <iomanip>
#include <limits>
#include <vector>
class StopWatch{
  private:
    std::chrono::time_point<std::chrono::high_resolution_clock> _start;
    std::chrono::time_point<std::chrono::high_resolution_clock> _end;
  public:
    StopWatch()
     {
      _start=std::chrono::high_resolution_clock::now();
      _end=std::chrono::high_resolution_clock::now();
     }
    void start()
    {
      _start=std::chrono::high_resolution_clock::now();
      return;
    }
    double end()
    {
      _end=std::chrono::high_resolution_clock::now();
      return std::chrono::duration_cast<std::chrono::nanoseconds>(_end-_start).count();
    }
};
int flip_bits(int value,int n)
{
  int bit_left;
  int bit_right;
  int res=0;
  for(int i=0;i<n/2;i++)
  {
    bit_right=(value&(1<<i))>>i;
    bit_left=(value&(1<<(n-i-1)))>>(n-i-1);
    res^=(bit_right<<(n-i-1))^(bit_left<<i);
  }
  return res;
}
int main()
{
  StopWatch mywatch;
  int max_xp=19;
  std::map<int,int> mymap;
  double time_clear;
  double time_append;
  std::vector<int> balanced_ordered_keys(1<<max_xp);
  for(int i=0;i<(1<<max_xp);i++)
  {
    balanced_ordered_keys[i]=flip_bits(i,max_xp);
    //std::cout << balanced_ordered_keys[i] << std::endl;
  }
  std::cout << std::endl;
  for(int n=0;n<max_xp;n++)
  {
    mywatch.start();
    mymap.clear();
    time_clear=mywatch.end();

    mywatch.start();
    for(int i=0;i<(1<<n);i++)
    {
      mymap.insert(std::make_pair(balanced_ordered_keys[i],i));
    }
    time_append=mywatch.end();

    std::cout << "n=" << n << " log2(time_clear)=" << log2(time_clear) << " log2(time_append)=" 
      << log2(time_append) << std::endl;
  }
  return 0;
}
