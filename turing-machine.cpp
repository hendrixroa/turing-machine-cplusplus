#include <iostream> 
#include <fstream>
#include <string>
using namespace std;

  string A_Unario(int num){
	string buf="";
	int i;
		
		for(i=0;i<num;i++){
		buf = buf + '1';
		}
		
	 return buf;
	}

  string M_mas_cinco(string MT){
  
  int i=0,cont=0;
  
  while(true){   
	   if(cont==5){
		   break;
	   }
	  if(MT[i]=='1'){
	  i++;
	  }else if(MT[i]=='\0'){
		  MT.append("1");
		  cont++;
	  }
  }  
  
return MT;
  }

  string M_por_2(string MT){
	  int i,tam = MT.length();
	  bool marque = false;
	  
	  for(i=0;i<tam;i++){
		  
		  if(MT[i]=='1' && marque == false){
			  int j=i;
			  while(MT[j]=='1'){
				  j++;
			  }
			  
			  MT[j-1] = 'F';
			  marque =true;
		  
		  }
		  if(MT[i]=='1' && marque == true){
			  MT.append("1");
		  }
		  
		  if(MT[i] =='F'){
		  MT[i] = '1';
		  MT.append("1");
		  break;
		  }
		  
	  }
	  return MT;
  }

	string M_mod_2(string MT){
	 
	 int i=0;
	 bool marque=false,vuelta = false;
	 
	 while(true){
		 
		 if(MT[i]=='1' && marque == false){
			 i++;
			 marque = true;
			 
			 if(MT[i+1]=='1'){
			 i++;
			 }
			  
		 } else if(MT[i]=='1' && marque == true){
			 while(MT[i]=='1'){
				i--;
			}
		i++;
		vuelta = true;
		 }
		  else if(vuelta == false){
			 i++;
			 vuelta = true;
		    }
		    if(MT[i]=='1' && vuelta == true){
				MT.erase(MT.begin());
			
				if(MT[i]=='1'){
					MT.erase(MT.begin());	
				}
			}
			if(MT[i]=='1'){
			i++;
			}
			
			if(MT[i]=='\0'){
			  while(MT[i]=='1'){
				  MT[i]='1';
				  i--;
			  }
			  break;
			}	 
	 }
	 
	 if(MT == "1"){
		 return MT;
	 }else{
     return "b";
	}
}

int main(){

fstream file,fileout;
	int N,i,numbuf;
	string M1,M2,M3,res1,res2,res3;
	
		file.open("tarea5.in",ios::in);
		fileout.open("Hendrix_Roa.out",ios::out);
			if(!file.is_open()){
				cout <<"El archivo no se pudo abrir"<<endl;
			}else{
					while(!file.eof()){
						file >> N;
						
						if(file.eof()){
							break;
						}
							for(i=0;i<N;i++){
								
								file >> numbuf;
						        M1 = A_Unario(numbuf);
						        M2 = A_Unario(numbuf);
						        M3 = A_Unario(numbuf);
						        res1 = M_mas_cinco(M1);	
								res2 = M_por_2(M2);
							    res3 = M_mod_2(M3);
								fileout <<"Caso "<<i+1<<":"<<endl;
								fileout <<res1<<endl;
								fileout <<res2<<endl;
							    fileout <<res3<<endl;	
							}
					}
					file.close();
					fileout.close();
			}
return 0;
}
