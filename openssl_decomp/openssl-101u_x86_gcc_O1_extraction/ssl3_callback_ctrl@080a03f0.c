
undefined4 ssl3_callback_ctrl(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  
  if ((param_2 - 5U < 2) && (iVar1 = ssl_cert_inst(param_1 + 0x98), iVar1 == 0)) {
    ERR_put_error(0x14,0xe9,0x41,"s3_lib.c",0xd69);
    return 0;
  }
  if (param_2 == 6) {
    *(undefined4 *)(*(int *)(param_1 + 0x98) + 0x24) = param_3;
    return 0;
  }
  if (param_2 < 7) {
    if (param_2 == 5) {
      *(undefined4 *)(*(int *)(param_1 + 0x98) + 0x1c) = param_3;
      return 0;
    }
  }
  else {
    if (param_2 == 7) {
      *(undefined4 *)(*(int *)(param_1 + 0x98) + 0x2c) = param_3;
      return 0;
    }
    if (param_2 == 0x38) {
      *(undefined4 *)(param_1 + 0x118) = param_3;
    }
  }
  return 0;
}

