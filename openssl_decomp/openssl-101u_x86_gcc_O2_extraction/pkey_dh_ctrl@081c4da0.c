
int pkey_dh_ctrl(int param_1,int param_2,int param_3)

{
  if (param_2 == 0x1001) {
    if (0xff < param_3) {
      **(int **)(param_1 + 0x14) = param_3;
      return 1;
    }
    return -2;
  }
  if (param_2 != 0x1002) {
    return (uint)(param_2 == 2) * 3 + -2;
  }
  (*(int **)(param_1 + 0x14))[1] = param_3;
  return 1;
}

