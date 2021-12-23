// WRITTEN BY:
// Arciella Brience C. Crisostomo 
//			   and 
// 	  Dustin Kyle D. Landicho
//
// SECTION: EQ1        
//                
// FOR COURSE:    LBYEC2B
//
// PURPOSE:
// This program provides an environment for a single user to document 
// thoughts and different moods as well as easily track patterns in internal 
// and external factors that affect the different moods experienced by the user.
//
// OVERALL METHOD/ALGORITHM:
// The list of general tasks is:
// 1. Create an account (if there is none made yet), or display the menu (if the user has already created an account)
// 2. Execute the menu item.
//    2-1. If selected menu item is '1', verify if the user wants to go back to the menu, or to add entries
//         2-1-a. If the user wants to add entries, direct to class entryClass
//    2-2. If selected menu item is '2', direct to class classStats
//    2-3. If selected menu item is '3', verify if the user wants to go back to the menu, or to add activity/mood, or to delete activity/mood
//         2-3-a. If the user wants to add or delete a mood, direct to class moodClass,
//         		  if the user wants to add or delete an activity, direct to class activityClass
//    2-4. If selected menu item is '4', direct to class menuClass (function printHistory())
//    2-5. If the selected menu item is '5', direct to class menuClass (function deleteAccount())
//    2-6. If the selected menu item is '6', exit the program
//
// CREDITS:
//   Jose Antonio Catalan (LBYEC2B_EQ1 Professor)
// 
// FUNCTIONS:
// menu
//   display the menu
//
// addMood
//   allows user to add a mood in the moods.txt file
//
// deleteMood
//   allows user to delete a mood from the moods.txt file
// 
// addActivity
//   allows user to add an activity in the activities.txt file
//
// deleteActivity
//   allows user to delete an activity from the activities.txt file
//
// addEntry
//   allows the user to input entries
//
// printHistory
//   displays total number of entries per month and all entries
// 
// displayStats
//   displays the statistics of overall selected moods and activities in entries.txt file
// 
// intro
//   If there is no account made yet, creates an account for the user.
//   If there is already an existing account, program welcomes the user and displays the menu
//
// displayMsg
//   displays an acknowledgement message 
//
// displayQuote
//   displays a short message that serve as the quote for the day
//
//
// STRUCTURES: 
// entryType
//   contains information about the user
//
//
// CLASSES:
// moodClass
//   contains functions that allow the user to add or delete a mood
//
// activityClass
//   contains functions that allow the user to add or delete an activity
//
// entryClass
//   allows the user to input entries
//
// menuClass
//   contains functions that allows the user to view the history of entries or to deactivate the account
//
//
// INCLUDED FILES:
//    stdio.h (for input and output functions; ex: printf(), scanf()), string.h (for string handling; ex: strcmp()), 
//    stdlib.h (process control; ex: exit()), conio.h (for console input and output; ex: getch()), time.h (for time; ex: time_t)
//
//
// DATA FILES:
//    activities.txt (stores all available user activities)
// 	  entries.txt (stores user entries)
//    initialAccount.txt (stores the user account information)
//    moods.txt (stores all available user moods)

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>

//function header
void menu();

// STRUCTURE NAME: entryType
// CREDITS: A. Crisostomo and D. Landicho     
//
// CALLS TO: None
//
// CALLED FROM: menu()
// Structure datatype that holds necessary details for user entries
typedef struct {
	int age; //for one-time use only and is used whenever an account is created
	
	char mood[15];
	char activity[100];
	char message[100];
} entryType;

// CLASS NAME: classMsgs
// CREDITS: A. Crisostomo
//
// CALLS TO: None
//
// CALLED FROM: menu()
// Class declaration that handles creating a short motivational
// message for the user when as it detects general moods
class classMsgs {
  public:
	void displayMsg();
	classMsgs() {}; // default constructor that doesn't change anything
};

// CLASS NAME: subclassMsgs
// CREDITS: A. Crisostomo    
//
// CALLS TO: None
//
// CALLED FROM: menu()
// subclass of classMsgs that is in charge of displaying messages when the user is feeling down
class subclassMsgs: public classMsgs {
  public:
  	
