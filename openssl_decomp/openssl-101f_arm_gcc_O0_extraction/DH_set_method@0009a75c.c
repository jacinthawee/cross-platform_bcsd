
int DH_set_method(DH *dh,DH_METHOD *meth)

{
  _func_1705 *p_Var1;
  _func_1704 *p_Var2;
  
  p_Var1 = dh->meth->finish;
  if (p_Var1 != (_func_1705 *)0x0) {
    (*p_Var1)(dh);
  }
  if (dh->engine != (ENGINE *)0x0) {
    ENGINE_finish(dh->engine);
    dh->engine = (ENGINE *)0x0;
  }
  p_Var2 = meth->init;
  dh->meth = meth;
  if (p_Var2 != (_func_1704 *)0x0) {
    (*p_Var2)(dh);
  }
  return 1;
}

