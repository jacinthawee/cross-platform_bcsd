
uint null_ctrl(undefined4 param_1,int param_2)

{
  uint uVar1;
  
  if (param_2 - 1U < 0xc) {
    uVar1 = 1 << (param_2 - 1U & 0xff) & 0xd0b;
    if (uVar1 != 0) {
      uVar1 = 1;
    }
    return uVar1;
  }
  return 0;
}