  	//array of strings that contain motivational messages
  	char randomMsgs[500][500] = {
		"\n***SYSTEM MESSAGE/QUOTE OF THE DAY: There are no great people in this world, only great challenges\nwhich ordinary people rise to meet.***\n",
		"\n***SYSTEM MESSAGE/QUOTE OF THE DAY: Life's challenges are not supposed to paralyze you;\nthey're supposed to help you discover who you are.***\n",
		"\n***SYSTEM MESSAGE/QUOTE OF THE DAY: Give yourself another day, another chance. You will find\nyour courage eventually. Don't give up on yourself just yet.***\n",
		"\n***SYSTEM MESSAGE/QUOTE OF THE DAY: It's going to be okay in the end. If it's not\nokay, it's not the end.***\n",
		"\n***SYSTEM MESSAGE/QUOTE OF THE DAY: Although it's difficult to see beyond the sorrow,\nmay looking back in memory help comfort you tomorrow.***\n",
		
		"\n***SYSTEM MESSAGE/QUOTE OF THE DAY: And if today all you did was hold yourself together,\nwe're proud of you.***\n",
		"\n***SYSTEM MESSAGE/QUOTE OF THE DAY: Be patient and strong; Someday this pain will\nbe useful to you.***\n",
		"\n***SYSTEM MESSAGE/QUOTE OF THE DAY: Still round the corner, there may wait,\na new road or a secret gate.***\n",
		"\n***SYSTEM MESSAGE/QUOTE OF THE DAY: Soak up the views. Take in the bad weather\n and the good weather. You are not the storm.***\n",
		"\n***SYSTEM MESSAGE/QUOTE OF THE DAY: Hardships often prepare ordinary people for\nan extraordinary destiny.***\n",
		
		"\n***SYSTEM MESSAGE/QUOTE OF THE DAY: Every day is different, and some days are better than others,\nbut no matter how challenging the day, live it.***\n",
		"\n***SYSTEM MESSAGE/QUOTE OF THE DAY: Recognize that on certain days the greatest grace\nis the day is over and you get to close your eyes. Tomorrow comes more brightly.***\n",
		"\n***SYSTEM MESSAGE/QUOTE OF THE DAY: Never give up. Today is hard, tomorrow will be worse,\nbut the day after tomorrow will be sunrise.***\n",
		"\n***SYSTEM MESSAGE/QUOTE OF THE DAY: Everyday is a good day, just some days are better.***\n",
		"\n***SYSTEM MESSAGE/QUOTE OF THE DAY: Bad days always promise a better tomorrow.***\n",
	};
	
  	int random; // variable where a random value will be stored
	time_t t;
		
  	subclassMsgs() {}; // default constructor which does not change anything
    void displayQuote();
};

// CLASS NAME: moodClass
// CREDITS: D. Landicho       
//
// CALLS TO: None
//
// CALLED FROM: menu()
// Class declaration that contains functions in adding or deleting moods
class moodClass {
	public:
		
		// FUNCTION NAME: addMood
		// CREDITS: D. Landicho
		//           
		// PARAMETERS: None
		//
		// RETURN VALUE: None      
		//
		// CALLS TO: None
		//
		// CALLED FROM: menu()
		//
		// METHOD:
		//
		// 1) prompt the user to enter mood name to add
		// 2) read user input then append to moods.txt file
		void addMood() {
			char mod[20];
			char lines[50], listMoods[50];
			bool exists;
			FILE *moo;
			
			system("cls");
			printf("Here is a list of all your moods so far: \n");
			
			//Lists all moods in the corresponding text file
			moo = fopen("moods.txt", "r");
			while (fgets(listMoods, sizeof listMoods, moo) != NULL) {
				//Program ignores blank lines
				if(strlen(listMoods) != 1) printf("%s", listMoods);
			}
			fclose(moo);
			
			printf("\nEnter mood name: ");
			scanf(" %[^\n]s", mod);
		
			FILE *read = fopen("moods.txt", "r");
			FILE *fp = fopen("moods.txt", "a"); //Appends the custom mood to the text file
			while (!feof(read)) {
				fscanf(read, "%s", lines);
				if ((stricmp(lines, mod) == 0)) {
					exists = true;
					break;
				}
			}
			
			if(!exists){
				fprintf(fp, "\n%s", mod);
				printf("Mood \"%s\" added. Press enter to continue. ", mod);
			}
			
			else printf("Mood \"%s\" already exists. Press enter to continue. ", mod);
			
			fclose (fp);
			fclose(read);
			getch();
			system("cls");
		}
		
		// FUNCTION NAME: deleteMood
		// CREDITS: A. Crisostomo and D. Landicho
		//           
		// PARAMETERS: None
		//
		// RETURN VALUE: None      
		//
		// CALLS TO: None
		//
		// CALLED FROM: menu()
		//
		// METHOD:
		//
		// 1) display list of moods
		// 2) prompt the user a mood to delete
		// 2) read user input then delete from moods.txt file
		void deleteMood() {
			system("cls");
			FILE *moo;
			FILE *fp1, *fp2;
			char mood[256];
			char temp[] = "temp.txt"; //Declares temporary file
			char listMoods[1000], lineMoods[1000]; //Text file line reader variables
			bool exists = false;
			
			printf("Here is a list of all your moods so far: \n");
			
			//Lists all moods in the corresponding text file
			moo = fopen("moods.txt", "r");
			while (fgets(listMoods, sizeof listMoods, moo) != NULL) {
				//Program ignores blank lines
				if(strlen(listMoods) != 1) printf("%s", listMoods);
			}
			fclose(moo);
			
			// Gets the mood to delete from the user
	        printf("\nEnter the mood you would want to delete: ");
	        scanf(" %[^\n]s", mood);
	        
	        //opens moods.txt file in read mode
	        fp1 = fopen("moods.txt", "r");
	
	        // error handling for original file
	        if (!fp1) {
	            printf("Unable to open file.\n");
	            getch();
	            menu();
	        }
	
	        // open temporary file in write mode 
	        fp2 = fopen(temp, "w");
	
	        // error handling for temporary file
	        if (!fp2) {
	            printf("Unable to open temporary file.\n");
	            getch();
	            menu();
	        }
	        
	        while (fgets(lineMoods, sizeof lineMoods, fp1) != NULL) {
	        	//Copies all lines of input text to temporary file except the activity chosen
	        	strtok(lineMoods, "\n");
				if (stricmp(lineMoods, mood) != 0) {
					strcat(lineMoods, "\n");
					fprintf(fp2, lineMoods);
				}
				else exists = true;
			}
			
			fclose(fp1);
			fclose(fp2);
			
			// removes original file
	        remove("moods.txt");
	        // renames temporary file name to the original file name
	        rename(temp, "moods.txt");
	        
	        if(exists) printf("Mood \"%s\" deleted. Press enter to continue. ", mood);
	        else printf("Mood \"%s\" does not exist. Press Enter to continue. ", mood);
			getch();
			system("cls");
			menu();	
		}
};

