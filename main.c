#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {

  int numWords = 0;
  int numSentence = 0;
  float myAverage = 0;

  //array of sentences
  char strs[100][10000];
  //array of integers which store number of words per sentence
  int myNums[1000];

  char str[] ="Someone once told me that time was a predator that stalked us all our lives. I rather believe that time is a companion who goes with us on the journey and reminds us to cherish every moment, because it will never come again. What we leave behind is not as important as how we've lived. After all Number One, we're only mortal.";

  char * pch;
  pch = strtok (str,".");


  //populates an array of sentences
  while(pch != NULL){
    strcpy(strs[numSentence], pch);
    numSentence++;
    pch = strtok (NULL, ".");
  }

  //populates array of integers for number of words per sentence
  for(int i=0; i<numSentence;i++){
    pch = strtok (strs[i]," ");
    while (pch != NULL)
    {
      numWords++;
      myNums[i]=numWords;
      pch = strtok (NULL, " ");
    }
    numWords = 0;
  }

  //calculating average
  for(int i=0; i<numSentence;i++){
    myAverage = myNums[i] + myAverage;
  }
  myAverage = myAverage/numSentence;
  
  printf("Average of words per sentence %f\n",myAverage);
  return 0;

}

