#include <stdio.h> //stdio.h (printf function) is a header file, It stands for standard input output header
#include <string.h>
#include <stdlib.h>

int main(void)
{
  //Allocate memory for userInput
  char userInput[100];
  char* charArray[100]; //Store tokens
  char* charPointer; //Points the location of each char
  int idx = 0;

  //Read in a full line from the user
  printf("Please type your input \n");
  //fgets(string,size,stdin)
  fgets(userInput,sizeof(userInput),stdin); //stdin is standard input
  charPointer = strtok(userInput, " "); //Seperated by space character
  printf("--------------------------\n");
  //In c, simple quotes delimit a single character whereas double quotes for strings
  while(charPointer != NULL)
  {
    charArray[idx] = charPointer;
    charPointer = strtok(NULL," ");
    idx++;
  }

  //\0 is null
  charArray[idx] = 0; //This point is NULL

  /*
  while(charPointer != NULL)
  {
    printf("%s\n", charPointer);
    charPointer = strtok(NULL, " ");
  }
  */
  //Print out lists
  for (idx=0; idx < sizeof(charArray); idx++)
  {
    if(charArray[idx] == 0) //Check the NULL str
    {
      break;
    }
    else
    {
    printf("charArray[%d] = %s\n", idx, charArray[idx]);
    }
  }
  //Clean the memory
  memset(charArray, 0 , sizeof(*charArray));
  //print
  printf("Current memory: %p\n",*charArray);


}
