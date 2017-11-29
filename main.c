#include <stdio.h>
#include "libreso_redundant.h"

int main(int argc, char** argv) {
  storeRedundantly("hey", "hi", 2, 2);
  return 0;
}
