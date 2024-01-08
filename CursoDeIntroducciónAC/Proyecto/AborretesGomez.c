#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int idProvedor;
char nombreProveedor[100];
char empresaProveedor[100];
char correoProveedor[100];

int respuestaRoles=0;
int contadorRoles=0;
int respuestaDueno=0;
int contadorDueno=0;
int respuestaArticulos=0;
int contadorArticulos=0;
int respuestaProveedores=0;
int contadorProveedores=0;

int idArticulo;

//Inicio de Menus

int menuRoles(){
    printf("---Bienvenido a Abarrotes Gomez----\n");

    while(contadorRoles<2){

    printf("1.-Soy el dueno   2.-Salir del sistema\n")   ;  
    scanf("%d",&respuestaRoles);
    printf("\n");

    if(respuestaRoles==1){
        contadorDueno=0;
        menuDueno();
    }
    else if (respuestaRoles==2){
        printf("Hasta luego y vuelve pronto!");
        contadorRoles=2;
    }
    else{
        printf("Esa no es una opcion\n");
        contadorRoles++;
    }
    }
    
    return 0;
}

int menuDueno(){
    while (contadorDueno<2){
    
    printf("Con que quieres trabajar?\n");
    printf("Recuerda que todos los IDs debe ser numericos y deben estar en el rango de 0000 a 9999\n");
    printf("1. Articulos\n");
    printf("2. Proveedor\n");
    printf("3.-Regresar al menu Anterior\n");
    scanf("%d",&respuestaDueno);
    printf("\n");

    if(respuestaDueno==1){
        contadorProveedores=0;
        menuProvedores();
    }
    else if (respuestaDueno==2){
        contadorProveedores=0;
        menuProvedores();
    }
    else if (respuestaDueno==3){
        contadorDueno=2;
    }
    else{
        printf("Esa no es una opcion");
        contadorDueno++;
    }
    }
    
    return 0;
}

int menuProvedores(){
    while(contadorProveedores<2){
    printf("Que desea hacer con Proveedores?\n");
    printf("1. Anadir proveedores\n");
    printf("2. Eliminar proveedores\n");
    printf("3. Modificar proveedores\n");
    printf("4. Ver proveedores\n");
    printf("5. Regresar al menu anterior\n");
    scanf("%d",&respuestaProveedores);
    printf("\n");

    if(respuestaProveedores==1){
        anadirProveedores();
    }
    else if (respuestaProveedores==2){
        eliminarProveedores();
    }
    else if (respuestaProveedores==3){
        modificarProveedores();
    }
    else if (respuestaProveedores==4){
        verProveedores();
    }
    else if (respuestaProveedores==5){
        contadorProveedores=2;
    }
    else{
        printf("Esa no es una opcion");
        contadorProveedores++;
    }
    }

    return 0;
}

//Proveedores

int verProveedores(){

    FILE *archivoVerProveedores;
    archivoVerProveedores = fopen("Proveedores.txt", "r");//abre el archivo en modo de lectura
    
    int i,num=100;
    char registro[100];
    char *lineas[100];

    if (archivoVerProveedores==NULL) {
        perror("Error al abrir el archivo");
        return 1;
    }

    int numLineas=0;

    //char *fgets(char *str, int num, FILE *stream);
    //str: almacena la línea leída
    //num: especifica el tamaño máximo del array str (el número máximo de caracteres que fgets leerá).
    //stream: representa el archivo desde el cual se leerá la línea.

    while (fgets(registro, num, archivoVerProveedores) != NULL) {// Lee cada línea del archivo y almacénala en el arreglo
        lineas[numLineas] = registro;
        numLineas++;
        printf("%s",lineas[numLineas-1]);
    }

    printf("\n");

    fclose(archivoVerProveedores);

    return 0;
}

int modificarProveedores() {
    int idModificar;

    printf("Proveedores existentes: \n");
    verProveedores();

    printf("Ingrese el ID del proveedor que desea modificar: \n");
    scanf("%d", &idModificar);

    FILE *archivoEntrada, *archivoSalida;

    archivoEntrada = fopen("Proveedores.txt", "r");
    archivoSalida = fopen("Proveedores_temp.txt", "w");

    if (archivoEntrada == NULL || archivoSalida == NULL) {
        fprintf(stderr, "No se pudo abrir el archivo\n");
        return 1;
    }

    int idProveedor;
    char nombreProveedor[50], empresaProveedor[50], correoProveedor[50];
    int encontrado = 0;

    while (fscanf(archivoEntrada, "%d,%49[^,],%49[^,],%49[^\n]", &idProveedor, nombreProveedor, empresaProveedor, correoProveedor) != EOF) {
        if (idProveedor == idModificar) {
            encontrado = 1;
            printf("Proveedor encontrado. Ingrese los nuevos datos:\n");

            // Pide al usuario que ingrese los nuevos datos
            printf("Ingrese el nuevo nombre del proveedor: \n");
            scanf("%s", nombreProveedor);
            printf("Ingrese la nueva empresa del proveedor: \n");
            scanf("%s", empresaProveedor);
            printf("Ingrese el nuevo correo electronico del proveedor: \n");
            scanf("%s", correoProveedor);
        }

        fprintf(archivoSalida, "%d,%s,%s,%s\n", idProveedor, nombreProveedor, empresaProveedor, correoProveedor);
    }

    fclose(archivoEntrada);
    fclose(archivoSalida);

    // Elimina el archivo original y renombra el temporal
    remove("Proveedores.txt");
    rename("Proveedores_temp.txt", "Proveedores.txt");

    if (encontrado) {
        printf("Proveedor modificado con exito\n\n");
    } else {
        printf("Proveedor no encontrado\n\n");
    }

    return 0;
}

