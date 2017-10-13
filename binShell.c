#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

void echo(char* charArray[]);
void ls();
void cd(const char * path);
void com_mkdir(char * name);
void com_rmdir(char * name);
void execute_redirect(char **charArray);
void execute_normal(char **charArray);
int i; //global variable

int main(void)
{
  char userInput[256];
  char* charArray[256];
  char* charPointer;
  char* get_current_dir_name(void); //Declare the function

  while (1)
  {
    i = 0;
    printf(">> ");
    fgets(userInput,sizeof(userInput),stdin);
    //EXIT : exit the prompt
    charPointer = strtok(userInput," \n"); //separated by space
    while(charPointer != NULL)
    {
      charArray[i] = charPointer;
      charPointer = strtok(NULL," \n");
      i++;
    };
    charArray[i] = 0; //This point is NULL
    //printf("%s\n", charArray[0]);

    //exit
    if (strcmp(userInput, "exit") == 0)
    { //For string comp, 0 means true, 1 means false
      break;
    }
    //pwd
    else if (strcmp(userInput, "pwd") == 0)
    {
      printf("%s\n", get_current_dir_name());
    }
    //echo
    else if (strcmp(userInput, "echo") == 0)
    {
      echo(charArray);
    }
    else if (strcmp(userInput, "ls") == 0)
    {
      ls();
    }
    else if (strcmp(userInput, "cd") == 0)
    {
      cd(charArray[1]);
    }
    else if (strcmp(userInput, "mkdir") == 0)
    {
      com_mkdir(charArray[1]);
    }
    else if (strcmp(userInput, "rmdir") == 0)
    {
      com_rmdir(charArray[1]);
    }
    else {
      if (strcmp(charArray[i-2],">") == 0)
      {
        execute_redirect(charArray);
      }
      else
      {
        execute_normal(charArray);
      }
    }
  }
}
//echo function
void echo(char* charArray[])
{
  int indexForEcho = 1;
  while(charArray[indexForEcho] != NULL)
  {
      printf("%s ",charArray[indexForEcho]);
      indexForEcho++;
  }
  printf("\n");
}
//ls function
void ls()
{
  DIR * directory; //DIR data type represents a directory stream.
  struct dirent * dir;
  directory = opendir(".");
  if (directory)
  {
    while ((dir = readdir(directory)) != NULL)
    {
      //Single quotes : char -- single character
      //Double quotes : null-terminated strings (char *) -- array of characters
      if (dir->d_name[0] != '.')
      {
        //Do not want to see .. and .
        printf("%s\n",dir->d_name);
      }
    }
    closedir(directory);
  }
}
//cd function
void cd(const char * path)
{
  int state = chdir(path);
  if (state == -1) // error, then return -1
  {
    printf("Nope!!\n");
  }
  
}
//mkdir function
void com_mkdir(char * name)
{
  mkdir(name,0755);
}

void com_rmdir(char * name)
{
  int state = rmdir(name);
  if (state == -1) // check the error
  {
    printf("Nope!!\n");
  }
  else
  {
    rmdir(name);
  }
}

void execute_normal(char ** charArray)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid < 0)
	{
		printf("ERROR fork failed\n");
		exit(1);
	}
	else if (pid == 0) //child thread
	{
		if (execvp(*charArray, charArray) < 0)
		{
			perror("execvp");
			exit(1);
		}
	}
	else
	{
		while (wait(&status) != pid) {} //parent, waits for completion
	}

}

void execute_redirect(char **charArray)
{
	pid_t pid;
	int status;
	int defout;
	int fd;

	pid = fork();
	if (pid < 0)
	{
		printf("ERROR fork failed\n");
		exit(1);
	}
	else if (pid == 0) //child thread
	{
    char * file = charArray[i-1];
    char * result = NULL;
    //strstr(haystack, needle)
    //haystack: this is the main C string to be scanned
    //needle : this is the small string to be searched with in haystack
    result = strstr(charArray[i-3], "./");
    charArray[i-2] = NULL; // symbol "<"
    charArray[i-1] = NULL; // files.txt
    if (result)
    {
      charArray[i-3] = NULL; //Set to null to prevent printing CS415-TEST.cpp
    }
		defout = dup(1);
		fd=open(file, O_RDWR|O_CREAT,0644);
		dup2(fd,1);
		if (execvp(*charArray, charArray) < 0)
		{
			perror("execvp");
			exit(1);
		}
		close(fd);
	}
	else
	{
		while (wait(&status) != pid) {} //parent, waits for completion
	}

}
