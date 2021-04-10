#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
  pid_t child_id;
  int status;
  time_t t;
  struct tm *tmp;
  char MY_TIME[50];
  time(&t);

  tmp = localtime(&t);

  // using strftime to display time
  strftime(MY_TIME, sizeof(MY_TIME), "%d-%m-%Y_%H:%M:%S", tmp);

  char dirname[100] = "/home/clarence/file_kelas_sisop/modul-2/latihan/2/";
  strcat(dirname, MY_TIME);

  child_id = fork();

  if (child_id < 0) {
    exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti
  }

  if (child_id == 0) {
    // this is child

    char *argv[] = {"mkdir", "-p", dirname, NULL};
    execv("/bin/mkdir", argv);
  } else {
    // this is parent
    while ((wait(&status)) > 0);
    char fromDir[] = "/home/clarence/file_kelas_sisop/modul-1";

    char *argv[] = {"cp", "-r", fromDir, dirname,NULL};
    execv("/bin/cp", argv);
  }
}
