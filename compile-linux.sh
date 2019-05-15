root="wxWidgets/";
path="build/linux/app/";
name="wxTemplateLinux";

mkdir -p $root$path;

# Compile dynamic linking
g++ `wx-config --cppflags` `wx-config --libs` -Wl,-rpath,/usr/local/lib/ -o $root$path$name source/*.cpp source/*.h &&

# print success

echo "    Build succeeded. Wrote executable to" $root$path$name;

# launch application if flag present

while getopts ":r" OptionArgument; do
case $OptionArgument in
	
	r ) echo "Launching $name"; ./$root$path$name ;;
	* ) echo "Unknown argument passed. Use -r to launch the program after successful compile";;
esac
done


# Compile static linking
#g++ `wx-config --static --cppflags` `wx-config --static --libs` -I wxWidgets/include/ -I wxWidgets/build/linux/lib/wx/include/gtk3-unicode-3.1 -o wxTemplate source/main.cpp