// CLASS NAME: activityClass
// CREDITS: D. Landicho  
//
// CALLS TO: none
//
// CALLED FROM: menu()
// Class declaration that contains functions in adding and deleting activities
class activityClass {
	public:
		
		// FUNCTION NAME: addActivity
		// CREDITS: D. Landicho
		//           
		// PARAMETERS: None
		//
		// RETURN VALUE: None      
		//
		// CALLS TO: None
		//
		// CALLED FROM: menu()
		//
		// METHOD:
		//
		// 1) prompt the user to enter activity name to add
		// 2) read user input then append to activities.txt file
		void addActivity() {
			char act[20];
			char lines[50], listActs[50];
			bool exists;
			FILE *a;
			
			system("cls");
			printf("Here is a list of all your activities so far: \n");
			
			//Lists all activities in the corresponding text file
			a = fopen("activities.txt", "r");
			while (fgets(listActs, sizeof listActs, a) != NULL) {
				//Program ignores blank lines
				if(strlen(listActs) != 1) printf("%s", listActs);
			}
			fclose(a);
			
			printf("\nEnter activity name: ");
			//The contents of the scanf function look the way it is as to be able to achieve 2 things
			//1. To prevent it from reading the newline from the previous input
			//2. To be able to read string entries that are longer than 1 word or contain multiple whitespaces
			scanf(" %[^\n]s", act);
			
			FILE *read = fopen("activities.txt", "r");
			FILE *fp = fopen("activities.txt", "a"); //Appends the custom activity to the text file
			while (!feof(read)) {
				fscanf(read, " %[^\n]s", lines);
				if ((stricmp(lines, act) == 0)) {
					exists = true;
					break;
				}
			}
			
			if(!exists) {
				fprintf(fp, "\n%s", act);
				printf("Activity \"%s\" added. Press enter to continue. ", act);
			}

			else printf("Activity \"%s\" already exists. Press enter to continue. ", act);			
			
			fclose(read);
			fclose (fp);
			getch();
			system("cls");
		}
		
		// FUNCTION NAME: deleteMood
		// CREDITS: A. Crisostomo and D. Landicho
		//           
		// PARAMETERS: None
		//
		// RETURN VALUE: None      
		//
		// CALLS TO: None
		//
		// CALLED FROM: menu()
		//
		// METHOD:
		//
		// 1) display list of activities
		// 2) prompt the user to enter activity name to delete
		// 3) read user input then delete from moods.txt file
		void deleteActivity() {
			system("cls");
			FILE *act;
			FILE *fp1, *fp2;
			char activity[256];
			char temp[] = "temp.txt"; //Declares temporary file
			char listActs[1000], lineActs[1000]; //Text file line reader variables
			bool exists = false;
						
			printf("Here is a list of all your activities so far: \n");
			
			//Lists all activities in the corresponding text file
			act = fopen("activities.txt", "r");
			while (fgets(listActs, sizeof listActs, act) != NULL) {
				//Program ignores blank lines
				if(strlen(listActs) != 1) printf("%s", listActs);
			}
			fclose(act);
			
			// gets the activity to delete from the user
	        printf("\nEnter the activity you would want to delete: ");
	        scanf(" %[^\n]s", activity);
	        
	        // opens activities.txt file in read mode
	        fp1 = fopen("activities.txt", "r");
	
	        // error handling for original file
	        if (!fp1) {
	            printf("Unable to open file.\n");
	            getch();
	            menu();
	        }
	
	        // open temporary file in write mode
	        fp2 = fopen(temp, "w");
	
	        // error handling for temporary file
	        if (!fp2) {
	            printf("Unable to open temporary file.\n");
	            getch();
	            menu();
	        }
	        
	        while (fgets(lineActs, sizeof lineActs, fp1) != NULL) {
	        	//Copies all lines of input text to temporary file except the activity chosen
	        	strtok(lineActs, "\n");
				if (stricmp(lineActs, activity) != 0) {
					strcat(lineActs, "\n");
					fprintf(fp2, lineActs);
				}
				else exists = true;
			}
			
			fclose(fp1);
			fclose(fp2);
			
			// removes the original activities.txt file
	        remove("activities.txt");
	        // renames temporary file name to the original file name
	        rename(temp, "activities.txt");
	        
	        if(exists) printf("Activity \"%s\" deleted. Press enter to continue. ", activity);
			else printf("Activity \"%s\" does not exist. Press enter to continue. ", activity);
			getch();
			system("cls");
			menu();	
		}
};

