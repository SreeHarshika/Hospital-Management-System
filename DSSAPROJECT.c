#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <math.h>
int count;
int beds=100;
typedef struct node
{
 char name[20];
 int age;
 char c;
 long ph;
 char disease[20];
 int hn;
 char street[20];
 char city[20];
 char state[20];
 int id;
 int cat;
 char date[20];
 int bed;
 struct node *next;
}NODE;
NODE* add(NODE *first)
{
 NODE *newnode,*temp;
 char ch;
 if(beds<=0)
 {
 printf("\nBeds are full!!!");
 return(first);
 }
 newnode=(NODE*)malloc(sizeof(NODE));
 newnode->next=NULL;
 printf("\n\t\t_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ");
 printf("\n\t\t|1\tGeneral physician\t201,202");
 printf("\n\t\t|2\tE.N.T\t\t\t203");
 printf("\n\t\t|3\tCardiologist\t\t204");
 printf("\n\t\t|4\tDermatologist\t\t205");
 printf("\n\t\t|5\tGeneral surgeon\t\t206,207");
 printf("\n\n\t\t\t\tRecord of patient number:%d",count+1);
 printf("\n\n\t\t\t\tName of patient:");
 getchar();
 scanf("%[^\n]s",newnode->name);
 printf("\n\t\t\t\tEnter the date of admission(dd/mm/yyyy):");
 scanf("%s",newnode->date);
 printf("\n\t\t\t\tAge:");
 scanf("%d",&newnode->age);
 printf("\n\t\t\t\tGender(M/F):");
 getchar();
 scanf("%c",&newnode->c);
 printf("\n\t\t\t\tAddress:");
 printf("\n\t\t\t\t\tHouse number:");
 scanf("%d",&newnode->hn);
 printf("\n\t\t\t\t\tStreet:");
 scanf("%s",newnode->street);
 printf("\n\t\t\t\t\tCity:");
 scanf("%s",newnode->city);
 printf("\n\t\t\t\t\tState:");
 scanf("%s",newnode->state);
 printf("\n\t\t\t\tEnter the disease or problem of patient:");
 getchar();
 scanf("%[^\n]s",newnode->disease);
 printf("\n\t\t\t\tEnter the category of consultant specialist:");
 scanf("%d",&newnode->cat);
 printf("\n\t\t\t\tEnter the contact number of Patient:");
 scanf("%ld",&newnode->ph);
 newnode->bed=count+1;
 newnode->id=count+1;
 printf("\n\n\t\t\t\tPatient %s is added successfully!",newnode->name);
 printf("\n\n\t\t\t\tThe ID of the patient %s is:%d",newnode->name,count+1);
 printf("\n\n\t\t\t\tBed number allocated:%d",newnode->bed);
 switch(newnode->cat)
 {
 case 1:printf("\n\n\t\t\t\tRoom number of consultant specialist:201");
 break;
 case 2:printf("\n\t\t\t\tRoom number of consultant specialist:203");
 break;
 case 3:printf("\n\t\t\t\tRoom number of consultant specialist:204");
 break;
 case 4:printf("\n\t\t\t\tRoom number of consultant specialist:205");
 break;
 case 5:printf("\n\t\t\t\tRoom number of consultant specialist:206");
 break;
 default:printf("\n\t\t\t\tRoom number of consultant specialist:208");
 }
 printf("\n\t\t\t\tPress any key to continue");
 getchar();
 ch=getch();
 system("cls");
 if(first==NULL)
 first=newnode;
 else
 {
 temp=first;
 while(temp->next!=NULL)
 temp=temp->next;
 temp->next=newnode;
 }
 count=(count+1)%100;
 beds--;
 return first;
}
void sea(NODE *first)
{
 char ch,c;
 NODE *temp;
 int id,flag=0;
 char name[20];
 if(first==NULL)
 {
 printf("\n\t\t\t\tRecord is empty!");
 }
 else
 {
 temp=first;
 printf("\n\t\t\t\tEnter the name of the patient:");
 getchar();
 scanf("%[^\n]s",name);
 printf("\n\t\t\t\tEnter the ID of the patient:");
 scanf("%d",&id);
 printf("\n");
 while(temp!=NULL)
 {
 if((strcmp(temp->name,name)==0)&&(temp->id==id))
 {
 printf("\t\t\t\tSearch successful!");
 printf("\n\t\t\t\tRecord of patient number:%d",temp->id);
 printf("\n\t\t\t\t\tName of patient:%s",temp->name);
 printf("\n\t\t\t\tDate of admission:%s",temp->date);
 printf("\n\t\t\t\t\tAge:%d",temp->age);
 printf("\n\t\t\t\t\tID:%d",temp->id);
 if(temp->c=='M'||temp->c=='m')
 printf("\n\t\t\t\t\tGender:MALE");
 else
 printf("\n\t\t\t\tGender:FEMALE");
 printf("\n\t\t\t\t\tAddress:");
 printf("\n\t\t\t\t\t\tHouse number:%d",temp->hn);
 printf("\n\t\t\t\t\t\tStreet:%s",temp->street);
 printf("\n\t\t\t\t\t\tCity:%s",temp->city);
 printf("\n\t\t\t\t\t\tState:%s",temp->state);
 printf("\n\t\t\t\t\tThe disease or problem of patient:%s",temp->disease);
 printf("\n\t\t\t\t\tBed number allocated:%d",temp->bed);
 flag++;
 }
 if(flag!=0)
 break;
 temp=temp->next;
 }
 if(flag==0)
 printf("\n\t\t\t\tFailure!,no patient named %s found with ID %d",name,id);
 }
 printf("\n\t\t\t\tPress any key to continue");
 getchar();
 c=getch();
 system("cls");
}
void dis(NODE *first)
{
 int i=1;
 char ch;
 if(first==NULL)
 {
 printf("\n\t\t\t\tNo record existing!");
 printf("\n\t\t\t\tPress any key to continue");
 getchar();
 ch=getch();
 system("cls");
 return;
 }
 printf("\n\t\t\t\tM or m:Male\n\t\t\t\t f or F:Female");
printf("\n\tSl.no.\tName\t\tID\tBed no.\t\tDisease\t\tAge\tGender\tCity\tDate of adms.\n");
 while(first!=NULL)
 {
 printf("\t%d\t%s\t\t%d\t%d\t\t%s\t\t%d\t%c\t%s\t%s\n",i,first->name,first->id,first->bed,first-
>disease,first->age,first->c,first->city,first->date);
 first=first->next;
 i++;
 }
 printf("\n\t\t\t\tPress any key to continue");
 getchar();
 ch=getch();
 system("cls");
}
NODE* del(NODE *first)
{
 NODE *temp,*prev=NULL;
 char ch;
 char name[20];
 int id,days;
 if(first==NULL)
 {
 printf("\n\t\t\t\tEmpty Record!");
 }
 else
 {
 printf("\n\t\t\t\tEnter the name of the patient to be deleted:");
 getchar();
 scanf("%[^\n]s",name);
 printf("\n\t\t\t\tEnter the ID of the patient:");
 scanf("%d",&id);
 temp=first;
 prev=temp;
 while(temp!=NULL)
 {
 if((strcmp(temp->name,name)==0)&&(temp->id==id))
 break;
 prev=temp;
 temp=temp->next;
 }
 if(temp==NULL)
 {
 printf("\n\t\t\t\tPatient named %s with ID %d is not found!",name,id);
 }
 else
 {
 if(temp==first)
 {
 first=temp->next;
 }
 else
 prev->next=temp->next;
 printf("\n\t\t\t\tEnter number of days stayed:");
 scanf("%d",&days);
 printf("\n\t\t\t\tBILL:");
 switch(temp->cat)
 {
 case 1:printf("\n\t\t\t\tConsultation fee:%d/-",days*150);
 printf("\n\t\t\t\tBed fee :%d/-",days*500);
 printf("\n\t\t\t\tTotal :%d/-",(days*150)+(days*500));
 break;
 case 2:printf("\n\t\t\t\tConsultation fee:%d/-",days*300);
 printf("\n\t\t\t\tBed fee :%d/-",days*500);
 printf("\n\t\t\t\tTotal :%d/-",(days*300)+(days*500));
 break;
 case 3:printf("\n\t\t\t\tConsultation fee:%d/-",days*750);
 printf("\n\t\t\t\tBed fee :%d/-",days*500);
 printf("\n\t\t\t\tTotal :%d/-",(days*750)+(days*500));
 break;
 case 4:printf("\n\t\t\t\tConsultation fee:%d/-",days*300);
 printf("\n\t\t\t\tBed fee :%d/-",days*500);
 printf("\n\t\t\t\tTotal :%d/-",(days*300)+(days*500));
 break;
 case 5:printf("\n\t\t\t\tConsultation fee:%d/-",days*100);
 printf("\n\t\t\t\tBed fee :%d/-",days*500);
 printf("\n\t\t\t\tTotal :%d/-",(days*100)+(days*500));
 break;
 default:printf("\n\t\t\t\tConsultation fee:%d/-",days*200);
 printf("\n\t\t\t\tBed fee :%d/-",days*500);
 printf("\n\t\t\t\tTotal :%d/-",(days*150)+(days*500));
 break;
 }
 printf("\n\t\t\t\tPatient %s with the ID %d is deleted from the Record",temp->name,temp-
>id);
 free(temp);
 }
 }
 printf("\n\t\t\t\tPress any key to continue");
 getchar();
 ch=getch();
 beds++;
 system("cls");
 return first;
}
int main()
{
 int choice;
 system("COLOR F0 ");
 NODE *first=NULL;
 printf("\n\n\t\t\t\t*************************************************");
 printf("\n\t\t\t\t *** WELCOME TO HOSPITAL MANAGEMENT SYSTEM ***");
 printf("\n\t\t\t\t*************************************************");
 printf("\n\n\n\n\n\n\n");
 while(1)
 {
 printf("\t\t\t\t\t\t\t\t_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ");
 printf("\n\t\t\tNumber of beds available:%d ",beds);
 printf("\t\t|cat.\tSpecialist\t\tRoom no.");
 printf("\n\t\t\t1:Add new patient record ");
 printf("\t\t|1\tGeneral physician\t201,202");
 printf("\n\t\t\t2:search a patient ");
 printf("\t\t|2\tE.N.T\t\t\t203");
 printf("\n\t\t\t3:display all patient records");
 printf("\t\t|3\tCardiologist\t\t204");
 printf("\n\t\t\t4:Delete patient record ");
 printf("\t\t|4\tDermatologist\t\t205");
 printf("\n\t\t\t5:Exit ");
 printf("\t\t|5\tGeneral surgeon\t\t206,207");
 printf("\n\t\t\tEnter your choice:");
 scanf("%d",&choice);
 system("cls");
 switch(choice)
 {
 case 1:first=add(first);
 break;
 case 2:sea(first);
 break;
 case 3:dis(first);
 break;
 case 4:first=del(first);
 break;
 case 5:exit(0);
 default:printf("\n\t\t\t\tInvalid input!");
 }
 }
 return 0;
}