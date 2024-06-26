# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /COMP371/Project/rainscene

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /COMP371/Project/rainscene/build

# Include any dependencies generated for this target.
include CMakeFiles/rainscene.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/rainscene.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/rainscene.dir/flags.make

CMakeFiles/rainscene.dir/src/main.cpp.o: CMakeFiles/rainscene.dir/flags.make
CMakeFiles/rainscene.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/COMP371/Project/rainscene/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/rainscene.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/rainscene.dir/src/main.cpp.o -c /COMP371/Project/rainscene/src/main.cpp

CMakeFiles/rainscene.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rainscene.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /COMP371/Project/rainscene/src/main.cpp > CMakeFiles/rainscene.dir/src/main.cpp.i

CMakeFiles/rainscene.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rainscene.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /COMP371/Project/rainscene/src/main.cpp -o CMakeFiles/rainscene.dir/src/main.cpp.s

CMakeFiles/rainscene.dir/src/Mesh.cpp.o: CMakeFiles/rainscene.dir/flags.make
CMakeFiles/rainscene.dir/src/Mesh.cpp.o: ../src/Mesh.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/COMP371/Project/rainscene/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/rainscene.dir/src/Mesh.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/rainscene.dir/src/Mesh.cpp.o -c /COMP371/Project/rainscene/src/Mesh.cpp

CMakeFiles/rainscene.dir/src/Mesh.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rainscene.dir/src/Mesh.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /COMP371/Project/rainscene/src/Mesh.cpp > CMakeFiles/rainscene.dir/src/Mesh.cpp.i

CMakeFiles/rainscene.dir/src/Mesh.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rainscene.dir/src/Mesh.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /COMP371/Project/rainscene/src/Mesh.cpp -o CMakeFiles/rainscene.dir/src/Mesh.cpp.s

CMakeFiles/rainscene.dir/src/Shader.cpp.o: CMakeFiles/rainscene.dir/flags.make
CMakeFiles/rainscene.dir/src/Shader.cpp.o: ../src/Shader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/COMP371/Project/rainscene/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/rainscene.dir/src/Shader.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/rainscene.dir/src/Shader.cpp.o -c /COMP371/Project/rainscene/src/Shader.cpp

CMakeFiles/rainscene.dir/src/Shader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rainscene.dir/src/Shader.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /COMP371/Project/rainscene/src/Shader.cpp > CMakeFiles/rainscene.dir/src/Shader.cpp.i

CMakeFiles/rainscene.dir/src/Shader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rainscene.dir/src/Shader.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /COMP371/Project/rainscene/src/Shader.cpp -o CMakeFiles/rainscene.dir/src/Shader.cpp.s

CMakeFiles/rainscene.dir/src/Window.cpp.o: CMakeFiles/rainscene.dir/flags.make
CMakeFiles/rainscene.dir/src/Window.cpp.o: ../src/Window.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/COMP371/Project/rainscene/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/rainscene.dir/src/Window.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/rainscene.dir/src/Window.cpp.o -c /COMP371/Project/rainscene/src/Window.cpp

CMakeFiles/rainscene.dir/src/Window.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rainscene.dir/src/Window.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /COMP371/Project/rainscene/src/Window.cpp > CMakeFiles/rainscene.dir/src/Window.cpp.i

CMakeFiles/rainscene.dir/src/Window.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rainscene.dir/src/Window.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /COMP371/Project/rainscene/src/Window.cpp -o CMakeFiles/rainscene.dir/src/Window.cpp.s

CMakeFiles/rainscene.dir/src/Camera.cpp.o: CMakeFiles/rainscene.dir/flags.make
CMakeFiles/rainscene.dir/src/Camera.cpp.o: ../src/Camera.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/COMP371/Project/rainscene/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/rainscene.dir/src/Camera.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/rainscene.dir/src/Camera.cpp.o -c /COMP371/Project/rainscene/src/Camera.cpp

CMakeFiles/rainscene.dir/src/Camera.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rainscene.dir/src/Camera.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /COMP371/Project/rainscene/src/Camera.cpp > CMakeFiles/rainscene.dir/src/Camera.cpp.i