// CLASS NAME: entryClass
// CREDITS: D. Landicho                
//
// CALLS TO: None
//
// CALLED FROM: menu()
// Class declaration that contains functions involving the user's entries
class entryClass {
	public:
		
		FILE *fp;
		char checker[50];
		
		//counter variables for general moods
		float radCounter = 0;
		float goodCounter = 0;
		float mehCounter = 0;
		float badCounter = 0;
		float awfulCounter = 0;
		float totalCounter = 0;
		
		FILE *fp2;
		
		//counter variables for general activities
		float familyCounter = 0;
		float friendsCounter = 0;
		float dateCounter = 0;
		float exerciseCounter = 0;
		float sportCounter = 0;
		float relaxCounter = 0;
		float moviesCounter = 0;
		float gamingCounter = 0;
		float readingCounter = 0;
		float shoppingCounter = 0;
		float totalCounter2 = 0;
		
		char lines[100];
		
		// FUNCTION NAME: addEntry
		// CREDITS: D. Landicho
		//           
		// PARAMETERS: None
		//
		// RETURN VALUE: None      
		//
		// CALLS TO: None
		//
		// CALLED FROM: menu()
		//
		// METHOD:
		//
		// 1) verify (if the user wants to go back to the menu)before adding an entry
		// 2) list of moods is displayed, the user picks which among the moods in which the user most relates to
		// 3) displays chosen mood, and list of activities is displayed, the user picks among the activities in which the user most relates to
		// 4) user is asked to input entry for that time
		// 5) date, mood, activity, and entry is appended to file
		void addEntry() {
			char entry[1000]; 
			int firstChoice, secondChoice;
			int mood, activity;
			entryType et; //Instantiation of the structure datatype
			time_t t = time(NULL);
		    struct tm *tm = localtime(&t); //Instantiation of current date and time to be used later
		    
		    classMsgs cm;
		    subclassMsgs scm;
		
		//Placeholder for the program to return to when the user chooses to    
		BASE:
			do {
				int count = 0;
				mood = 0;
				
				printf("ADDING ENTRY\n");
				printf("%s", asctime(tm));
				printf("How are you feeling today?\n");
				printf("[0] RETURN TO MENU\n");	
				
				//Accesses the text file containing moods and enumerates them
				//numerically for the user to pick
				FILE *m = fopen("moods.txt", "r");
				char moodlines[100];
				while (fgets(moodlines, sizeof moodlines, m) != NULL) {
					
					//The program ignores blank lines in the text file
					if(strlen(moodlines) != 1) {
						
						//Lists all the moods for the user to choose from
						printf("%i.) %s", mood+1, moodlines, strlen(moodlines));
						mood++; // the counter goes up for each valid line read
					}
				}
				fclose(m);
				printf("\nChoice: ");
				scanf("%i", &firstChoice);
				
				char select[100]; //String element to save each line of the moods text file
				FILE *m2 = fopen("moods.txt", "r");
				while (fgets(select, sizeof select, m2) != NULL) {
					
					//Checks if the number selected by the user matches the line number
					//in the text file containing the selected mood
					if(count == firstChoice-1) {
						
						//Once validated, the contents of the line are then appended into
						//the mood value of the structure datatype and the loop ends
						strcpy(et.mood, select);
						
						//Removes the newline character included at the end of the string variable
						strtok(et.mood, "\n");
						break;
					}
					else count++; //Counter goes up until it matches the user-defined number
				}
				fclose(m2);
				
				system("cls");			
				//The do-while loop does not allow user entries above the limit of the number of moods
			} while(firstChoice < 0 || firstChoice > mood);
			
			if(firstChoice == 0) menu();
			
			//do-while loop that asks for the specific activity the user has done
			do {
				int count = 0;
				activity = 0;
				printf("Feeling %s", et.mood);
				printf("\nWhat have you been up to?\n");
				printf("\n[0] RETURN TO MENU\n");
				printf("[100] RETURN TO MOODS\n\n");
						
						
				FILE *a = fopen("activities.txt", "r");
				char actlines[100];
				while (fgets(actlines, sizeof actlines, a) != NULL) {
					if(strlen(actlines) != 1) { //The program ignores blank lines
						printf("%i.) %s", activity+1, actlines); //Lists all activities that the user may choose from
						activity++; //Counter goes up for each valid line detected
					}
				}
				fclose(a);
				
				printf("\nChoice: ");
				scanf(" %i", &secondChoice);
				
				if (secondChoice == 0) {
					system("cls");	
					menu();
				}
				
				if (secondChoice == 100) {
					system("cls");	
					goto BASE; //Brings the user back to the placeholder stated earlier
				}
				
				char select[100]; //String element to save each line of the activities text file
				FILE *a2 = fopen("activities.txt", "r");
				while (fgets(select, sizeof select, a2) != NULL) {
					
					//Checks if the number selected by the user matches the line number
					//in the text file containing the selected activity
					if(count == secondChoice-1) {
						strcat(select, "\n");
						
						//Once validated, the contents of the line are then appended into
						//the mood value of the structure datatype and the loop ends
						strcpy(et.activity, select);
						
						//Removes the newline character included at the end of the string variable
						strtok(et.activity, "\n");
						break;
					}
					else count++; //Counter goes up until it matches the user-defined number
				}
				fclose(a2);
				
				system("cls");
				//The do-while loop does not allow user entries above the limit of the number of activities
			} while(secondChoice < 1 || secondChoice > activity);
			
			//Displays current date and time
			printf("%s", asctime(tm));
			
			printf("Mood: %s\nActivity: %s", et.mood, et.activity);
			printf("\nEnter message: ");
			scanf(" %[^\n]s", entry);
			
			//Copies user entry onto structure message variable
			strcpy(et.message, entry);
			
			//appends all necessary values stored in structure datatype to the corresponding text file
			FILE *fp = fopen("entries.txt", "a");
			fprintf(fp, "Date: %sMood: %s\nActivity: %s\nEntry: %s\n\n", asctime(tm), et.mood, et.activity, et.message);
			fclose (fp);
			
			printf("Entry added.");
			
			// function in base class
			//cm.displayMsg();
			
			// derived class can access inherited function from base class, and derived class has its own function
			scm.displayMsg();
			scm.displayQuote();
			
			printf("Press Enter to Return to Menu.");
			getch();
			
			system("cls");
		}
		
