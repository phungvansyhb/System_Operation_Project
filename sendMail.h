//
// Created by phungsy on 27/10/2020.
//

#ifndef C_C___TRAINNING_SENDMAIL_H
#define C_C___TRAINNING_SENDMAIL_H

#endif //C_C___TRAINNING_SENDMAIL_H
#include <stdio.h>
#include <string.h>

int sendmail(char body[] , char mailReceive[]) {
    char cmd[100];  // to hold the command.
//    char to[] = "phungvansyhb@gmail.com"; // email id of the recepient.
//    char body[] = "hello i have sent you an email";    // email body.
    char tempFile[100];     // name of tempfile.
    char subject[] = "NoReply";
    strcpy(tempFile,tempnam("/tmp","sendmail")); // generate temp file name.
    FILE *fp = fopen(tempFile,"w"); // open it for writing.
    fprintf(fp,"%s\n",body);        // write body to it.
    fclose(fp);             // close it.
    sprintf(cmd,"mail -s %s %s < %s",subject,mailReceive,tempFile); // prepare command.
    system (cmd);     // execute it.
    return 0;
}