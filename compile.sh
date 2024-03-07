# compile.sh
echo "Compileing"
gcc `pkg-config --cflags gtk+-3.0` -o TestReadJson json_reader.c `pkg-config --libs gtk+-3.0`
echo "Done"