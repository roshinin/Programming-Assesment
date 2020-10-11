#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

int checkminprice(int minprice, int value);
int checkmaxprice(int maxprice, int value);

int main(){
    printf("Initiate");
    int noe;
    int minprice = 0;
    int maxprice = 0;
    char line[256];
    char *delimiter = ":";
    FILE *file;
    FILE *fileout;
   
    if ((file = fopen("input.txt", "r")) == NULL) {
        printf("File not found");
        exit(1);
    }

     if ((fileout = fopen("output.txt", "w")) == NULL) {
        printf("File not found");
        exit(1);
    }

    fprintf(fileout,"%s","The goodies selected for distribution are:\n\n");

    while (fgets(line, sizeof(line), file)) {
      char *key;
      char actline[256] ;
      strcpy (actline, line);
      key = strtok(line, delimiter);
      int value;
      if (strstr(line, "Number of employees") != NULL) { 
        noe = atoi(strtok(NULL, delimiter));
        printf("\nNumber of employees %d\n", noe);
      } else {
        if(strstr(line, "Microwave Oven") != NULL){
          if(noe == 2 || noe == 4 || noe == 6){
            value = atoi(strtok(NULL, delimiter));
            minprice = checkminprice(minprice,value);
            maxprice = checkmaxprice(maxprice,value);
            fprintf(fileout,"%s",actline);
          }
        }else if(strstr(line, "Alexa") != NULL){
          if(noe == 2 || noe == 4 || noe == 6){
            value = atoi(strtok(NULL, delimiter));
            minprice = checkminprice(minprice,value);
            maxprice = checkmaxprice(maxprice,value);
            fprintf(fileout,"%s",actline);
          }
        }else if(strstr(line, "Fitbit Plus") != NULL){
          if(noe == 4 || noe == 6){
            value = atoi(strtok(NULL, delimiter));
            minprice = checkminprice(minprice,value);
            maxprice = checkmaxprice(maxprice,value);
            fprintf(fileout,"%s",actline);
          }
        }else if(strstr(line, "Digital Camera") != NULL){
          if(noe == 4){
            value = atoi(strtok(NULL, delimiter));
            minprice = checkminprice(minprice,value);
            maxprice = checkmaxprice(maxprice,value);
            fprintf(fileout,"%s",actline);
          }
        }else if(strstr(line, "Sandwich Toaster") != NULL){
          if(noe == 6){
            value = atoi(strtok(NULL, delimiter));
            minprice = checkminprice(minprice,value);
            maxprice = checkmaxprice(maxprice,value);
            fprintf(fileout,"%s",actline);
          }
        }else if(strstr(line, "Cult Pass") != NULL){
          if(noe == 6){
            value = atoi(strtok(NULL, delimiter));
            minprice = checkminprice(minprice,value);
            maxprice = checkmaxprice(maxprice,value);
            fprintf(fileout,"%s",actline);
          }
        }else if(strstr(line, "Scale") != NULL){
          if(noe == 6){
            value = atoi(strtok(NULL, delimiter));
            minprice = checkminprice(minprice,value);
            maxprice = checkmaxprice(maxprice,value);
            fprintf(fileout,"%s",actline);
          }
        }
      }
    }
    fprintf(fileout,"\n\nAnd the difference between the chosen goodie with highest price and the lowest price is %d",maxprice-minprice);
    fclose(file);
    fclose(fileout);
    return 0;
}

int checkminprice(int minprice, int value){ 
  int retval;
  if(minprice == 0){
    retval = value;
  }else if(minprice >= value){
    retval = value;
  }else{
    retval = minprice;
  }
  return retval;
}

int checkmaxprice(int maxprice, int value){
  int retval;
  if(maxprice == 0){
    retval = value;
  }else if(maxprice <= value){
    retval = value;
  }else{
    retval = maxprice;
  }
  return retval;
}

