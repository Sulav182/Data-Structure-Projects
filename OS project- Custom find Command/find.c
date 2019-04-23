/*
*this program shows how to pass the arguments using getopt,
*This program can be integrated into your find utility project, to pass the multiple arguments

*compile this code: gcc -o getopt getopt.c

*Input: ./getopt -w Document -n myfile -a delete

*Output find Document myfile delete
*/

#include <stdio.h>
/* getopt is defined in "unistd.h". */
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
struct Options {
	char name[20];
	char mmin[20];
	char inum[20];
};
void read_sub (char* sub_dir, struct Options criteria, char* user_action);
void find(char *where, struct Options criteria,char *action)
	{
        read_sub(where,criteria,action);
 

	//this is your find function, maybe different from this sample codes
	 printf("find %s %s %s\n",where,criteria.name,action);
	}
int main (int argc, char ** argv)
{
    int w,n,m,i,a;
    char *where, *name, *mmin,* inum, *action;
    struct Options criteria;
    while (1) {
        char c;

        c = getopt (argc, argv, "w:n:m:i:a:");//a colon (â€˜:â€™) to indicate that it takes a required argument, e.g, -w testdir
        if (c == -1) {
            /* We have finished processing all the arguments. */
            break;
        }
        switch (c) {
            case 'w':
        	w=1;
        	where=optarg;
                printf ("where: %s\n",optarg);
                break;
            case 'n':
        	n=1;
        	name=optarg;
		strcpy(criteria.name,name);
                printf ("name: %s\n", optarg);
                break;
    	    case 'm':
        	m=1;
        	mmin=optarg;
		strcpy(criteria.mmin,mmin);
        	printf("mmin: %s\n", optarg);
        	break;
    	    case 'i':
    	       i=1;
      	       inum=optarg;//may need use atoi to convert int and char, I don't know
	       strcpy(criteria.inum,inum);
    	       printf("inum: %s\n", optarg);
    	       break;
            case 'a':
               a=1;
               action=optarg;
               printf("action: %s\n", optarg);
               break;
           case '?':
               default:
               	printf ("not argument\n");
        }
    }

     /*now you can pass the parameter to the find function
     for example, if the action, where, name are all specified,
     then you can call the find(where, name, action), but also depends on
     how you implement the find function, some people probably would like
     to implement only one find function, e.g., find(where, criteria, action)
     some will implement multiple, e.g., find_where(where), find_where_criteria(where, criteria), and find_where_action(where, criteria, action)
     anyway, just make sure you can make use of the getopt() to pass the arguments
    */
     if(a==1 && w==1 && n==1&& i==1 && m==1)
      	find(where,criteria,action);
      else{
      	printf("Please enter the command in the format: find -w <dir name> -n <file name> -m <modified time> -i <inode number> -a <action>");
      	printf("If you do not want to enter options, enter none in the option field");

      }
      //note: the find function maybe not like this. you do not have to follow this format.

    /*the following codes are optional, but better to study it*/
    
    /* Now set the values of "argc" and "argv" to the values after the
       options have been processed, above. */
    argc -= optind;
    argv += optind;

    /* Now do something with the remaining command-line arguments, if
       necessary. */
    if (argc > 0) {
        printf ("There are %d command-line arguments left to process:\n", argc);
        for (i = 0; i < argc; i++) {
            printf ("    Argument %d: '%s'\n", i + 1, argv[i]);
        }
    }
    return 0;
}
 /* 
*A function that recursively print all file names 
*Input: directory name, i.e., char * sub_dir 
*Output: all file names 
*/ 
void read_sub (char* sub_dir,struct Options criteria, char* user_action) 
{ 

  DIR *sub_dp=opendir(sub_dir);//open a directory stream
  struct dirent * sub_dirp;//define  
  struct stat buf;//define a file status structure
  char temp1[]=".";   
  char temp2[]="..";   
  char info[20];
  struct tm * timeinfo;
  time_t now = time(0);
   char* action = user_action;
  if(sub_dp!=NULL) 
  //check whether the directory stream is opened successfully     
  { 
       // read one entry each time 
       while((sub_dirp=readdir(sub_dp))!=NULL)  
        { 
	     char temp3[]="/";  
             //print the first entry, a file or a subdirectory          
             //printf("%s\n",sub_dirp->d_name); 
     
             //check whether the first entry is a subdirectory          
             char * temp =sub_dirp->d_name; 

     	     //printf("Before making full path %s\n", temp);
            //to avoid recursively searching . and .. in the directory. 
            if(strcmp(temp,temp1)!=0 && strcmp(temp,temp2)!=0) 
            { 
		
                char *temp_sub=temp3; 
		//printf("Inside if values of temp3 and temp_sub and temp: %s %s %s\n",temp3, temp_sub, temp);

                temp_sub=strcat(temp_sub,temp); 
		//printf("Inside if values: %s %s %s\n", temp_sub, temp3, temp);

                //now you add the / in front of the entry’s name             
                char* temp_full_path=malloc(sizeof(char)*2000);
		  
                temp_full_path=strcpy(temp_full_path,sub_dir); 
                
                strcat(temp_full_path,temp_sub); 
                //now you get a full path, e.g., testdir/dir1 or testdir/test1 
     
                // try to open 
				//Print full if only the name argument is none
				
                
                DIR * subsubdp=opendir(temp_full_path);  
                //if not null, means we find a subdirectory, otherwise, its just a file
             	
                if(subsubdp!=NULL){ 
                    //close the stream, because we will reopen it in the recursive call.              
                    closedir(subsubdp);             
                    read_sub(temp_full_path,criteria,action);//call the recursive function call.         
                }
				//Checking if the name of the file matches the name given by the user
				else if(strcmp(temp,criteria.name)==0){
					printf("Filename found at %s\n",temp_full_path);	
					if(strcmp(action,"delete")==0){
						remove( temp_full_path)	;
						printf("File with filename %s is deleted\n",criteria.name);
					}		
				}
				//checking for the modified time
				else if(strcmp("none",criteria.mmin)!=0){
					if(stat(temp_full_path,&buf)==0){
						double minutes = (difftime(now, buf.st_mtime))/60;
						char sign = criteria.mmin[0];
						char min[20];
						int i=1;
						int j=0;
						for(i;i<strlen(criteria.mmin);i++){
							min[j]=criteria.mmin[i];
							//printf("%c %c\n",min[j],criteria.mmin[i]);
							j=j+1;
						}
						min[j]='\0';
						if(sign==43 && minutes>atoi(min)){
							printf("File modified after %s is %s\n",min,temp_full_path);
						}
						if(sign==45 && minutes<atoi(min)){
							printf("File modified before %s is %s\n",min,temp_full_path);
						}
						if(sign==45 && minutes==atoi(min)){
							printf("File modified at %s min is %s\n",min,temp_full_path);
						}
						if(strcmp(action,"delete")==0){
							remove( temp_full_path)	;
							printf("File with mmin %s is deleted\n",criteria.mmin);
						}	
						//printf("%c %f", sign, min);
					}
				}
				else if(strcmp("none",criteria.inum)!=0) {
				
					 if(stat(temp_full_path,&buf)==0){
					
					 	if(atoi(criteria.inum)==buf.st_ino){
					 	
					 		printf("File with inode number %s is %s\n",criteria.inum ,temp_full_path);
					 	}
					 	if(strcmp(action,"delete")==0){
							remove( temp_full_path)	;
							printf("File with inode %s is deleted\n",criteria.inum);
						}	
					 }
				}
				
				
				if(((strcmp(criteria.name,"none")==0) && (strcmp(criteria.mmin,"none")==0) && (strcmp(criteria.inum,"none")==0)) && (strcmp(action,"none")==0)){
					printf("fullpath %s \n", temp_full_path);
				}


			}
		
                
             
      	}//end of while loop 
    	closedir(sub_dp);//close the steam 
    }     
    else{ 
        printf("cannot open directory\n");         
        exit(2); 
    }
} 