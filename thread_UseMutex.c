#include<stdio.h>
#include<string.h>
#include<pthread.h>
// declare struct student
struct student {
    int threadID;
    char Name[30];
    char Email[30];
    float GPA;
    int ToEic;
    int SubjectCount;
    float StudyFee;
};
typedef struct student Student;

// example we have 3 threads
pthread_t tid[3];

// global var what 3 threads can use
int counter;
pthread_mutex_t lock;

void *Log(Student *a) {
    pthread_mutex_lock(&lock);
    counter += 1;
    a->threadID = counter;
    a->GPA= a->threadID+0.5;
    printf("\n Job %d started\n", counter);
    printf("---");
    printf("ThreadId: %d\n",a->threadID);
    printf("Ten hoc sinh: %s \n", a->Name);
    printf("Diem GPA hoc sinh: %f \n", a->GPA);
    printf("Diem Toeic hoc sinh: %d \n", a->ToEic);
    printf("Hoc phi hoc sinh: %f \n", a->StudyFee);
    printf("So tin da qua cua hoc sinh: %d \n", a->SubjectCount);
    printf("\n Job %d finished\n", counter);
    pthread_mutex_unlock(&lock);
    printf("------------------------ \n");
    return NULL;
}

int main(void) {

    Student phungsy;
    strcpy(phungsy.Name, "Phung van sy");
    strcpy(phungsy.Email, "phungvansyhb@gmail.com");
    phungsy.StudyFee = 12000000;
    phungsy.SubjectCount = 99;
    phungsy.ToEic = 550;
    int i = 0;
    int err;

    if (pthread_mutex_init(&lock, NULL) != 0) {
        printf("\n mutex init has failed\n");
        return 1;
    }
    while( i<3 ){
        err = pthread_create(&(tid[i]), NULL, Log, &phungsy);
        if (err != 0)
            printf("\ncan't create thread :[%s]", strerror(err));
        i++;
    }
    /* make 3 threads run async pthread_join like await in js*/
    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);
    pthread_join(tid[2], NULL);
    pthread_mutex_destroy(&lock);
    return 0;
}