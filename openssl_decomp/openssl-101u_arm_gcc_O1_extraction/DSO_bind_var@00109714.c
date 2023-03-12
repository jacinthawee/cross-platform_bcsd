
void * DSO_bind_var(DSO *dso,char *symname)

{
  _func_3767 *p_Var1;
  
  if (symname == (char *)0x0 || dso == (DSO *)0x0) {
    ERR_put_error(0x25,0x6d,0x43,"dso_lib.c",0xf8);
    p_Var1 = (_func_3767 *)0x0;
  }
  else {
    p_Var1 = dso->meth->dso_bind_var;
    if (p_Var1 == (_func_3767 *)0x0) {
      ERR_put_error(0x25,0x6d,0x6c,"dso_lib.c",0xfc);
    }
    else {
      p_Var1 = (_func_3767 *)(*p_Var1)(dso,symname);
      if (p_Var1 == (_func_3767 *)0x0) {
        ERR_put_error(0x25,0x6d,0x6a,"dso_lib.c",0x100);
      }
    }
  }
  return p_Var1;
}

