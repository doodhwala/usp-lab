#include <dirent.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

int main(int argc, char **argv)
{
   DIR* p;
   struct stat sb;
   struct dirent *dir;
   
   char cwd[100];
   getcwd(cwd , sizeof(cwd));
   
   int count = 1;
   while (argc > count)
   {
      chdir(cwd);
      
      if(stat(argv[count] , &sb) >= 0)
      {
        printf("Entered path: %s\n" , argv[count]);
        
        if(S_ISREG(sb.st_mode))
        {
          printf("File Type: Regular file\n");
          printf("File contents:\n");
          char buf[10];
          int fd = open(argv[count] , O_RDONLY , 0777);
          while ( read(fd , buf , 1) > 0 )
            printf("%s" , buf); 
          
        }
        
        else if(S_ISDIR(sb.st_mode))
        {
          printf("File Type: Directory\n");
          printf("Contents of directory:\n");
          int fcount = 0 , dcount = 0;
          p = opendir(argv[count]);
          chdir(argv[count]);
   
          if(p == NULL)
             perror("Error:");
          else
          {
             while( (dir = readdir(p)) != NULL )
             {
                 stat(dir->d_name , &sb);
                 if(strcmp(dir -> d_name,".") != 0  && strcmp(dir -> d_name,"..") != 0)
                 {
                   printf("Name - %s ; " , dir->d_name);
                   if(S_ISREG(sb.st_mode))
                      printf("Type - regular file\n") , fcount++;
                   else if(S_ISDIR(sb.st_mode))
                      printf("Type - Directory\n") , dcount++;
                 }
             }
          closedir(p);
          }
          printf("No. of files = %d\nNo. of directories = %d\n" , fcount , dcount);
        }  
        
      }
      
      else
         perror("Error:");
         
      printf("\n");
      count++;
   }
   
   if(count == 1)
   { 
      int fcount = 0 , dcount = 0;
      chdir(cwd);
      p = opendir(cwd);
    
      if(p == NULL)
             perror("Error:");
      else
      {
             while( (dir = readdir(p)) != NULL )
             {
                 stat(dir->d_name , &sb);
                 if(strcmp(dir -> d_name,".") != 0  && strcmp(dir -> d_name,"..") != 0)
                 {
                   printf("Name - %s ; " , dir->d_name);
                   if(S_ISREG(sb.st_mode))
                      printf("Type - regular file\n") , fcount++;
                   else if(S_ISDIR(sb.st_mode))
                      printf("Type - Directory\n") , dcount++;
                 }
             }
             closedir(p);
      }
      printf("No. of files = %d\nNo. of directories = %d\n" , fcount , dcount);   
   }
   return 0;
 }
 
 
 
 
 
 
 
