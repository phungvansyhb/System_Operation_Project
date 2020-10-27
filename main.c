#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include "sendMail.h"

// declare struct student
struct student {
    char Name[30];
    char Email[30];
    float GPA;
    int ToEic;
    int SubjectCount;
    float StudyFee;
};
typedef struct student Student;

// example we have 3 threads
pthread_t tid[2];
pthread_mutex_t lock;
// global var what 3 threads can use
int counter;

void *Log(Student *a) {
    counter += 1;
    a->GPA = counter + 0.5;
    printf("\n Job %d started\n", counter);
    printf("---");
    printf("ThreadId: %d\n", counter);
    printf("Student Name: %s \n", a->Name);
    printf("GPA: %f \n", a->GPA);
    printf("Toeic: %d \n", a->ToEic);
    printf("Course Fee: %f \n", a->StudyFee);
    printf("NUmber Pass: %d \n", a->SubjectCount);
    printf("\n Job %d finished\n", counter);
    printf("------------------------ \n");
    return NULL;
}

void *sendNotify(Student *a) {
    printf("Send email to student!");
    pthread_mutex_lock(&lock);
    char strtemp1[50];
    char strtemp2[50];
    char whoUpdated[] = "Ban Update duoc thuc hien boi thread ";
    sprintf(strtemp1, "%d", counter);
    strcat(whoUpdated, strtemp1);
    char ContentUpdated[] = " GPA vua duoc cap nhat lai la : ";
    sprintf(strtemp2, "%f", a->GPA);
    strcat(ContentUpdated, strtemp2);
    strcat(whoUpdated, ContentUpdated);
    sendmail(whoUpdated, a->Email);
    pthread_mutex_unlock(&lock);
}


int main(void) {
    Student phungsy;
    strcpy(phungsy.Name, "Phung van sy");
    strcpy(phungsy.Email, "phungvansyhb@gmail.com");
    phungsy.StudyFee = 12000000;
    phungsy.SubjectCount = 99;
    phungsy.ToEic = 550;
    int i = 0;
    int errUpdate;
    int errSendMail;

    if (pthread_mutex_init(&lock, NULL) != 0) {
        printf("\n mutex init has failed\n");
        return 1;
    }
    while (i < 2) {
        errUpdate = pthread_create(&(tid[i]), NULL, Log, &phungsy);
        errSendMail = pthread_create(&(tid[i]), NULL, sendNotify, &phungsy);
        if (errUpdate != 0 || errSendMail != 0)
            printf("Error create thread!");
        i++;
    }
    /* make 3 threads run async pthread_join like await in js*/
    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);
//    pthread_join(tid[2], NULL);
    pthread_mutex_destroy(&lock);
    return 0;
}