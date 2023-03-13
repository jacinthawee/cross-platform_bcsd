
long DSO_ctrl(DSO *dso,int cmd,long larg,void *parg)

{
  _func_3769 *UNRECOVERED_JUMPTABLE;
  long lVar1;
  int reason;
  int line;
  
  if (dso == (DSO *)0x0) {
    line = 0x127;
    reason = 0x43;
  }
  else {
    if (cmd == 2) {
      dso->flags = larg;
      return 0;
    }
    if (cmd == 3) {
      dso->flags = dso->flags | larg;
      return 0;
    }
    if (cmd == 1) {
      return dso->flags;
    }
    if ((dso->meth != (DSO_METHOD *)0x0) &&
       (UNRECOVERED_JUMPTABLE = dso->meth->dso_ctrl, UNRECOVERED_JUMPTABLE != (_func_3769 *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x081c6020. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      lVar1 = (*UNRECOVERED_JUMPTABLE)(dso,cmd,larg,parg);
      return lVar1;
    }
    line = 0x13b;
    reason = 0x6c;
  }
  ERR_put_error(0x25,0x6e,reason,"dso_lib.c",line);
  return -1;
}