		// FUNCTION NAME: displayStats
		// CREDITS: A. Crisostomo
		//           
		// PARAMETERS: None
		//
		// RETURN VALUE: None      
		//
		// CALLS TO: None
		//
		// CALLED FROM: menu()
		//
		// METHOD:
		//
		// 1) reads through the entries.txt file and counts all the general moods and general activities
		// 2) displays statistics with respect to the chosen general moods and general activities to the total entries
		void displayStats() {
			system("cls");
			
			//while loop reads through the entire file and counts the frequency of general moods
			fp = fopen("entries.txt", "r");
			while (!feof(fp)) {
				fscanf(fp, "%s", checker);
				if (strcmp(checker, "Rad") == 0) radCounter++;
				if (strcmp(checker, "Good") == 0) goodCounter++;
				if (strcmp(checker, "Meh") == 0) mehCounter++;
				if (strcmp(checker, "Bad") == 0) badCounter++;
				if (strcmp(checker, "Awful") == 0) awfulCounter++;
				if (strcmp(checker, "Mood:") == 0) totalCounter++;
			}
			fclose(fp);
			
			//prints statistics of general moods
			printf("GENERAL MOODS");
			if (radCounter > 0) printf("\nRad: %.2f%% (%.0f Entries)", (radCounter/totalCounter)*100, radCounter);
			if (goodCounter > 0) printf("\nGood: %.2f%% (%.0f Entries)", (goodCounter/totalCounter)*100, goodCounter);
			if (mehCounter > 0) printf("\nMeh: %.2f%% (%.0f Entries)", (mehCounter/totalCounter)*100, (mehCounter * 10.0) / 10.0);
			if (badCounter > 0) printf("\nBad: %.2f%% (%.0f Entries)", (badCounter/totalCounter)*100, (badCounter * 10.0) / 10.0);
			if (awfulCounter > 0) printf("\nAwful: %.2f%% (%.0f Entries)\n", (awfulCounter/totalCounter)*100, awfulCounter);
			
			//while loop reads through the entire file and counts the frequency of general activities
			fp2 = fopen("entries.txt", "r");
			while(!feof(fp2)) {
				fscanf(fp2, "%s", checker);
				if (strcmp(checker, "Family") == 0) familyCounter++;
				if (strcmp(checker, "Friends") == 0) friendsCounter++;
				if (strcmp(checker, "Date") == 0) dateCounter++;
				if (strcmp(checker, "Exercise") == 0) exerciseCounter++;
				if (strcmp(checker, "Sport") == 0) sportCounter++;
				if (strcmp(checker, "Relax") == 0) relaxCounter++;
				if (strcmp(checker, "Movies") == 0) moviesCounter++;
				if (strcmp(checker, "Gaming") == 0) gamingCounter++;
				if (strcmp(checker, "Reading") == 0) readingCounter++;
				if (strcmp(checker, "Shopping") == 0) shoppingCounter++;
				if (strcmp(checker, "Activity:") == 0) totalCounter2++;
			}
			fclose(fp2);
			
			//prints statistics of general activities
			printf("\nGENERAL ACTIVIIES");
			if (familyCounter > 0) printf("\nFamily: %.2f%% (%.0f Entries)", (familyCounter/totalCounter2)*100, familyCounter);
			if (friendsCounter > 0) printf("\nFriends: %.2f%% (%.0f Entries)", (friendsCounter/totalCounter2)*100, friendsCounter);
			if (dateCounter > 0) printf("\nDate: %.2f%% (%.0f Entries)", (dateCounter/totalCounter2)*100, dateCounter);
			if (exerciseCounter > 0) printf("\nExercise: %.2f%% (%.0f Entries)", (exerciseCounter/totalCounter2)*100, exerciseCounter);
			if (sportCounter > 0) printf("\nSport: %.2f%% (%.0f Entries)", (sportCounter/totalCounter2)*100, sportCounter);
			if (relaxCounter > 0) printf("\nRelax: %.2f%% (%.0f Entries)", (relaxCounter/totalCounter2)*100, relaxCounter);
			if (moviesCounter > 0) printf("\nMovies: %.2f%% (%.0f Entries)", (moviesCounter/totalCounter2)*100, moviesCounter);
			if (gamingCounter > 0) printf("\nGaming: %.2f%% (%.0f Entries)", (gamingCounter/totalCounter2)*100, gamingCounter);
			if (readingCounter > 0) printf("\nReading: %.2f%% (%.0f Entries)", (readingCounter/totalCounter2)*100, readingCounter);
			if (shoppingCounter > 0) printf("\nShopping: %.2f%% (%.0f Entries)", (shoppingCounter/totalCounter2)*100, shoppingCounter);
			
			printf("\n\n");
		}
};

