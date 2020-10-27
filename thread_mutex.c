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

int counter;
void *Log(Student *a) {
    unsigned long i = 0;
    counter += 1;
    printf("\n Job %d started\n", counter);
    printf("---");
    printf("Ghi boi Thread: %d\n",a->threadID);
    printf("Ten hoc sinh: %s \n", a->Name);
    printf("Diem GPA hoc sinh: %f \n", a->GPA);
    printf("Diem Toeic hoc sinh: %d \n", a->ToEic);
    printf("Hoc phi hoc sinh: %d \n", a->StudyFee);
    printf("So tin da qua cua hoc sinh: %f \n", a->SubjectCount);
    for(i=0; i<(0xFFFFFFFF);i++);
    printf("\n Job %d finished\n", counter);
    printf("------------------------ \n");
    return NULL;
}

int main(void) {
    int i = 0;
    int err;
    Student phungsy;
    strcpy(phungsy.Name, "Phung van sy");
    strcpy(phungsy.Email, "phungvansyhb@gmail.com");
    phungsy.StudyFee = 12000000;
    phungsy.SubjectCount = 99;
    phungsy.ToEic = 550;

    while( i<3 ){
       phungsy.threadID = i+1;
        phungsy.GPA = i+0.5;
        err = pthread_create(&(tid[i]), NULL, Log, &phungsy);
        if (err != 0)
            printf("\ncan't create thread :[%s]", strerror(err));
        i++;
    }
    /* make 3 threads run async pthread_join like await in js*/
    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);
    pthread_join(tid[2], NULL);
    return 0;
}