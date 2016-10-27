I set myself the following additional goal (devised by me):

I decided to make a program that would read in peoples' contact details from a CSV file, format the information in a way that is more useful to myself, and then output this data so that I can import it into my contacts library.

The nature of this task stems from my involvement in the Cambridge Theatre scene. Often there is a spreadsheet with all of the cast & crew's names and contact details however different shows use different columns in different orders. I use the 'Contacts' app on MAC OSX to manage all my contact information and sync across to my phone so I wanted to automate the process of reading in from a spreadsheet, formatting the data columns into the correct order, and then outputting the data ready for import into the 'Contacts' app. Since I am already reasonably familiar with programming and C++ I set myself the additional challenge that I want to make my solution using object-orientated concepts, in order to allow maximum code reuse by others.

My solution contains several files:
*  makefile = so I can build the program simply by issuing the command 'make' on the command line
*  FormatMyDetails.cpp = the main body of the program
*  functions.cpp = contains code for some useful functions used across different classes
*  exceptions.cpp = contains code to make pretty exception messages if the user is silly
*  textStrings.cpp = contains in string variables text which gets written out to the command line so that language modifications and translations are easy
*  contactImporter.cpp = contains the code used to read from a CSV file with contact info in
*  contactExporter.cpp = contains the code use to write to a CSV file the post-processed contact info