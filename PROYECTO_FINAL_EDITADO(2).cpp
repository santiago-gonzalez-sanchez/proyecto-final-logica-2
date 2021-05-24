#include<iostream>
using namespace std;

//_______/
//definimos constantes/
int const filas=4;
int const columnas=5;
int const posibleFila=-1;
int const posibleColumna=-1;
int kconzonapremium = 0;
int kconzonaeconomica = 0;

//_______/

//_________/

//definimos las funciones y procedimientos mencionados más abajo
int puertosAvisitar();
void nombrePuertos(int n, string nombrePuerto);
void limpiarMatriz(bool disponibilidad[filas][columnas],float peso[filas][columnas]);
void llenadoPuertos(string puertoActual, int &sumPrecioPuerto,bool disponibilidad[filas][columnas],string nombre[filas][columnas],string puertoCarga[filas][columnas],string tipoArticulo[filas][columnas],float peso[filas][columnas],int cantidadContenedoresI);

void porcentajeOcupacionTotal(bool disponibilidad[filas][columnas]);
void percioPorPuerto(string puerto, int precio);

//____________________/
//imprimir matrices

void imprimirMatrizTexto1(string nombre[filas][columnas]);
void imprimirMatrizTexto2(string puertoCarga[filas][columnas]);
void imprimirMatrizTexto3(string tipoArticulo[filas][columnas]);
void imprimirMatrizEntero(float peso[filas][columnas]);
void mostrarMatriz(bool disponibilidad[filas][columnas]);
void listadoMarcasZona(string nombre[filas][columnas]);
void buscarMarcas(string nombre[filas][columnas]);

//____________________/

//procedimientos/
//void OrdenamientoBurbuja(int vectorOrdenamiento[],string nombrePuerto[],int n);
void totalContenedorescargados(bool disponibilidad[filas][columnas]);
void contenedoresPorZona(bool disponibilidad[filas][columnas]);
int validarZonaprecios(int i, int j, int filas, int columnas);
string verificarZona(int i, int j, int filas, int columnas);
void ordenamientoBurbuja(string puertoCarga[filas],int contenedoresCargados[filas],int n);
void calcularPromedioPeso(float peso[filas][columnas], bool disponibilidad[filas][columnas]);
void calcularFilaMayorCarga(float peso[filas][columnas]);
void calcularColumnaMenorCarga(float peso[filas][columnas]);
int cantContenedoresSegunClase(string tipoArticulo[filas][columnas]);
float pesoIngresadoPorPuerto(float peso[filas][columnas], string puertoCarga[filas][columnas], string nompuerto);
void empresaContMasPesado(float peso[filas][columnas], string nombre[filas][columnas]);
void empresaContMasliviano(float peso[filas][columnas], string nombre[filas][columnas]);

