/**************************************************************
 *
 * userprog/ksyscall.h
 *
 * Kernel interface for systemcalls 
 *
 * by Marcus Voelp  (c) Universitaet Karlsruhe
 *
 **************************************************************/

#ifndef __USERPROG_KSYSCALL_H__ 
#define __USERPROG_KSYSCALL_H__ 

#include "kernel.h"

#include "synchconsole.h"


void SysHalt()
{
  kernel->interrupt->Halt();
}

void SysPrintInt(int number)
{
	kernel->interrupt->PrintInt(number);
}

int SysAdd(int op1, int op2)
{
  return op1 + op2;
}

int SysCreate(char *filename)
{
	// return value
	// 1: success
	// 0: failed
	return kernel->interrupt->CreateFile(filename);
}

int SysOpen(char *filename)
{
  // return value
  // failed -> -1
  // success -> fileId
  return kernel->interrupt->OpenFile(filename);
}

int SysWrite(char *buffer, int size, int fileId)
{
  return kernel->interrupt->WriteFile(buffer, size, fileId);  
}

int SysRead(char *buffer, int size, int fileId)
{
  return kernel->interrupt->ReadFile(buffer, size, fileId);  
}

int SysClose(int fileId)
{
  return kernel->interrupt->CloseFile(fileId);
}

#endif /* ! __USERPROG_KSYSCALL_H__ */
