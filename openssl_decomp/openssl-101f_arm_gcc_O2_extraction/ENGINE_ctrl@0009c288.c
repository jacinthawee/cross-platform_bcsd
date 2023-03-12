
int ENGINE_ctrl(ENGINE *e,int cmd,long i,void *p,f *f)

{
  code *UNRECOVERED_JUMPTABLE;
  code *pcVar1;
  int iVar2;
  
  if (e == (ENGINE *)0x0) {
    ERR_put_error(0x26,0x8e,0x43,"eng_ctrl.c",0xbb);
    return 0;
  }
  CRYPTO_lock(9,0x1e,"eng_ctrl.c",0xbe);
  iVar2 = *(int *)(e + 0x58);
  CRYPTO_lock(10,0x1e,"eng_ctrl.c",0xc0);
  UNRECOVERED_JUMPTABLE = *(code **)(e + 0x40);
  pcVar1 = UNRECOVERED_JUMPTABLE;
  if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
    pcVar1 = (code *)0x1;
  }
  if (iVar2 < 1) {
    ERR_put_error(0x26,0x8e,0x82,"eng_ctrl.c",0xc4);
    return 0;
  }
  if (cmd == 10) {
    return (int)pcVar1;
  }
  if ((cmd < 10) || (0x12 < cmd)) {
    if (pcVar1 == (code *)0x0) {
      ERR_put_error(0x26,0x8e,0x78,"eng_ctrl.c",0xe5);
      return 0;
    }
  }
  else {
    if (pcVar1 == (code *)0x0) {
      ERR_put_error(0x26,0x8e,0x78,"eng_ctrl.c",0xd9);
      return -1;
    }
    if (-1 < *(int *)(e + 0x54) << 0x1e) {
      iVar2 = int_ctrl_helper_isra_1(e + 0x50,cmd,i,p);
      return iVar2;
    }
  }
                    /* WARNING: Could not recover jumptable at 0x0009c2fc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar2 = (*UNRECOVERED_JUMPTABLE)(e,cmd,i,p);
  return iVar2;
}

