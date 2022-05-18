## Que se puede esperar de este tutorial?

Este repo contiene dos ejemplos prácticos de como implementar
un cliente y un servidor TCP wrappeando/encapsulando
un `socket` en C++.

El código esta fuertemente documentado así como también los commits
de este repo.

El primer y mas antiguo commit es una implementación completa usando sintaxis
y convenciones de C y no de C++.

Los subsiguientes commits van poco a poco modificando las estructuras
de C y llevándolas a clases de C++ con conceptos mas elaborados como
RAII (Resource Acquisition is Initialization), Move Semantics y
Excepciones.

La idea es partir de C y llegar a código profesional de C++ que protege
los recursos y chequea errores.

Sin embargo no debe considerarse el código final como el perfecto: se
han omitido ciertos detalles con el fin de simplificar el código y
hacerlo mas entendible.

El lector puede, si lo desea, ir un paso mas allá y extender el código
C++ con:

 - métodos que reciban no solo punteros raw (buffers) sino también
   `std::vector<char>`. Por ejemplo `Socket::sendsome(const
std::vector<char> &buf, ...)`
 - extension de `Socket` para que soporte no solamente TCP sino también
   UDP. Incluso, otros tipos de sockets fuera de la familia de IP como
   los sockets UNIX.

## Como leer este tutorial?

Usa `git log` para ver el listado de commits. Podes ver el código en
cada paso haciendo `git checkout <commit hash>`.

Podes ver que cosas se cambiaron entre un commit y el anterior haciendo
`git log --patch`. Así podrás ver los cambios de cada commit y también
el mensaje del commit que explica el por que.

Te recomiendo que empieces checkouteando el mas antiguo de los commits,
el que implementa los sockets *"a la C"*. Lee el codigo y sus
comentarios.

Luego checkoutea el commit que le sigue y mira que cambio y cual es el
mensaje del commit.

En todo momento podrás correr `git checkout master` para ir al commit
mas nuevo.

## Como compilar?

Simplemente `make`

## Licencia

GPL v2

## Puedo usar este código en el Trabajo Práctico?

Si, pero tenes que decir de donde lo sacaste y respetar la licencia.

Ademas tenes que recordad que este código es parte de un tutorial y
aunque trata de ser exacto y correcto, no esta libre de simplificaciones
que en el Trabajo Práctico pueden ser exigidos.

En todo momento seras responsable ya que la inclusion parcial o total
de este código y su uso es decision tuya.