int eliminarProveedores() {
    int idEliminar;

    printf("Proveedores existentes: \n");
    verProveedores();

    printf("Ingrese el ID del proveedor a eliminar: \n");
    scanf("%d", &idEliminar);

    FILE *archivoEntrada, *archivoSalida;
    archivoEntrada = fopen("Proveedores.txt", "r");
    archivoSalida = fopen("Proveedores_temp.txt", "w");

    if (archivoEntrada == NULL || archivoSalida == NULL) {
        fprintf(stderr, "Error al abrir archivos\n");
        return 1;
    }

    int idProveedor;
    char nombreProveedor[50], empresaProveedor[50], correoProveedor[50];

    //fscanf: lee datos del archivo asi como scanf
    //%49[^,]: lee una cadena de hasta 49 caracteres que no contenga comas
    while (fscanf(archivoEntrada, "%d,%49[^,],%49[^,],%49[^\n]\n", &idProveedor, nombreProveedor, empresaProveedor, correoProveedor) == 4) {
        if (idProveedor != idEliminar) {
            fprintf(archivoSalida, "%d,%s,%s,%s\n", idProveedor, nombreProveedor, empresaProveedor, correoProveedor);
        }
    }

    fclose(archivoEntrada);
    fclose(archivoSalida);

    remove("Proveedores.txt");
    rename("Proveedores_temp.txt", "Proveedores.txt");

    printf("Proveedor eliminado con éxito\n\n");

    return 0;
}

int anadirProveedores(){
    printf("Ingrese el ID del proveedor: \n");
    scanf("%d",&idProvedor);
    printf("Ingrese el nombre del proveedor: \n");
    scanf("%s",&nombreProveedor);
    printf("Ingrese la empresa del proveedor: \n");
    scanf("%s",&empresaProveedor);
    printf("Ingrese el correo electronico del proveedor: \n");
    scanf("%s",&correoProveedor);
    printf("\n");


    FILE *archivoAnadirProveedores;

    archivoAnadirProveedores = fopen("Proveedores.txt", "a");

    if (archivoAnadirProveedores == NULL) {
        fprintf(stderr, "No se pudo abrir el archivo\n");
        return 1;
    }

    fprintf(archivoAnadirProveedores, "%d",idProvedor);
    fprintf(archivoAnadirProveedores, ",%s",nombreProveedor);
    fprintf(archivoAnadirProveedores, ",%s",empresaProveedor);
    fprintf(archivoAnadirProveedores, ",%s\n",correoProveedor);

    fclose(archivoAnadirProveedores);

    printf("Proveedor agregado con exito\n\n");
    
    return 0;
}

//Articulos

int menuArticulos(){
    while(contadorArticulos<2){
    printf("Que desea hacer con Articulos?:\n");
    printf("1. Anadir articulos\n");
    printf("2. Eliminar articulos\n");
    printf("3. Modificar articulos\n");
    printf("4. Ver articulos\n");
    printf("5. Regresar al menu anterior\n");
    scanf("%d",&respuestaArticulos);
    printf("\n");

    if(respuestaDueno==1){
        anadirArtiuclos();
    }
    else if (respuestaDueno==2){
        eliminarArticulos();
    }
    else if (respuestaDueno==3){
        modificarArticulos();
    }
    else if (respuestaDueno==4){
        verArticulos();
    }
    else if (respuestaDueno==5){
        contadorArticulos=2;
    }
    else{
        printf("Esa no es una opcion\n");
        contadorArticulos++;
    }
    }
    return 0;
}

int verArticulos() {
    FILE *archivoVerArticulos;
    archivoVerArticulos = fopen("Articulos.txt", "r");

    if (archivoVerArticulos == NULL) {
        perror("Error al abrir el archivo");
        return 1;
    }

    int numLineas = 0;
    char registro[100];

    while (fgets(registro, sizeof(registro), archivoVerArticulos) != NULL) {
        numLineas++;
        printf("%s", registro);
    }

    printf("\n");

    fclose(archivoVerArticulos);

    return 0;
}

