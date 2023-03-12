
long DSO_ctrl(DSO *dso,int cmd,long larg,void *parg)

{
  long lVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  _func_3769 *UNRECOVERED_JUMPTABLE;
  
  if (dso == (DSO *)0x0) {
    uVar3 = 0x43;
    uVar2 = 0x127;
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
                    /* WARNING: Could not recover jumptable at 0x00601b98. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      lVar1 = (*UNRECOVERED_JUMPTABLE)(dso,cmd,larg,parg);
      return lVar1;
    }
    uVar3 = 0x6c;
    uVar2 = 0x13b;
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(0x25,0x6e,uVar3,"dso_lib.c",uVar2);
  return -1;
}

