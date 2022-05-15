# Implement an algorithm for finding cut vertices using depth-first-search (DFS).
Name: Ram Chandra Jangir

Roll Number : CS21M517

Registered Mail ID: contactjangir@gmail.com


**How to compile and run the program:**

**Step-1 :**

Clone this project using below command and you will get below list of files.

       git clone https://github.com/contactjangir/cut_vertex.git

       cd cut_vertex

       cut_vertex$ tree
	.
	├── cut_vertex
	├── cut_vertex.cpp
	├── Makefile
	├── output.txt
	└── README.md

0 directories, 5 files


**Step-2 :**

It is already having a precompiled binary cut_vertex which can be run directly on Ubuntu system.

OR

**How to compile**

	cut_vertex$ make
	g++ -o cut_vertex cut_vertex.cpp



**Step-3 :**

**How to run this program:**


	cut_vertex$ ./cut_vertex

           (1)
          / | \
         /  |  \
        /   |   \
       /    |    (3)
     (0)    |   /  |
     |      |  /   |
     |      | /    |
    (5)    (2)----(4)


--------------------------------------------------

cut vertices in the above given  graph using DFS are : 0 1