int main(){
	
	bool disponibilidad[filas][columnas];
	string nombre[filas][columnas];
	string puertoCarga[filas][columnas];
	string tipoArticulo[filas][columnas];
	float peso[filas][columnas];
	string prueba;
	int salir=0;
	float promPesoCarga = 0;
	string nompuerto;
	int cantcont=0;
	
	
	
	int n=puertosAvisitar();	
	
	string nombrePuerto[n];
	int sumPrecioPuerto[n];
	int cantidadContenedoresI[n];
	
	
	
	//int vectorOrdenamiento[n];
	//______________/
	
	//limpiar matrices
	limpiarMatriz(disponibilidad,peso);
	
	//______________/
	
	//llenar  puertos
	for(int i=0;i<n;i++){
		cout<<"Ingrese el nombre del puerto a visitar"<<endl;
		cin>>nombrePuerto[i];
	}
	
	//______________/
	
	//llegar al puerto
	for(int i=0;i<n;i++){
		
		sumPrecioPuerto[i] = 0;
		kconzonaeconomica =0;
		kconzonapremium = 0;
		
		if(i>0){
			cout<<endl;
			cout<<"**** SIGUIENTE PUERTO **** "<<endl;
			cout<<endl;
		}
			
		cout<<"* Bienvenido al puerto: "<<nombrePuerto[i]<<"*"<<endl;
	
		cout<<"Ingrese cantidad de contenedores a llenar"<<endl;
		cin>>cantidadContenedoresI[i];
		
		cout<<endl;
		cout<<"Coordenadas disponibles"<<endl;
		mostrarMatriz(disponibilidad);
		cout<<endl;
		//llenado de la información de cada puerto
		
		llenadoPuertos(nombrePuerto[i],sumPrecioPuerto[i], disponibilidad, nombre, puertoCarga, tipoArticulo, peso, cantidadContenedoresI[i]);
		
		
		cout<<endl;
		cout<<"Matriz nombres"<<endl;
		imprimirMatrizTexto1(nombre);
		cout<<endl;
		cout<<"________"<<endl;
		cout<<"Matriz puertos "<<endl;
		imprimirMatrizTexto2(puertoCarga);
		cout<<endl;
		cout<<"________"<<endl;
		cout<<"Matriz Tipo Articulo "<<endl;
		imprimirMatrizTexto3(tipoArticulo);
		cout<<endl;
		cout<<"________"<<endl;
		cout<<"Matriz Pesos "<<endl;
		imprimirMatrizEntero(peso);
		cout<<endl;		
		
		//impresión procentaje de ocupación del barco
		cout<<endl;	
		porcentajeOcupacionTotal(disponibilidad);
		
		//mostrar el total que paga cada puerto por los contenedores cargados
		cout<<endl;
		percioPorPuerto(nombrePuerto[i],sumPrecioPuerto[i]);
		cout<<endl;
		
	
	}

	//obtener el total de contenedores cargados al barco
		cout<<endl;
		totalContenedorescargados(disponibilidad);
		
		cout<<endl;
		contenedoresPorZona(disponibilidad);
		
		//ordenamiento burbuja de mayor a menor 
		ordenamientoBurbuja(nombrePuerto,cantidadContenedoresI, n);	
		
		//listado de marcas por zonas 
		listadoMarcasZona(nombre);
		
		cout<<endl;
		
		do
		{
			cout<<endl;
			cout<<"MENU DE OPCIONES"<<endl;
			cout<<"1. Buscar contenedor por nombre de empresa"<<endl;
			cout<<"2. Promedio de peso de contenedores"<<endl;
			cout<<"3. Fila con mayor carga"<<endl;
			cout<<"4. Columna con menos carga"<<endl;
			cout<<"5. Cantidad de contenedores segun tipo de articulo"<<endl;
			cout<<"6. Promedio de peso segun puerto origen"<<endl;
			cout<<"7. Empresa con el contenedor mas pesado"<<endl;
			cout<<"8. Empresa con el contenedor mas liviano"<<endl;
			cout<<"0. Salir"<<endl;
			cout<<"Digite opción >> ";
			cin>>salir;
			
			switch(salir){
			
				case 1:
					buscarMarcas(nombre);
					break;
				case 2:
					calcularPromedioPeso(peso,disponibilidad);
					break;
				case 3:
					calcularFilaMayorCarga(peso);
					break;
				case 4:
					calcularColumnaMenorCarga(peso);
					break;
				case 5:
					cantcont = cantContenedoresSegunClase(tipoArticulo);
					cout<<"   Cantidad : "<<cantcont <<endl;
					break;
				case 6:
					cout<<endl;
					cout<<"Digite nombre del puerto >> ";
					cin>>nompuerto;
					promPesoCarga = pesoIngresadoPorPuerto(peso,puertoCarga, nompuerto);
					cout<<endl;
					cout<<endl;
					cout<<"Promedio de carga puerto: "<<nompuerto <<" es: " <<promPesoCarga <<endl;
					break;	
				case 7:
					empresaContMasPesado(peso,nombre);
					break;
				case 8:
					empresaContMasliviano(peso,nombre);
					break;
					
			}
			
		}
		while(salir!=0);
	//cout<<"los puertos ordenados de menor a mayor son los siguientes: "<<endl;
	//OrdenamientoBurbuja(vectorOrdenamiento,nombrePuerto,n);
	
	return 0;
}

void limpiarMatriz(bool disponibilidad[filas][columnas],float peso[filas][columnas]){
	for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
			disponibilidad[i][j]=1;
			peso[i][j]=0;
		}
	}
}

int puertosAvisitar(){
	
	int cantidadPuertos=0;
	
	cout<<"digite la cantidad de puertos a visitar"<<endl;
	cin>>cantidadPuertos;
	
	return cantidadPuertos;
}

void mostrarMatriz(bool disponibilidad[filas][columnas]){
	
	for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
			cout<<disponibilidad[i][j]<<"\t";
		}
	cout<<endl;
	}
	
}

