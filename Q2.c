//Name:Supriya Das  Roll:301910501008
/* Write a program to store student information in a file and t do the following operations. 
Information includes roll, name, and score in five subjects. 
Use may like to add record (ensure roll number is unique), display all records showing roll, name and total score. User may search for the record against a roll. 
User may edit the details a record. 
User may delete record.
 Deletion may be logical (by some means indicate it is an invalid record and to be avoided in processing) and physical (file will not have the record).
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>
int maxRoll[5000];
struct student{
    int roll;
    char name[40];
    int score[5];
};
int main()
{
    FILE *fp=fopen("test_score.txt","w+");
    
    struct student st;
    printf("Enter the students details:\n");
    printf("Students Roll :");
    scanf("%d",&st.roll);
    fprintf(fp,"%d",st.roll);
    maxRoll[st.roll]=1;
    printf("Enter the name:");
    scanf(" %s[^\n]",st.name);
    fprintf(fp,"    %s",st.name);
    int i=0;
    printf("Enter the marks of 5 subjects:");
    for(i=0;i<5;i++)
    {
        scanf("%d",&st.score[i]);
        fprintf(fp,"  %d",st.score[i]);
    }
    fprintf(fp,"\n");
    // to insert a new record
    int choice=0;
    // long n=ftell(fp);
    fclose(fp);
    int total_lines=1;
    printf("1.To Add\n2.To Search\n3.To Edit\n4.To Delete\n5.ToDisplay\n6.Exit\n");
    scanf("%d",&choice);
    
    while(1)
    {
        
        
        if(choice==6)
        {
            break;
        }
        if(choice ==1)
        {
            FILE *fp=fopen("test_score.txt","a+");
            printf("Enter the Roll number:");
            scanf("%d",&st.roll);
            if(maxRoll[st.roll]==0)
            {
                fprintf(fp,"%d",st.roll);
                printf("Enter the name:");
                scanf(" %s[^\n]",st.name);
                fprintf(fp,"    %s",st.name);
                printf("Enter the marks of the 5 subjects:");
                
                for(i=0;i<5;i++)
                {
                    scanf("%d",&st.score[i]);
                    fprintf(fp,"  %d",st.score[i]);
                }
                fprintf(fp,"\n");
                // n=ftell(fp);
                total_lines+=1;
                maxRoll[st.roll]+=1;
            }
            else
            {
                printf("A Student with the given roll number already exists\n");
            }
            fclose(fp);
        }
        if(choice==2)
        {
         
            FILE *fp;
            fp=fopen("test_score.txt","r+");
        
            int rl;
            
            printf("Enter the roll you want to search:");
            scanf("%d",&rl);
           int found=0;
           
           for(i=0;i<total_lines;i++)
           {
               fscanf(fp,"%d%s%d%d%d%d%d",&st.roll,st.name,&st.score[0],&st.score[1],&st.score[2],&st.score[3],&st.score[4]);
               if(rl==st.roll)
               {
                   found=1;
                   printf("The student is found\n");
                   printf("Roll:%d",st.roll);
                   printf("  Name:%s",st.name);
                   printf(" Scores:%d %d %d %d %d\n",st.score[0],st.score[1],st.score[2],st.score[3],st.score[4]);
                   break;
               }

           }
        if(!found)printf("The student do not exist\n");
           fclose(fp);

        }
           if(choice == 3)
           {
               FILE*fp=fopen("test_score.txt","r+");
               FILE*fp1=fopen("test_copy.txt","w+");
               int rl;

               printf("\nEnter the roll to edit\n");
               scanf("%d",&rl);
               while(maxRoll[rl]==0)
               {
                   printf("The student with given roll number do not exist\n");
                   printf("Please Enter again:");
                   scanf("%d",&rl);
               }
               rewind(fp);
               for(i=0;i<total_lines;i++)
               {
                   struct student st2;
                   
                   fscanf(fp,"%d%s%d%d%d%d%d",&st2.roll,st2.name,&st2.score[0],&st2.score[1],&st2.score[2],&st2.score[3],&st2.score[4]);
                //    printf("%d\n",st2.roll);
                   if(st2.roll!=rl)
                   {
                       
                       fprintf(fp1,"%d %s %d %d %d %d %d",st2.roll,st2.name,st2.score[0],st2.score[1],st2.score[2],st2.score[3],st2.score[4]);
                       fprintf(fp1,"\n");
                   }
                   else
                   {
                       struct student st1;
                       printf("Enter the roll of the new student:");
                       scanf("%d",&st1.roll);
                       printf("Enter the name:");
                       scanf("%s",st1.name);
                       printf("Enter the score:");
                       scanf("%d%d%d%d%d",&st1.score[0],&st1.score[1],&st1.score[2],&st1.score[3],&st1.score[4]);
                       fprintf(fp1,"%d %s %d %d %d %d %d",st1.roll,st1.name,st1.score[0],st1.score[1],st1.score[2],st1.score[3],st1.score[4]);
                       fprintf(fp1,"\n");
                       
                   }
                   
               }
               fclose(fp1);
               fclose(fp);
           
              
               remove("test_score.txt");

               rename("test_copy.txt","test_score.txt");
           }
           if(choice == 5)
           {
               printf("\n------------------------\n");
               fp=fopen("test_score.txt","r+");
               printf("\nStudents Records:\n");
               for(i=0;i<total_lines;i++){
               fscanf(fp,"%d%s%d%d%d%d%d",&st.roll,st.name,&st.score[0],&st.score[1],&st.score[2],&st.score[3],&st.score[4]);
               printf("Roll:%d \nName:%s \nScores:%d %d %d %d %d\n",st.roll,st.name,st.score[0],st.score[1],st.score[2],st.score[3],st.score[4]);
               printf("Total:%d\n",st.score[0]+st.score[1]+st.score[2]+st.score[3]+st.score[4]);
               printf("\n------------------------\n");
               }
               fclose(fp);
           }
           if(choice == 4)
           {
               FILE*fp=fopen("test_score.txt","r+");
               FILE*fp1=fopen("test_copy.txt","w+");
               int rl;
               printf("\nEnter the roll to delete\n");
               scanf("%d",&rl);
               while(maxRoll[rl]==0)
               {
                   printf("The student with given roll number do not exist\n");
                   printf("Please Enter again:");
                   scanf("%d",&rl);
               }
               maxRoll[rl]-=1;
               for(i=0;i<total_lines;i++)
               {
                   struct student st2;
                   
                   fscanf(fp,"%d%s%d%d%d%d%d",&st2.roll,st2.name,&st2.score[0],&st2.score[1],&st2.score[2],&st2.score[3],&st2.score[4]);
                //    printf("%d\n",st2.roll);
                   if(st2.roll!=rl)
                   {
                       
                       fprintf(fp1,"%d %s %d %d %d %d %d",st2.roll,st2.name,st2.score[0],st2.score[1],st2.score[2],st2.score[3],st2.score[4]);
                       fprintf(fp1,"\n");
                   }
                  
                   
               }
               total_lines-=1;
               fclose(fp1);
               fclose(fp);
           
              
               remove("test_score.txt");

               rename("test_copy.txt","test_score.txt");
               
           }

        printf("1.To Add\n2.To Search\n3.To Edit\n4.To Delete\n5.Display\n6.Exit\n");
        printf("\nEnter the choice:");
        scanf("%d",&choice);
        
    }
    
    
}
