#include <stdio.h>
//Create a parking lot with 3 types of vehicles. When someone comes in, 
//ID is given and the parking location depends on the type of car that person is using
//If someone else wants to leave, they must declare their ID and then delete the location of the person who left,
// so when another person comes in, it will take that location and give it to that person.

int ID_car = 1000;
int ID_motorbike = 3000;
int ID_bicycle = 5000;
//khoi tao id cua tung bai giu xe
//initial the id number of location


struct carPark {
    int car_parking[20]={0};
    int motorbike_parking[20]={0};
    int bicycle_parking[20]={0};
    //tao ra 3 bai giu xe cho 3 loai xe
    //create 3 parking_lot types of vehicle 
    //Each parking lot has 20 parking spaces
};

struct driver {
	//tao ra tai xe voi tung id
    int id;
};

int main() {
    struct carPark P;
    struct driver driver[100]={0};
    int n; 
    int i=0;
    
    while(1>0){
    printf("Please pick your choice:\n");
    printf("1: Enter the parking lot\n");
    printf("2: Get out of the parking lot\n");

    scanf("%d", &n);
    printf("\n");
    //tao ra 2 truong hop vao hoac ra  
    //create 2 cases go in or go out
    switch (n) {
        case 1:
        	  //tao ra 3 truong hop cho 3 loai xe
             //create 3 cases for 3 types of vehicle
            printf("Please choose your type of vehicle:\n");
            printf("1: Car\n");
            printf("2: Motorbike\n");
            printf("3: Bicycle\n");
            

            int vehicleChoice;
            scanf("%d", &vehicleChoice);
            printf("\n");
            
            if(vehicleChoice==1){
            	for(int i=0;i<100;i++){
            		if(driver[i].id==0){ //if driver [i]=0 eaual the value of ID_Car
            			driver[i].id=ID_car;
            	         ID_car++; // every time have people go in=> ID_car+1 to create new Id for new people
            	         printf(" here your id : %d \n ",driver[i].id); // inform for people about id
            	         break;
					}
				}
            	
            	for(int i=0;i<20;i++){
            		if(P.car_parking[i]==0){ 
            			P.car_parking[i]=i+1;// = 1 if have people             				
			             	printf("here your location of car_parking : %d \n ",P.car_parking[i]);
			             	break;
					}	
				}
				
			}
			else if(vehicleChoice==2){
            		for(int i=0;i<100;i++){
            		if(driver[i].id==0){
            			driver[i].id=ID_motorbike;
            	         ID_motorbike++;
            	         printf(" here your id : %d \n ",driver[i].id);
            	         break;
					}
				}
            	
            	for(int i=0;i<20;i++){
            		if(P.motorbike_parking[i]==0){
            			P.motorbike_parking[i]=i+1;// = 1 if have people 
            				
			             	printf("here your location of motorbike_parking : %d \n ",P.motorbike_parking[i]);
			             	break;
					}	
				}
				
			}
			
			else if(vehicleChoice==3){
            	for(int i=0;i<100;i++){
            		if(driver[i].id==0){
            			driver[i].id=ID_bicycle;
            	         ID_bicycle++;
            	         printf(" here your id : %d \n ",driver[i].id);
            	         break;
					}
				}
            	
            	for(int i=0;i<20;i++){
            		if(P.bicycle_parking[i]==0){
            			P.bicycle_parking[i]=i+1;// = 1 if have people          				
			             	printf("here your location of bicycle_parking : %d \n ",P.bicycle_parking[i]);
			             	break;
					}	
				}
				
			}	
			printf("\n");		 
            break;
            
        case 2:
        	int check_id;
        	int check_location;
        	
        	printf("Please enter your ID : \n");
        	scanf("%d",&check_id);
        	printf("Please enter your location \n");
        	scanf("%d",&check_location);
        	
        	int flag=0; // tao ra co` flag de nhan biet xem da co id duoc check chua
        	 //Creat flag to check the id exist or not 
        	
        	if(check_id>=1000 &&check_id<=2999){
        		for(int i=0;i<100;i++){
        			if(driver[i].id==check_id ){
        			    driver[i].id=0; 
        			    flag=1;
        			    break;
					}
				}
				if(flag==0){
					printf("ban da nhap sai id ");
					break;
				}
				
				
				for(int i=0;i<20;i++){
					if(P.car_parking[i]==check_location ){
        			   P.car_parking[i]=0;
        			   //check location if location== car_parking[i] 
        			   // => car_parking=0; So when someone else comes in 
					   //it will start at the place where someone else left
        			   break;
					}
				}
			}
			
			else if(check_id>=3000&& check_id<=4999){
        		for(int i=0;i<100;i++){
        			if(driver[i].id==check_id ){
        			    driver[i].id=0;
        			    flag=1;
        			    break;
					}
				}
				if(flag==0){
					printf("ban da nhap sai id ");
					break;
				}
				
				
				for(int i=0;i<20;i++){
					if(P.motorbike_parking[i]==check_location ){
        			   P.motorbike_parking[i]=0;
        			   break;
					}
				}
			}
			
			else if(check_id>=5000){
        		for(int i=0;i<100;i++){
        			if(driver[i].id==check_id ){
        			    driver[i].id=0;
        			    flag=1;
        			    break;
					}
				}
					if(flag==0){
					printf("ban da nhap sai id ");
					break;
				}
				
				
				for(int i=0;i<20;i++){
					if(P.bicycle_parking[i]==check_location ){
        			   P.bicycle_parking[i]=0;
        			   break;
					}
				}
			}
        	
        	
        	
        	break;
        	
        	printf("\n");
    }
}

    return 0;
}

