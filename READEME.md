****************************************
* Name:		Smartel
* Author: 	Bale
* Email: 	zhangguowei@pku.edu.cn
****************************************
The Smartel is a hotel manage software.
Now it supports three functions:
1. Staff management.
2. Price recommendation.
3. Build customer credit system.

you can use it as follow:

NOTE1: Your compiler should support c++11. 

1. Change the dictory to: ~/intern/Worksap/workspace/China_Intern/China_Intern_Cpp/src
$ cd ~/intern/Worksap/workspace/China_Intern/China_Intern_Cpp/src/compileall.sh

2. Compile the source code
$./compileall.sh

3. Run main.
$./main

Then It's easy to follow.

NOTE2: The date used to build customer credit system is produced by the mapreduce program.
If you have new data, you can rerun the mapreduce program as follow:

Quickly begin: $ ./runAll.sh. 
Or you can run step by step as follow.

1. Change the dictory to: ~/intern/Worksap/workspace/China_Intern/China_Intern_Cpp/src/mapreduce
$ cd ~/intern/Worksap/workspace/China_Intern/China_Intern_Cpp/src/mapreduce

NOTE3: Your host should support python. Python2.7 is recommended.
2. Run python program to scan the new data files.
$ ./getFileName.py

3. Compile the mapreduce source code.
$ ./compile.sh

4. Run the mapreduce program
$ ./runMapReduce.sh

Explanation about file structure:
1. All source code in: ~/intern/Worksap/workspace/China_Intern/China_Intern_Cpp/src

2. Date for mapreduce in: ~/intern/Worksap/workspace/China_Intern/China_Intern_Cpp/src/mapreduce/data
All other data in: ~/intern/Worksap/workspace/China_Intern/China_Intern_Cpp/files 

3. Some output in: ~/intern/Worksap/workspace/China_Intern/China_Intern_Cpp/output

