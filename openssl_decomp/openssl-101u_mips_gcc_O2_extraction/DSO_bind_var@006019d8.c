
void * DSO_bind_var(DSO *dso,char *symname)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  _func_3767 *p_Var4;
  
  if ((dso == (DSO *)0x0) || (symname == (char *)0x0)) {
    uVar3 = 0x43;
    uVar2 = 0xf8;
  }
  else {
    p_Var4 = dso->meth->dso_bind_var;
    uVar3 = 0x6c;
    if (p_Var4 != (_func_3767 *)0x0) {
      pvVar1 = (*p_Var4)(dso,symname);
      if (pvVar1 != (void *)0x0) {
        return pvVar1;
      }
      (*(code *)PTR_ERR_put_error_006a7f34)(0x25,0x6d,0x6a,"dso_lib.c",0x100);
      return (void *)0x0;
    }
    uVar2 = 0xfc;
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(0x25,0x6d,uVar3,"dso_lib.c",uVar2);
  return (void *)0x0;
}

