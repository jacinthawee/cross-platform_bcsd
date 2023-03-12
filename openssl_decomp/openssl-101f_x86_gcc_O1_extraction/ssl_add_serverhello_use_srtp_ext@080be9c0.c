
undefined4
ssl_add_serverhello_use_srtp_ext(int param_1,undefined *param_2,undefined4 *param_3,int param_4)

{
  undefined4 uVar1;
  int reason;
  int line;
  
  if (param_2 == (undefined *)0x0) {
LAB_080bea06:
    *param_3 = 5;
    return 0;
  }
  if (param_4 < 5) {
    line = 0x19c;
    reason = 0x16b;
  }
  else {
    if (*(int *)(param_1 + 0x180) != 0) {
      *param_2 = 0;
      param_2[1] = 2;
      param_2[2] = (char)((uint)*(undefined4 *)(*(int *)(param_1 + 0x180) + 4) >> 8);
      uVar1 = *(undefined4 *)(*(int *)(param_1 + 0x180) + 4);
      param_2[4] = 0;
      param_2[3] = (char)uVar1;
      goto LAB_080bea06;
    }
    line = 0x1a2;
    reason = 0x171;
  }
  ERR_put_error(0x14,0x134,reason,"d1_srtp.c",line);
  return 1;
}

