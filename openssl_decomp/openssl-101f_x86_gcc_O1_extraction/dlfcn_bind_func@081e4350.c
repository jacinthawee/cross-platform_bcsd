
int dlfcn_bind_func(int param_1,int param_2)

{
  int iVar1;
  void *pvVar2;
  undefined4 uVar3;
  int line;
  
  if ((param_1 == 0) || (param_2 == 0)) {
    line = 0x110;
    iVar1 = 0x43;
  }
  else {
    iVar1 = sk_num(*(_STACK **)(param_1 + 4));
    if (iVar1 < 1) {
      line = 0x115;
      iVar1 = 0x69;
    }
    else {
      iVar1 = sk_num(*(_STACK **)(param_1 + 4));
      pvVar2 = sk_value(*(_STACK **)(param_1 + 4),iVar1 + -1);
      if (pvVar2 != (void *)0x0) {
        iVar1 = dlsym(pvVar2,param_2);
        if (iVar1 == 0) {
          ERR_put_error(0x25,100,0x6a,"dso_dlfcn.c",0x121);
          uVar3 = dlerror();
          ERR_add_error_data(4,"symname(",param_2,"): ",uVar3);
          iVar1 = 0;
        }
        return iVar1;
      }
      line = 0x11b;
      iVar1 = 0x68;
    }
  }
  ERR_put_error(0x25,100,iVar1,"dso_dlfcn.c",line);
  return 0;
}

