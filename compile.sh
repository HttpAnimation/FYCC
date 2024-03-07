# compile.sh
echo "Compileing"
echo "Script | READJSON.c"
gcc `pkg-config --cflags gtk+-3.0` -o TestReadJson ReadJSON.c `pkg-config --libs gtk+-3.0`
echo "Done"
echo "Script | READConf.c"
gcc `pkg-config --cflags gtk+-3.0` -o TestReadConf READConf.c `pkg-config --libs gtk+-3.0`