
undefined4 gost_imit_ctrl(int param_1,int param_2,int param_3,undefined4 *param_4)

{
  if (param_2 == 0x1003) {
    *param_4 = 0x20;
    return 1;
  }
  if (param_2 == 0x1004) {
    if (param_3 != 0x20) {
      ERR_GOST_error(0x72,0x6f,"gost_crypt.c",0x260);
      return 0;
    }
    gost_key(*(undefined4 *)(param_1 + 0xc),param_4,0x20,param_4,&_gp);
    *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x103c) = 1;
    return 1;
  }
  return 0;
}

