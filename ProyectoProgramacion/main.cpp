#include<fstream>//permite buscar lo que se le indicara en toda la computadora
#include <iostream> // Biblioteca para la entrada-salida estándar
#include<conio.h>
#include<stdio.h>
#include<cstring>
#include <stdlib.h>
#include <fstream>
#include <ctype.h>
using namespace std;

struct empleados
{
char nombre[50], direccion[25], email[25], telefono[8], dpi[50];//
bool estado;
int codigo;
int departamento, horassemanales, valorhoras, valorextra;
};

struct dpto
{
	char nombre[50];
	int codigo;
};

struct pagoHoras
{
	int dpiEmpleado,codigo;
	int semana1,semana2,semana3,semana4,semana5,total;
};

 empleados trabajador[100];//crear una variable
 dpto departamento[100];
 pagoHoras horas[100];

int main()
{
	int opcion, i=0,x=0, resultadoDpi,resultadoNombre, opcion2, opcion3, opcion4,OpcionEliminar, opcioningreso,opcioncancelar;//
	char busqueda[50];
	
		long contadorEmpleados,verificadorEmpleados;////Variables para trabajar con el archivo de empleados
		long contadorDepto,verificadorDepto;////Variables para trabajar con el archivo de departamentos
		long contadorHoras,verificadorHoras;////Variables para trabajar con el archivo de departamentos
//////////////////////////////*************************/////////////////////////////
			ifstream ingresar("empleados.txt",ios::out|ios::binary); //Crea el archivo clientes
			ifstream ingresar2("departamento.txt",ios::out|ios::binary); //Crea el archivo departamento
			ifstream ingresar3("horas.txt",ios::out|ios::binary); //Crea el archivo Horas
			

		
////////////////////verifica que el archivo empleados exista
		    if(ingresar==NULL)
		        {
		            ifstream ingresar("empleados.text",ios::out|ios::binary);
		        }
		    else{
		            for (int i=1; i<1000; i++) /// crea el archivo si en caso no existiera
		            {
		            ingresar.read(reinterpret_cast<char*>(&trabajador[i]),sizeof(empleados));
		            }
		        }
		    ingresar.close();/// cierra el archivo clientes		
//////////////////////////////////////*********************************////////////////////////////	

		
////////////////////verifica que el archivo departamento exista
		    if(ingresar2==NULL)
		        {
		            ifstream ingresar2("departamento.text",ios::out|ios::binary);
		        }
		    else{
		            for (int i=1; i<1000; i++) /// crea el archivo si en caso no existiera
		            {
		            ingresar2.read(reinterpret_cast<char*>(&departamento[i]),sizeof(dpto));
		            }
		        }
		    ingresar2.close();/// cierra el archivo clientes		
//////////////////////////////////////*********************************////////////////////////////	

////////////////////verifica que el archivo departamento exista
		    if(ingresar3==NULL)
		        {
		            ifstream ingresar3("horas.text",ios::out|ios::binary);
		        }
		    else{
		            for (int i=1; i<1000; i++) /// crea el archivo si en caso no existiera
		            {
		            ingresar3.read(reinterpret_cast<char*>(&horas[i]),sizeof(pagoHoras));
		            }
		        }
		    ingresar3.close();/// cierra el archivo clientes		
//////////////////////////////////////*********************************////////////////////////////	
	
	
///////Inicio del Menu.
	
	do
	{ // Inicio Do
		system("cls");
		cout<<"*************************Departamento de contabilidad**************************"<<endl;
		cout<<"\t\tObtencion de Mercaderia Agropecuaria Rural (OMAR)"<<endl<<endl;
		cout<<"1. Ingreso de nuevo empleado"<<endl;
		cout<<"2. Busqueda de empleado"<<endl;
		cout<<"3. Departamentos"<<endl;
		cout<<"4. Reportes"<<endl;
		cout<<"5. Salir"<<endl<<endl;
		cout<<"Elija una opcion.....";
		cin>>opcion;
		
	//////////////////////////////******************************************************
                    	contadorEmpleados=0;
                        if (contadorEmpleados!=1001)
                        {
                            while (contadorEmpleados<1000)
                            {
                                contadorEmpleados++;
                                if (trabajador[contadorEmpleados].codigo!=contadorEmpleados)
                                {
                                    verificadorEmpleados=contadorEmpleados;
                                    contadorEmpleados=1001;
                                }
                            }
                            trabajador[verificadorEmpleados].codigo=verificadorEmpleados-1;
                        }
                        
     ///*****************************
     
    	//////////////////////////////******************************************************
                       	contadorDepto=0;
                        if (contadorDepto!=1001)
                        {
                            while (contadorDepto<1000)
                            {
                                contadorDepto++;
                                if (departamento[contadorDepto].codigo!=contadorDepto)
                                {
                                    verificadorDepto=contadorDepto;
                                    contadorDepto=1001;
                                }
                            }
                            departamento[verificadorDepto].codigo=verificadorDepto-1;
                        }
     ///*****************************
     
     
         	//////////////////////////////******************************************************
                       	contadorHoras=0;
                        if (contadorHoras!=1001)
                        {
                            while (contadorHoras<1000)
                            {
                                contadorHoras++;
                                if (horas[contadorHoras].codigo!=contadorHoras)
                                {
                                    verificadorHoras=contadorHoras;
                                    contadorHoras=1001;
                                }
                            }
                            horas[verificadorHoras].codigo=verificadorHoras-1;
                        }
     ///*****************************
		
			switch (opcion)// Inicio Switch Principal
		{
			case 1://////////////////////////////////////////////////////////INGRESO
				system("cls");
				
							contadorEmpleados=0;
                            while (contadorEmpleados<1000)
                            {
                                contadorEmpleados++;
                                if (trabajador[contadorEmpleados].codigo!=contadorEmpleados)
                                {
                                    verificadorEmpleados=contadorEmpleados;
                                    contadorEmpleados=1001;
                                }
                            }
				
				if(verificadorDepto==1)
				{
					cout<<"No se pueden Ingresar Empleados si no Exiten departamentos";
					getch();
				}
				else
				{
					cout<<"*********Ingreso de nuevo empleado**********"<<endl<<endl;
					trabajador[verificadorEmpleados].codigo=verificadorEmpleados;
					cout<<"Codigo del Empleado: "<<trabajador[verificadorEmpleados].codigo<<"\n";////genera el codigo
					cout<<"Numero de dpi ";
		       		cin>>trabajador[verificadorEmpleados].dpi,50;
		       		cout<<"Nombre completo ";
		       		cin.ignore();
					cin.getline(trabajador[verificadorEmpleados].nombre,50);
		       		cout<<"Telefono movil ";
		       		cin>>trabajador[verificadorEmpleados].telefono,8;
		       		cout<<"Direccion exacta ";
		       		cin.ignore();
					cin.getline(trabajador[verificadorEmpleados].direccion,25);
		       		cout<<"E-mail ";
		       		cin>>trabajador[verificadorEmpleados].email,25;
		       			       		
		       		for(int a=1;a<verificadorDepto;a++)////Muestro un Listado de los departamentos
							{	cout<<"-----------------------------------------"<<endl;
								cout<<"Codigo: "<<departamento[a].codigo<<endl;
								cout<<"Nombre: "<<departamento[a].nombre<<endl;
							}
					cout<<"Escoja el Codigo del Departamento que desea Asignar: ";
					cin>>trabajador[verificadorEmpleados].departamento;		
		       		trabajador[verificadorEmpleados].estado=true;
		       		
				
					getch();
				}
			break;
			
			
			case 2://///////////////////////////////////////////////////////////BUSQUEDA
				system("cls");
				cout<<"*********Busqueda de Empleado**********"<<endl<<endl;
				cout<<"Ingrese el numero de DPI o Nombre completo: ";
				cin.ignore();
				cin.getline(busqueda,50);
				
				for(int buscador=1;buscador<=25;buscador++)
        		{// inicio del for		
				resultadoDpi=strncmp(trabajador[buscador].dpi,busqueda,50);
				resultadoNombre=strncmp(trabajador[buscador].nombre,busqueda,50);
				
	                if(resultadoDpi==0 || resultadoNombre==0 )//Conector Logico
	                {
	                	
	                    cout<<"****************************************************\n";
	                    cout<<"DPI: "<<trabajador[buscador].dpi<<endl;
	                    cout<<"Nombre: "<<trabajador[buscador].nombre<<endl;
	                    cout<<"Telefono: "<<trabajador[buscador].telefono<<endl;
	                    cout<<"Direccion: "<<trabajador[buscador].direccion<<endl;
	                    cout<<"E-mail: "<<trabajador[buscador].email<<endl;
	                    
	                    for(int a=1;a<verificadorDepto;a++)////Muestro un Listado de los departamentos
						{	
							if(departamento[a].codigo==trabajador[buscador].departamento)
							{
								cout<<"Departamento Asignado "<<departamento[a].nombre<<endl;
							}
						}
	                    
	                    	if(trabajador[buscador].estado==true)
							{
	                    		 cout<<"Estado: Activo"<<endl<<endl;
	                    	}
	                    	else
							{
	                    		 cout<<"Estado: De Inactivo"<<endl<<endl;
	                    	}
	                    
		                cout<<"****************************************************\n";
	                   	cout<<"1. Modificar "<<endl;
	                    cout<<"2. Eliminar Empleado "<<endl;
	                    cout<<"3. Horas laboradas "<<endl;
	                    cout<<"4. Regresar "<<endl<<endl;
	                    cout<<"Elija una opcion....";
	                    cin>>opcion2;
	                    
	                    switch(opcion2)
                    {
                    	case 1:
                    		system("cls");
                    		cout<<"************Que Desea Modificar**********"<<endl;
                    		cout<<"1. Dpi "<<endl;
                    		cout<<"2. Nombre "<<endl;
                    		cout<<"3. Telefono "<<endl;
                    		cout<<"4. Direccion "<<endl;
                    		cout<<"5. Email "<<endl;
                    		cout<<"6. Departamento "<<endl<<endl;
                    		cout<<"Elija una opcion....";
                    		cin>>opcion3;
                    			switch(opcion3)/// Inicio de Opciones del Empleado
								{
									case 1:
										system("cls");
										cout<<"Ingrese el Nuevo DPI ";
										cin.ignore();
										cin.getline(trabajador[buscador].dpi,50);
									break;
									                    	
									case 2:
										system("cls");
										cout<<"Ingrese el Nuevo Nombre ";
										cin.ignore();
										cin.getline(trabajador[buscador].nombre,50);
									break;		
									case 3:
										system("cls");
										cout<<"Ingrese el Nuevo Telefono ";
										cin.ignore();
										cin.getline(trabajador[buscador].telefono,8);
									break;	
									case 4:
										system("cls");
										cout<<"Ingrese la nueva direccion ";
										cin.ignore();
										cin.getline(trabajador[buscador].direccion,25);
									break;
									case 5:
										system("cls");
										cout<<"Ingrese el Nuevo Email ";
										cin.ignore();
										cin.getline(trabajador[buscador].email,25);
									break;
									case 6:
										system("cls");
											for(int a=1;a<verificadorDepto;a++)
											{	cout<<"-----------------------------------------"<<endl;
												cout<<"Codigo: "<<departamento[a].codigo<<endl;
												cout<<"Nombre: "<<departamento[a].nombre<<endl;
											}
										cout<<"Asigne un Departamento ";
										cin.ignore();
										cin>>trabajador[buscador].departamento;
									break;
									
                    			}//// fin switch opciones del empleado
                    		
                    		break;
                    		
                    	case 2:
                    		system("cls");
                    		cout<<"*******************Eliminar******************"<<endl;
                    		cout<<"Esta Seguro que desea Eliminar al Empleado  1.Si 2.No"<<endl;
                    		cin>>OpcionEliminar;
	            				if(OpcionEliminar==1){
	            					trabajador[buscador].estado=false;
	            					cout<<"Eliminando Cliente.......";
	            				}
                    		break;
                    		
                    	case 3:
                    		system("cls");
                    			if(trabajador[buscador].estado==true)
								{
									cout<<"*************Horas laboradas**************"<<endl;
									cout<<"1. Ingresar horas semanales"<<endl;
									cout<<"2. Horas laboradas"<<endl<<endl;
									cout<<"Elija una opcion.....";
									cin>>opcioningreso;
									
									switch(opcioningreso)
									{
										case 1:
										system("cls");
										cout<<"Nombre: "<<trabajador[buscador].nombre<<endl;
                    					cout<<"***************Ingreso de Horas Laboradas*************"<<endl<<endl;
                    					cin>>trabajador[buscador].horassemanales;
                    					cout<<endl<<"LAS HORAS HAN SIGO GUARDADAS";
		                    			break;
		                    			
		                    			case 2:
		                    				system("cls");
		                    				cout<<trabajador[buscador].nombre<<endl;
		                    				if (trabajador[buscador].horassemanales>=44)
	                    					{
	                    						trabajador[buscador].valorhoras=(44*12);
		                    					trabajador[buscador].valorextra=(trabajador[buscador].horassemanales-44)*(12*1.5);		
	                    					}
	                    					else
	                    					{
	                    						trabajador[buscador].valorhoras=trabajador[buscador].horassemanales*12;
			                    			}
			                    			
			                    			cout<<"Valor monetario de las horas hasta el momento"<<endl<<endl;
		                    				cout<<"Ordinario "<<trabajador[buscador].valorhoras<<"....."<<"Extraordinario "<<trabajador[buscador].valorextra<<endl;
											cout<<"Con un total de "<<trabajador[buscador].valorhoras+trabajador[buscador].valorextra;
			                    			
			                    			cout<<"DESEA CANCELAR EL TOTAL DE HORAS....1.SI....2.NO.....";
												cout<<"Elija una opcion.....";
												cin>>opcioncancelar;
												
												switch(opcioncancelar)
												{
													case 1:	
														cout<<"......."<<buscador;
														trabajador[buscador].horassemanales=0;	
															
													break;
													
													case 2:
													
													break;
												}		
		                    			break;
									}
		                    		
		                    	}
		                    	else
								{
		                    		 cout<<endl<<endl<<"**********El trabajador se encuenta de Baja***********"<<endl<<endl;
		                    	}
                    		break;
                    		
                    	case 4:
                    		
                    	break;
                    		
					}
					}
					if(resultadoDpi==0 and resultadoNombre==0 )
					{	cout<<"El Usuario no Existe";
						buscador=1000;
					}
					
						               					
				}	//fin del for de empleados	
                    
					
					
			getch();
			break;
			
			
			case 3:////////////////////////////////////////////////////////////////////DEPARTAMENTO
				system("cls");
				cout<<"**********Departamentos************"<<endl<<endl;
				cout<<"1. Nuevo Departamentos"<<endl;
				cout<<"2. Ver Departamentos"<<endl;
				cout<<"Escoja una opcion";
				cin>>opcion4;
				
				switch (opcion4)// Inicio Switch Departamentos
				{
					case 1:	
						system("cls");
						
						contadorDepto=0;
                            while (contadorDepto<1000)
                            {
                                contadorDepto++;
                                if (departamento[contadorDepto].codigo!=contadorDepto)
                                {
                                    verificadorDepto=contadorDepto;
                                    contadorDepto=1001;
                                }
                            }
				
						cout<<"*********Nuevo Departamento**********"<<endl;
						departamento[verificadorDepto].codigo=verificadorDepto;
						cout<<"Codigo del Departamento: "<<departamento[verificadorDepto].codigo<<"\n";////genera el codigo
						cout<<"Nombre: ";
						cin.ignore();
						cin.getline(departamento[verificadorDepto].nombre,50);
						
						break;
					
					case 2:
						system("cls");
						cout<<"Departametos existentes"<<endl;
						cout<<verificadorDepto;
						for(int a=1;a<verificadorDepto;a++)
						{	cout<<"-----------------------------------------"<<endl;
							cout<<"Codigo: "<<departamento[a].codigo<<endl;
							cout<<"Nombre: "<<departamento[a].nombre<<endl;
						}
						
						break;
						
				}///fin del switch departamento
				
				getch();
			break;
			
			case 4:///////////////////////////////////////////////////////////////////REPORTE
				system("cls");
				cout<<"***********Reportes y calculo de nomina***********"<<endl<<endl;
				cout<<"1. Reporte General";
				cout<<"2. Reporte Individual";
				cout<<"3. Reporte de Personal que gana mas de Q2500.00";
				
				switch (opcion4)// Inicio Switch Departamentos
				{
					case 1:	
						system("cls");
						cout<<"*********Reporte General**********"<<endl<<endl;
						
						break;
					
					case 2:
						system("cls");
						cout<<"*********Reporte individual********"<<endl;
						
						break;
					case 3:
						system("cls");
						cout<<"*********Reporte de personal que gana mas de Q2500.00********"<<endl;
						
						break;

				}

				getch();
			break;
			
			case 5://///////////////////////////////////////////////////////////////SALIR
				cout<<"Saliendo del Programa";
				
					ofstream agregar("empleados.txt",ios::out|ios::binary);
                for ( int c=1; c<verificadorEmpleados; c++)
        			{
			   	     agregar.write(reinterpret_cast<char*>(&trabajador[c]),sizeof(empleados));
        			}
				agregar.close();///cierra el archivo clientes	
				
				
				ofstream agregar2("departamento.txt",ios::out|ios::binary);
                for ( int c=1; c<verificadorDepto; c++)
        			{
			   	     agregar2.write(reinterpret_cast<char*>(&departamento[c]),sizeof(dpto));
        			}
				agregar2.close();///cierra el archivo departamentos
				
				
					ofstream agregar3("horas.txt",ios::out|ios::binary);
                for ( int c=1; c<verificadorEmpleados; c++)
        			{
			   	     agregar3.write(reinterpret_cast<char*>(&horas[c]),sizeof(pagoHoras));
        			}
				agregar3.close();///cierra el archivo horas		
    				
		
		} // fin del switch principal
	
		
		
		
	}while(opcion!=5); // fin del while principal
		
}
