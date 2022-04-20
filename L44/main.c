#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "utils/includes/util.h"

static void gestore(int signum)
{
    write(1,"Ricevuto SIGINT\n", 17);
    _exit(EXIT_FAILURE);
}

int main(void)
{
    struct sigaction s;
    int i;

    memset(&s, 0, sizeof(s));
    s.sa_handler = gestore;

    sigaction(SIGINT, &s, NULL);
    for (i = 1;; i++)
    {
        sleep(1);
        printf("% d \n", i);
    }

    exit(EXIT_SUCCESS);
}
