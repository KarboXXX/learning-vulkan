CFLAGS = -std=c++17 -O2
LDFLAGS = -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi

all: shaders main

main: shaders *.cpp *.hpp
	g++ $(CFLAGS) -o ./dist/main *.cpp $(LDFLAGS)

shaders: shaders/*.vert shaders/*.frag
	glslc shaders/shader.vert -o shaders/shader.vert.spv
	glslc shaders/shader.frag -o shaders/shader.frag.spv
