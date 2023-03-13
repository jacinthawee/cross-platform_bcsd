
undefined4 dlfcn_globallookup(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = dlopen(0,1);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = dlsym(iVar1,param_1);
    dlclose(iVar1);
  }
  return uVar2;
}