// CLASS NAME: menuClass
// CREDITS: D. Landicho                
//
// CALLS TO: none
//
// CALLED FROM: menu()
//
// Class declaration that contains menu and login features
class menuClass {
	private:
		//declaration of objects from classes
		moodClass mood;
		activityClass act;
		entryClass ent;
		
		
	public:
		FILE *fp;
		char c, line[100];
		
		//declaration and instantiation of2D array containing the months of the year
		char arrayMonths[15][30] = {"January", "February","March", "April", 
									"May", "June", "July", "August", "September", 
									"October", "November", "December"};
		//declaration of 1D array 
		int volume[15];
		
		//counter for all the months
		int janCounter = 0;
		int febCounter = 0;
		int marCounter = 0;
		int aprCounter = 0;
		int mayCounter = 0;
		int junCounter = 0;
		int julCounter = 0;
		int augCounter = 0;
		int sepCounter = 0;
		int octCounter = 0;
		int novCounter = 0;
		int decCounter = 0;
		
		// FUNCTION NAME: printHistory
		// CREDITS: A. Crisostomo
		//           
		// PARAMETERS: None
		//
		// RETURN VALUE: None      
		//
		// CALLS TO: None
		//
		// CALLED FROM: menu()
		//
		// METHOD:
		//
		// 1) verify (if the user wants to go back to the menu) before adding an entry
		// 2) list of moods is displayed, the user picks which among the moods in which the user most relates to
		// 3) displays chosen mood, and list of activities is displayed, the user picks among the activities in which the user most relates to
		// 4) user is asked to input entry for that time
		// 5) date, mood, activity, and entry is appended to file
		void printHistory() {
			fp = fopen("entries.txt", "r");
			
			//while loop reads the entire file and counts the frequency of months in entries.txt file
			while (!feof(fp)) {
				fscanf(fp, "%s", line);
				if (strcmp(line, "Jan") == 0) janCounter++;
				if (strcmp(line, "Feb") == 0) febCounter++;
				if (strcmp(line, "Mar") == 0) marCounter++;
				if (strcmp(line, "Apr") == 0) aprCounter++;
				if (strcmp(line, "May") == 0) mayCounter++;
				if (strcmp(line, "Jun") == 0) junCounter++;
				
				if (strcmp(line, "Jul") == 0) julCounter++;
				if (strcmp(line, "Aug") == 0) augCounter++;
				if (strcmp(line, "Sep") == 0) sepCounter++;
				if (strcmp(line, "Oct") == 0) octCounter++;
				if (strcmp(line, "Nov") == 0) novCounter++;
				if (strcmp(line, "Dec") == 0) decCounter++;
			}
			fclose(fp);
			
			//instantiation of 1D array, with values from the counters in the previous while loop
			volume[0] = janCounter;
			volume[1] = febCounter;
			volume[2] = marCounter;
			volume[3] = aprCounter;
			volume[4] = mayCounter;
			volume[5] = junCounter;
			volume[6] = julCounter;
			volume[7] = augCounter;
			volume[8] = sepCounter;
			volume[9] = octCounter;
			volume[10] = novCounter;
			volume[11] = decCounter;
			
			//utilizes 1D amd 2D arrays in printing the number of entries per month inputtedby the user
			printf("\n");
			for (int i = 0; i < 11; i++) {
				printf("%i Entries made in %s.\n", volume[i], arrayMonths[i]);	
			}
			
			//prints the entire entries.txt file to console
			printf("\nAll entries:\n");
			fp = fopen("entries.txt", "r");
			c = fgetc(fp);
			while (c != EOF) {
				printf("%c", c);
				c = fgetc(fp);
			}
			fclose(fp);
			
			printf("Press any key to return to menu.");
			getch();
			system("cls");
		}
		
