//
// Created by Маргарита  on 21.03.2022.
//

#include<stdio.h>
#include<math.h>
#include<dirent.h>
#include <strings.h>
#include <sys/types.h>
#include <stdlib.h>

struct Storage{
    char **strs;
    int size;
    int n;
};
void readFile(char * filename){
    FILE *f= fopen(filename,"r");
    char s[100];
    while(fgets(s,100,f)){

        printf("%s",s);
    }
    fclose(f);

}
void fileCopy(char* filename,char *outfilename){
    FILE *f = fopen(filename,"r");
    FILE *f_out = fopen(outfilename,"w");
    char s[100];
    while(fgets(s,100,f)){

        fprintf(f_out,":%s",s);
    }
    fclose(f);
    fclose(f_out);
}
void dirtravel(char *dirname,struct Storage* st){
    DIR* dir = opendir(".");// !!!dir!=null
    struct dirent* cur;
    while(cur = readdir(dir)){
        if(cur->d_type == DT_DIR){
            printf("Dir:\t");
            if(strcmp(cur->d_name,".") && strcmp(cur->d_name,"..")){
                int slen= strlen(dirname);
                strcat(dirname,"/");
                strcat(dirname,cur->d_name);
                dirtravel(dirname,st);
                dirname[slen]='\0';
                //
            }

        }
        if(cur->d_type == DT_REG){
            printf("REG:\t");
            //addTO
        }
        printf("%s\n",cur->d_name);
    }
    closedir(dir);
}
int main(){
//    char s[100];
   char *filename="test.txt";
//    FILE *f = fopen(filename,"r");//first -- way; second -- r/w (read /write)
//    fgets(s,100,stdin);
//    puts(s);


    readFile(filename);
    //fileCopy(filename,"out.txt");

    struct Storage *st=malloc(sizeof (struct Storage));
    //char path[100]=".";
    char* path=".";
    //dirtravel(path,st);
    return 0;
}