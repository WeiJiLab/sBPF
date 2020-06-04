#include <stdio.h>
#include <gtest/gtest.h>
#include <stdlib.h>
#include <elf.h>

void read_elf(Elf64_Ehdr header, const char* elfPath){
    FILE* file = fopen(elfPath, "rb");
    if(file){
       fread(&header,1,sizeof(header),file);
       if(memcmp(header.e_ident,ELFMAG,SELFMAG)!=0){
           perror("Not a vaild elf file");
           exit(0);
       }
    }   
    fclose(file);
}


unsigned long *readEBPFBinaryFile(const char *elfPath){
    Elf64_Ehdr header;
    read_elf(header, elfPath);
    printf("entry: %d\n",header.e_machine);
}

int main(int argc,char *argv[]){
    testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();

    readEBPFBinaryFile("/workspaces/NMCS/sBPF/example/bpf_program.o");

    return 1;
}