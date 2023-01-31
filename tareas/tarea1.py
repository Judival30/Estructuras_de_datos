"""
Tarea 1, curso Estructuras de datos 2023-1, 3/02/2023
Este modulo contiene las soluciones de la tarea 1.
Juan Diego Valencia Alomia 
codigo: 8977467

"""

#punto 1
def verificarDiagonales(mat):
    """
    Esta función verifica si las diagonales de una matriz cuadrada son iguales
    Args:
        mat ([list]): matriz cuadrada
    Returns:
        [bool]: Verdadero si son iguales, falso si no lo son
    """
    ans = True
    for i in range(len(mat)):
        if not mat[i][i] == mat[i][-i - 1]:
            ans = False
    return ans
    
 
#punto 2
def esCapicua(lista):
    """
    Esta función muestra si los valores de una lista son una secuencia capicua
    Args:
        lista ([list]): lista de enteros
    Returns:
        [bool]: Verdadero si es capicua, falso si no lo es
    """
    ans = True
    for i in range(len(lista)):
        if not lista[i] == lista[-i - 1]:
            ans = False
    return ans


#punto 3
#parte (3a)
def diferenciaListas(listaA, listaB):
    """
    La función muestra la diferencia entre los valores de la listaA y la B
    Args:
        listaA ([list]): lista de enteros
        listaB ([type]): lista de enteros
    Returns:
        [list]: Lista con los numeros que estan en la listaA y no en la listaB
    """
    resultado = []
    # Recorrer la lista A
    for varA in listaA:
        # verificar si el valor no esta en la listaB
        if not varA in listaB:
            resultado.append(varA)
        else:
            listaB.remove(varA)
    return resultado
    
   
#parte(3b)
def leerImprimir():
    """La función imprime muestra la diferencia de los valores ingresados
    """
    nEjecuciones = int(input())
    for i in range(nEjecuciones):
        var1 = input()
        var2 = input()
        lista1 = var1.split(" ")
        lista2 = var2.split(" ")
        lista1.pop(0)
        lista2.pop(0)
        resultado = diferenciaListas(lista1, lista2)
        for j in range(len(resultado)):
            if j == len(resultado) - 1:
                print(resultado[j])
            else:
                print(resultado[j], end=", ")


#Punto 4
def mostrarPrimos(n):
    """
    La función imprime los numeros primos entre 1 y n, posteriormente imprime
    los primos con suma de digitos primos.
    Args:
        n ([int]): entero mayor a 1
    """
    listaPrimos = []
    for i in range(2, n + 1):
        if (esPrimo(i)):
            listaPrimos.append(i)
    for m in range(len(listaPrimos)):
        if m == len(listaPrimos) - 1:
            print("-->", listaPrimos[m])
        else:
            print("-->", listaPrimos[m], end=",")
            print()
    print()
    print("Números entre 1 y", n, "con suma de dígitos con valor primo:")
    sumaPrimo = []
    for j in range(len(listaPrimos)):
        suma = 0
        for digitosSumar in str(listaPrimos[j]):
            suma += int(digitosSumar)
        if (esPrimo(suma)):
            sumaPrimo.append(listaPrimos[j])
    for k in range(len(sumaPrimo)):
        if k == len(sumaPrimo) - 1:
            print(sumaPrimo[k])
        else:
            print(sumaPrimo[k], end=", ")


#Punto 5
def sumarValoresMatriz(mat, par):
    """
    La función muestra la suma de los valores en las cordenadas ingresadas de la matiz dispersa
    Args:
        mat ([dict]): diccionario que contiene la información de una matriz dispersa
        par ([list]): lista con tuplas que contienen las coordenadas
    Returns:
        [int]: Suma de los valores de la matriz
    """
    suma = 0
    # Obtener los keys del dic
    for i in mat:
        # Obtener los valores (listas)
        for j in range(len(mat[i])):
            # Generar una tupla con la cual se va a comparar con la lista par
            var = (i, mat[i][j][0])
            for puntos in par:
                # Verificar si la tupla está en la lista que se ingreso
                if var == puntos:
                    # Si está entonces sumar el valor de la matriz
                    suma += mat[i][j][1]
    return suma
   
