all:
	g++ -omusic2dDemo -I./argo/inc ./argo/src/*.cpp *.cpp -fopenmp
clean:
	rm -rf *.o
