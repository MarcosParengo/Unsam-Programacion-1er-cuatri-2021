/*abml final*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct producto {
    int cod_art;
    char marca[30];
    int stock;
    float precio;
    char valido; // campo para verificar si hay existencias de productos o no
};
/*creo archivo*/
void crearbin(FILE * pA){
   if ( ( pA = fopen( "stock.dat", "w+b" ) ) == NULL )
      printf( "No pudo abrirse el pA.\n" );
   else {
    printf("Archivo creado exitosamente.\n");
    fclose( pA );
    }
}

/*menú de operaciones*/
int Menu(){
    char opcion;
    printf("Elige una opci%cn:\n",162);
    printf("C) Crear el archivo\n");
    printf("G) Guardar nuevo producto\n");
    printf("E) Listar productos en stock\n");
    printf("B) Buscar producto\n");
    printf("A) Aumentar stock\n");
    printf("D) Decrementar stock\n");
    printf("P) Modificar precio\n");
    printf("O) Dar de Baja l%cgica un producto\n",162);
    printf("X) Actualizar archivo eliminando bajas de productos (Baja f%csica)\n", 161);
    printf("S) Salir\n");
    scanf("%c",&opcion);
    fflush(stdin);
    return toupper(opcion); // retorna la letra ingresada en mayúscula
}

/*alta de producto*/
void altaProducto(FILE * pA){
struct producto prod;
    pA=fopen("stock.dat","r+b");
    printf("Ingrese c%cdigo num%crico del art%cculo: \n",162,130,161);
    scanf("%d",&prod.cod_art);
    fflush(stdin);
    printf("Ingrese marca del producto: \n");
    gets(prod.marca);
    fflush(stdin);
    printf("Ingrese stock: \n");
    scanf("%d",&prod.stock);
    fflush(stdin);
    while(prod.stock<0){
        printf("El stock de un producto no puede ser con valor negativo,\npor favor ingrese un valor correcto...\n");
        printf("Ingrese stock: \n");
        scanf("%d",&prod.stock);
    }
    printf("Ingrese el precio: \n");
    scanf("%f",&prod.precio);
    fflush(stdin);
    while(prod.precio<=0){
        printf("El precio de un producto debe ser mayor a 0(cero), ingrese un valor correcto...\n");
        printf("Ingrese precio: \n");
        scanf("%f",&prod.precio);
    }
    prod.valido='S';// si es un alta no se ingresa por teclado si está activo, se asigna S directamente

    if (prod.cod_art == 1){
        fseek(pA,0,SEEK_SET);
        fwrite(&prod,sizeof(struct producto),1,pA);}
    else {
        fseek(pA,(prod.cod_art-1)*sizeof(struct producto),SEEK_SET);
        fwrite(&prod,sizeof(struct producto),1,pA);
        }
    fclose(pA);
}

/*lista de productos*/
void listarDatos(FILE *pA){
struct producto prod;
int i=0, cantprod;
pA=fopen("stock.dat","rb");
    fseek(pA,0,SEEK_END);
    cantprod=ftell(pA)/sizeof(struct producto);// calculo la cantidad de productos registrados para el ciclo
    printf( "Art%cculo\tMarca\t\tStock\t\tPrecio\tActivo\n",161 );
    fseek(pA,0,SEEK_SET);
    while( i < cantprod ){
        fseek(pA,i*sizeof(struct producto),SEEK_SET);
        fread(&prod,sizeof(struct producto),1,pA);
        printf( "%-14d%-10s%13d%15.2lf%10c\n", prod.cod_art, prod.marca, prod.stock, prod.precio, prod.valido);
        i++;
    }
fclose(pA);
}

/* función auxiliar me permite obtener el código de producto para utilizar en otras funciones*/
int leerArt(){
int art;
printf("Ingrese c%cdigo num%crico del art%cculo: \n",162,130,161);
scanf("%d",&art);
fflush(stdin);
return art;
}
/*búsqueda secuencial en el archivo, también puede hacerse con acceso directo*/
void buscarProducto(FILE *pA){
struct producto prod;
int art = leerArt();
pA=fopen("stock.dat","rb");

    while(!feof(pA)){
    // las funciones en c devuelven un valor entero lo que permite usar ese valor para las operaciones
     if (fread(&prod, sizeof(struct producto),1,pA)==1){
         if(art == prod.cod_art)
         printf("Marca: %s, Art%cculo: %d, Stock: %d, Precio: %.2f, Activo: %c\n",prod.marca,161, prod.cod_art, prod.stock, prod.precio, prod.valido);

      }
    }
fclose(pA);
}

