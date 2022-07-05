### Remake Dune 2000

## Equipo de desarrollo

| Nombre y apellido | Padrón | Mail | GitHub |
|-------------------|--------|------|--------|
| Santiago Nahuel Ruiz Sugliani | 106768 | sruizs@fi.uba.ar | [ruizsugliani](https://github.com/ruizsugliani) |
| Joaquín Velazquez | 105980 | jvelazquez@fi.uba.ar | [jm-velazquez](https://github.com/jm-velazquez) |
| Lautaro Gabriel Ghosn | 106998 | lghosn@fi.uba.ar | [LGhosn](https://github.com/LGhosn) |

## Sistema operativo
**Ubuntu 20.04 LTS**

## Dependencias necesarias
**YAML-CPP**: seguir las instrucciones desde el subtítulo `How to build` del [repositorio original](https://github.com/jbeder/yaml-cpp).

**SDL2PP**: hay que instalar el [release 0.16.2](https://github.com/libSDL2pp/libSDL2pp/releases/tag/0.16.2) y para su instalación seguir las instrucciones del [repositorio original](https://github.com/libSDL2pp/libSDL2pp) a partir del subtitulo `Building` e `Installation`.

**QT5**: ingresar las siguientes líneas en la consola (las últimas tres corresponden a la documentación):
```
sudo apt-get install build-essential
sudo apt-get install qtcreator
sudo apt-get install qt5-default
sudo apt-get install qt5-doc
sudo apt-get install qt5-doc-html qtbase5-doc-html
sudo apt-get install qtbase5-examples
```

## Instalación
Para instalar el juego se provee del script installer.sh que corre en bash. Se debe ejecutar:
```
$ ./installer.sh
```
Si fallan los permisos, se le deberán conceder los mismos ejecutando:
```
$ chmod +x ./installer.sh
```
Una vez que la instalación haya finalizado, se puede abrir el cliente corriendo:
``
$ ClientDune2000 localhost <puerto>
``
donde `<puerto>` es un parámetro que representa el puerto en que queremos abrir el servidor.

Para lanzar el servidor hacer:
```
$ ServerDune2000 <puerto>
```
donde `<puerto>` es un parámetro que representa el puerto en que queremos abrir el servidor.

## Como lanzar el servidor
1. Abrir la terminal de Linux dentro de la carpeta `build`
2. Ejecutar el comando `cmake .. && make`.
3. Escribir la siguiente linea: ```./ServerDune2000 <port>``` donde `<port>` se reemplaza por el puerto en donde queramos que el servidor escuche nuevas conexiones.

Para terminarlo, simplemente presionar `Ctrl + C`.

## Como lanzar el cliente
1. Abrir la terminal de Linux dentro de la carpeta `build`.
2. Ejecutar el comando ```cmake .. && make```.
3. Escribir la siguiente linea: ```./ClientDune2000 <address> <port>``` donde `<address>` se reemplaza por la IP del servidor al que queramos conectarnos, y el `<port>` por el puerto de ese servidor que reciba conexiones.

## Como lanzar el editor
1. Abrir la terminal de Linux dentro de la carpeta `build`
2. Ejecutar el comando ```cmake .. && make```.
3. Escribir la siguiente linea: ```./DuneEditorDeMapas```.
4. Listo! Se abrirá la interfaz del editor en la cual se deberá elegir si queremos crear un mapa nuevo o editar uno existente.

## Creación de un nuevo mapa
1. Se nos presenta una pequeña ventana la cual nos pide indicar el modo de edición, en caso de seleccionar "Crear un nuevo mapa" se mostrarán los parámetros para el mismo, en caso de seleccionar "Editar un mapa existente", simplemente clickear en "Continuar".
1a. Luego de elegir la opción de crear un mapa debemos elegir la cantidad de jugadores (máxima) la cual queremos que puedan jugar en este mapa y las dimensiones del mismo (inicialmente un mapa sería de 25x25 y puede agrandarse hasta 250x250).
2. Para ambos casos de edición, tras presionar "Continuar", se mostrará la interfaz del editor en la cual podremos observar los parámetros elegidos y los tipos de terreno los cuales podremos elegir, luego de elegir uno de los mismos podremos elegir entre las distintas texturas disponibles clickeando en la lista desplegable o posicionando el mouse sobre la misma y girando la ruedita del mouse (recomendamos hacer esto para poder ver la textura si tener que desplegar la lista de texturas).
3. Cuando el usuario esté listo para guardar el mapa, el mismo deberá clickear en "Guardar" , en caso de no haberse situado los centros para cada jugador, será notificado, también lo será si quiere ponerle como nombre al mapa que crea, el de uno ya existente.
4. Para salir, simplemente clickear en la cruz de la esquina superior derecha.

## Como se juega
Con el cliente ya lanzado, se tiene dos opciones: crear partida, o unirse a una existente.
Luego de hacer click en “Crear partida”, se desplegará un menú con todas las opciones. Antes de presionar “Crear”, se tiene que asegurar de haber seleccionado casa, nombre, mapa, y cantidad de jugadores. Luego se quedará esperando hasta que se unan los jugadores requeridos a la partida. Cuando esto suceda se lanzará la ventana del juego en sí.
En el caso de “Unirse a una partida”, se lanzará otro menú con el nombre de partida, y la casa a elegir. Una vez seleccionado todo, al apretar “Unirse” se espera a que se llene la partida, al igual que al crear. Cuando se complete la cantidad de jugadores necesarios se lanza el juego.

Una vez en el juego, se puede salir presionando “Esc” o cerrando la ventana. En el menú derecho se encontrará todos los edificios que se pueden construir, y las unidades/vehiculos que se pueden obtener.

Para hacer aparecer una unidad requerimos de tener los edificios necesarios para la misma, sabremos cuando podemos hacerla aparecer cuando el botón de la misma no esté oscuro, cuando ésta unidad se esté entrenando nos enteraremos de su aparición mediante un comando de voz, al igual que si la seleccionamos y movemos.

Para atacar otras unidades deberemos seleccionar las nuestras con click izquierdo y luego la unidad enemiga con click derecho, la misma operación se lleva a cabo para atacar edificios enemigos.

---------------------------------------------------------------------------------------------------------------------------------------------------------
## [Manuales de Proyecto y Documentación Técnica disponibles](https://drive.google.com/drive/folders/1i1DJQOORScO8AFi8x2nMgytjtSEab5Kv?usp=sharing)