CMakeFiles/rainscene.dir/src/Camera.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rainscene.dir/src/Camera.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /COMP371/Project/rainscene/src/Camera.cpp -o CMakeFiles/rainscene.dir/src/Camera.cpp.s

CMakeFiles/rainscene.dir/src/Texture.cpp.o: CMakeFiles/rainscene.dir/flags.make
CMakeFiles/rainscene.dir/src/Texture.cpp.o: ../src/Texture.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/COMP371/Project/rainscene/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/rainscene.dir/src/Texture.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/rainscene.dir/src/Texture.cpp.o -c /COMP371/Project/rainscene/src/Texture.cpp

CMakeFiles/rainscene.dir/src/Texture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rainscene.dir/src/Texture.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /COMP371/Project/rainscene/src/Texture.cpp > CMakeFiles/rainscene.dir/src/Texture.cpp.i

CMakeFiles/rainscene.dir/src/Texture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rainscene.dir/src/Texture.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /COMP371/Project/rainscene/src/Texture.cpp -o CMakeFiles/rainscene.dir/src/Texture.cpp.s

CMakeFiles/rainscene.dir/src/Light.cpp.o: CMakeFiles/rainscene.dir/flags.make
CMakeFiles/rainscene.dir/src/Light.cpp.o: ../src/Light.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/COMP371/Project/rainscene/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/rainscene.dir/src/Light.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/rainscene.dir/src/Light.cpp.o -c /COMP371/Project/rainscene/src/Light.cpp

CMakeFiles/rainscene.dir/src/Light.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rainscene.dir/src/Light.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /COMP371/Project/rainscene/src/Light.cpp > CMakeFiles/rainscene.dir/src/Light.cpp.i

CMakeFiles/rainscene.dir/src/Light.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rainscene.dir/src/Light.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /COMP371/Project/rainscene/src/Light.cpp -o CMakeFiles/rainscene.dir/src/Light.cpp.s

CMakeFiles/rainscene.dir/src/Material.cpp.o: CMakeFiles/rainscene.dir/flags.make
CMakeFiles/rainscene.dir/src/Material.cpp.o: ../src/Material.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/COMP371/Project/rainscene/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/rainscene.dir/src/Material.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/rainscene.dir/src/Material.cpp.o -c /COMP371/Project/rainscene/src/Material.cpp

CMakeFiles/rainscene.dir/src/Material.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rainscene.dir/src/Material.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /COMP371/Project/rainscene/src/Material.cpp > CMakeFiles/rainscene.dir/src/Material.cpp.i

CMakeFiles/rainscene.dir/src/Material.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rainscene.dir/src/Material.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /COMP371/Project/rainscene/src/Material.cpp -o CMakeFiles/rainscene.dir/src/Material.cpp.s

CMakeFiles/rainscene.dir/src/DirectionalLight.cpp.o: CMakeFiles/rainscene.dir/flags.make
CMakeFiles/rainscene.dir/src/DirectionalLight.cpp.o: ../src/DirectionalLight.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/COMP371/Project/rainscene/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/rainscene.dir/src/DirectionalLight.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/rainscene.dir/src/DirectionalLight.cpp.o -c /COMP371/Project/rainscene/src/DirectionalLight.cpp

CMakeFiles/rainscene.dir/src/DirectionalLight.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rainscene.dir/src/DirectionalLight.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /COMP371/Project/rainscene/src/DirectionalLight.cpp > CMakeFiles/rainscene.dir/src/DirectionalLight.cpp.i

CMakeFiles/rainscene.dir/src/DirectionalLight.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rainscene.dir/src/DirectionalLight.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /COMP371/Project/rainscene/src/DirectionalLight.cpp -o CMakeFiles/rainscene.dir/src/DirectionalLight.cpp.s

CMakeFiles/rainscene.dir/src/PointLight.cpp.o: CMakeFiles/rainscene.dir/flags.make
CMakeFiles/rainscene.dir/src/PointLight.cpp.o: ../src/PointLight.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/COMP371/Project/rainscene/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/rainscene.dir/src/PointLight.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/rainscene.dir/src/PointLight.cpp.o -c /COMP371/Project/rainscene/src/PointLight.cpp

