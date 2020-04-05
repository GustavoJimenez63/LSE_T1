#include<iostream>

using namespace std;
class Nodo
{	
	private:
		int dato;
		Nodo *sig;
	public:
		Nodo()
		{	dato=0;
			sig=NULL;	
		}
		Nodo(int x)
		{	dato=x;
			sig=NULL;	
		}
		void Asignasig(Nodo*);
		void Leer(int);
		void Imprimir();
		Nodo *Obtienesig();
		int Obtienedato();
};
void Nodo::Asignasig(Nodo *x)
{	this->sig=x;
}
void Nodo::Leer(int x)
{	this->dato=x;
}
void Nodo::Imprimir()
{ cout<<this->dato<<endl;
}
Nodo* Nodo::Obtienesig()
{	return(this->sig);
}
int Nodo::Obtienedato()
{	return(this->dato);
}
class LSE
{	private:
		Nodo *Inicio;
	public:
		void InsertarI(int);
		void InsertarF(int);
		void Imprimir();
		LSE()
		{	Inicio=NULL;
		}
		void BorrarI();
		void BorrarF();
		int Contar();
		Nodo *Buscar(int);
		void Borrar(int);
};

//Funcion De Clase LSE Que Borra EL Dato Inicial De La Lista
void LSE::BorrarI()
{
    if(!Inicio)			//Verifica si hay inicio
        cout<<"Lista Vacia"<<endl;
	
    else			
        {
            if(Inicio->Obtienesig()==NULL)	//Para Cuando Inicio Es El Unico Dato De La Lista, Elimina Inicio Dejando La Lista Vacia	
                {
                    delete Inicio;
                    Inicio=NULL;
                }
	    
            else
                {
                    Nodo *hay=Inicio;		//Apuntador Auxiliar Que Apunta A Inicio
                    Inicio=Inicio->Obtienesig();	//Ordena Que Inicio Se Coloque En Donde El Mismo Inicio Esta Apuntando 
                    hay->Asignasig(NULL);		//Elimina El Apuntador Auxiliar Ya Que Este APunta Hacia EL Primer Dato
                    delete hay;
                }
        }
}

//Funcion De Clase LSE Que Borra EL Dato Final De La Lista
void LSE::BorrarF()
{    if(!Inicio)		//Verifica Si Hay Inicio
    cout<<"Lista Vacia";
else
{    if(Inicio->Obtienesig()==NULL)		//Cuando Solo Hay Un Dato El Final Y El Inicio Es El Mismo Haciendo Que se Elimine El Unico Dato
{    delete Inicio;
    Inicio=NULL;
}
else		
{    
	Nodo *Aux1,*Aux2;		//Se Crean Dos Apuntadores Auxiliares 
    	Aux1=Inicio;
	
    	while(Aux1->Obtienesig()!=NULL) //Va Recorriendo La Lista Hasta LLegar Uno Antes Al Ultimo
    	{
		Aux2=Aux1;	//El Auxiliar Dos Ahora Apunta Al Antepenultimo Dato 
        	Aux1=Aux1->Obtienesig();	//El Auxiliar 1 Es El Ultimo Dato "El Que Se Debe Eliminar"
    	}
    	Aux2->Asignasig(NULL);		//Ordena Que El Que Ahora Es EL Ultimo Dato Apunte a NULL
    	delete Aux1;		//Eliminas El Auxiliar 1 ya Que Era El Ultimo Dato
}
}
}




int main(int argc, const char * argv[])
{
    
    
    
    LSE A;
    int opc, dato;
    do{
        cout<<"1.- Insertar Inicio"<<endl;
        cout<<"2.- Insertar Fin"<<endl;
        cout<<"3.- Borrar Inicio"<<endl;
        cout<<"4.- Borrar Fin"<<endl;
        cout<<"5.- Contar"<<endl;
        cout<<"6.- Borrar"<<endl;
        cout<<"7.- Imprimir"<<endl;
        cout<<"8.- Salir"<<endl;
        cout<<"Teclee la opcion"<<endl;
        cin>>opc;
        
        switch(opc)
        {
            case 1:
                cout<<"teclee el dato a insertar"<<endl;
                cin>>dato;
                A.InsertarI(dato);
                break;
            case 2:
                cout<<"Teclee el dato a insertar"<<endl;
                cin>>dato;
                A.InsertarF(dato);
                break;
            case 3:
                A.BorrarI();
                break;
            case 4:
                A.BorrarF();
                break;
            case 5:
                dato=A.Contar();
                cout<<"Hay "<<dato<<" nodos en la Lista"<<endl;
                break;
            case 6:
                cout<<"Teclee el dato a borrar"<<endl;
                cin>>dato;
                A.Borrar(dato);
                break;
            case 7:
                A.Imprimir();
                break;
            default:
                cout<<"opción salir...";
                break;
        }
    }while(opc<8);
    
    return 0;
}
