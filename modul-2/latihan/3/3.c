#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>


int fcpy(FILE *sourceFile, FILE *destFile) {
    int count = 0;
    char ch;

    while ((ch = fgetc(sourceFile)) != EOF) {
        fputc(ch, destFile);
    }

    return count;
}


int main() {
  pid_t pid, sid;        // Variabel untuk menyimpan PID

  pid = fork();     // Menyimpan PID dari Child Process

  /* Keluar saat fork gagal
  * (nilai variabel pid < 0) */
  if (pid < 0) {
    exit(EXIT_FAILURE);
  }

  /* Keluar saat fork berhasil
  * (nilai variabel pid adalah PID dari child process) */
  if (pid > 0) {
    exit(EXIT_SUCCESS);
  }

  umask(0);

  sid = setsid();
  if (sid < 0) {
    exit(EXIT_FAILURE);
  }

  if ((chdir("/")) < 0) {
    exit(EXIT_FAILURE);
  }

  close(STDIN_FILENO);
  close(STDOUT_FILENO);
  close(STDERR_FILENO);

  while (1) {

    FILE *sourceFile;
    FILE *destFile;
    char sourcePath[100] = "/Users/Clarence/sisop/error.txt";
    char destPath[100] = "/Users/Clarence/sisop/error.log.";
    strcat(destPath, "1");

    sourceFile = fopen(sourcePath, "r+");
    destFile = fopen(destPath, "w");

    /* fopen() return NULL if unable to open file in given mode. */
    if (sourceFile == NULL || destFile == NULL) {
        /* Unable to open file hence exit */
        printf("\nUnable to open file.\n");
        printf(
            "Please check if file exists and you have read/write privilege.\n");

        exit(EXIT_FAILURE);
    }

    // Call function to copy file
    fcpy(sourceFile, destFile);

    /* Finally close files to release resources */
    fclose(sourceFile);
    fclose(destFile);

    // using "w to " a file will rewrite it
    fclose(fopen(sourcePath, "w"));

    sleep(30);
  }
}

