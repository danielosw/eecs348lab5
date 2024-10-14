#include <stdio.h>
#include <stdlib.h>
// Name: Daniel Van Dalsem
// KU ID: 3129614

float getaveragetotal(float nums[12]){
  float hold[12];
  // I think this is the only way to copy in c
  for (int i = 0; i < 12; i++) {
    hold[i] = nums[i];
  }
	float total = 0;
	for (int i = 0; i < sizeof(hold)/sizeof(hold[0]); i++) {
	total+=hold[i];
	}
	return total/(((float)sizeof(hold)/sizeof(hold[0])));
}
float sixmonthaverage(float nums[12],int start, int end){
  float hold[6];
  // I think this is the only way to copy in c
  int j = 0;
  for (int i = start-1; i < end; i++) {
    hold[j] = nums[i];
    j+=1;
  }
	float total = 0;
	for (int i = 0; i < sizeof(hold)/sizeof(hold[0]); i++) {
	total+=hold[i];
	}
	return total/(((float)sizeof(hold)/sizeof(hold[0])));
}
void listwithout(int m,float l1[m], float l2[m-1], int i){
  float hold[m];
  for (int k = 0; k < m; k++) {
    hold[k] = l1[k];
  }
int l = 0;
for (int j = 0; j < sizeof(hold)/sizeof(hold[0]); j++) {
if(!(j == i)){
  l2[j] = hold[l];
  l++;
}
else{
l2[j] = hold[++l];
l++;
}
}
}
void monthprint(int dex){
	switch (dex) {
    case 0: {
      printf("January");
      break;
    }
    case 1: {
      printf("Febuary");
      break;
    }
    case 2: {
      printf("March");
      break;
    }
    case 3: {
      printf("April");
      break;
    }
    case 4: {
      printf("May");
      break;
    }
    case 5: {
      printf("June");
      break;
    }
    case 6: {
      printf("July");
      break;
    }
    case 7: {
      printf("August");
      break;
    }
    case 8: {
      printf("September");
      break;
    }
    case 9: {
      printf("October");
      break;
    }
    case 10: {
      printf("November");
      break;
    }
    case 11: {
      printf("December");
      break;
    }
    }
}
void printMonthOnMatch(float num, float truth[12]){
float hold[12];
for (int i = 0; i < 12; i++) {
hold[i] = truth[i];
}
for (int i = 0; i < 12; i++) {
if(hold[i] == num){
  monthprint(i);
  break;
}
} 
}
int printlast(int m, float nums[m], float truth[12]){
  float hold[m];
  // I think this is the only way to copy in c
  for (int i = 0; i < m; i++) {
    hold[i] = nums[i];
  }
  float last = 0;
  int dex = -1;
  for (int i = 0; i < sizeof(hold)/sizeof(hold[0]); i++) {
    if(hold[i]>last){
      last = hold[i];
      dex = i;
    }
  } 
  printMonthOnMatch(last, truth);
  printf("\t%f\n",last);
  return dex;
}
void dataprint(float data[12]) {
  printf("Monthly Sales report for 2024\n");
  float hold[12];
  for (int i = 0; i < 12; i++) {
    hold[i] = data[i];
  }
  printf("Month	    Sales\n");
  for (int i = 0; i < 12; i++) {
    monthprint(i);
    printf("    %f\n", hold[i]);
  }
  printf("\n");
  printf("Sales summary report:\n");
  printf("Minimum sales:");
  // set abitrarilly high
  float mini = 9999999999.9;
  int dex = -1;
  for (int i = 0; i < 12; i++) {
    if (hold[i] < mini) {
      mini = hold[i];
	dex = i;
    }
  }
  
  printf("\t%f ",mini);
	printf("(");
	monthprint(dex);
	printf(")\n");
  printf("Maximux sales:");
  // set abitrarilly low
  float max = -1;
  int index = -1;
  for (int i = 0; i < 12; i++) {
    if (hold[i] > max) {
      max = hold[i];
	index = i;
    }
  }
  
  printf("\t%f ",max);
	printf("(");
	monthprint(index);
	printf(")\n");
  
  
	printf("Average sales: %f\n",getaveragetotal(hold));
  printf("\n");
  printf("Six-month moving average report: \n");
  printf("January-June\t%f\n", sixmonthaverage(hold,1,6));

  printf("February-July\t%f\n", sixmonthaverage(hold,2,7));
  printf("March-August\t%f\n", sixmonthaverage(hold,3,8));
  printf("April-September\t%f\n", sixmonthaverage(hold,4,9));
  printf("May-October\t%f\n", sixmonthaverage(hold,5,10));
  printf("June-November\t%f\n", sixmonthaverage(hold,6,11));
  printf("July-December\t%f\n", sixmonthaverage(hold,7,12));
    printf("\n");

  float htl[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
  float g[12];
  // WARNING this is a really bad way to do this but I just don't really have time to sort it.
  printf("Sales report (highest to lowest):\n");
  printf("Month\tSales\n");
  int toRemove;
  toRemove = printlast(12,hold,hold);
  float newlist1[11];
  listwithout(12, hold, newlist1, toRemove);
  toRemove = printlast(11,newlist1,hold);
  float newlist2[10];
  listwithout(11, newlist1, newlist2, toRemove);
  toRemove = printlast(10,newlist2,hold);
  float newlist3[9];
  listwithout(10, newlist2, newlist3, toRemove);
  toRemove = printlast(9,newlist3,hold);
  float newlist4[8];
  listwithout(9, newlist3, newlist4, toRemove);
  toRemove = printlast(8,newlist4,hold);
  float newlist5[7];
  listwithout(8, newlist4, newlist5, toRemove);
  toRemove = printlast(7,newlist5,hold);
  float newlist6[6];
  listwithout(7, newlist5, newlist6, toRemove);
  toRemove = printlast(6,newlist6,hold);
  float newlist7[5];
  listwithout(6, newlist6, newlist7, toRemove);
  toRemove = printlast(5,newlist7,hold);
  float newlist8[4];
  listwithout(5, newlist7, newlist8, toRemove);
  toRemove = printlast(4,newlist8,hold);
  float newlist9[3];
  listwithout(4, newlist8, newlist9, toRemove);
  toRemove = printlast(3,newlist9,hold);
  float newlist10[3];
  listwithout(3, newlist9, newlist10, toRemove);
  toRemove = printlast(2,newlist10,hold);
  float newlist11[2];
  listwithout(2, newlist10, newlist11, toRemove);
  toRemove = printlast(1,newlist11,hold);
  
  
}
int main(int argc, char *argv[]) {
  char str[12][10000];

  FILE *file_ptr = fopen("./input.txt", "r");
  int i = 0;
  while (fgets(str[i], sizeof(str[i]), file_ptr)) {
    i++;
  }
  fclose(file_ptr);
  float data[12];
  int index = 0;
  for (int i = 0; i < (sizeof(str) / sizeof(str[0])); i++) {
    // This is the only reason we need to import stdlib
    data[index] = strtof(str[i], NULL);
    index++;
  }
  dataprint(data);
  return 1;
}
