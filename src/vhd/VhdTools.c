#include<stdio.h>

static const char *VHD_PATH = "/Users/shrek/VirtualBox\ VMs/customOS/customOS.vhd";
static const char *FILE_PATH = "/Users/shrek/Documents/code/TestOS/src/asm/boot.bin";

int main(int argc, char const *argv[])
{
    
    FILE *vhd = fopen(VHD_PATH, "rb+"); 
    if (!vhd)
    {
        printf("vhd not found \n");
        return -1;
    }

    FILE *asmTest = fopen(FILE_PATH, "rb+");
    if (!asmTest)
    {
        printf("asm test file not found \n");
        return -1;
    }

    printf("write start \n");    
    char content;
    int count = 0;
    while (count < 512)
    {
        content = fgetc(asmTest);
        fputc(content, vhd);
        count++;
    }
    
    fclose(asmTest); 
    fclose(vhd);
    printf("write finish count:%d \n",count);
    return 0;
}
