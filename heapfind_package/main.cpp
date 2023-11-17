#include <stdio.h>
#include <iostream>
#include <vector>
#include <stack>
#include "priority_queue.h"
#include "student.h"

using namespace std;

int main() {
  CP::priority_queue<int> pq;
  char c;
  scanf("%c", &c);
  while (c != 'q') {
    if (c == 'a' || c == 'f' || c == 'l') {
      // add data
      int n;
      scanf("%d", &n);
      if (c == 'a') {
        pq.push(n);
      } else if (c == 'f') {
        bool r = pq.find(n);
        if (r) {
          printf("Found %d\n",n);
        } else {
          printf("%d not found\n",n);
        }
      } else if (c == 'l') {
        int r = pq.find_level(n);
        if (r >= 0) {
          printf("Found %d at level %d\n",n,r);
        } else {
          printf("%d not found\n",n);
        }
      }
    } else if (c == 'd') {
       pq.pop();
    }
    scanf("%c", &c);
  }
  return 0;
}


// a 1 a 2 a 3 a 4 a 5 f 5 l 5 d l 5 q

// a 10
// a 10
// a 10
// a 10
// a 20
// f 10
// l 10
// f 20
// l 9000
// f 9000
// d
// l 10 q