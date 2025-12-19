#include <iostream>
using namespace std;

/*
Source - https://stackoverflow.com/a
Posted by Mehdi Mohammadpour,
modified by community. See post 'Timeline' for change history
Retrieved 2025-12-18, License - CC BY-SA 4.0
*/

int main(){

  // string concatenation (combining strings)
  string test1 = "testtest";
  string test2 = "woahhh " + test1 + " does this work?";
  cout << "test 1 & 2: " << test2 <<
    " §test" << endl;

  // casting from int to string is possible
  int test3 = 5;
  string test4 = to_string(test3);
  cout << "\ntest 3 & 4: " << test4 << endl;

  // casting from float to double is possible
  float test5 = 1.5;
  double test6 = double(test5);
  cout << "\ntest 5 & 6: " << test6 <<
    " of type: " << typeid(test6).name() << endl;

  // implicit type conversion
  int test7 = 3;
  double test8 = 7.777;
  double test9 = test7 + test8;
  cout << "\ntest 7, 8 & 9: " << test9 << endl;

  // automatically takes the highest resolution
  int test10 = 9;
  float test11 = 5.5;
  double test12 = 6.6;
  auto test13 = test10 + test11 + test12;
  cout << "\ntest 10, 11, 12 & 13: " << test13 <<
    " of type: " << typeid(test13).name() << endl;

// Color test
//=================================================

  cout << "\n\x1B[31m";
  cout << "TEST";
  cout << "\033[0m\n\n" << endl;

    printf("\n");
    printf("\x1B[31mTexting\033[0m\t\t");
    printf("\x1B[32mTexting\033[0m\t\t");
    printf("\x1B[33mTexting\033[0m\t\t");
    printf("\x1B[34mTexting\033[0m\t\t");
    printf("\x1B[35mTexting\033[0m\n");

    printf("\x1B[36mTexting\033[0m\t\t");
    printf("\x1B[36mTexting\033[0m\t\t");
    printf("\x1B[36mTexting\033[0m\t\t");
    printf("\x1B[37mTexting\033[0m\t\t");
    printf("\x1B[93mTexting\033[0m\n");

    printf("\033[3;42;30mTexting\033[0m\t\t");
    printf("\033[3;43;30mTexting\033[0m\t\t");
    printf("\033[3;44;30mTexting\033[0m\t\t");
    printf("\033[3;104;30mTexting\033[0m\t\t");
    printf("\033[3;100;30mTexting\033[0m\n");

    printf("\033[3;47;35mTexting\033[0m\t\t");
    printf("\033[2;47;35mTexting\033[0m\t\t");
    printf("\033[1;47;35mTexting\033[0m\t\t");
    printf("\t\t");
    printf("\n");

    return 0;
}
