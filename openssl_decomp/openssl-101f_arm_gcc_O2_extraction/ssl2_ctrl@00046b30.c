
undefined4 ssl2_ctrl(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 == 8) {
    uVar1 = *(undefined4 *)(param_1 + 0x6c);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

