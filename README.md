# pipex
This project is the first project in the 42 School where we use pipes, dup2,execve and fork to make the same thing the function pipe represented by "|" does in shell.\n
The command to use the program is :\n
./pipex inputfile "command1" "command2" outputfile \n
and it works similar to:\n
<inputfile command1 | command2 > outputfile\n
The bonus accepts multiples commands.\n

The program is divided in 3 parts:\n
1: Reading a cheking the input and output(create it if it does not exists) file.\n
2: Creating a fork that will divide the process to run separately, so the child and parent process will run in a fork, but the parent process has to wait the child to finish.\n
3: After running it the pipe will take the output of the the execve child and in the other side of the pipe the parent process will take take the pipe as input.\n
4: Then finally the program will use the execve to execute the parent process and write it in the outfile life.\n
5: This is a simple explanation about the program, if you have any doubt and want a more deep explanation just message me through github for more info.\n
