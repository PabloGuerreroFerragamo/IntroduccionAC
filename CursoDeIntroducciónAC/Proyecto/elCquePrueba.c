#include <stdio.h>

int modificarProveedores() {
    int idModificar;
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

int main() {
    // Llama a la función modificarProveedores desde tu programa principal
    modificarProveedores();

    return 0;
}