void llenadoPuertos(string puertoActual, int &sumPrecioPuerto,bool disponibilidad[filas][columnas],string nombre[filas][columnas],string puertoCarga[filas][columnas],string tipoArticulo[filas][columnas],float peso[filas][columnas],int cantidadContenedoresI){
	
	int salir=0;
	int posibleFila=-1;
	int posibleColumna=-1;
	int contadorContenedores=0;
	int precio = 0;

			
	do{
		
		cout<<endl;
		cout<<"Ingrese la coordenada de la fila"<<endl;
		cin>>posibleFila;
		cout<<"Ingrese la coordenada de la columna"<<endl;
		cin>>posibleColumna;

		
		if(disponibilidad[posibleFila][posibleColumna]==0){
					
			cout<<endl;
			cout<<"Ingrese otra coordenada"<<endl; 
			cout<<endl;
			
			cout<<"Ingrese la coordenada de la fila"<<endl;
			cin>>posibleFila;
			cout<<"Ingrese la coordenada de la columna"<<endl;
			cin>>posibleColumna;
			
		}
		
		//Se le debe sumar 1 cuando se va a comparar por que el primer indice es cero
		if((posibleFila+1)<=filas && (posibleColumna+1)<=columnas && posibleFila>=0 && posibleColumna>=0){
		
			if(disponibilidad[posibleFila][posibleColumna]==1){
				
				cout<<"Ingrese el nombre de la marca"<<endl;
				cin>>nombre[posibleFila][posibleColumna];
				
				cout<<"Ingrese el peso de la carga"<<endl;
				cin>>peso[posibleFila][posibleColumna];
				
				cout<<"Ingrese el tipo de articulo"<<endl;
				cin>>tipoArticulo[posibleFila][posibleColumna];
				
				disponibilidad[posibleFila][posibleColumna]=0;
				
				puertoCarga[posibleFila][posibleColumna]=puertoActual;
				
				cout<<endl;
				cout<<"Cargamento llenado exitosamente"<<endl;
				cout<<endl;
				precio = 0;
				precio = validarZonaprecios(posibleFila, posibleColumna, filas, columnas);
				
				sumPrecioPuerto = sumPrecioPuerto + precio;
				if	(precio == 100){
					kconzonaeconomica = kconzonaeconomica + 1;					
				} 
				else{						
					kconzonapremium = kconzonapremium + 1;					
				}
				
				contadorContenedores=contadorContenedores+1;
				
				cout<<endl;
				cout<<"Total contenedores:  "<<cantidadContenedoresI<<endl;
				cout<<endl;
				cout<<"Contenedores llenados actualmente:  "<<contadorContenedores<<endl;
				cout<<endl;
				
				cout<<"Coordenadas disponibles"<<endl;
				mostrarMatriz(disponibilidad);
				
			}else{
				
				cout<<endl;
				cout<<"Posicion no disponible, vuelva a intentarlo"<<endl;
				cout<<endl;
				
			}
			
		}else{
			
			cout<<"Coordenadas invalidas, vuelva a intentarlo."<<endl;
			cout<<endl;
			
		}
		
		if(contadorContenedores>=cantidadContenedoresI){
			
			cout<<"Puerto completado"<<endl;
			cout<<endl;
			
			salir=1;
		}
		
	}while(salir!=1);
	
	
}

void porcentajeOcupacionTotal(bool disponibilidad[filas][columnas]){

	float porcentaje=0.0;
	int contadorOcupados=0;
	
	for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
			if(disponibilidad[i][j]==0){
				contadorOcupados++;
				}
			}	
		}
	porcentaje=(contadorOcupados*100)/(filas*columnas);
	cout<<"El porcentaje de ocupacion es: "<<porcentaje<<"%"<<endl;
}

void percioPorPuerto(string puerto, int precio){

		
        cout<<"Valor recaudado en el puerto " <<puerto << " = " <<precio;
		cout<<endl;
		
		cout<<"Cantidad contenedores en Zona Premium Puerto " << puerto << " = " <<kconzonapremium;
		cout<<endl;
		
		cout<<"Cantidad contenedores en Zona economica Perto " << puerto << " = " <<kconzonaeconomica;
		cout<<endl;  

}
	
void ordenamientoBurbuja(string puertoCarga[filas],int contenedoresCargados[filas], int n){
	string nombrePuerto;
	int aux = 0;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			
			if(contenedoresCargados[i]>contenedoresCargados[j]){
			
				aux=contenedoresCargados[i];
				contenedoresCargados[i] = contenedoresCargados[j];
				contenedoresCargados[j] = aux;
				
				nombrePuerto = puertoCarga[i];
				puertoCarga[i]=puertoCarga[j];
				puertoCarga[j]=nombrePuerto;
				
			}
		}
	}
	cout<<endl;
	
	cout<<"El orden de mayor a menor contenedor ingresado es: "<<endl;
	for(int i=0;i<n;i++){
		
		cout<<puertoCarga[i]<< " -> " << contenedoresCargados[i]<<endl;		
	}
}