#include <stdio.h>

void verArticulos() {
    // Implementa la función para mostrar los artículos existentes
}

int modificarArticulo() {
    int idModificar;

    printf("Artículos existentes: \n");
    verArticulos();

    printf("Ingrese el ID del artículo que desea modificar: \n");
    scanf("%d", &idModificar);

    FILE *archivoEntrada, *archivoSalida;

    archivoEntrada = fopen("Articulos.txt", "r");
    archivoSalida = fopen("Articulos_temp.txt", "w");

    if (archivoEntrada == NULL || archivoSalida == NULL) {
        fprintf(stderr, "No se pudo abrir el archivo\n");
        return 1;
    }

    int idArticulo;
    char nombreArticulo[50];
    float precioArticulo;
    int cantidadArticulo;
    int encontrado = 0;

    while (fscanf(archivoEntrada, "%d,%49[^,],%f,%d", &idArticulo, nombreArticulo, &precioArticulo, &cantidadArticulo) != EOF) {
        if (idArticulo == idModificar) {
            encontrado = 1;
            printf("Artículo encontrado. Ingrese los nuevos datos:\n");

            // Pide al usuario que ingrese los nuevos datos
            printf("Ingrese el nuevo nombre del artículo: \n");
            scanf("%s", nombreArticulo);
            printf("Ingrese el nuevo precio del artículo: \n");
            scanf("%f", &precioArticulo);
            printf("Ingrese la nueva cantidad del artículo: \n");
            scanf("%d", &cantidadArticulo);
        }

        fprintf(archivoSalida, "%d,%s,%.2f,%d\n", idArticulo, nombreArticulo, precioArticulo, cantidadArticulo);
    }

    fclose(archivoEntrada);
    fclose(archivoSalida);

    // Elimina el archivo original y renombra el temporal
    remove("Articulos.txt");
    rename("Articulos_temp.txt", "Articulos.txt");

    if (encontrado) {
        printf("Artículo modificado con éxito\n\n");
    } else {
        printf("Artículo no encontrado\n\n");
    }

    return 0;
}

int main() {
    modificarArticulo();
    return 0;
}


int eliminarArticulo() {
    int idEliminar;

    printf("Artículos existentes: \n");
    verArticulos();

    printf("Ingrese el ID del artículo a eliminar: \n");
    scanf("%d", &idEliminar);

    FILE *archivoEntrada, *archivoSalida;
    archivoEntrada = fopen("Articulos.txt", "r");
    archivoSalida = fopen("Articulos_temp.txt", "w");

    if (archivoEntrada == NULL || archivoSalida == NULL) {
        fprintf(stderr, "Error al abrir archivos\n");
        return 1;
    }

    int idArticulo;
    char nombreArticulo[50];
    float precioArticulo;
    int cantidadArticulo;

    while (fscanf(archivoEntrada, "%d,%49[^,],%f,%d\n", &idArticulo, nombreArticulo, &precioArticulo, &cantidadArticulo) == 4) {
        if (idArticulo != idEliminar) {
            fprintf(archivoSalida, "%d,%s,%.2f,%d\n", idArticulo, nombreArticulo, precioArticulo, cantidadArticulo);
        }
    }

    fclose(archivoEntrada);
    fclose(archivoSalida);

    remove("Articulos.txt");
    rename("Articulos_temp.txt", "Articulos.txt");

    printf("Artículo eliminado con éxito\n\n");

    return 0;
}

int anadirArticulo() {
    int idArticulo;
    char nombreArticulo[50];
    float precioArticulo;
    int cantidadArticulo;

    printf("Ingrese el ID del artículo: \n");
    scanf("%d", &idArticulo);
    printf("Ingrese el nombre del artículo: \n");
    scanf("%s", nombreArticulo);
    printf("Ingrese el precio del artículo: \n");
    scanf("%f", &precioArticulo);
    printf("Ingrese la cantidad del artículo: \n");
    scanf("%d", &cantidadArticulo);
    printf("\n");

    FILE *archivoAnadirArticulos;
    archivoAnadirArticulos = fopen("Articulos.txt", "a");

    if (archivoAnadirArticulos == NULL) {
        fprintf(stderr, "No se pudo abrir el archivo\n");
        return 1;
    }

    fprintf(archivoAnadirArticulos, "%d,%s,%.2f,%d\n", idArticulo, nombreArticulo, precioArticulo, cantidadArticulo);

    fclose(archivoAnadirArticulos);

    printf("Artículo agregado con éxito\n\n");

    return 0;
}

int menuCliente(){

    return 0;
}

int main(){
    menuRoles();
    return 0;
}