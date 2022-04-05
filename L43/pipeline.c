#define  _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include "utils/includes/util.h"
#include "unboundedqueue.h"

#define N_THREAD 3
#define MAX_LINE_LEN 1024

typedef struct
{
	int argc;
	const char **argv;
	Queue_t *q;
} thread1_struct;

typedef struct
{
	Queue_t *q1;
	Queue_t *q2;
} thread2_struct;

void *TH1(void *arg)
{
	thread1_struct *th_struct = (thread1_struct *)arg;
	assert(th_struct);

	for (int i = 1; i < th_struct->argc; i++)
	{
		const char *filename = th_struct->argv[i];
		int r;
		size_t filesize;
		if ((r = isRegular(filename, &filesize)) == 1)
		{
			/* if (filesize > MAX_FILE_SIZE)
			{
				fprintf(stderr, "Il file %s e' troppo grande, il limite e' %d byte\n", filename, MAX_FILE_SIZE);
				continue;
			} */
			FILE *fp;
			char *line = NULL;
			size_t len = 0;
			ssize_t read;

			fp = fopen(filename, "r");
			if (fp == NULL)
				exit(EXIT_FAILURE);

			while ((read = getline(&line, &len, fp)) != -1)
			{
				//printf("Retrieved line of length %zu:\n", read);
				//printf("%s", line);
				//fflush(stdout);
				char *msg = malloc(strlen(line)+1);
				strcpy(msg,line);
				msg[strlen(msg)-1]='\0';
				push(th_struct->q, (void *)msg);
			}

			fclose(fp);
		}
		if (r == 0)
			fprintf(stderr, "%s is not a regular file\n", filename);
	}

	char *exit = ">exit<";
	push(th_struct->q, (void *)exit);
	//free(line);

	DBG("TH1 [%ld] closing\n", pthread_self());
	return NULL;
}

void *TH2(void *arg)
{
	thread2_struct *th_struct = (thread2_struct *)arg;
	assert(th_struct);

	while (1)
	{
		char *line = (char *)pop(th_struct->q1);
		if (strncmp(line, ">exit<", strlen(">exit<")) == 0)
		{
			char *msg = malloc(strlen(line)+1);
			msg = strcpy(msg,line);
			push(th_struct->q2, (void *)msg);
			//free(line);
			break;
		}

		char *token;
		token = strtok(line, " ");
		if (token != NULL)
		{
			do
			{
				push(th_struct->q2, token);
			} while ((token = strtok(NULL, " ")) != NULL);
		}
	}

	char *exit = ">exit<";
	push(th_struct->q2, (void *)exit);

	DBG("TH2 [%ld] closing\n", pthread_self());
	return NULL;
}

void *TH3(void *arg)
{
	Queue_t *q = (Queue_t *)arg;
	assert(q);

	while (1)
	{
		char *str = (char *)pop(q);
		if (strncmp(str, ">exit<", strlen(">exit<")) == 0)
		{
			free(str);
			break;
		}
		fprintf(stdout, "%s\n",str);
		fflush(stdout);
		//free(str);
		
	}

	DBG("TH3 [%ld] closing\n", pthread_self());
	
	return NULL;
}

int main(int argc, char const *argv[])
{
	pthread_t th[N_THREAD];

	Queue_t *q1 = initQueue();
	assert(q1);
	Queue_t *q2 = initQueue();
	assert(q2);

	thread1_struct *th1_struct = malloc(sizeof(thread1_struct));
	th1_struct->argc = argc;
	th1_struct->argv = argv;
	th1_struct->q = q1;

	if (pthread_create(&th[0], NULL, TH1, th1_struct) != 0)
	{
		fprintf(stderr, "pthread_create failed (TH1)\n");
		return (EXIT_FAILURE);
	}

	thread2_struct *th2_struct = malloc(sizeof(thread2_struct));
	th2_struct->q1 = q1;
	th2_struct->q2 = q2;

	if (pthread_create(&th[1], NULL, TH2, th2_struct) != 0)
	{
		fprintf(stderr, "pthread_create failed (TH2)\n");
		return (EXIT_FAILURE);
	}

	if (pthread_create(&th[2], NULL, TH3, q2) != 0)
	{
		fprintf(stderr, "pthread_create failed (TH2)\n");
		return (EXIT_FAILURE);
	}

	for (size_t i = 0; i < N_THREAD; i++)
	{
		if (pthread_join(th[i], NULL) != 0)
		{
			fprintf(stderr, "pthread_join failed (Producer)\n");
			return (EXIT_FAILURE);
		}
	}
	deleteQueue(q1);
	deleteQueue(q2);
	free(th1_struct);
	free(th2_struct);
	printf("Esco\n");
	return 0;
}