void totalContenedorescargados(bool disponibilidad[filas][columnas]){
	
	int contadorContenedores=0;
	int contadorContPremiun=0;
	int contadorContEconomica=0; 
	
	for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
			if(disponibilidad[i][j]==0){
			
			contadorContenedores++;
			
			}
		}
	}
	
	cout<<"Estos son los contenedores totales: "<<contadorContenedores<<endl;
	
}

void imprimirMatrizTexto1(string nombre[filas][columnas]){
	for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
			cout<<nombre[i][j]<<", \t";
		}
		cout<<endl;
	}
}

void imprimirMatrizTexto2(string puertoCarga[filas][columnas]){
	for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
			cout<<puertoCarga[i][j]<<", \t";
		}
		cout<<endl;
	}
}

void imprimirMatrizTexto3(string tipoArticulo[filas][columnas]){
	for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
			cout<<tipoArticulo[i][j]<<", \t";
		}
		cout<<endl;
	}
}

void imprimirMatrizEntero(float peso[filas][columnas]){
	for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
			cout<<peso[i][j]<<"\t";
		}
		cout<<endl;
	}
}

void contenedoresPorZona(bool disponibilidad[filas][columnas]){
	
	
	int contadorEconomico=0;
	int contadorPremium=0;
	
	for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
			if	(disponibilidad[i][j] == 0) {
				if ((i > 0 && (i+1) < filas) && (j > 0 && (j+1) < columnas))
			 	{
					//premium
	     			contadorPremium++;
     			}else{
       				//economico
         			contadorEconomico++;    
    			}
    		}
		}
	}
	
	cout<<endl;
	cout<<"Contenedores en la zona economica: "<<contadorEconomico<<endl;
	cout<<endl;
	cout<<"Contenedores en la zona premium: "<<contadorPremium<<endl;
}

int validarZonaprecios(int i, int j, int filas, int columnas){
	
	
	 if(verificarZona(i,j,filas,columnas)=="P"){
		//premium
	     return 300;
     }else{
       	//economico
         return 100;    
    }
	
}

string verificarZona(int i, int j, int filas, int columnas){
	 if((i > 0 && (i+1) < filas) && (j > 0 && (j+1) < columnas))
	 {
		//premium
	     return "P";
     }else{
       	//economico
         return "E";    
    }
	
}

void listadoMarcasZona(string nombre[filas][columnas]){
	string listPremium="-";
	string listeconomica="-";
	
	for(int i = 0; i < filas; i++)
	{
		for(int j=0; j<columnas; j++){
			if(nombre[i][j] != "")
			{
				if ((i > 0 && (i+1) < filas) && (j > 0 && (j+1) < columnas))
	 			{
					//premium
	     			listPremium =  listPremium + "-" + nombre[i][j];
     			}else{
       				//economico
         			listeconomica = listeconomica +"-"+nombre[i][j];
    			}					
			}
		}
	}
	
	if(listPremium=="-"){
		cout<<endl;
		cout<<"No Existen conetenedores en Zona Premium"<<endl;;
	}
	else
	{
		cout<<endl;
		cout<<"Marcas de contenedores en zona Premium = " << listPremium<<endl;;
	}
	
	if(listeconomica=="-"){
		cout<<endl;
		cout<<"No Existen conetenedores en Zona Económica"<<endl;;
	}
	else
	{
		cout<<endl;
		cout<<"Marcas de contenedores en zona Economica = " << listeconomica<<endl;;
	}
}

void buscarMarcas(string nombre[filas][columnas]){
	string marcaBuscar;
	int  contZonaPremium=0;
	int  contZonaeconomica=0;
	int sumZonaPremium=0;
	int sumZonaeconomica=0;
	
	
	cout<<endl;
	cout<<"Digite el nombre de la empresa :>> ";
	cin>>marcaBuscar;
	for(int i=0; i<filas;i++){
		for(int j=0; j<columnas;j++){
			if(nombre[i][j]==marcaBuscar){
				if (verificarZona(i,j,filas,columnas) == "P")
				{
					
					
					contZonaPremium++;
					sumZonaPremium += 300;
					
				}
				else
				{
					contZonaeconomica++;
					sumZonaPremium += 100;
				}
				
			}
		}
	}
	cout<<endl;
	cout<<"Empresa: "<<marcaBuscar <<endl;
	cout<<"El valor a pagar es de " <<sumZonaPremium+sumZonaeconomica <<" USD " <<endl;
	cout<<"Contenedores es Zona premium : "<<contZonaPremium <<endl;
	cout<<"Contenedores es Zona economica : "<<contZonaeconomica <<endl;
	
}

