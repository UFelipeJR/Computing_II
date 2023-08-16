# Fundamentos c++

* Lenguaje de maquina

```c++
1010010001
1010101010
1001000100
```

* Lenguaje de programación de bajo nivel

* Ventajas
    * El programa optimiza el uso de los recursos de la maquina.
    * Programas veloces en ejecución.

* Desventajas
    * Dependiente de la maquina. (No portables).
    * Necesidad de conocimientos avanzados tanto de programación como de la maquina.

Ejemplo de Assembly
```c++
MOV AX, @data;
MOV DS, AX;
MOV DX, offset;
MOV Ah,9;
INT 21h;
```