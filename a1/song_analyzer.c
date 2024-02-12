/** @file song_analyzer.c
 *  @brief A pipes & filters program that uses conditionals, loops, and string processing tools in C to process song
 *  data and printing it in a different format.
 *  @author Felipe R.
 *  @author Hausi M.
 *  @author Angadh S.
 *  @author Juan G.
 *  @author Reed Bryan.
 *
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * @brief The maximum line length.
 *
 */
#define MAX_LINE_LEN 132

/**
 * Function: main
 * --------------
 * @brief The main function and entry point of the program.
 *
 * @param argc The number of arguments passed to the program.
 * @param argv The list of arguments passed to the program.
 * @return int 0: No errors; 1: Errors produced.
 *
 */


void question1(FILE *song_list, FILE *output) {

    // insert first line
    fprintf(output, "Artist(s),Song\n");

    // Read lines from the file
    char line[MAX_LINE_LEN];
    while (fgets(line, MAX_LINE_LEN, song_list)) {
              
        // Remove newline character at the end of the line, if present
        line[strcspn(line, "\r\n")] = 0;

        // Split the line into tokens based on the comma delimiter
        char *token = strtok(line, ",\n");
        char *cur_song_name = token;

        // iterate through tokens on line
        while (token != NULL) {

            // Check token for artist name
            if (strcmp(token, "Rae Spoon") == 0){
                fprintf(output, "%s,%s\n", token, cur_song_name);
            }
            
            token = strtok(NULL, ",");   
        }      
    }
}


void question2(FILE *song_list, FILE *output) {

    // insert first line
    fprintf(output, "Artist(s),Song\n");

    // Read lines from the file
    char line[MAX_LINE_LEN];
    while (fgets(line, MAX_LINE_LEN, song_list)) {
              
        // Remove newline character at the end of the line, if present
        line[strcspn(line, "\r\n")] = 0;

        // Split the line into tokens based on the comma delimiter
        char *token = strtok(line, ",\n");
        char *cur_song_name = token;
        
        // iterate through tokens on line
        while (token != NULL) {
            
            // check token for artist
            if (strcmp(token, "Tate McRae") == 0){                
                fprintf(output, "%s,%s\n", token, cur_song_name);
            }
            token = strtok(NULL, ",");   
        }
    }
}

void question3(FILE *song_list, FILE *output) {

    // insert first line
    fprintf(output, "Artist(s),Song\n");

    // Read lines from the file
    char line[MAX_LINE_LEN];
    while (fgets(line, MAX_LINE_LEN, song_list)) {
              
        // Remove newline character at the end of the line, if present
        line[strcspn(line, "\r\n")] = 0;

        // Split the line into tokens based on the comma delimiter
        char *token = strtok(line, ",\n");
        
        // Set filtering variables
        char *cur_song_name = token;
        bool the_weekend = false;
        
        // iterate through tokens on line
        while (token != NULL) {
            
            // check artist name -> if true set bool
            if (strcmp(token, "The Weeknd") == 0){
                the_weekend = true;
            } // check key name + bool
            if (strcmp(token, "Major") == 0 && the_weekend){
                fprintf(output, "The Weeknd,%s\n", cur_song_name);
            }
            
            token = strtok(NULL, ",");   
        }
    }
}

void question4(FILE *song_list, FILE *output) {

    // insert first line
    fprintf(output, "Artist(s),Song\n");

    // Read lines from the file
    char line[MAX_LINE_LEN];
    while (fgets(line, MAX_LINE_LEN, song_list)) {
              
        // Remove newline character at the end of the line, if present
        line[strcspn(line, "\r\n")] = 0;

        // Split the line into tokens based on the comma delimiter
        char *token = strtok(line, ",\n");
        
        // Set filtering variables + song info counter
        char *cur_song_name = token;
        char *cur_artist_name;
        bool in_playlists = false;
        int count = 1;

        // iterate through tokens on line
        while (token != NULL) {
            
            // Get artist name
            if (count == 2) cur_artist_name = token;
            // Check for over 5000 playlists
            if (count == 5 && atoi(token) > 5000){
                in_playlists = true;
            }
            // Check for A or D keys
            if (count == 7 && in_playlists && (strcmp(token, "A") == 0 || strcmp(token, "D") == 0) ){
                fprintf(output, "%s,%s\n", cur_artist_name, cur_song_name);
            }
            
            token = strtok(NULL, ",");   
            count++;
        }
      
    }
}

void question5(FILE *song_list, FILE *output) {

    // insert first line
    fprintf(output, "Artist(s),Song\n");

    char line[MAX_LINE_LEN];

    // Read lines from the file
    while (fgets(line, MAX_LINE_LEN, song_list)) {
              
        // Remove newline character at the end of the line
        line[strcspn(line, "\r\n")] = 0;

        // Split the line into tokens based on the comma delimiter
        char *token = strtok(line, ",\n");
        
        // Set filtering variables + song info counter
        char *cur_song_name = token;
        char *cur_artist_name;
        bool in_years = false;
        int count = 1;

        // iterate through tokens on line
        while (token != NULL) {
            
            // Get artist name
            if (count == 2) cur_artist_name = token;
            // Check for over 5000 playlists
            if (count == 4 && (atoi(token) == 2021 || atoi(token) == 2022)){
                in_years = true;
            }

            token = strtok(NULL, ",");   
            count++;
        }
        
        // Check for the goat Drake
        if (strstr(cur_artist_name, "Drake") != NULL){
            fprintf(output, "%s,%s\n", cur_artist_name, cur_song_name);
        }      
    }
}

int main(int argc, char *argv[])
{
    
    // parse inputs
    char question_num = argv[1][11];
    FILE *song_list = fopen(argv[2] + 7, "r");
    
    // create output file
    FILE *output = fopen("output.csv", "w");

    
    if (question_num == '1'){
        question1(song_list, output);
    }
    if (question_num == '2'){        
        question2(song_list, output);
    }
    if (question_num == '3'){
        question3(song_list, output);
    }
    if (question_num == '4'){
        question4(song_list, output);
    }
    if (question_num == '5'){
        question5(song_list, output);
    }
    
    // Close the files
    fclose(song_list);
    fclose(output);

    exit(0);
}