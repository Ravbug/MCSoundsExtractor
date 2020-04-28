# flags needed to build the target (compiler, target name, and compiler flags)
CC = c++
WXROOT := wxWidgets
CFLAGS := `$(WXROOT)/build/linux/wx-config --cxxflags --libs` -Wl,-rpath,$(WXROOT)/build/linux/lib/ -std=gnu++17 -lstdc++fs -I./rapidjson/include
target = MinecraftSoundsExtractor

# location of source files
source_dir = source
build_dir = linux-build

# library build information
lib_build_path = $(WXROOT)/build/linux
lib_file_detect = Makefile

# derives names of object files (only looks at .cpp files)
sources := $(shell cd $(source_dir) && find . -type f -name '*.cpp' -printf "$(build_dir)/%f ")
objects := $(subst .cpp,.o,$(sources))

debug:
	@make --no-print-directory mode=-g all
	
release:
	@make --no-print-directory mode=-O3 all
	
linux-pkg:
	@make --no-print-directory release
	name=$(target) build_dir=$(build_dir) src=$(source_dir) lib_dir=$(lib_build_path)/lib ./linux-pkg.sh

# Compiles the app, and the library if needed. Uses all the available processor cores.
all: $(lib_build_path)/$(lib_file_detect)
	@make --no-print-directory $(build_dir)/$(target) -j$(shell nproc)

# link the object files together into the executable
$(build_dir)/$(target): $(objects)
	$(CC) $(mode) -o $@ $^ $(CFLAGS)

# compile object files from source files
# This only looks at changes in the .cpp files, so if headers are modified, a rebuild is needed.
$(build_dir)/%.o: $(source_dir)/%.cpp
	mkdir -p $(build_dir)
	$(CC) $(CFLAGS) $(mode) $(CPPFLAGS) -c -o $@ $<
	
# build the library
$(lib_build_path)/$(lib_file_detect): $(lib_build_path)/$(lib_file_detect)
	./setup-linux.sh

# remove the build folder
clean:
	rm -rf $(build_dir)
	
clean-library:
	rm -rf $(WXROOT)/build/linux/
	
clean-all: clean clean-library
	
# launch the app
run: debug
	@./$(build_dir)/$(target)

