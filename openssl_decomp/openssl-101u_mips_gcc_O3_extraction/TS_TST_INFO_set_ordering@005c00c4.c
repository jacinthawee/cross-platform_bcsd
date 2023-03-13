
undefined4 TS_TST_INFO_set_ordering(int param_1,int param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0xff;
  if (param_2 == 0) {
    uVar1 = 0;
  }
  *(undefined4 *)(param_1 + 0x18) = uVar1;
  return 1;
}

