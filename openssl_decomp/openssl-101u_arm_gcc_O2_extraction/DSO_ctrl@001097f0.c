
long DSO_ctrl(DSO *dso,int cmd,long larg,void *parg)

{
  long lVar1;
  _func_3769 *UNRECOVERED_JUMPTABLE;
  
  if (dso == (DSO *)0x0) {
    ERR_put_error(0x25,0x6e,0x43,"dso_lib.c",0x127);
    lVar1 = -1;
  }
  else {
    if (cmd == 2) {
      dso->flags = larg;
      return 0;
    }
    if (cmd == 3) {
      lVar1 = 0;
      dso->flags = larg | dso->flags;
    }
    else if (cmd == 1) {
      lVar1 = dso->flags;
    }
    else {
      if ((dso->meth != (DSO_METHOD *)0x0) &&
         (UNRECOVERED_JUMPTABLE = dso->meth->dso_ctrl, UNRECOVERED_JUMPTABLE != (_func_3769 *)0x0))
      {
                    /* WARNING: Could not recover jumptable at 0x0010981a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        lVar1 = (*UNRECOVERED_JUMPTABLE)(dso,cmd,larg,parg);
        return lVar1;
      }
      ERR_put_error(0x25,0x6e,0x6c,"dso_lib.c",0x13b);
      lVar1 = -1;
    }
  }
  return lVar1;
}

