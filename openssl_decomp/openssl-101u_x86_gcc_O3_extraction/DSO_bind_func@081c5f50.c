
DSO_FUNC_TYPE DSO_bind_func(DSO *dso,char *symname)

{
  _func_3768 *p_Var1;
  DSO_FUNC_TYPE pDVar2;
  int reason;
  int line;
  
  if ((dso == (DSO *)0x0) || (symname == (char *)0x0)) {
    line = 0x10c;
    reason = 0x43;
  }
  else {
    p_Var1 = dso->meth->dso_bind_func;
    if (p_Var1 == (_func_3768 *)0x0) {
      line = 0x110;
      reason = 0x6c;
    }
    else {
      pDVar2 = (*p_Var1)(dso,symname);
      if (pDVar2 != (DSO_FUNC_TYPE)0x0) {
        return pDVar2;
      }
      line = 0x114;
      reason = 0x6a;
    }
  }
  ERR_put_error(0x25,0x6c,reason,"dso_lib.c",line);
  return (DSO_FUNC_TYPE)0x0;
}

