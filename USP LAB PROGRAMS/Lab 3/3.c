#include <dirent.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

main()
{
   char name[30];
   DIR* p;
   struct stat sb;
   struct dirent *dir;
   printf("Enter the path name:\n");
   scanf("%s" , name);
   p = opendir(name);
   chdir(name);
   
   if(p == NULL)
     perror("Error:");
   else
   {
       while( (dir = readdir(p)) != NULL )
       {
           stat(dir->d_name , &sb);
           if(sb.st_size == 0)
              unlink(dir->d_name);
       }
       closedir(p);
   }
}
   
