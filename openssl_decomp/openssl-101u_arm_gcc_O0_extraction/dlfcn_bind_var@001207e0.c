
void * dlfcn_bind_var(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  _STACK *p_Var3;
  void *pvVar4;
  
  if (param_2 != 0 && param_1 != 0) {
    pvVar4 = (void *)0x0;
    iVar1 = sk_num(*(_STACK **)(param_1 + 4));
    if (iVar1 < 1) {
      ERR_put_error(0x25,0x65,0x69,"dso_dlfcn.c",0xef);
    }
    else {
      p_Var3 = *(_STACK **)(param_1 + 4);
      iVar1 = sk_num(p_Var3);
      pvVar4 = sk_value(p_Var3,iVar1 + -1);
      if (pvVar4 == (void *)0x0) {
        ERR_put_error(0x25,0x65,0x68,"dso_dlfcn.c",0xf4);
      }
      else {
        pvVar4 = (void *)dlsym(pvVar4,param_2);
        if (pvVar4 == (void *)0x0) {
          ERR_put_error(0x25,0x65,0x6a,"dso_dlfcn.c",0xf9);
          uVar2 = dlerror();
          ERR_add_error_data(4,"symname(",param_2,"): ",uVar2);
        }
      }
    }
    return pvVar4;
  }
  ERR_put_error(0x25,0x65,0x43,"dso_dlfcn.c",0xeb);
  return (void *)0x0;
}