CMakeFiles/rainscene.dir/src/PointLight.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rainscene.dir/src/PointLight.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /COMP371/Project/rainscene/src/PointLight.cpp > CMakeFiles/rainscene.dir/src/PointLight.cpp.i

CMakeFiles/rainscene.dir/src/PointLight.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rainscene.dir/src/PointLight.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /COMP371/Project/rainscene/src/PointLight.cpp -o CMakeFiles/rainscene.dir/src/PointLight.cpp.s

CMakeFiles/rainscene.dir/src/SpotLight.cpp.o: CMakeFiles/rainscene.dir/flags.make
CMakeFiles/rainscene.dir/src/SpotLight.cpp.o: ../src/SpotLight.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/COMP371/Project/rainscene/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/rainscene.dir/src/SpotLight.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/rainscene.dir/src/SpotLight.cpp.o -c /COMP371/Project/rainscene/src/SpotLight.cpp

CMakeFiles/rainscene.dir/src/SpotLight.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rainscene.dir/src/SpotLight.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /COMP371/Project/rainscene/src/SpotLight.cpp > CMakeFiles/rainscene.dir/src/SpotLight.cpp.i

CMakeFiles/rainscene.dir/src/SpotLight.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rainscene.dir/src/SpotLight.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /COMP371/Project/rainscene/src/SpotLight.cpp -o CMakeFiles/rainscene.dir/src/SpotLight.cpp.s

CMakeFiles/rainscene.dir/src/learnopengl/stb_image.cpp.o: CMakeFiles/rainscene.dir/flags.make
CMakeFiles/rainscene.dir/src/learnopengl/stb_image.cpp.o: ../src/learnopengl/stb_image.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/COMP371/Project/rainscene/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/rainscene.dir/src/learnopengl/stb_image.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/rainscene.dir/src/learnopengl/stb_image.cpp.o -c /COMP371/Project/rainscene/src/learnopengl/stb_image.cpp

CMakeFiles/rainscene.dir/src/learnopengl/stb_image.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rainscene.dir/src/learnopengl/stb_image.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /COMP371/Project/rainscene/src/learnopengl/stb_image.cpp > CMakeFiles/rainscene.dir/src/learnopengl/stb_image.cpp.i

CMakeFiles/rainscene.dir/src/learnopengl/stb_image.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rainscene.dir/src/learnopengl/stb_image.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /COMP371/Project/rainscene/src/learnopengl/stb_image.cpp -o CMakeFiles/rainscene.dir/src/learnopengl/stb_image.cpp.s

CMakeFiles/rainscene.dir/src/tinyobjloader/tiny_obj_loader.cc.o: CMakeFiles/rainscene.dir/flags.make
CMakeFiles/rainscene.dir/src/tinyobjloader/tiny_obj_loader.cc.o: ../src/tinyobjloader/tiny_obj_loader.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/COMP371/Project/rainscene/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/rainscene.dir/src/tinyobjloader/tiny_obj_loader.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/rainscene.dir/src/tinyobjloader/tiny_obj_loader.cc.o -c /COMP371/Project/rainscene/src/tinyobjloader/tiny_obj_loader.cc

CMakeFiles/rainscene.dir/src/tinyobjloader/tiny_obj_loader.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rainscene.dir/src/tinyobjloader/tiny_obj_loader.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /COMP371/Project/rainscene/src/tinyobjloader/tiny_obj_loader.cc > CMakeFiles/rainscene.dir/src/tinyobjloader/tiny_obj_loader.cc.i

CMakeFiles/rainscene.dir/src/tinyobjloader/tiny_obj_loader.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rainscene.dir/src/tinyobjloader/tiny_obj_loader.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /COMP371/Project/rainscene/src/tinyobjloader/tiny_obj_loader.cc -o CMakeFiles/rainscene.dir/src/tinyobjloader/tiny_obj_loader.cc.s

CMakeFiles/rainscene.dir/src/Model.cpp.o: CMakeFiles/rainscene.dir/flags.make
CMakeFiles/rainscene.dir/src/Model.cpp.o: ../src/Model.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/COMP371/Project/rainscene/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/rainscene.dir/src/Model.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/rainscene.dir/src/Model.cpp.o -c /COMP371/Project/rainscene/src/Model.cpp

