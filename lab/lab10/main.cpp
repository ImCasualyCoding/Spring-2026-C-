#include <iostream>
#include <unistd.h>    // fork(), execlp()
#include <sys/wait.h>  // wait()
#include <sys/types.h> // pid_t

int main() {
    std::cout << "Main Process started. PID: " << getpid() << std::endl;

    pid_t pid = fork(); 

    if (pid < 0) {
        // Error occurred
        std::cerr << "Fork failed!" << std::endl;
        return 1;
    }
    else if (pid == 0) {
        // --- Child process ---
        std::cout << "[Child] PID: " << getpid() << " | Parent PID: " << getppid() << std::endl;
        
        // execlp replaces the child process memory with the 'ls' command
        execlp("ls", "ls", "-l", NULL);

        // This part only runs if execlp fails (e.g., 'ls' not found)
        std::cerr << "[Child] Exec failed!" << std::endl;
        exit(1); 
    }
    else {
        // --- Parent process ---
        std::cout << "[Parent] Waiting for child (PID: " << pid << ") to finish..." << std::endl;
        
        int status;
        wait(&status); // Wait for the child and collect exit status
        
        std::cout << "[Parent] Child has completed. Resuming parent..." << std::endl;
    }

    return 0;
}