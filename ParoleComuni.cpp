#include <iostream>
#include <fstream>
#include <cstring>

#define MAX_LENGTH 100
#define DIM_MAX 32

void comuni(std::ifstream &f1, std::ifstream &f2, const std::string &nomefile, const char &delimitatore1 = '\n', const char &delimitatore2 = ' ') {
	char c1, c2;
	char *parola_file1 = new char[MAX_LENGTH];
    char *parola_file2 = new char[MAX_LENGTH];
    int contatore1 = 0, contatore2 = 0;
	int line = 0;
	
	while(!f1.eof()){
		
		while(!f1.eof()){
			c1 = f1.get();
			
			if(c1 != delimitatore1 && c1 != delimitatore2){ // delimitatore1 solitamente sara' '\n' e delimitatore2 sara' ' '  
				parola_file1[contatore1] = c1;
				contatore1++;
			}
			
			else break;
		}

		if (delimitatore2 == NULL) line++;
		
		parola_file1[contatore1] = '\0';
		contatore1 = 0;

		while(!f2.eof()){
			
			while(!f2.eof()){
				c2 = f2.get();

				if(c2 != delimitatore1 && c2 != delimitatore2){
					parola_file2[contatore2] = c2;
					contatore2++;
				}
				else break;
			}
			
			parola_file2[contatore2] = '\0';
			contatore2 = 0;
			
			if(strcmp(parola_file1, parola_file2) == 0){
				if (delimitatore2 == NULL) std::cout<< "line: "<< line<< " -> ";
				std::cout<<parola_file1<<std::endl;
				break;
			}

		}
		

		//va chiuso e riaperto a fine di ogni ciclo in questo modo la lettura del file ricomincia da capo e non continua
		f2.close();
		f2.open(nomefile);				
	}

}

void non_comuni(std::ifstream &f1, std::ifstream &f2, const std::string &nomefile, const char &delimitatore1 = '\n', const char &delimitatore2 = ' ') {
	char c1, c2;
	char *parola_file1 = new char[MAX_LENGTH];
    char *parola_file2 = new char[MAX_LENGTH];
    int contatore1 = 0, contatore2 = 0;
	bool trovato = false;
	int line = 0;

	while(!f1.eof()){
		
		while(!f1.eof()){
			c1 = f1.get();
			
			if(c1 != delimitatore1 && c1 != delimitatore2){
				parola_file1[contatore1] = c1;
				contatore1++;
			}
			
			else break;
		}
		
		if (delimitatore2 == NULL) line++;

		parola_file1[contatore1] = '\0';
		contatore1 = 0;
		trovato = false;
	
		while(!f2.eof()){
			
			while(!f2.eof()){
				c2 = f2.get();
	
				if(c2 != delimitatore1 && c2 != delimitatore2){
					parola_file2[contatore2] = c2;
					contatore2++;
				}
				else break;
			}
			
			parola_file2[contatore2] = '\0';
			contatore2 = 0;
			
			if(strcmp(parola_file1, parola_file2) == 0){
				trovato = true;
				break;
			}
	
		}
		
		if(trovato == false){
			if (delimitatore2 == NULL) std::cout<< "line: "<< line<< " -> ";
			std::cout<<parola_file1<<std::endl;
		}
		
		//va chiuso e riaperto a fine di ogni ciclo in questo modo la lettura del file ricomincia da capo e non continua
		f2.close();
		f2.open(nomefile);				
	}
}

int main(void){

    std::ifstream f1;
    std::ifstream f2;

    char *nomefile1 = new char[DIM_MAX];
    char *nomefile2 = new char[DIM_MAX];
	
	std::cout<<"\tCreated By Dennis Turco\n\n";
	
//-------- APERTURA FILE INPUT ---------
	
    do{
        std::cout<<"Inserire Nome Primo File: ";
        std::cin.getline(nomefile1, DIM_MAX);
        f1.open(nomefile1);
        if(f1.fail()){
            strcat(nomefile1, ".txt");
            f1.open(nomefile1);
        }
    } while(f1.fail());

    do{
        std::cout<<"Inserire Nome Secondo File: ";
        std::cin.getline(nomefile2, DIM_MAX);
        f2.open(nomefile2);
        if(f2.fail()){
            strcat(nomefile2, ".txt");
            f2.open(nomefile2);
        }
    } while(f2.fail());

    system("cls");
	

//-------- OPERAZIONI SU FILE ---------
    // int scelta;
	// std::cout<<"Sceglere l'operazione: \n\t1)  Parole Comuni;\n\t2)  Frasi Comuni;\n\t3)  Parole Non Comuni;\n\t4)  Frasi Non Comuni.\nOperazione: ";
	// std::cin>>scelta;
	// system("cls");
	
	
//-------- SCELTA SWITCH ---------
	// switch(scelta){
	// 	case 1:
	// 		std::cout<<"Parole Comuni: "<<std::endl;
	// 		comuni(f1, f2, nomefile2, '\n', ' ');
	// 		break;
		
	// 	case 2:
	// 		std::cout<<"Frasi Comuni: "<<std::endl;
	// 		comuni(f1, f2, nomefile2, '\n', NULL); // inserisco NULL perche' voglio usare un solo delimitatore ('\n')
	// 		break;
		
	// 	case 3:
	// 		std::cout<<"Parole Non Comuni: "<<std::endl;
	// 		non_comuni(f1, f2, nomefile2, '\n', ' ');
	// 		break;
		
	// 	case 4:
	// 		std::cout<<"Frasi Non Comuni: "<<std::endl;
	// 		non_comuni(f1, f2, nomefile2, '\n', NULL); // inserisco NULL perche' voglio usare un solo delimitatore ('\n')
	// 		break;
	// }

	std::cout<<"Frasi Comuni: "<<std::endl;
	comuni(f1, f2, nomefile2, '\n', NULL); // inserisco NULL perche' voglio usare un solo delimitatore ('\n')
	f1.close();
    f2.close();
	f1.open(nomefile1);
	f2.open(nomefile2);
	

	std::cout<<"\n--------------------------------------------------------------------------------------\n\n";

	std::cout<<"Frasi Non Comuni: "<<std::endl;
	non_comuni(f1, f2, nomefile2, '\n', NULL); // inserisco NULL perche' voglio usare un solo delimitatore ('\n')


//-------- CHIUSURA FILE ---------
    f1.close();
    f2.close();
    system("Pause");
    return 0;
}