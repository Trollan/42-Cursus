# So_Long

So_Long is a project within Telefónica's 42 program, which involves the implementation of a simple 2D game using the minilibX graphics library. The objective of the game is for the player to control a character and collect all the objects present in the level to complete it.

This project is developed in the C language and runs on the Unix/Linux operating system.

## 🎮 Features
Displaying a map in a graphical window.
Movement of the character across the map.
Collecting objects present on the map.
Counting movements and collected objects.
Exiting the game once all objects have been collected..

## ⚙️ System Requirements
To compile and run the project, you will need to have the following installed:

- Unix/Linux operating system.
- GCC compiler.
- minilibX graphics library.

## 🚀 Installation Instructions
Clone this repository to your local machine:
```
git clone https://github.com/trollan/so_long.git
```
Navigate to the project directory:
```
cd so_long
```
Compile the project using the Makefile:
```
make
```
This will generate an executable called "so_long".

## 💡 Usage Instructions
Once you have compiled the project, you can run the game with the following command:
```
./so_long maps/map.ber
```
Replace "map.ber" with the name of the map file you want to load. Make sure the map file is in the correct format.

You will then see the game in a graphical window. Use the arrow keys (WASD or the arrows) to move the character around the map. The goal is to collect all the objects ('C') and reach the exit ('E') to complete the level.

The game will display the number of movements made and the number of objects collected at the top of the window.

## 📁 Project Structure
The project is organized as follows:
```
so_long/
  ├── ft_printf     # 📚 Auxiliary ft_printf function library
  ├── get_next_line # 📚 Auxiliary get_next_line function library
  ├── libft/        # 📚 Auxiliary function library
  ├── maps/         # 🗺️ Example map files
  ├── mlx/          # 🎨 minilibX graphics library
  ├── Makefile      # 🛠️ File for compiling the project
  └── so_long       # ▶️ Game executable
```

## 📧 Contact
If you have any questions or suggestions about the project, you can contact me via email at manuelsanchezies@gmail.com.

Enjoy the game!