void calcularPromedioPeso(float peso[filas][columnas], bool disponibilidad[filas][columnas]){
	
	int contceldasocupadas=0;
	float sumtoneladas = 0;
	float promedio = 0;
	
	for(int i=0; i<filas;i++){
		for(int j=0; j<columnas;j++){
			if(disponibilidad[i][j] == 0){
				contceldasocupadas++;
				sumtoneladas += peso[i][j];
				
			}
		}
	}
	if (contceldasocupadas != 0)
	{	
		promedio = sumtoneladas / contceldasocupadas;		
	}
	
	cout<<"promedio de peso de los contenedores  =>> " <<promedio <<endl;
	
}

void calcularFilaMayorCarga(float peso[filas][columnas]){
	float pesofila=0;
	float aux=INT_MIN;
	int filaMayCarga=0;
	
	for(int i=0; i<filas;i++){
		pesofila =0;
		for(int j=0; j<columnas;j++)
		{
			pesofila = pesofila + peso[i][j];
					
		}
		if (pesofila > aux)
		{
			filaMayCarga = i;
			aux = pesofila;				
		}
	}
	cout<<endl;
	cout<<"La Fila con mayor peso es =>> " << filaMayCarga << " con un peso de =>> " <<aux <<endl;
	
}

void calcularColumnaMenorCarga(float peso[filas][columnas]){
	int colunMencarga=0;
	float aux=INT_MAX;
	float pesoColumna=0;
	bool primingreso = true;
	
	
	for(int j=0; j<columnas;j++){		
		pesoColumna =0;
		for(int i=0; i<filas;i++)
		{
			pesoColumna = pesoColumna + peso[i][j];
		}
		
		if (primingreso)
		{
			aux = pesoColumna;
			primingreso = false;
		}
				
		if (pesoColumna < aux)
		{
			colunMencarga = j;
			aux = pesoColumna;	
		}
	}
	
	cout<<endl;
	cout<<"La Columna con menor carga es =>> " << colunMencarga << " con un peso de =>> " <<aux <<endl;

}

int cantContenedoresSegunClase(string tipoArticulo[filas][columnas]){
	string clsArtBuscar;
	int contTipoArt = 0;
	cout<<endl;
	cout<<"Digite clase de artículo >> ";
	cin>>clsArtBuscar;
	for(int i=0; i<filas;i++){
		for(int j=0; j<columnas;j++){
			if(tipoArticulo[i][j]==clsArtBuscar){
				contTipoArt++;
			}
		}
	}
	cout<<endl;
	cout<<"Cantidad de contenedores clase "<<clsArtBuscar;
	return contTipoArt;
}

float pesoIngresadoPorPuerto(float peso[filas][columnas], string puertoCarga[filas][columnas], string nompuerto){	
	
	int contingreso = 0;
	float sumPeso =0;
	float promedio = 0;
	
	for(int i=0; i<filas;i++){
		for(int j=0; j<columnas;j++){
			if(puertoCarga[i][j]==nompuerto){
				contingreso++;
				sumPeso += peso[i][j];
			}
		}
	}
	if(contingreso!=0) {
		promedio = sumPeso / contingreso;
	}
	return promedio;	
}

void empresaContMasPesado(float peso[filas][columnas], string nombre[filas][columnas]){
	float aux = 0;
	string empresa;
	
		for(int i=0; i<filas;i++){
			
			for(int j=0; j<columnas;j++){
				if (peso[i][j] > aux ){
					aux = peso[i][j];
					empresa = nombre[i][j];
				}
			}
		}
		
		cout<<"la empresa " << empresa <<" Tienen el contenedor mas pesado = " << aux <<endl;
	
}

void empresaContMasliviano(float peso[filas][columnas], string nombre[filas][columnas]){
	bool primVez = true;
	float aux = 0;
	string empresa="";

	for(int i=0; i<filas;i++)
		{
			
			for(int j=0; j<columnas;j++)
			{
				if (peso[i][j] != 0 )
				{
					if (primVez)
					{
						aux = peso[i][j];
						primVez = false;
						
					}
					
					if (peso[i][j] < aux)
					{
						aux = peso[i][j];
						empresa = nombre[i][j];						
					}
				}
			}
		}
		
		cout<<endl;
		cout<<"La Empresa con el contenedor mas liviano es: "<< empresa <<" con un peso de: "<<aux <<endl;	
}

