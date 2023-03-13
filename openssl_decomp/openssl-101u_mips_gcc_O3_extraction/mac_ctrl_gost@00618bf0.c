
undefined4 mac_ctrl_gost(undefined4 param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  if (param_2 == 3) {
    *param_4 = 0x32f;
    return 2;
  }
  return 0xfffffffe;
}

