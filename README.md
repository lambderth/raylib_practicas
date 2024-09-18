# Prácticas raylib.
Introducción al desarrollo de videojuegos en lenguaje C.

### Prerrequisitos:
- Descargar e instalar [Code::Blocks](https://www.codeblocks.org/).
- Descargar e instalar [raylib](https://www.raylib.com/index.html).

### Configuración en Code::Blocks:
1. Abrir Code::Blocks e ir a "Settings > Compiler...".

![Paso 1](setup_tutorial/images/1.png)

2. Seleccionar cualquier compilador y haz click en "Copy".

![Paso 2](setup_tutorial/images/2.png)

3. Agrega un nombre para el nuevo compilador.

![Paso 3](setup_tutorial/images/3.png)
![Paso 3.1](setup_tutorial/images/4.png)

4. En la pestaña de "Toolchain executables" estableces el directorio de instalación del compilador. Este debe apuntar a donde se encuentra la carpeta "bin" la cual contiene los compiladores. La ruta predeterminada es "C:\raylib\w64devkit".
   
![Paso 4](setup_tutorial/images/5.png)

5. En la pestaña de "Search directories", seleccionar la pestaña de "Compiler" y agregar la ruta hacia la carpeta "include". La ruta predeterminada es "C:\raylib\w64devkit\x86_64-w64-mingw32\include".

![Paso 6](setup_tutorial/images/6.png)

6. En la pestaña de "Search directories", seleccionar la pestaña de "Linker" y agregar la ruta hacia la carpeta "lib". La ruta predeterminada es "C:\raylib\w64devkit\x86_64-w64-mingw32\lib".

![Paso 7](setup_tutorial/images/7.png)

7. En la pestaña de "Linker settings", Agregar las siguientes librerias que se encuentran en la carpeta lib. La ruta predeterminada donde se encuentran las librerias es "C:\raylib\w64devkit\x86_64-w64-mingw32\lib".
   - librarylib.a
   - libopengl32.a
   - libgdi32.a
   - libwinmm.a
   - libm.a
   - libcomdlg32.a
   - libole32.a

![Paso 8](setup_tutorial/images/8.png)

8. Click OK.
9. Abrir la práctica 1 de este repo.

![Paso 9](setup_tutorial/images/9.png)
![Paso 10](setup_tutorial/images/10.png)

10. Click derecho en el proyecto y seleccionar "Build options...".

![Paso 11](setup_tutorial/images/11.png)

11. Seleccionar el proyecto (Debug, Release o el proyecto completo) y asegurarse de que el compilador seleccionado sea el configurado previamente.

![Paso 12](setup_tutorial/images/12.png)

12. Compilar y correr el proyecto :).

![Paso 13](setup_tutorial/images/13.png)
