#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void start_dumping(char* argv1,char* argv2){
    FILE* f = fopen(argv1,"r");
    if(!f){printf("\nFile not found\n"); return;}
    unsigned char *data = (char*)malloc(1024*32);
    int i = 0;
    while(!feof(f)){
        data[i] = fgetc(f);
        i++;
    }
    data[i+1] = '\0';
    fclose(f);
    f = fopen(argv2, "w");
    i--;
    if(!f){printf("\nFile not found\n"); return;}
    for(int j = 0; j < i; j++){
        if(data[j] != '\0' || data[j] != '\n') fprintf(f,"0x%02x", data[j]);
        if(j != i-1) fputc(',',f);
        if(j != i-1) fputc('\n',f);
    }
    fclose(f);
    printf("\nOperation finished successfully\n");
}

int main(int argc, char** argv){
    assert(argc > 2);
    start_dumping(argv[1], argv[2]);
    return -1;
}