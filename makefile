For c:  
  gcc -c -fPIC one.c -o one.o
	gcc -shared -o libone.so one.o
	gcc -c test.c -o test.o
	gcc test.o -L. -Wl,-rpath,. -lone -o test

For c++:
  g++ -c -Wall test2.cpp -o test2.o
	g++ -c -fPIC two.cpp -o two.o
	g++ two.o -g -shared -L. -lone -Wl,-rpath,. -o libtwo.so
	g++ test2.o -o test2 -L. -ltwo -Wl,-rpath,.
	
For python:
  swig -c++ -python verylong.i
	g++ -c -fPIC verylong_wrap.cxx -I/usr/include/python2.7
	g++ verylong_wrap.o -shared -fPIC -L. -ltwo -Wl,-rpath,. -o _verylong.so
