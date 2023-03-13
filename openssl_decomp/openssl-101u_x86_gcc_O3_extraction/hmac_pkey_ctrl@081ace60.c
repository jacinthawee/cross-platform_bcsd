
undefined4 hmac_pkey_ctrl(undefined4 param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  if (param_2 == 3) {
    *param_4 = 0x40;
    return 1;
  }
  return 0xfffffffe;
}

