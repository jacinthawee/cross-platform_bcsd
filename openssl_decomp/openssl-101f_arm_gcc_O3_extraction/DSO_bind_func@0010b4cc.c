
DSO_FUNC_TYPE DSO_bind_func(DSO *dso,char *symname)

{
  _func_3768 *p_Var1;
  
  if (symname == (char *)0x0 || dso == (DSO *)0x0) {
    ERR_put_error(0x25,0x6c,0x43,"dso_lib.c",0x11c);
    p_Var1 = (_func_3768 *)0x0;
  }
  else {
    p_Var1 = dso->meth->dso_bind_func;
    if (p_Var1 == (_func_3768 *)0x0) {
      ERR_put_error(0x25,0x6c,0x6c,"dso_lib.c",0x121);
    }
    else {
      p_Var1 = (_func_3768 *)(*p_Var1)();
      if (p_Var1 == (_func_3768 *)0x0) {
        ERR_put_error(0x25,0x6c,0x6a,"dso_lib.c",0x126);
      }
    }
  }
  return (DSO_FUNC_TYPE)p_Var1;
}

