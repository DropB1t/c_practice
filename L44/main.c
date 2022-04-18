#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    struct sigaction s;
    sigset_t set;

    EC(sigfillset(&set), "fillset");
    EC(pthread_sigmask(SIG_SETMASK, &set, NULL), "sigmask");

    EC(sigaction(SIGINT, NULL, &s), "sigaction1");
    s.sa_handler = handlerINT;
    EC(sigaction(SIGINT, &s, NULL), "sigaction2");

    s.sa_handler = handlerTSTP;
    EC(sigaction(SIGTSTP, &s, NULL), "sigaction3");

    s.sa_handler = handlerALRM;
    EC(sigaction(SIGALRM, &s, NULL), "sigaction4");

    sigdelset(&set, SIGINT);
    sigdelset(&set, SIGALRM);
    sigdelset(&set, SIGTSTP);

    alarm(10);
    while (1)
    {
        pause();
    }

    return 0;
}
