#include <stdio.h>
#include <stdlib.h>
void dataprint(float data[12]){
printf("Monthly Sales report for 2024\n");
float hold[12];
// I think this is the only way to copy in c
for (int i = 0; i < 12; i++) {
    hold[i] = data[i];
}
printf("Month	    Sales\n");
for (int i = 0; i < 12; i++)
    {
	switch (i) {
	    case 0:{
	    printf("January");
	    break;
	}
	    case 1:{
	    printf("Febuary");
	    break;
	}
	    case 2:{
	    printf("March");
	    break;
	}
	    case 3:{
		       printf("April");
		       break;
		   }
	    case 4:{
		       printf("May");
		       break;
		   }
	    case 5:{
		       printf("June");
		       break;
		   }
	    case 6:{
		       printf("July");
		       break;
		   }
	    case 7:{
		       printf("August");
		       break;
		   }
	    case 8:{
		       printf("September");
		       break;
		   }
	    case 9:{
			printf("October");
			break;
		    }
	    case 10:{
			printf("November");
			break;
		    }
	    case 11:{
			printf("December");
			break;
		    }
	}
	printf("    %f\n",hold[i]);
    }
}
int main(int argc, char *argv[])
{
	char str[12][10000];
	
	FILE* file_ptr = fopen("./input.txt", "r");
	int i = 0;
	while(fgets(str[i], sizeof(str[i]), file_ptr))
  {
    puts(str[i]);
	i++;
  }
  fclose(file_ptr);
  float data[12];
  int index = 0;
  for (int i = 0; i < (sizeof(str) / sizeof(str[0])); i++) {
	data[index] = strtof(str[i], NULL); 
	index++;
  }
    // Hardcoded for testing
    dataprint(data);
    return 1;
}

