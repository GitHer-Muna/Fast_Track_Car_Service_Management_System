//Commercial Test Program to replace traditional paper bill.

/*Sample company "Fast Track Car Pvt. Ltd." is using the program to perform a Digital Invoice and Service System.

Program written by: Muna Bhattarai
Date: Monday, March 1st, 2021 */

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int invoice_no=1000;    //Global Invoice no. overwritten when read from file
// the costs and time are replaced by literals

struct service
{
int x; // represents the count of services
int y; // represents the input service value

int service_type;

int z[8]; // represents all the service value used....
double service_fee;
double total_time;

char invoice_no[4];
char *service_no[2];
char date[15]; 
char reg_no[12];
char f_name[17];
char l_name[17];

}car;


void invoice(struct service *vehicle , int autoinvoice_no , int fl);
void proceed();
void menu();

 int Autoinvoice()
     {
		 invoice_no = invoice_no + 1;
     	 return invoice_no;
     }



void question(struct service *vehicle)
   {	
              char doAgain='y';
			  int autoinvoice_no = Autoinvoice();
       while(doAgain == 'y' || doAgain == 'Y')
       {
		   menu();
    
         printf("\nPlease Fill Customer Details:: \n");
         

         printf("\nEnter First Name: \n");
         scanf("%s", vehicle->f_name);

         printf("\nEnter Last Name? \n");
         scanf("%s", vehicle->l_name);

         printf("\nPlease Fill Vehicle Details:: \n");

		 printf("Please Specify Total No. Of Services You want (in count): \n");
         scanf("%d", &vehicle->x);

		 //prevent count overflow
		 if(vehicle->x > 8)
		 {
		 	vehicle->x = 8;
			 printf("\nOptimized to be 8.\n");
		 }
		 if(vehicle->x < 1)
		 {
		 	vehicle->x = 1;
			 printf("\nOptimized to be 1.\n");
		 }


         printf("Specify All The Services you want (From Menu[1-8]): \n");
          for(int i = 0; i < vehicle->x; i++) // loop until count
          {
          	printf("%dst service no: ", i+1);
          	scanf("%d", &vehicle->y);

          	if(vehicle->y >= 1 && vehicle->y <= 8 )
          		vehicle->z[i]=vehicle->y;   // z can hold upto 8 values
          	else
          		{ printf("Invalid Entry\n");
					i -= 1;
          	      continue;  // needs to continue the for loop
          	    }
           }

			printf("Service Type \n1. [U]rgent \n2. [N]ormal?)\nEnter Choice: \n");
			scanf("%d", &vehicle->service_type);

			printf("\nToday's Date (Format; yyyy/mm/dd ) : \n");
			scanf("%s", vehicle->date);

			printf("\nEnter Vehicle Reg No.: \n");
			scanf("%s", vehicle->reg_no);

			printf("\n\n");
            
            invoice(&car , autoinvoice_no , 0);
            printf("Do you want to edit the data by redoing the operation? (Y/N)");
            scanf(" %c",&doAgain);

			if (doAgain != 'y' && doAgain != 'Y')
			{
				invoice(&car , autoinvoice_no , 1);
				break;
			}
			
   		}
		proceed();
    
    }

void menu()        //Welcome Note & Service Menu
    {
    	 system("cls");

         printf("\t\t\t\tFast Track Car Service Management System \n");
         printf("\t\t\t\t          XYZ Street, XYZ City           \n");
         printf("\n\t\t___________________________________________________________________________\n");
         printf("\n");
         printf("------------------------------------------------------------------------------------------------------------\n");
         printf("\tNo\tService type\t\t\tTime Needed(minutes)\t\t        Service Fee\n");
         printf("\t\t\t\t\t\t\t\t\t\tNormal       |     Urgent\n");
         printf("------------------------------------------------------------------------------------------------------------\n");
         printf("\t1\tRepair punctured car tyre/piece\t\t10\t\t\tRM5                 RM6\n");
         printf("\t2\tCar tyre change/piece\t\t\t15\t\t\tRM150               RM160\n");
         printf("\t3\tMineral Oil change \t\t\t20\t\t\tRM80                RM90\n");
		 printf("\t3\tSynthetic Oil change \t\t\t20\t\t\tRM130               RM140\n");
         printf("\t5\tBattery Change\t\t\t\t5\t\t\tRM200               RM210\n");
         printf("\t6\tHead light bulb change/piece\t\t5\t\t\tRM6                 RM8\n");
         printf("\t7\tTaillight bulb change/piece\t\t5\t\t\tRM6                 RM8\n");
         printf("\t8\tCar Wash\t\t\t\t10\t\t\tRM10                RM12\n");
         printf("\t\t\tCurrent Invoice Number is %d \n\n" , invoice_no);
    }

