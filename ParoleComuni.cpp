#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;


int main(){

    ifstream f1;
    ifstream f2;

    char nomefile1[32];
    char nomefile2[32];
	
	cout<<"\tCreated By Dennis Turco\n\n";
	
//-------- APERTURA FILE INPUT ---------
	
    do{
        cout<<"Inserire Nome Primo File: ";
        cin.getline(nomefile1, 32);
        f1.open(nomefile1);
        if(f1.fail()){
            strcat(nomefile1, ".txt");
            f1.open(nomefile1);
        }
    } while(f1.fail());

    do{
        cout<<"Inserire Nome Secondo File: ";
        cin.getline(nomefile2, 32);
        f2.open(nomefile2);
        if(f2.fail()){
            strcat(nomefile2, ".txt");
            f2.open(nomefile2);
        }
    } while(f2.fail());

    system("cls");
	

//-------- OPERAZIONI SU FILE ---------
    int scelta;
    char parola_file1[100];
    char parola_file2[100];
    int contatore1 = 0, contatore2 = 0;
    char c1, c2;
    bool trovato = false;
	cout<<"Sceglere l'operazione: \n\t1)  Parole Comuni;\n\t2)  Frasi Comuni;\n\t3)  Parole Non Comuni;\n\t4)  Frasi Non Comuni.\nOperazione: ";
	cin>>scelta;
	system("cls");
	
	
//-------- SCELTA SWITCH ---------
	switch(scelta){
		case 1:
			cout<<"Parole Comuni: "<<endl;
			while(true){
				if(f1.eof()==true) break;
			    
			    while(true){
			    	c1 = f1.get();
			    	if(f1.eof()==true) break;
			    	
			    	if(c1 != ' ' && c1 != '\n'){
			    		parola_file1[contatore1] = c1;
			    		contatore1++;
					}
					
					else break;
				}
			    
			    parola_file1[contatore1] = '\0';
			    contatore1 = 0;
			
				while(true){
			    	if(f2.eof()==true) break;
			    	
					while(true){
						c2 = f2.get();
						if(f2.eof()==true) break;
			
						if(c2 != ' ' && c2 != '\n'){
							parola_file2[contatore2] = c2;
							contatore2++;
						}
						else break;
					}
					
					parola_file2[contatore2] = '\0';
					contatore2 = 0;
			    	
					if(strcmp(parola_file1, parola_file2) == 0){
						cout<<parola_file1<<endl;
						break;
					}
			
				}
				
			
				//va chiuso e riaperto a fine di ogni ciclo in questo modo la lettura del file ricomincia da capo e non continua
				f2.close();
				f2.open(nomefile2);				
			}
			
			break;
		
		case 2:
			cout<<"Frasi Comuni: "<<endl;
			while(true){
				if(f1.eof()==true) break;
			    
			    while(true){
			    	c1 = f1.get();
			    	if(f1.eof()==true) break;
			    	
			    	if(c1 == ' ') continue;
			    	else if(c1 != '\n'){
			    		parola_file1[contatore1] = c1;
			    		contatore1++;
					}
					
					else break;
				}
			    
			    parola_file1[contatore1] = '\0';
			    contatore1 = 0;
			    
				while(true){
			    	if(f2.eof()==true) break;
			    	
					while(true){
						c2 = f2.get();
						if(f2.eof()==true) break;
						
						if(c2 == ' ') continue;	
						else if(c2 != '\n'){
							parola_file2[contatore2] = c2;
							contatore2++;
						}
						else break;
					}
					
					parola_file2[contatore2] = '\0';
					contatore2 = 0;
			    	
					if(strcmp(parola_file1, parola_file2) == 0){
						cout<<parola_file1<<endl;
						break;
					}
				}
	
				//va chiuso e riaperto a fine di ogni ciclo in questo modo la lettura del file ricomincia da capo e non continua
				f2.close();
				f2.open(nomefile2);	
			}
			
			break;
		
		case 3:
			cout<<"Parole Non Comuni: "<<endl;
			while(true){
				if(f1.eof()==true) break;
			    
			    while(true){
			    	c1 = f1.get();
			    	if(f1.eof()==true) break;
			    	
			    	if(c1 != ' ' && c1 != '\n'){
			    		parola_file1[contatore1] = c1;
			    		contatore1++;
					}
					
					else break;
				}
			    
			    parola_file1[contatore1] = '\0';
			    contatore1 = 0;
			    trovato = false;
			
				while(true){
			    	if(f2.eof()==true) break;
			    	
					while(true){
						c2 = f2.get();
						if(f2.eof()==true) break;
			
						if(c2 != ' ' && c2 != '\n'){
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
					cout<<parola_file1<<endl;
				}
				
				//va chiuso e riaperto a fine di ogni ciclo in questo modo la lettura del file ricomincia da capo e non continua
				f2.close();
				f2.open(nomefile2);				
			}
			
			break;
		
		case 4:
			cout<<"Frasi Non Comuni: "<<endl;
			while(true){
				if(f1.eof()==true) break;
			    
			    while(true){
			    	c1 = f1.get();
			    	if(f1.eof()==true) break;
			    	
			    	if(c1 == ' ') continue;
			    	else if(c1 != '\n'){
			    		parola_file1[contatore1] = c1;
			    		contatore1++;
					}
					
					else break;
				}
			    
			    parola_file1[contatore1] = '\0';
			    contatore1 = 0;
			    trovato = false;
			    
				while(true){
			    	if(f2.eof()==true) break;
			    	
					while(true){
						c2 = f2.get();
						if(f2.eof()==true) break;
						
						if(c2 == ' ') continue;	
						else if(c2 != '\n'){
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
					cout<<parola_file1<<endl;
				}
	
				//va chiuso e riaperto a fine di ogni ciclo in questo modo la lettura del file ricomincia da capo e non continua
				f2.close();
				f2.open(nomefile2);	
			}
			
			break;
	}


//-------- CHIUSURA FILE ---------
    f1.close();
    f2.close();
    system("Pause");
    return 0;
}
