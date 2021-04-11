#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <syslog.h>
#include <unistd.h>

int main()
{
    pid_t pid, sid; // Variabel untuk menyimpan PID
    int count = 1;

    pid = fork(); // Menyimpan PID dari Child Process

    /* Keluar saat fork gagal
     * (nilai variabel pid < 0) */
    if (pid < 0)
    {
        exit(EXIT_FAILURE);
    }

    /* Keluar saat fork berhasil
     * (nilai variabel pid adalah PID dari child process) */
    if (pid > 0)
    {
        exit(EXIT_SUCCESS);
    }

    umask(0);

    sid = setsid();
    if (sid < 0)
    {
        exit(EXIT_FAILURE);
    }

    if ((chdir("/home/clarence/test-daemon")) < 0)
    {
        exit(EXIT_FAILURE);
    }

    close(STDIN_FILENO);
    // close(STDOUT_FILENO);
    close(STDERR_FILENO);

    pid_t child_id;
    char buffer[50];

    while (1)
    {
        child_id = fork();

        sprintf(buffer, "%d", count);
        printf("%s", buffer);

        if (child_id == 0)
        {
            char *argv[] = {"touch", buffer, NULL};
            execv("/bin/touch", argv);
        }

        count++;

        sleep(10);
    }
}

// buat daemon yang membuat file dengan nama nilai count (dari 0) tiap 5 detik
// tanpa menggunakan File di C