/*modificación de stock*/
void aumentarStock(FILE * pA){
struct producto prod;
int nstock, art=leerArt();
pA=fopen("stock.dat","r+b");

printf("Ingrese stock\n");
scanf("%d",&nstock);
fflush(stdin);
while(!feof(pA)){
    if(fread(&prod,sizeof(struct producto),1,pA) == 1){
        if(prod.cod_art == art){
            prod.stock = prod.stock + nstock;
            fseek(pA,-sizeof(struct producto),SEEK_CUR);
            fwrite(&prod,sizeof(struct producto),1,pA);
            fflush(pA); // vaciamos el buffer para evitar errores
        }
    }
}
printf("Stock modificado correctamente\n");
fclose(pA);
}

/*modificación de stock*/
void decrementarStock(FILE * pA){
struct producto prod;
int nstock, art=leerArt();

pA=fopen("stock.dat","r+b");
printf("Ingrese cantidad a decrementar\n");
scanf ("%d",&nstock );
fflush(stdin);
while(!feof(pA)){
    if(fread(&prod,sizeof(struct producto),1,pA)==1){
        if(prod.cod_art==art){
           prod.stock = prod.stock - nstock;
            fseek(pA,-sizeof(struct producto),SEEK_CUR);
            fwrite(&prod,sizeof(struct producto),1,pA);
            fflush(pA);
        }
    }
}
printf("Stock modificado correctamente\n");
fclose(pA);
}

/*modificación de precio*/
void modificarPrecio(FILE * pA){
struct producto prod;
float nuevoPrecio;
int art=leerArt();

    pA=fopen("stock.dat","r+b");
    fseek(pA,0,SEEK_SET);
    fseek(pA,(art-1)*sizeof(struct producto ),SEEK_SET);
    fread(&prod,sizeof(struct producto ),1,pA);
    printf("Usted modificar%c el precio de:\n",160);
    printf("Marca: %s, Art%cculo: %d, Stock: %d, Precio: %.2f, Activo: %c\n",prod.marca,161, prod.cod_art, prod.stock, prod.precio, prod.valido);
    getchar();
    printf("Ingrese nuevo precio\n");
    scanf("%f",&nuevoPrecio);
    fflush(stdin);

    while(nuevoPrecio <= 0){
        printf("El precio debe ser mayor a 0, ingrese nuevamente\n");
        printf("Ingrese nuevo precio\n");
        scanf("%f",&nuevoPrecio);
        fflush(stdin);
    }

    prod.precio = nuevoPrecio;
    fseek(pA,-sizeof(struct producto),SEEK_CUR);
    fwrite(&prod,sizeof(struct producto),1,pA);
fclose(pA);
printf("\n***--Precio modificado correctamente\n--***");
}

/*modificación de campo valido*/
void bajaLogica(FILE * pA){
struct producto prod;
int art=leerArt();
pA=fopen("stock.dat","r+b");

    fseek(pA,0,SEEK_SET);
    fseek(pA,(art-1)*sizeof(struct producto ),SEEK_SET);
    fread(&prod,sizeof(struct producto ),1,pA);
    printf("Usted dar%c de baja a:\n", 160);
    printf("Marca: %s, Art%cculo: %d, Stock: %d, Precio: %.2f, Activo: %c\n",prod.marca,161, prod.cod_art, prod.stock, prod.precio, prod.valido);
    getchar();
    prod.valido = 'N';
    fseek(pA,-sizeof(struct producto),SEEK_CUR);
    fwrite(&prod,sizeof(struct producto),1,pA);

fclose(pA);
printf("\n***--El producto %d se dio de baja correctamente--***\n", art);
}

/*creación de nuevo archivo eliminando los inactivos*/
void bajaFisica(FILE * pA){
FILE *temp;
struct  producto prod;
    pA=fopen("stock.dat","rb");
    temp= fopen("stock.temp","w+b");
    fseek(pA,0,SEEK_SET);

    while(fread(&prod,sizeof(struct producto),1,pA)==1){
        if(prod.valido == 'S'){
            fwrite(&prod,sizeof(struct producto ),1,temp);
        }
    }
    fclose(temp);
    fclose(pA);
    remove("stock.dat");
    rename("stock.temp","stock.dat");
    remove("stock.temp");
printf("\n***--Archivo actualizado--***\n");
}

int main() {
    char opcion;
    FILE * pArchivo;
    do{
     opcion=Menu();
     switch(opcion){
        case 'C': crearbin(pArchivo); printf("\n"); break;
        case 'G': altaProducto(pArchivo); printf("\n"); break;
        case 'E': listarDatos(pArchivo); printf("\n"); break;
        case 'B': buscarProducto(pArchivo); printf("\n"); break;
        case 'A': aumentarStock(pArchivo); printf("\n"); break;
        case 'D': decrementarStock(pArchivo); printf("\n"); break;
        case 'P': modificarPrecio(pArchivo); printf("\n"); break;
        case 'O': bajaLogica(pArchivo); printf("\n"); break;
        case 'X': bajaFisica(pArchivo); printf("\n"); break;
            }
    } while(opcion != 'S');
}
