Asegurarse de tener todos los archivos en el repositorio local (incluidas las 4 melodias)
Abrir la terminal ctrl+alt+t
ir a la carpeta donde se encuentra el repositorio local
ejecutar sudo ./install_mplayer.sh
una vez instalado mplayer, ejecutar dentro del path del repositorio local ./cancion
En caso de que no se ejecute, escribir en la terminal gcc sugar_tututu.c -o cancion -lpthread
luego ejecutar  ./cancion

para el codigo de astros se encuentra el archivo seccionCritica.c junto con el archivo astros. 
ejectar en la terminal ./astros o primero compilar con gcc seccionCritica.c -o astros -lpthread y luego ejecutar

agregado una version de seccionCritica con mutex version compilada es "./seccion"
