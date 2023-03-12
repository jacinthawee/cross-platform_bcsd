
void * DSO_bind_var(DSO *dso,char *symname)

{
  _func_3767 *p_Var1;
  void *pvVar2;
  int reason;
  int line;
  
  if ((dso == (DSO *)0x0) || (symname == (char *)0x0)) {
    line = 0x105;
    reason = 0x43;
  }
  else {
    p_Var1 = dso->meth->dso_bind_var;
    if (p_Var1 == (_func_3767 *)0x0) {
      line = 0x10a;
      reason = 0x6c;
    }
    else {
      pvVar2 = (*p_Var1)(dso,symname);
      if (pvVar2 != (void *)0x0) {
        return pvVar2;
      }
      line = 0x10f;
      reason = 0x6a;
    }
  }
  ERR_put_error(0x25,0x6d,reason,"dso_lib.c",line);
  return (void *)0x0;
}

