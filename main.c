#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <windows.h>
#include <ctype.h>
#include <unistd.h>
#include <string.h>

int thread_count;
int counter;
pthread_mutex_t lock;

void* hello(void* id) {

    long my_id = (long) id;

    printf("Thread %ld de %d criada\n", my_id, thread_count);

    return NULL;
}

void funcThread(char str[],int tamanho,int i) {

    pthread_mutex_lock(&lock);

    counter++;

    printf("\nJob %d started", counter);

    str[i] = toupper(str[i]);

    printf("\n%s",str);

    printf("Job %d finished\n\n", counter);

    //Sleep(1000);

    pthread_mutex_unlock(&lock);

    return NULL;
}

int main(int argc, char* argv[]) {

    int error;
    char str[90] = "ExercicioDaDisciplinaDeSistemasDigitaisNoCursoDeSistemasDeInformacaoQuintoPeriodo\n";
    int tam = strlen(str);
    long thread;
    int i=0;

    printf("\nSTRING INICIAL:\n");
    printf("\n%s\n",str);

    if (pthread_mutex_init(&lock, NULL) != 0){

        printf("\n mutex init failed\n");
        return 1;

    }

    pthread_t* thread_handles;

    thread_count = 30;
    thread_handles = malloc(thread_count*sizeof(pthread_t));

    for (thread = 1; thread <= thread_count; thread++){

        error = pthread_create(&thread_handles[thread], NULL, hello, (void*) thread);

        if (error != 0){

            printf("\ncan't create thread :[%s]", strerror(error));
        }
    }

    Sleep(100);
    thread = 1;

    do{

        while(isupper(str[i]) && i < tam-1){
            i++;
        }

        printf("\nThread: %ld",thread);
        pthread_join(thread_handles[thread], NULL);
        funcThread(str,tam,i);

        if(thread == 30){
            thread = 1;
        }
        else {
            thread ++;
        }

    }

    while (!isupper(str[tam-2]));

    free(thread_handles);
    pthread_mutex_destroy(&lock);

    printf("\nMensagem Final:\n");
    printf("%s",str);

 return 0;
}
