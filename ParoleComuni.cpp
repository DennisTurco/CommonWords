/*
	Author	-> Dennis Turco 2022
	Email 	-> dennisturco@gmail.com
	WebSite	-> https://dennisturco.github.io/
	GitHub	-> https://github.com/DennisTurco
*/

#include <iostream>
#include <fstream>
#include <cstring>

#define MAX_LENGTH 1000
#define DIM_MAX 32


void open_file(std::ifstream &file, char *file_name, const std::string &message = ""){
	do{
        std::cout<<message;
        std::cin.getline(file_name, DIM_MAX);
        file.open(file_name);
        if(file.fail()){
            strcat(file_name, ".txt");
            file.open(file_name);
        }
    } while(file.fail());

}

void common(std::ifstream &f1, std::ifstream &f2, const std::string &file_name, const char &delimitator1 = '\n', const char &delimitator2 = ' ') {
	char c1, c2;
	char *word_file1 = new char[MAX_LENGTH];
    char *word_file2 = new char[MAX_LENGTH];
    int count1 = 0, count2 = 0;
	int line = 0;
	
	while(!f1.eof()){
		
		while(!f1.eof()){
			c1 = f1.get();
			
			if(c1 != delimitator1 && c1 != delimitator2){ // delimitator1 will be '\n' and delimitator2 will be ' '  for default
				word_file1[count1] = c1;
				count1++;
			}
			
			else break;
		}

		if (delimitator2 == NULL) line++;
		
		word_file1[count1] = '\0';
		count1 = 0;

		while(!f2.eof()){
			
			while(!f2.eof()){
				c2 = f2.get();

				if(c2 != delimitator1 && c2 != delimitator2){ // delimitator1 will be '\n' and delimitator2 will be ' '  for default
					word_file2[count2] = c2;
					count2++;
				}
				else break;
			}
			
			word_file2[count2] = '\0';
			count2 = 0;
			
			if(strcmp(word_file1, word_file2) == 0){
				if (delimitator2 == NULL) std::cout<< "line: "<< line<< " -> ";
				std::cout<<word_file1<<std::endl;
				break;
			}

		}
		
		f2.close();
		f2.open(file_name);				
	}

}

void not_common(std::ifstream &f1, std::ifstream &f2, const std::string &file_name, const char &delimitator1 = '\n', const char &delimitator2 = ' ') {
	char c1, c2;
	char *word_file1 = new char[MAX_LENGTH];
    char *word_file2 = new char[MAX_LENGTH];
    int count1 = 0, count2 = 0;
	bool trovato = false;
	int line = 0;

	while(!f1.eof()){
		
		while(!f1.eof()){
			c1 = f1.get();
			
			if(c1 != delimitator1 && c1 != delimitator2){
				word_file1[count1] = c1;
				count1++;
			}
			
			else break;
		}
		
		if (delimitator2 == NULL) line++;

		word_file1[count1] = '\0';
		count1 = 0;
		trovato = false;
	
		while(!f2.eof()){
			
			while(!f2.eof()){
				c2 = f2.get();
	
				if(c2 != delimitator1 && c2 != delimitator2){
					word_file2[count2] = c2;
					count2++;
				}
				else break;
			}
			
			word_file2[count2] = '\0';
			count2 = 0;
			
			if(strcmp(word_file1, word_file2) == 0){
				trovato = true;
				break;
			}
	
		}
		
		if(trovato == false){
			if (delimitator2 == NULL) std::cout<< "line: "<< line<< " -> ";
			std::cout<<word_file1<<std::endl;
		}
		
		f2.close();
		f2.open(file_name);				
	}
}

int main(int argc, char **argv){

    std::ifstream f1;
    std::ifstream f2;

    char *nomefile1 = new char[DIM_MAX];
    char *nomefile2 = new char[DIM_MAX];
	
	std::cout<<"\tCreated By Dennis Turco\n\n";
	
//-------- OPEN INPUT FILES ---------
	open_file(f1, nomefile1, "Enter First File Name: ");
    open_file(f2, nomefile2, "Enter Second File Name: ");

//-------- OPERATIONS ON FILES ---------
	std::cout<<"Common Phrases: "<<std::endl;
	common(f1, f2, nomefile2, '\n', NULL); // i insert NULL because i weant to use only one delimitator ('\n')
	f1.close();
    f2.close();
	
	f1.open(nomefile1);
	f2.open(nomefile2);

	std::cout<<"\n--------------------------------------------------------------------------------------\n\n";

	std::cout<<"Uncommon Phrases: "<<std::endl;
	not_common(f1, f2, nomefile2, '\n', NULL); // i insert NULL because i weant to use only one delimitator ('\n')
	f1.close();
	f2.close();

    system("Pause");
    return 0;
}