#include <pthread.h>  //library thread
#include <stdio.h>
#include <stdlib.h>

void *factorial(void *input);

struct args {
  int number;
};

int main() {
  pthread_t thread1, thread2;  // inisialisasi awal
  const char *message1 = "Thread 1";
  const char *message2 = "Thread 2";

  struct args *passing = (struct args *)malloc(sizeof(struct args));
  passing->number = 2;

  int iret1, iret2;
  // membuat thread pertama
  iret1 =
      pthread_create(&thread1, NULL, factorial, (void *)passing);

  // jika error
  if (iret1) {
    fprintf(stderr, "Error - pthread_create() return code: %d\n", iret1);
    exit(EXIT_FAILURE);
  }
  // membuat thread kedua
  iret2 =
      pthread_create(&thread2, NULL, factorial, (void *)passing);

  // jika gagal
  if (iret2) {
    fprintf(stderr, "Error - pthread_create() return code: %d\n", iret2);
    exit(EXIT_FAILURE);
  }

  printf("pthread_create() for thread 1 returns: %d\n", iret1);
  printf("pthread_create() for thread 2 returns: %d\n", iret2);

  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);

  exit(EXIT_SUCCESS);
}

void *factorial(void *input) {
  int num = ((struct args *)input)->number;
  printf("%d \n", num);

  // for (int i = 0; i < 10; i++) {
  //   printf("%s %d \n", message, i);
  // }
}