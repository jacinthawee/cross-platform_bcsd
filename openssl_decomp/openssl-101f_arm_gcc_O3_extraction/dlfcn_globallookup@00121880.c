
int dlfcn_globallookup(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
  iVar1 = dlopen(0,1,param_3,param_4,param_4);
  if (iVar1 != 0) {
    iVar2 = dlsym(iVar1,param_1);
    dlclose(iVar1);
    iVar1 = iVar2;
  }
  return iVar1;
}

