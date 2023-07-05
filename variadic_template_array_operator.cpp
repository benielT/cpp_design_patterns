#include <cstdio>
#include <cstdarg>
#include <iostream>
#include <array>

template <int ...VAL>
class TemplateArrayOp
{
public:
    const int N = sizeof...(VAL);
    int values[sizeof...(VAL)];
    
    TemOp()
    {
        _init(N, VAL...);
    }
    
    int add()
    {
        int result = 0;
        
        for (int i = 0; i < N; i++)
        {
            result += values[i];
        }
        
        return (result);
    }
    
private:
    void _init(int N, ...) 
    {
        std::va_list args;
    
        va_start(args, N);
        for (int i = 0; i < N; i++)
        {
            values[i] = va_arg(args, int);
        }
    
        va_end(args);
    }
};

int main(int argc, char** argv) {
  printf("Hello world\n");
  TemplateArrayOp<32,45,1> op;
  std::cout << "number of input: " << op.N << ", add: " << op.add()<< std::endl;
  printf("Hello circle\n");
  return 0;
}
