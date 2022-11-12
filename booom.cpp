#include <iostream>
#include <unistd.h>
#include <fcntl.h>

int main()
{
  int stdin_dup = dup(STDIN_FILENO);
  int zero_fd = open("/dev/zero", O_RDONLY);
  
  dup2(zero_fd, STDIN_FILENO);
  int number;
  std::cin >> number;
  std::cout << number << "\n";
  
  dup2(STDIN_FILENO, stdin_dup);
  int what_zero;
  std::cin >> what_zero;
  std::cout << what_zero << "\n";
}