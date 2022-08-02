#include<stdio.h>
#include<stdlib.h>


/**
 * args[1] 起始写入位置 args[2] 源文件路径 args[3] 目的文件路径
 **/
int main(int argc, char const *argv[])
{
    
    if (argc != 4)
    {
        printf("argv count must 4 \n");
        return -1;
    }
    
    int startCount = atoi(argv[1]);
    const char *sourcePath = argv[2];
    const char *targetPath = argv[3];
    printf("startCount %d target path %s source path %s\n", startCount, sourcePath, targetPath);

    FILE *targetFile = fopen(targetPath, "rb+"); 
    if (!targetFile)
    {
        printf("target path not found %s \n", targetPath);
        return -1;
    }

    FILE *sourceFile = fopen(sourcePath, "rb+");
    if (!sourceFile)
    {
        printf("source path not found %s \n",sourcePath);
        return -1;
    }
    fseek(targetFile, startCount, SEEK_SET);
    printf("write start path target path(%s) source path(%s) \n",targetPath, sourcePath);    
    char content;
    int count = 0;
    do
    {
        if (feof(sourceFile))
        {
            printf("write count %d \n",count);
            break;
        }
        count++;
        content = fgetc(sourceFile);
        //printf("write content %x \n", content);
        fputc(content, targetFile);
    } while (1);
    
    fclose(sourceFile); 
    fclose(targetFile);
    printf("write finish count:%d \n",count);
    return 0;
}
