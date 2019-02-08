all:
#	g++ -omusic2dDemo -I./argo/inc ./argo/src/*.cpp *.cpp -fopenmp
#obj:
	make -C ./obj
	g++ -omusic2dDemo -I./argo/inc *.cpp ./obj/*.o -fopenmp
clean:
	make -C ./obj clean
	rm -rf *.o music2dDemo