		// FUNCTION NAME: deleteAccount
		// CREDITS: A. Crisostomo and D. Landicho
		//           
		// PARAMETERS: None
		//
		// RETURN VALUE: None      
		//
		// CALLS TO: None
		//
		// CALLED FROM: menu()
		//
		// METHOD:
		//
		// 1) verify (if the user wants to delete his/her account) before deactivating the account
		// 1.a) if the user wants to deactivate the account, input of the acount's password is needed before deleting and exiting the program
		// 1.b) if the user does not want to deactivate the account, the user will be directed to the menu
		void deleteAccount() { //function that deletes all user entries and profile data
			FILE *fp, *f2;
			int finalize;
		
			printf("\nAre you sure you want to deactivate your account? (1 for YES, and 2 for NO): ");
		    scanf("%i", &finalize); 
			
			if (finalize == 1) {
				int count = 0;
				char password[10], line[20];
				
				//Opens the text file containing user profile details
				FILE *reset = fopen("initialAccount.txt", "r");
				while (fgets(line, sizeof line, reset) != NULL) {
					count++;
					//Reads the pre-saved password and asks the user 
					//to retype it to confirm their profile deletion
					if (count == 2) {  
						printf("Enter your password to confirm: ");
						for (int i = 0; i < 10; i++) {
							password[i] = getch();
							printf("*"); //Output encryption when retyping the password
						}
						break;
					}
				}
				
				//Removes the random symbols being appended to the password after retyping
				while(strlen(password) > 10) password[strlen(password)-1] = '\0';
				while(strlen(line) > 10) line[strlen(line)-1] = '\0';
				
				//If passwords match
				if(strcmp(password, line) == 0) {
					fp = fopen("initialAccount.txt", "w");
					fclose(fp);
					f2 = fopen("entries.txt", "w");
					fclose(f2);
					printf("\nAccount deleted successfully.");
					getch(); //Account is deleted and the program ends
				}
				
				//If passwords do not match
				else {
					printf("%s--%s", line, password);
					printf("\nPasswords do not match.");
					getch();
					system("cls");
					menu(); //User is returned to the menu
				}
				
				exit(0);
			} 
			
			//User is returned to the menu if they decide not
			//to delete their account
			else {
				system("cls");
				menu();
			}
		}
	
		// FUNCTION NAME: intro
		// CREDITS: A. Crisostomo and D. Landicho
		//           
		// PARAMETERS: None
		//
		// RETURN VALUE: None      
		//
		// CALLS TO: None
		//
		// CALLED FROM: menu()
		//
		// METHOD:
		//
		// 1) initialAccount.txt file is read
		// 1.a) if file is empty, the user is asked for his/her name (or username), age, and password for the account
		// 1.b) if file is not empty, program greets user with recorded name (or username) then menu is displayed
		void intro() {
			//Variable declarations
			char username[50];
			char password[10], confirmationPW[10];
			FILE *fp, *fp2;
			long size;
			
			//structure variable to access structure entryType
			entryType et;
			
			fp = fopen("initialAccount.txt", "r");
			fseek(fp, 0, SEEK_END);	//function that checks for an already existing account
			size = ftell(fp);
			fclose(fp);
			
			//If no account is detected, user is asked to create one
			if (size == 0) {
				do {
					printf("CREATE YOUR ACCOUNT\n");
					printf("Enter your name (or username): ");
					scanf(" %[^\n]s", username);
					
					printf("Enter your age: ");
					scanf("%i", &et.age);
			
					printf("Enter password (SHOULD STRICTLY be ten (10) characters long to ensure security): ");
					for (int i = 0; i < 10; i++) {
						password[i] = getch();
						printf("*"); //Encrypts each keypress to show only asterisks for password input
					}
			
					printf("\nRe-enter password: ");
					for (int j = 0; j < 10; j++) {
						confirmationPW[j] = getch();
						printf("*"); //Password confirmation feature
					}
					
					//The following two lines remove the last character of the string value for the password confirmation
					//variable as it seems to save an extra random value after having the user retype their
					//password for confirmation
					while(strlen(password) > 10) password[strlen(password)-1] = '\0';
					while(strlen(confirmationPW) > 10) confirmationPW[strlen(confirmationPW)-1] = '\0';
					
					if (strcmp(password, confirmationPW) == 0) {
						printf("\nAccount created successfully.\nPress Enter to Continue. ");
						getch();
						system("cls");
						
						//Saves account details to the text file that will be checked for existing accounts
						//at the start of the program to prevent overwriting of data
						fp = fopen("initialAccount.txt", "w");
						fprintf(fp, "%s", username);
						fprintf(fp, "\n%s", password);
						fprintf(fp, "\n%i", et.age);
						fclose (fp);
						
						fp = fopen("initialAccount.txt", "r"); //Reopens the file to obtain the username
						char lines[100];
						while (fgets(lines, sizeof lines, fp) != NULL) {
								printf("Hello, %s", lines); //Username is utilized in this greeting
								printf("WELCOME TO YOUR VERY OWN MOOD CALENDAR\n");
								fclose(fp);
						}
					}
						
					else {
						//Scenario for when the password does not match with its confirmation
						printf("\nPasswords do not match.");
						getch();
						system("cls");
					}
				
				//This do-while statement continues until the user creates a valid account
				} while (strcmp(password, confirmationPW)!=0);
			}
			
			
			//If an existing account is detected
			else {
				fp = fopen("initialAccount.txt", "r");
				char line[100];
				
				while (fgets(line, sizeof line, fp) != NULL) {
						printf("Welcome back, %s", line); //reads the first line of the text file to obtain the username then closes the file right after
						fclose(fp);
				}
			}	
	}
};

