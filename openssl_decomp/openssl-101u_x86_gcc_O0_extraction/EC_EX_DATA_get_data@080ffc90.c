
int EC_EX_DATA_get_data(int *param_1,int param_2,int param_3,int param_4)

{
  if (param_1 == (int *)0x0) {
    return 0;
  }
  while (((param_1[2] != param_2 || (param_1[3] != param_3)) || (param_1[4] != param_4))) {
    param_1 = (int *)*param_1;
    if (param_1 == (int *)0x0) {
      return 0;
    }
  }
  return param_1[1];
}
