#include <cstdio>
#include <windows.h>

#include <processthreadsapi.h>
#include <string>
#include <winnt.h>

#include "libfenetre/dll_injection.h"
#include "libfenetre/process.h"

int main(int argc, char **argv) {

  LPCSTR *process_name;
  BOOL ret = 0;
  DWORD ppid = 0;
  if (argc < 3) {
    printf("USAGE : %s [DLL_TO_INJECT_ABSOLUE_PATH] [PROCESS_TO_INJECT]\n",
           argv[0]);
    return (-1);
  }

  std::string dllPath = std::string(argv[1]);
  ppid = process::pid_from_processname(argv[2]);

  if (ppid == 0) {
    fprintf(stderr, "err: Can't find pid for process : %s\n", argv[2]);
    return (-1);
  }

  injection::inject_dll(ppid, argv[1]);

  return (0);
}