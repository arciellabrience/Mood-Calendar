# Mood-Calendar
Computer Fundamentals and Programming 2 course using C++ language in DevC++ software.

## Integrated Concepts
<ul>
  <li>1D and 2D Numerical Arrays</li>
  <li>Strings and String Processing</li>
  <li>Structures</li>
  <li>Aggregation of Data</li>
  <li>File I/O</li>
  <li>Object-Oriented Programming (OOP)</li>
  <li>Modular Programming with Objects (and Classes)</li>
  <li>Inheritance</li>
  </ul>

## Walkthrough

### I. Create Account

The program starts off with no user info saved in the “initialAccount.txt” file. The user is then asked to create an account by entering their name or a specific username that the program will recognize the account owner as, the user’s age, and a specific password that is exclusive to that account. The password is encrypted as the user types it as to preserve privacy and asks the user to retype the password for confirmation purposes. Once verified, the account is created and saved into the “initialAccount.txt” file and the program directs the user to the main menu of the program.

### II. Main Menu

The program’s main menu consists of 6 possible operations (III., IV., V., VI., VII., and Exit) for the program to perform. 
Each of these operations house the program’s main features. It saves the details necessary 
details in a way that they can still be accessed even after the program is closed and started
up again. The program is created so that any invalid integer input in all parts of the program 
will not cause the application to crash or experience or end abruptly.

### III. Add Entries

The first option in the main menu allows the user to add and document entries in their 
digital journal to be saved in its corresponding directory. It offers a list of preset moods 
and activities that allows the user to pick between to provide a sense of categorization in 
their journalling as they jot down important details about their day.

The user then inputs a message to allow them to describe their day, note a memorable 
experience, or just let out bellyache. This entry is then saved onto the “entries.txt” file 
along with the date and time it was created as well as the user’s selected mood and activity 
for the day. The program shows random messages depending on the user’s mood; creating 
depth in its interactivity with the user as a program. The formatted entries are then 
dynamically saved to the aforementioned text file to prevent it from being deleted or 
overwritten once the program closes or restarts as well as to easily access all user entries 
for other key features that the program contains.

### IV. View Statistics
This feature of the program allows the user to view detailed statistics of all their entries 
saved so far to view which moods they have felt most frequently as well as to determine 
which activities they have been doing the most. It shows the percentages of moods that 
consist of the original preset moods and activities as well as how many entries were made 
using those moods and activities by the user. This features provides a medium for the user 
to look back on their emotional progress throughout the span of their usage of the program.

### V. Add/Delete Activities and Moods
This key feature provides the entire program with a level of customization for the user as 
to make the program more “personal” in a way by allowing them to add their own custom 
moods and activities that they may choose when creating new entries. The program gives 
the user the choice to add new moods or activities as well as to delete already existing ones. 
They are allowed to name these additions to whatever they please, and the only limitations 
are that of their imagination due to the fact that these newly added activities and moods are 
dynamically saved to “moods.txt” and “activities.txt” which stores their respective values 
to prevent them from being deleted once the program closes.

These added moods and activities may also be deleted upon the user’s liking. This method 
is done by asking the user to input the name of the mood or activity that they want to delete 
from the database, and the program dynamically creates a new text file; copying all the 
moods or activities onto it line by line except the one chosen by the user to delete. This 
results in a new file that includes all the same assets but leaving out the specific user input. 
The original text file is then deleted and the newer file with one less asset is renamed to 
match that of the original text file, as to make it seem like the user has actually deleted their 
chosen mood or activity, when in actuality they have overwritten the original database with 
a new one that does not include the mood or activity they intended to delete.

### VI. View Entries
This feature accesses the “entries.txt” file and lists every entry that the user has logged into 
their digital journal while also providing a list of the number of entries made per month.

### VII. Deactivate Account
The final feature of the mood calendar, which gives the user the option to delete all of their 
data from the application along with their user entries and account information. The 
program asks for password confirmation before executing this operation as to prevent any 
unwanted deletions. After verification, the contents of the “initialAccount.txt” and 
“entries.txt” text files are deleted and the program ends. Once started up again, the program 
will ask the user to create a new account as there will no longer be any recognizable saved 
data in its directories.

### Authors

#### Arciella Brience C. Crisostomo [arciella_brience_crisostomo@dlsu.edu.ph]

#### Dustin Kyle D. Landicho [dustin_kyle_landicho@dlsu.edu.ph]
