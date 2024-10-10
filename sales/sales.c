#include <stdio.h>
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
    // Hardcoded for testing
    float data[12] = {23458.01,40112.00,56011.85,37820.88,37904.67,60200.22,72400.31,56210.89,67230.84,68233.12,80950.34,95225.22};
    dataprint(data);
    return 1;
}

