# 1 "foo.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "foo.c"

# 1 "foo.h" 1




void some_func(void);
# 3 "foo.c" 2

int main(void)
{
   some_func();
   return 0;
}
