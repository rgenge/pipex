# pipex
This project is the first project in the 42 School where we use pipes, dup2,execve and fork to make the same thing the function pipe represented by "|" does in shell.

The command to use the program is :

./pipex inputfile "command1" "command2" outputfile 
and it works similar to:

<inputfile command1 | command2 > outputfile

The bonus accepts multiples commands.

The program is divided in 4 steps:

1: Reading and cheking the input and output(create the output if it does not exists) file.

2: Creating a fork that will divide the process to run separately, so the child and parent process will run in a fork, but the parent process has to wait the child to finish.

3: After running it the pipe will take the output of the the execve child and in the other side of the pipe the parent process will take take the pipe as input.

4: Then finally the program will use the execve to execute the parent process and write it in the outfile life.

This is a simple explanation about the program, if you have any doubt and want a more deep explanation just message me through my linkedin.

linkedin.com/in/atila-costa-almeida-21ab01233
