# Lab 2 - C Pointers, Functions, POSIX Threads and OpenMP

In this lab, you will work on three different C programming challenges in order to become more comfortable with pointers, funtions, memory allocation and timing of C code as well as looking at building POSIX thread-based code as well as code based on OpenMP.  These problems can be approached using the Ecliplse IDE in the lab or using the command line.  Please ensure that your system is configured to support POSIX threads and OpenMP (see Canvas for details if you are using your own machine). 

Regardless of where you develop and test your code, your solutions to all problems will need to be added to your repository, commited and pushed back upstream to GitHub.  Detailed instructions follow.  Review the marking rubric to ensure you have addressed all points required for each problem.  

**Please note that the starter code (and the location of where your files should go is `./src`**

| **Item**            | **Criteria** |
|----------------|---------------|
|**Assignment:** | Work will be done individually|
|**Assignment Submissions:**| All submissions will be done via GitHub Classrom. **Submit via GitHub**. **Submit only your .c and .txt files (Q1.c, Q2.c, Q3.c, Q3.txt, Q4.c, Q5.c and Q5.txt) files.**|
|**Due Date:**| Electronic submission Sunday, October 3rd, 2021 – end of day (23:59).  GitHub Classroom is automatically configured to submit your repositories at this time.  Make sure that you have completed the assignemnt and pushed the changes upstream (back) to your repository.  **While lab 2 isn't due until October 3rd, please start early as you will have a new lab next week!**|

**Rubric:** The assignment will be marked as follows:

| **Rubric**                          | **Max Score** | **Value**  |
|-------------------------------------|:-------------:|:----------:|
|*Question 1*                         |               |            |
|Function operation                   |       /4      |            |
|Testing (and error checking) of code (2 marks or error checking) |       /5      |            |
|Reporting correct results as a comment|       /1      |            |
|-------------------------------------|---------------|------------|
|*Question 2*                         |               |            |                                                                
|Function operation (2 marks for error checking/handling bad allocation)                      |       /6      |            |
|Testing (and error checking) of code (2 marks or error checking) |       /5      |            |
|Reporting correct results as a comment|       /1      |            |
|-------------------------------------|---------------|------------|
|*Question 3*                         |               |            |                                                                
|Running and output in text file  |       /4      |            |
|-------------------------------------|---------------|------------|
|*Question 4*                         |               |            |                                                                
|Function operation (add c = a + b) to function using proper slicing|       /2      |            |
|Initial A and B vectors with random int |       /4      |            |
|Timing/testing of code |       /4      |            |
|Reporting testing results as a comment in code |       /2      |            |
|-------------------------------------|---------------|------------|
|*Question 5*                         |               |            |                                                                
|Running and output in text file  |       /4      |            |
|-------------------------------------|---------------|------------|
|Total                                |       /32     |            |

Total possible marks 20/20

**Question 1 (10 marks)**

Write a C function that sequentially adds 2 vectors `A` and `B` as `C[i]=A[i]+B[i]` (this is similar to the code from last week, but uses pointers). Use this function header: `void addVec(int* C, int* A, int* B, int size)`, where size is the number of elements in a vector. You should **not create any additional local variables in the function** (hint: use pointers and pointer expressions; what is the advantage here to use pointers to pass in A, B and C?). 

Test your function with two vectors, each having 50 million integers, all initialized to 0 (hint: calloc). Note that memory allocation for A, B, and C is done within your test code (the `main` function). Print the first 10 elements of C as well as the total time the function took to complete. Report the results as a comment in your code.  Your code also needs to handle the situation where it can't successfully handle the allocation of the required memory; ensure to handle this conditio as well.  When you are developing this solution, if you run into a memory allocation issue when allocating 50 million integers, test with a smaller value.  

Build your solution using Q1.c (provided in the repo, with the function prototype).  

The sample runs of your code should look like:

**Sample run 1**

    0 0 0 0 0 0 0 0 0 0
    Execution time: 281.0 ms

**Sample run 2** (unsuccessful memory allocation)
    
    Not enough memory.

Commit your Q1.c file to the lab 2 repository. 

**Notes:** 
* Lookup the function `clock()` from `time.h`.

**Question 2 (12 marks)**

Repeat question Q1 with a function that receives pointers to A and B, **but allocates memory space for C, and returns a pointer to the memory holding the computed output** ('C' needs to be created inside the function as a `int*`, properly allocated and if it isn't `NULL`, used to store the results of the operation.  The pointer is then returned to the caller. Use the header `int* addVec2(int* A, int* B, int size)`. The function should return `NULL` if memory allocation for C fails. **You can only create two local variables of the type `int*` within the function `addVec2`** (you will need to keep track of the start of`C` as well as have another variable to itterate over the array.  You will need to use some pointer arithmetic here!)   Your test code should produce output similar to the sample runs in Q1.

Build your solution using Q2.c (provided in the repo, with the function prototype).  
   
**Notes:** 
* Lookup the function `clock()` from `time.h`.
* Refer to lab 1 on allocating with `malloc` in Q2. 
* Write code to print the error message if the operating system fails to allocate memory to your arrays, in which case `malloc` will return `NULL`. 

Commit your Q2.c file to the lab 2 repository. 

**Question 3 (4 marks)**

In this question, you will run a code sample using pthreads.  Open Q3.c from the repository. You can either open this and build it with Eclipse or use the command line (don't forget to use -lpthread). Examine the code in Q3 and understand what it is doing.  You will need to build and run this code. There are a few errors/warngings in the code that need to be resolved.  Once it is running, check that it operates as expected.  Copy the output of the code and paste it into a text file Q3.txt.  Commit your Q3.txt file along with the corrected running code to the lab 2 repository.

**Question 4 (12 marks)**

In this question, you will examine an example of threaded code that uses POSIX threads to sum up to vectors (like in Q1).  Build your solution using Q4.c.  You can either open this and build it with Eclipse or use the command line (don't forget to use -lpthread).  The majority of the code has been provided for you, as there are some challenges with threading with POSIX (OpenMP makes this a lot easier).
Make sure that you can compile this code (it should compile for you with -lpthread).  You don't need to modify any code regarding how the threads are created or run, but just add code to the indicated sections. 

In the code there are a series of `@todo` statements that need to be completed:
1. Add code to properly add C = A + B for each thread that processes part of the array in the function called by the thread. (see `@todo` in code comments)
2. Initialize A and B as noted in the code using rand() (see `@todo` in code comments)
3. Add timing information for thread creation, addition and cleanup to the code; have it print the results out for a given run.  (see `@todo` in code comments)
4. Experiment by increaasing the number of threads using 2, 4, 8 and 16 threads and increase the size from 1000 to 1 million and record the times in the comments in your code.

Commit your Q4.c file to the lab 2 repository with the results as a comment in the code. 

**Question 5 (4 marks)**

In this question, you will build Q5.c.  Open Q5.c from the repository.  You can either open this and build it with Eclipse or use the command line (don't forget to use -fopenmp).  If you are going to use Eclipse. Start the Eclipse, create an OpenMP project, and copy and paste the code below into a new source file. Build and run. Check everything works as expected, if not fix as appropriate. Copy the output into a text file named Q5.txt. 

**Submission Details**

When you are complete with the assignment, ensure all files are added and commited to your repository and that your repository is pushed back upstream to GitHub.  You can @mention your respective TA which will let them know you have completed the assignment.  **You will then submit the URL to your repository via the lab submission link in Canvas.  This link will be used by the TA's to grade your submission**.  **Your submission must be pushed back to the GitHub classroom before the assignment due date and time**.  Your TA's will provide direct feedback (if required), via your repository. 
