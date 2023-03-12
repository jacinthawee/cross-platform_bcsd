
int ENGINE_ctrl(ENGINE *e,int cmd,long i,void *p,f *f)

{
  int reason;
  int iVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  if (e == (ENGINE *)0x0) {
    ERR_put_error(0x26,0x8e,0x43,"eng_ctrl.c",0xbb);
    return 0;
  }
  (*(code *)PTR_CRYPTO_lock_006a926c)(9,0x1e,"eng_ctrl.c",0xbe);
  iVar1 = *(int *)(e + 0x58);
  (*(code *)PTR_CRYPTO_lock_006a926c)(10,0x1e,"eng_ctrl.c",0xc0);
  UNRECOVERED_JUMPTABLE = *(code **)(e + 0x40);
  if (0 < iVar1) {
    if (cmd == 10) {
      return (uint)(UNRECOVERED_JUMPTABLE != (code *)0x0);
    }
    if ((cmd < 10) || (0x12 < cmd)) {
      if (UNRECOVERED_JUMPTABLE == (code *)0x0) {
        reason = 0x78;
        iVar1 = 0xe5;
        goto LAB_0051b9e0;
      }
    }
    else {
      if (UNRECOVERED_JUMPTABLE == (code *)0x0) {
        ERR_put_error(0x26,0x8e,0x78,"eng_ctrl.c",0xd9);
        return -1;
      }
      if ((*(uint *)(e + 0x54) & 2) == 0) {
        iVar1 = int_ctrl_helper_isra_1(e + 0x50,cmd,i,p);
        return iVar1;
      }
    }
                    /* WARNING: Could not recover jumptable at 0x0051b9bc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (*UNRECOVERED_JUMPTABLE)(e,cmd,i,p);
    return iVar1;
  }
  reason = 0x82;
  iVar1 = 0xc4;
LAB_0051b9e0:
  ERR_put_error(0x26,0x8e,reason,"eng_ctrl.c",iVar1);
  return 0;
}

