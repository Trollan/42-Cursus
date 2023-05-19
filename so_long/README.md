# So_Long
![Logo de So_Long](logo.png)

So_Long es un proyecto del programa 42 de Telefónica que consiste en la implementación de un juego 2D simple utilizando la biblioteca gráfica minilibX. El objetivo del juego es que el jugador controle un personaje y recolecte todos los objetos presentes en el nivel para completarlo.

Este proyecto está desarrollado en lenguaje C y se ejecuta en el sistema operativo Unix/Linux.

## Funcionalidades
- Visualización de un mapa en una ventana gráfica.
- Movimiento del personaje a través del mapa.
- Recolección de objetos presentes en el mapa.
- Conteo de movimientos y objetos recolectados.
- Salida del juego una vez se hayan recolectado todos los objetos.

## Requisitos del sistema
Para compilar y ejecutar el proyecto, necesitarás tener instalado lo siguiente:
- Sistema operativo Unix/Linux.
- Compilador GCC.
- Biblioteca gráfica minilibX.

## Instrucciones de instalación
Clona este repositorio en tu máquina local:
bash
git clone https://github.com/tu_usuario/so_long.git
Navega hasta el directorio del proyecto:

bash
Copy code
cd so_long
Compila el proyecto utilizando el Makefile:

bash
Copy code
make
Esto generará un ejecutable llamado "so_long".

Instrucciones de uso
Una vez hayas compilado el proyecto, puedes ejecutar el juego con el siguiente comando:

bash
Copy code
./so_long map.ber
Reemplaza "map.ber" con el nombre del archivo de mapa que deseas cargar. Asegúrate de que el archivo de mapa esté en el formato adecuado.

A continuación, podrás ver el juego en una ventana gráfica. Utiliza las teclas de dirección (WASD o las flechas) para mover al personaje por el mapa. El objetivo es recolectar todos los objetos ('C') y llegar a la salida ('E') para completar el nivel.

El juego mostrará la cantidad de movimientos realizados y la cantidad de objetos recolectados en la parte superior de la ventana.

Estructura del proyecto
El proyecto está organizado de la siguiente manera:

bash
Copy code
so_long/
  ├── inc/          # Archivos de cabecera
  ├── libft/        # Biblioteca de funciones auxiliares
  ├── maps/         # Archivos de mapa de ejemplo
  ├── mlx/          # Biblioteca gráfica minilibX
  ├── src/          # Archivos fuente
  ├── Makefile      # Archivo para compilar el proyecto
  └── so_long       # Ejecutable del juego
Contribución
Si deseas contribuir a este proyecto, puedes realizar un fork del repositorio, hacer tus modificaciones y enviar una solicitud de pull. Agradecemos cualquier mejora o corrección de errores que puedas aportar.

Licencia
Este proyecto se distribuye bajo la licencia MIT. Puedes consultar el archivo LICENSE para obtener más información.

Contacto
Si tienes alguna pregunta o sugerencia sobre el proyecto, puedes contactar conmigo a través de mi dirección de correo electrónico tu_correo@example.com.

¡Disfruta del juego!

