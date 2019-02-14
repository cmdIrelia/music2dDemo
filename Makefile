all:
	make -C ./obj
	g++ -omusic2dDemo -I./argo/inc *.cpp ./obj/*.o -fopenmp
	make -C eigenImp/pureC
clean:
	make -C ./obj clean
	rm -rf *.o music2dDemo
	make -C eigenImp/pureC clean
