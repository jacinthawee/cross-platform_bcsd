
int ENGINE_ctrl(ENGINE *e,int cmd,long i,void *p,f *f)

{
  code *UNRECOVERED_JUMPTABLE;
  int iVar1;
  int line;
  
  if (e == (ENGINE *)0x0) {
    line = 0xb7;
    iVar1 = 0x43;
  }
  else {
    CRYPTO_lock((int)f,9,(char *)0x1e,(int)"eng_ctrl.c");
    iVar1 = *(int *)(e + 0x58);
    CRYPTO_lock((int)f,10,(char *)0x1e,(int)"eng_ctrl.c");
    UNRECOVERED_JUMPTABLE = *(code **)(e + 0x40);
    if (0 < iVar1) {
      if (cmd == 10) {
        return (uint)(UNRECOVERED_JUMPTABLE != (code *)0x0);
      }
      if ((cmd < 10) || (0x12 < cmd)) {
        if (UNRECOVERED_JUMPTABLE == (code *)0x0) {
          line = 0xe1;
          iVar1 = 0x78;
          goto LAB_0811223b;
        }
      }
      else {
        if (UNRECOVERED_JUMPTABLE == (code *)0x0) {
          ERR_put_error(0x26,0x8e,0x78,"eng_ctrl.c",0xd4);
          return -1;
        }
        if (((byte)e[0x54] & 2) == 0) {
          iVar1 = int_ctrl_helper_isra_1();
          return iVar1;
        }
      }
                    /* WARNING: Could not recover jumptable at 0x08112223. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar1 = (*UNRECOVERED_JUMPTABLE)();
      return iVar1;
    }
    line = 0xbf;
    iVar1 = 0x82;
  }
LAB_0811223b:
  ERR_put_error(0x26,0x8e,iVar1,"eng_ctrl.c",line);
  return 0;
}