CMakeFiles/rainscene.dir/src/Model.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rainscene.dir/src/Model.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /COMP371/Project/rainscene/src/Model.cpp > CMakeFiles/rainscene.dir/src/Model.cpp.i

CMakeFiles/rainscene.dir/src/Model.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rainscene.dir/src/Model.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /COMP371/Project/rainscene/src/Model.cpp -o CMakeFiles/rainscene.dir/src/Model.cpp.s

# Object files for target rainscene
rainscene_OBJECTS = \
"CMakeFiles/rainscene.dir/src/main.cpp.o" \
"CMakeFiles/rainscene.dir/src/Mesh.cpp.o" \
"CMakeFiles/rainscene.dir/src/Shader.cpp.o" \
"CMakeFiles/rainscene.dir/src/Window.cpp.o" \
"CMakeFiles/rainscene.dir/src/Camera.cpp.o" \
"CMakeFiles/rainscene.dir/src/Texture.cpp.o" \
"CMakeFiles/rainscene.dir/src/Light.cpp.o" \
"CMakeFiles/rainscene.dir/src/Material.cpp.o" \
"CMakeFiles/rainscene.dir/src/DirectionalLight.cpp.o" \
"CMakeFiles/rainscene.dir/src/PointLight.cpp.o" \
"CMakeFiles/rainscene.dir/src/SpotLight.cpp.o" \
"CMakeFiles/rainscene.dir/src/learnopengl/stb_image.cpp.o" \
"CMakeFiles/rainscene.dir/src/tinyobjloader/tiny_obj_loader.cc.o" \
"CMakeFiles/rainscene.dir/src/Model.cpp.o"

# External object files for target rainscene
rainscene_EXTERNAL_OBJECTS =

rainscene: CMakeFiles/rainscene.dir/src/main.cpp.o
rainscene: CMakeFiles/rainscene.dir/src/Mesh.cpp.o
rainscene: CMakeFiles/rainscene.dir/src/Shader.cpp.o
rainscene: CMakeFiles/rainscene.dir/src/Window.cpp.o
rainscene: CMakeFiles/rainscene.dir/src/Camera.cpp.o
rainscene: CMakeFiles/rainscene.dir/src/Texture.cpp.o
rainscene: CMakeFiles/rainscene.dir/src/Light.cpp.o
rainscene: CMakeFiles/rainscene.dir/src/Material.cpp.o
rainscene: CMakeFiles/rainscene.dir/src/DirectionalLight.cpp.o
rainscene: CMakeFiles/rainscene.dir/src/PointLight.cpp.o
rainscene: CMakeFiles/rainscene.dir/src/SpotLight.cpp.o
rainscene: CMakeFiles/rainscene.dir/src/learnopengl/stb_image.cpp.o
rainscene: CMakeFiles/rainscene.dir/src/tinyobjloader/tiny_obj_loader.cc.o
rainscene: CMakeFiles/rainscene.dir/src/Model.cpp.o
rainscene: CMakeFiles/rainscene.dir/build.make
rainscene: /usr/lib/x86_64-linux-gnu/libGLU.so
rainscene: /usr/lib/x86_64-linux-gnu/libGLEW.so
rainscene: /usr/lib/x86_64-linux-gnu/libglfw.so.3.3
rainscene: /usr/lib/x86_64-linux-gnu/libGLX.so
rainscene: /usr/lib/x86_64-linux-gnu/libOpenGL.so
rainscene: CMakeFiles/rainscene.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/COMP371/Project/rainscene/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Linking CXX executable rainscene"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/rainscene.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/rainscene.dir/build: rainscene

.PHONY : CMakeFiles/rainscene.dir/build

CMakeFiles/rainscene.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/rainscene.dir/cmake_clean.cmake
.PHONY : CMakeFiles/rainscene.dir/clean

CMakeFiles/rainscene.dir/depend:
	cd /COMP371/Project/rainscene/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /COMP371/Project/rainscene /COMP371/Project/rainscene /COMP371/Project/rainscene/build /COMP371/Project/rainscene/build /COMP371/Project/rainscene/build/CMakeFiles/rainscene.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/rainscene.dir/depend

