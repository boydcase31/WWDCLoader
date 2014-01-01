//
//  main.c
//  wwdcloader
//
//  Created by 3x7R00Tripper on 01.01.14.
//  Copyright (c) 2014 3x7R00Tripper. All rights reserved.
//

#include <curl/curl.h>
#include <curl/easy.h>
#include <errno.h>
#include <time.h>
#include <stdio.h>
#include <CoreFoundation/CoreFoundation.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

int main(int argc, const char * argv[])
{
    CURL *curl;
    CURLcode curl_res;
    CURLINFO info;
    long http_code;
    double c_length;
    FILE *tmp;
    tmp=fopen("resources/wwdc.ipa", "w");
    if(tmp==NULL) {
        printf("%s [*] Error to download file\n", KRED);
        printf("%s", KNRM);
        exit(2);
    }
    curl = curl_easy_init();
    curl_easy_setopt(curl, CURLOPT_URL, "http://a396.phobos.apple.com/us/r1000/098/Purple/v4/c3/4e/98/c34e989a-8522-fde0-db2d-884dd3b1302d/mzps6036043982514941651.D2.pd.ipa");
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, tmp);
    curl_easy_setopt(curl, CURLOPT_COOKIE, "downloadKey=expires=1388667604~access=/us/r1000/098/Purple/v4/c3/4e/98/c34e989a-8522-fde0-db2d-884dd3b1302d/mzps6036043982514941651.D2.pd.ipa*~md5=2e943e2f3b9e1143f3e1588fd7c1c9e0");
    curl_res = curl_easy_perform(curl);
    if(curl_res==0) {
        printf("%s [*] WWDC downloaded successfully\n", KGRN);
    } else {
        printf("%s [*] ERROR in dowloading file\n", KRED);
        printf("%s", KNRM);
        fclose(tmp);
        curl_easy_cleanup(curl);
    }
    fclose(tmp);
    curl_easy_cleanup(curl);
    printf("%s", KNRM);
    return 0;
}