int main() {
	menuClass m;
	m.intro();
	menu();
	exit(0);
}

// FUNCTION NAME: menu
// CREDITS: A. Crisostomo and D. Landicho
//           
// PARAMETERS: None
//
// RETURN VALUE: None          
//
// CALLS TO: None
//
// CALLED FROM: main()
//
// METHOD:
//
// This function displays the menu and asks for user input
void menu() {
	int mainChoice, subChoice1, subChoice2, subChoice3;
	
	//declaration of objects from classes
	entryClass ent;
	menuClass m;
//	classStats sm;
	
	do {
		//Displays the main menu layout of the program once logged in
		printf("What would you like to do?\n");
		printf("1.) Add entries\n");
		printf("2.) View statistics\n");
		printf("3.) Add/delete activities and moods\n");
		printf("4.) View entries\n");
		printf("5.) Deactivate account\n");
		printf("6.) Exit\n");
		printf("Choice: ");
		scanf("%i", &mainChoice);
		
		//Switch-case for main menu options
		switch(mainChoice) {
			case 1: { //Adding and Deleting entries
				
				system("cls");
				ent.addEntry();
				break;
			};
		
			case 2: { //View user statistics based on entries
				ent.displayStats();
				break;
			}
			
			case 3: { //Adding and Deleting Moods
				int choice;
				activityClass act;
				moodClass mood;
			
				//Shows different options regarding activities and moods
				do {
					system("cls");
					printf("ADD/DELETE ACTIVITIES AND MOODS");
					printf("\n[0] RETURN TO MENU");
					printf("\n[1] Add Activity/Mood");
					printf("\n[2] Delete Activity/Mood");
					printf("\nChoice: ");
					scanf("%i", &subChoice2);
				
				} while (subChoice2 < 0 || subChoice2 > 2);
				
				if (subChoice2 == 1) {
					
					//Allows the user to add moods and activities
					do{
						system("cls");
						printf("ADD A MOOD OR ACTIVITY");
						printf("\n[0] RETURN TO MENU");
						printf("\n[1] Add an activity\n[2] Add a mood\n");
						printf("Choice: ");
						scanf("%i", &choice);
						
						if (choice == 0) {
							system("cls");	
							menu();
							break;
						}
						
					} while(choice < 1 || choice > 2);
					
					//Directs the user to the activity class to add custom activities
					if (choice == 1) act.addActivity();
					
					//Directs the user to the mood class to add custom moods
					else if (choice == 2) mood.addMood();
					
					break;	
				}
				
				else if (subChoice2 == 2) {
					
					//Allows the user to permanently delete specific moods and activities
					int choice;
					activityClass act;
					moodClass mood;
					do {
						system("cls");
						printf("DELETE A MOOD OR ACTIVITY");
						printf("\n[0] RETURN TO MENU");
						printf("\n[1] Delete an activity\n[2] Delete a mood\n");
						printf("Choice: ");
						scanf("%i", &choice);
						
						if (choice == 0) {
							system("cls");	
							break;
							menu();
					}
					
				} while(choice < 1 || choice > 2);
				
				//Directs the user to the activity class to delete existing activities
				if (choice == 1) act.deleteActivity();
				
				//Directs the user to the mood class to delete existing moods
				else if (choice == 2) mood.deleteMood();
					break;
				}
				
				else if (subChoice2 == 0) {
					system("cls");
					menu();
					break;
				}
			}
			
			case 4: {
				system("cls");
				printf("VIEWING ENTRIES");
				m.printHistory(); 
				break;
			}
			
			case 5: {
				system("cls");
				printf("DEACTIVATE ACCOUNT");
				m.deleteAccount();
				break;
			}
		}
		if(mainChoice < 1 || mainChoice > 6) system("cls");
	} while (mainChoice != 6);
	 //This do-while loop prevents the program from abruptly closing and gives the 
	 //user complete freedom to explore the application and exit anytime they want
	 
	 exit(0);
}

// FUNCTION NAME: displayMsg
// CREDITS: A. Crisostomo and D. Landicho
//           
// PARAMETERS: None
//
// RETURN VALUE: None          
//
// CALLS TO: addEntry() (of class entryClass)
//
// CALLED FROM: menu()
//
// METHOD:
//
// implementation of function displayMsg() in class classMsgs that displays 
// feedback appropriate for any entry
void classMsgs::displayMsg() {
	printf("\nThank you for today's entry! We hope you know that we are always listening.");
}

// FUNCTION NAME: displayMsg
// CREDITS: A. Crisostomo and D. Landicho
//           
// PARAMETERS: None
//
// RETURN VALUE: None          
//
// CALLS TO: None
//
// CALLED FROM: addEntry() (of class entryClass)
//
// METHOD:
//
// implementation of function displayQuote() that display a random message from the array of strings
void subclassMsgs::displayQuote() {
	srand((unsigned) time(&t)); // initializes random number generator
	random = rand()%15; // any random number from 0-14
	printf("%s", randomMsgs[random]);
}
