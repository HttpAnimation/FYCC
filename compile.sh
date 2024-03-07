# compile.sh
echo "Compileing"
gcc `pkg-config --cflags gtk+-3.0` -o json_reader json_reader.c `pkg-config --libs gtk+-3.0`
echo "Done"