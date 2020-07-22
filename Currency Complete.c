#include<stdio.h>

int main ()
{
	int  match,i,a, quantity;
	float price, amount1, amount2;
	char convert[10],base[10], again;
	char cname[6][10]={"Ringgit","Dollar", "Pound","Won","Yen","Riyal"};
	float cvalue[6]={1,4.27,5.37,0.0035,0.040,1.14};

do  														// Loop untuk Repeat Convert
{
	printf("\n PAYMENT DETAIL \n");
	do{														// loop untuk Compare/Check/Validate Base Currency
		
		printf("Enter Base Currency: ");
		scanf("%s",base);
		
			
		for (i=0;i<6;i++)									//Loop untuk check by row. eg. check row0 ada Won tak, row1,..., bila jumpa dah kat row3, break=berhenti cari dalam loop 
		{
			match = strcmpi (base,cname[i],10);			
			if( match== 0)									//strcmpi(a,b) = 0 = sama string
		    break;	
		};													//Dah cari sampai row last, masih takde yang sama, loop 'for' akan berhenti, & strcmpi akan != 0
		
		if(match!=0)
		printf("Invalid Currency\n"); 						// salah currency..jadi akan display ni
	
	}while(match!=0); 										// buat loop sampailah strcmpi(a,b) = 0 
	
	
	do 													// loop untuk Compare/Check/Validate Convert Currency
	{
		
		printf("Enter Converted Currency: ");
		scanf("%s",convert);
		
		for (a=0;a<6;a++)
		{
			match = strcmpi (convert,cname[a],10);
			if( match== 0)
		    break;	
		};
		
		if(match!=0)
		printf("Invalid Currency\n");
	
	}while(match!=0);
	
	
	printf("\nEnter item price in %s: ",base);  				//Input price
	scanf("%f",&price);
	
	printf("Enter quantity purchase: ");					//Input quantity
	scanf("%d",&quantity);
	
	
	
	amount1= price*quantity; 										//price belum convert
	
	if (convert[10] == "ringgit")										//kalau convert ke Ringgit
		amount2 = amount1 * cvalue[i];
	
	else if (base[10] == "ringgit") 									//kalau dari ringgit
		amount2 = amount1 / cvalue[a];
		
	else if ( base[10] != "ringgit" && convert[10] != "ringgit" )			
		amount2 = amount1 * cvalue[i] / cvalue[a];
							
	
	printf("Total Amount to be paid in %s is: %.2f \n",convert,amount2); // Display convert
	
	printf("\nDo you want to continue (Y/N)? :  "); //Untuk continue
	fflush(stdin);
	scanf("%c", &again);
		
	
}while (again != 'N' && again !='n');

	system("pause");
	return 0;
}
