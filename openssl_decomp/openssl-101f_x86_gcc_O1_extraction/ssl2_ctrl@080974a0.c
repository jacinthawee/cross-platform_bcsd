
undefined4 ssl2_ctrl(int param_1,int param_2)

{
  if (param_2 == 8) {
    return *(undefined4 *)(param_1 + 0x6c);
  }
  return 0;
}

