#include <stdio.h>
#include <stdbool.h>
#include <getopt.h>
#include <stdlib.h>

#include "common.h"
#include "file.h"
#include "parse.h"

void print_usage(char *argv[]) {
}

int main(int argc, char *argv[]) {
  char *filepath = NULL;
  char *portarg = NULL;
  unsigned short port = 0;
  bool newfile = false;
  bool list = false;
  int c;

  while ((c = getopt(argc, argv, "nf:a:l")) != -1) { //Here the option that has : requires an arguemnt. 
    switch (c) {
    case 'n':
      newfile = true;
      printf("option n detected\n");
      break;
    case 'f':
      filepath = optarg;
      printf("option f detected and the arguemnt given is: %s\n",optarg);
      break;
    case 'p':
      portarg = optarg;
      printf("option p detected\n");
      break;
    case 'l':
      list = true;
      break;
    case '?':
      printf("Unknown option -%c\n", c);
      break;
    default:
      return -1;
    }
  }
  printf("New file: %d\n", newfile);
  printf("file path is %s\n", filepath);
}