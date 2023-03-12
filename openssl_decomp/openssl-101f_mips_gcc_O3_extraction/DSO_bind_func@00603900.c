
DSO_FUNC_TYPE DSO_bind_func(DSO *dso,char *symname)

{
  DSO_FUNC_TYPE pDVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  _func_3768 *p_Var4;
  
  if ((dso == (DSO *)0x0) || (symname == (char *)0x0)) {
    uVar3 = 0x43;
    uVar2 = 0x11c;
  }
  else {
    p_Var4 = dso->meth->dso_bind_func;
    uVar3 = 0x6c;
    if (p_Var4 != (_func_3768 *)0x0) {
      pDVar1 = (*p_Var4)(dso,symname);
      if (pDVar1 != (DSO_FUNC_TYPE)0x0) {
        return pDVar1;
      }
      (*(code *)PTR_ERR_put_error_006a9030)(0x25,0x6c,0x6a,"dso_lib.c",0x126);
      return (DSO_FUNC_TYPE)0x0;
    }
    uVar2 = 0x121;
  }
  (*(code *)PTR_ERR_put_error_006a9030)(0x25,0x6c,uVar3,"dso_lib.c",uVar2);
  return (DSO_FUNC_TYPE)0x0;
}

