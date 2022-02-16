/* C program by Kevin Huy Trinh CS1311 Jan 2022

||=============================================================================||
||																		       ||
||  #    # ####### #     # ### #     #    ####### ######  ### #     # #     #  ||
||  #   #  #       #     #  #  ##    #       #    #     #  #  ##    # #     #  ||
||  #  #   #       #     #  #  # #   #       #    #     #  #  ##    # #     #  ||
||  ###    #####   #     #  #  #  #  #       #    ######   #  #  #  # #######  ||
||  #  #   #        #   #   #  #   # #       #    #   #    #  #   # # #     #  ||
||  #   #  #         # #    #  #    ##       #    #    #   #  #    ## #     #  ||
||  #    # #######    #    ### #     #       #    #     # ### #     # #     #  ||
||                                   						   		 	  	   ||  	  		  		  
||=============================================================================||

* Author: Kevin Huy Trinh
* Class: CS1311 12:35pm
* Language: C
* Project Name: Transpose Program #1

* Purpose: This program reads information from a file called names.txt
* and prints output on a file named trans.txt and the screen. The output 
* will be the names but in vertical form. */


#include <stdio.h>
#include <string.h>


void main(void){

	 FILE *name, *trans;				/* get access to in and out txt */
	 char names[20][60] = {};			/* name 2D array initialized to all '\0' */
	 int i, j;							/* index values for loops */
	 
	 name = fopen("name.txt", "r");		/* reads name.txt */
	 trans = fopen("trans.txt", "w");	/* writes to trans.txt */

	 printf("This program reads video game titles from names.txt and outputs the game titles in a vertical format. \n\n");
	 
	 for(i = 0; i < 15; i++){
         fgets(names[i], 60, name);		/* reads in line from name.txt into 2D array*/
         printf("%s", names[i]);		/* prints each string as its being copied */
	 }
	 
	 printf("\nThe vertical format print below...\n\n");
	 
	 /* double for loop goes down 2D array row by row */
	 for(j = 0; j < 60; j++){
         for(i = 0; i < 20; i++){
		 	   if(names[i][j] != '\n' && names[i][j] != '\0'){	/* checks if were at the end of line or done with the list */
				
				   printf("%c ", names[i][j]);					/* prints out to screen with space*/
				   fprintf(trans, "%c ", names[i][j]);			/* prints out to trans.txt with space*/
				
				}
               else {						
			   
     	           printf("  ");			/* spacing */
	   		       fprintf(trans, "  ");
			   
			   }
			   printf("  ");				/* spacing */
		 	   fprintf(trans, "  ");
		 }
		 printf("\n");						/* new line */
	 	 fprintf(trans, "\n");
	 }
	 
	 fclose(name);
	 fclose(trans);

}
