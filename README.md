## Hi there 👋
чтобы запустить библиотеку, введите в командную строку 
C:\Users\пользователь>cd C:\Users\пользователь\Desktop\папка
echo. > mylib.h
gcc -c list.c -o list.o
gcc -c tree.c -o tree.o
ar rcs libmylib.a list.o tree.o
gcc laba3.c -L. -lmylib -o program
program.exe
gcc dop.c -L. -lmylib -o dop.exe
dop.exe flight_data10.bin
























































