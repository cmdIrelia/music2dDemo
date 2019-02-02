all:
	g++ -omusic2dDemo -I./argo/inc *.cpp ./argo/src/*.cpp -fopenmp
