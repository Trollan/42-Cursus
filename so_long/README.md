<!DOCTYPE html>
<html>

<head>
    <title>So_Long</title>
</head>

<body>
    <h2>So_Long es un proyecto del programa 42 de Telefónica que consiste en la implementación de un juego 2D simple
        utilizando la biblioteca gráfica minilibX. El objetivo del juego es que el jugador controle un personaje y
        recolecte todos los objetos presentes en el nivel para completarlo.</h2>

    <h2>Este proyecto está desarrollado en lenguaje C y se ejecuta en el sistema operativo Unix/Linux.</h2>

    <h3>Funcionalidades</h3>
    <ul>
        <li>Visualización de un mapa en una ventana gráfica.</li>
        <li>Movimiento del personaje a través del mapa.</li>
        <li>Recolección de objetos presentes en el mapa.</li>
        <li>Conteo de movimientos y objetos recolectados.</li>
        <li>Salida del juego una vez se hayan recolectado todos los objetos.</li>
    </ul>

    <h3>Requisitos del sistema</h3>
    <p>Para compilar y ejecutar el proyecto, necesitarás tener instalado lo siguiente:</p>
    <ul>
        <li>Sistema operativo Unix/Linux.</li>
        <li>Compilador GCC.</li>
        <li>Biblioteca gráfica minilibX.</li>
    </ul>

    <h3>Instrucciones de instalación</h3>
    <p>Clona este repositorio en tu máquina local:</p>
    <pre><code>git clone https://github.com/tu_usuario/so_long.git</code></pre>
    <p>Navega hasta el directorio del proyecto:</p>
    <pre><code>cd so_long</code></pre>
    <p>Compila el proyecto utilizando el Makefile:</p>
    <pre><code>make</code></pre>
    <p>Esto generará un ejecutable llamado "so_long".</p>

    <h3>Instrucciones de uso</h3>
    <p>Una vez hayas compilado el proyecto, puedes ejecutar el juego con el siguiente comando:</p>
    <pre><code>./so_long map.ber</code></pre>
    <p>Reemplaza "map.ber" con el nombre del archivo de mapa que deseas cargar. Asegúrate de que el archivo de mapa esté en
        el formato adecuado.</p>
    <p>A continuación, podrás ver el juego en una ventana gráfica. Utiliza las teclas de dirección (WASD o las flechas) para
        mover al personaje por el mapa. El objetivo es recolectar todos los objetos ('C') y llegar a la salida ('E') para
        completar el nivel.</p>
    <p>El juego mostrará la cantidad de movimientos realizados y la cantidad de objetos recolectados en la parte superior de
        la ventana.</p>

    <h3>Estructura del proyecto</h3>
    <p>El proyecto está organizado de la siguiente manera:</p>
    <pre><code>so_long/
  ├── inc/          # Archivos de cabecera
  ├── libft/        # Biblioteca de funciones auxiliares
  ├── maps/           # Archivos de mapa de ejemplo
  ├── mlx/          # Biblioteca gráfica minilibX
  ├── src/          # Archivos fuente
  ├── Makefile      # Archivo para compilar el proyecto
  └── so_long       # Ejecutable del juego
</code></pre>

<h3>Contribución</h3>
<p>Si deseas contribuir a este proyecto, puedes realizar un fork del repositorio, hacer tus modificaciones y enviar una solicitud de pull. Agradecemos cualquier mejora o corrección de errores que puedas aportar.</p>

<h3>Licencia</h3>
<p>Este proyecto se distribuye bajo la licencia MIT. Puedes consultar el archivo LICENSE para obtener más información.</p>

<h3>Contacto</h3>
<p>Si tienes alguna pregunta o sugerencia sobre el proyecto, puedes contactar conmigo a través de mi dirección de correo electrónico <a href="mailto:tu_correo@example.com">tu_correo@example.com</a>.</p>

<p>¡Disfruta del juego!</p>
</body>

</html>