void proceed()
{
		int ahead;

		printf("Do you want to repeat the program for a new car Entry? (1.[C]otinue 2.[E]nd )\n");
 		 scanf ("%d", &ahead);
 		 if (ahead == 2 || ahead !=1 )
  		  {
  		    printf ("Thank you for using this program! Program Closing......!!!!");
          
           exit(1);
 		     
 		   }
 		 if (ahead == 1)
 		   {
			question(&car);
 		   }

}


	void invoice(struct service *vehicle , int autoinvoice_no , int fl)
		{
    	        system("cls");

                vehicle->service_fee =0000; // initalize to be 0 for operations.
                vehicle->total_time =00;
                
					FILE *file;
					file = fopen("myfile.txt","a");

				if (fl == 1)
				{
					fprintf(file,"__________________________________________INVOICE(%d)__________________________________________\n", autoinvoice_no );
					
					fprintf(file,"\t\t\t     Fast Track Car Service Management System \n");
					fprintf(file,"\t\t\t              XYZ Street, XYZ City           \n");
					fprintf(file,"_________________________________________________________________________________________________\n");
					
					fprintf(file,"Date: %s                                             Name: %s %s \n",vehicle->date ,vehicle->f_name,vehicle->l_name);
					fprintf(file,"Vehicle No: %s                                                 Service Type: %d ",vehicle->reg_no,vehicle->service_type);
					
					
					if(vehicle->service_type == 1)
						{fprintf(file,"(URGENT) \n");
						// fclose(file);
						}


					else if(vehicle->service_type == 2)
						{fprintf(file,"(NORMAL) \n");
						// fclose(file);
						}

					else
						{fprintf(file,"Default:'NORMAL'\n");
						// fclose(file);
						}
					
					
					fprintf(file,"_________________________________________________________________________________________________\n");
					fprintf(file,"S.N.\t\t\t\tParticular\t\t\t\t\t\tAmount\n");
					fprintf(file,"_________________________________________________________________________________________________\n");
					// fclose(file);

				}


                 printf("__________________________________________INVOICE(%d)__________________________________________\n", autoinvoice_no );
        		 
        		 printf("\t\t\t     Fast Track Car Service Management System \n");
         		 printf("\t\t\t              XYZ Street, XYZ City           \n");
         		 printf("_________________________________________________________________________________________________\n");
        		 
        		 printf("Date: %s                                             Name: %s %s \n",vehicle->date ,vehicle->f_name,vehicle->l_name);
        		 printf("Vehicle No: %s                                                 Service Type: %d ",vehicle->reg_no,vehicle->service_type);
        		

        		 if(vehicle->service_type == 1)
                    {
                        printf("(URGENT) \n");
                    
                    }
                 else if(vehicle->service_type == 2)
                    {
                        printf("(NORMAL) \n");
                    }
                 else
                 	{
                         printf("Default:'NORMAL'\n");
                    }

                 printf("_________________________________________________________________________________________________\n");
        		 printf("S.N.\t\t\t\tParticular\t\t\t\t\t\tAmount\n");
        		 printf("_________________________________________________________________________________________________\n");
        		

                 //URGENT Service
                 if(car.service_type == 1)
                 {	

                 	for(int i = 0; i < vehicle->x; i++) 
            	   	{ 
                        int c = vehicle->z[i];

          				switch(c) 
          				{

          				case 1 :
                    	printf("%d\t\t\t\tRepair Punctured Tyre\t\t\t\t\t        RM 160\n", i+1 );
						if(fl == 1)
                        	fprintf(file,"%d\t\t\t\tRepair Punctured Tyre\t\t\t\t\tRM 6\n", i+1  );
                    	vehicle->service_fee += 6;
                    	vehicle->total_time += 10;
                        // fclose(file);
                    	break;
      
                    	case 2 :
      					printf("%d\t\t\t\tCar Tyre Change\t\t\t\t\t        RM 160\n", i+1 );
                        if(fl == 1)
                        	fprintf(file,"%d\t\t\t\tCar Tyre Change\t\t\t\t\t        RM 160\n", i+1 );
      					vehicle->service_fee += 160;
      					vehicle->total_time += 15;
      					// fclose(file);
      						break;
      
      					case 3 :
        				printf("%d\t\t\t\tMineral Oil Change          \t\t\t\tRM 90\n", i+1 );
                        if(fl == 1)
                        	fprintf(file,"%d\t\t\t\tMineral Oil Change          \t\t\t\tRM 90\n", i+1 );
         				vehicle->service_fee += 90;
         				vehicle->total_time += 20;
         				// fclose(file);
         					break;
      
      			    	case 4 :         					
        				printf("%d\t\t\t\tSynthetic Oil Change     \t\t\t\tRM 140\n", i+1 );
                        if(fl == 1)
                        	fprintf(file,"%d\t\t\t\tSynthetic Oil Change     \t\t\t\tRM 140\n", i+1 );
      			    	vehicle->service_fee += 140;
      			    	vehicle->total_time += 20;
      			    	//fclose(file);
      			    	    break;
         
         				case 5 :
         				printf("%d\t\t\t\tBattery Change     \t\t\t\t\tRM 210\n", i+1 );
                        if(fl == 1)
                        	fprintf(file,"%d\t\t\t\tBattery Change     \t\t\t\t\tRM 210\n", i+1 );
         				vehicle->service_fee += 210;
         				vehicle->total_time += 5;
         				//fclose(file);
         					break;
      
      					case 6 :
         				printf("%d\t\t\t\tHead Light Bulb Change\t\t\t\t\tRM 8\n", i+1 );
                        if(fl == 1)
                        	fprintf(file,"%d\t\t\t\tHead Light Bulb Change\t\t\t\t\tRM 8\n", i+1 );
         				vehicle->service_fee += 8;
         				vehicle->total_time += 5;
         				//fclose(file);
         					break;
         
         				case 7 :
         				printf("%d\t\t\t\tTaillight Bulb Change\t\t\t\t\tRM 8\n", i+1   );
                        if(fl == 1)
                        	fprintf(file,"%d\t\t\t\tTaillight Bulb Change\t\t\t\t\tRM 8\n", i+1   );
         				vehicle->service_fee += 8;
         				vehicle->total_time += 5;
         				//fclose(file);
         					break;
         
         				case 8 :
         				printf("%d\t\t\t\tCar Wash          \t\t\t\t\tRM 12\n", i+1  );
                        if(fl == 1)
                        	fprintf(file,"%d\t\t\t\tCar Wash          \t\t\t\t\tRM 12\n", i+1  ); 
         				vehicle->service_fee += 12;
         				vehicle->total_time += 10;
         				//fclose(file);
         					break;

      					default :
						  // this is impossible for z variable cause it is checked before already
         				printf("Invalid Entry\n" );
                        if(fl == 1)
                        	fprintf(file,"Invalid Entry\n" );
         				//fclose(file);
   				        
   				        }
   				    }
   				 }



                 //NORMAL Service
                 if ( car.service_type == 2 || car.service_type != 1 )
                 {	

                 	for ( int i = 0; i < vehicle->x; i++ ) 
            	   	{
                        int c = vehicle->z[i];

          				switch(c) 
          				{

          				case 1 :
                    	printf("%d\t\t\t\tRepair Punctured Tyre\t\t\t\t\tRM 5\n", i+1    );
                        if(fl == 1)
                        	fprintf(file,"%d\t\t\t\tRepair Punctured Tyre\t\t\t\t\tRM 5\n", i+1    );
                    	vehicle->service_fee += 5;
                    	vehicle->total_time += 10;
                    	//fclose(file);
                    		break;
      
                    	case 2 :
      					printf("%d\t\t\t\tCar Tyre Change\t\t\t\t\t        RM 150\n", i+1   );
                        if(fl == 1)
                        	fprintf(file,"%d\t\t\t\tCar Tyre Change\t\t\t\t\t        RM 150\n", i+1   );
                        vehicle->service_fee += 150;
                        vehicle->total_time += 15;
                        //fclose(file);
      						break;
      
      					case 3 :
        			    printf("%d\t\t\t\tMineral Oil Change          \t\t\t\tRM 80\n", i+1   );
                        if(fl == 1)
                        	fprintf(file,"%d\t\t\t\tMineral Oil Change          \t\t\t\tRM 80\n", i+1   );
         				vehicle->service_fee += 80;
         				vehicle->total_time += 20;
         				//fclose(file);
         					break;
      
      			    	case 4 :
         				printf("%d\t\t\t\tSynthetic Oil Change     \t\t\t\tRM 130\n", i+1  );
                        if(fl == 1)
                        	fprintf(file,"%d\t\t\t\tSynthetic Oil Change     \t\t\t\tRM 130\n", i+1  );
         				vehicle->service_fee += 130;
         				vehicle->total_time += 20;
         				//fclose(file);
         					break;
         
         				case 5 :
         				printf("%d\t\t\t\tBattery Change     \t\t\t\t\tRM 200\n", i+1   );
                        if(fl == 1)
                        	fprintf(file,"%d\t\t\t\tBattery Change     \t\t\t\t\tRM 200\n", i+1   );
         				vehicle->service_fee += 200;
         				vehicle->total_time += 5;
         				//fclose(file);
         					break;
      
      					case 6 :
         		     	printf("%d\t\t\t\tHead Light Bulb Change\t\t\t\t\tRM 6\n", i+1   );
                        if(fl == 1)
                        	fprintf(file,"%d\t\t\t\tHead Light Bulb Change\t\t\t\t\tRM 6\n", i+1   );
         				vehicle->service_fee += 6;
         				vehicle->total_time += 5;
         				//fclose(file);
         					break;
         
         				case 7 :
         				printf("%d\t\t\t\tTaillight Bulb Change\t\t\t\t\tRM 6\n", i+1  );
                        if(fl == 1)
                        	fprintf(file,"%d\t\t\t\tTaillight Bulb Change\t\t\t\t\tRM 6\n", i+1  );
         				vehicle->service_fee += 6;
         				vehicle->total_time += 5;
         				//fclose(file);
         					break;
         
         				case 8 :
         				printf("%d\t\t\t\tCar Wash          \t\t\t\t\tRM 10\n", i+1  );
                        if(fl == 1)
                        	fprintf(file,"%d\t\t\t\tCar Wash          \t\t\t\t\tRM 10\n", i+1  );
         				vehicle->service_fee += 10;
         				vehicle->total_time += 10;
         				//fclose(file);
         					break;

      					default :
         			    printf("Invalid Entry\n" );
                        if(fl == 1)
                        	fprintf(file,"Invalid Entry\n" );
         				//fclose(file);
   				        }
   				    }
   			     }

printf("_________________________________________________________________________________________________\n");
        		 printf("\n");
        		 printf("\t\t\t\t\t\t\t      Total Service Fee::::RM %f \n", vehicle->service_fee );
        		 printf("\nTotal Expected Time for all mentioned services: %f Minutes\n", vehicle->total_time );
				 printf("\n\n\n\n");
				
				if(fl == 1)
				{
        		 fprintf(file,"_________________________________________________________________________________________________\n");
        		 fprintf(file,"\n");
        		 fprintf(file,"\t\t\t\t\t\t\t      Total Service Fee::::RM %f \n", vehicle->service_fee );
        		 fprintf(file,"\nTotal Expected Time for all mentioned services: %f Minutes\n", vehicle->total_time );

                 
                 fprintf(file,"\n&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n\n\n");
                 
				}
				fclose(file);

    }



int main()
{

// create the file once code runs also get the total number of entries
	FILE * file;
	file = fopen("myfile.txt","a+");
	    
		
		int count_entries = 0;

		char chr;

	//extract character from file and store in chr

		chr = getc(file);

		while (chr != EOF)

		{

			//Count whenever new entries are encountered - in which & is repeated 85 times total

			if (chr == '&')
			{
				count_entries = count_entries + 1;

			}

			//take next character from file.

			chr = getc(file);

		}
		
	fclose(file);

	invoice_no += count_entries / 85;

	question(&car);

 return(0);


 
 
}
