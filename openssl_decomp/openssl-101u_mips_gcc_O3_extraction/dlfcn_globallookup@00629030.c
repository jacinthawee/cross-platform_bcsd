
undefined4 dlfcn_globallookup(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (*(code *)PTR_dlopen_006a9abc)(0,1);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = (*(code *)PTR_dlsym_006a9a0c)(iVar1,param_1);
    (*(code *)PTR_dlclose_006a9aac)(iVar1);
  }
  return uVar2;
}

