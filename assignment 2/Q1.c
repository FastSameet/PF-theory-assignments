#include<stdio.h>
#include<string.h> 
void newbook(int isbns[100], char title[100][50], float price[100], int quantities[100], int *count){
		int isbn;
		printf("enter ISBN of your book:");
		scanf("%d",&isbn);
		int i;
		for(i=0;i< *count;i++){   
			if(isbns[i]==isbn){
				printf("book with isbn %d already exists!\n", isbn);
				return;  
			}
		}
		 isbns[*count]= isbn; 
  
		while (getchar() != '\n');  
		printf("enter title of the book:");
		fgets(title[*count],50, stdin); 
		title[*count][strcspn(title[*count], "\n")] = '\0'; 
		printf("enter price of the book:");
		scanf("%f",&price[*count]);
		printf("Enter Quantity of the book:");
   		scanf("%d", &quantities[*count]);
   		
   		(*count)++; 
		printf("Book added successfully!\n");
	}
void ProcessSale(int isbns[100], int quantities[100], int count){
	if(count==0){   
		printf("\nNo books in the inventory curently.\n");
		return;
	}
	int isbn, sold;
	printf("enter isbn of the book sold:");
	scanf("%d",&isbn);
	
	int i;
	int found=-1;  
	for(i=0;i<count;i++){
		if(isbns[i]==isbn){
			found=i;
			break;
		}
	}
	if(found==-1){  
		printf("the book with isbn %d not found in the inventory.",isbn);
		return;
	}
	printf("enter number of copies sold: ");
	scanf("%d",&sold);
	 
	 if(sold> quantities[found]){ 
	 	 printf("Error: Only %d copies available. Cannot process sale.\n", quantities[found]);
	 }
	 else{
	 	quantities[found]-=sold;
	 	printf("sale proceed successfully. remaining stock: %d\n",quantities[found]);
	 }
	
}	
void StockReport(int isbns[100], char title[100][50], float price[100], int quantities[100], int count){
	if(count==0){   
		printf("\nNo books in the inventory curently.\n");
		return;
	}
		int found=0;
		int i;
		printf("\n\t LOW STOCK REPORT \n\n");
		for(i=0;i<count;i++){
			if(quantities[i]<5){
				printf("ISBN: %d\n Title: %s\n Price: %f\n Quantities: %d\n", isbns[i], title[i], price[i], quantities[i]);
				found=1;
			}			
		}
	if(!found){
		printf("no books are low in stock.");
	}	
		
} 

int main(){
	int isbns[100];
	char title[100][50];
	float price[100];
	int quantities[100];
	int count=0;
	int choice;
	
	do{
		printf("\n=== Liberty Books Inventory Management ===\n");
        printf("1. Add a Book\n");
        printf("2. Process a Sale\n");
        printf("3. Generate Low-Stock Report\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
          switch(choice){
          	case 1:
          		newbook(isbns, title, price, quantities, &count);
          		break;
          	case 2:
			  	ProcessSale(isbns, quantities, count);
			  	break;
			case 3:
			    StockReport(isbns, title, price, quantities, count);
				break;
			case 4:
				printf("exiting the inventory....thank you! ");
				break;
			default:
				printf("invalid choice! please select from 1 to 4 ");	
				break;		
		  }
	}
	while (choice !=4);
	return 0;
}




	
