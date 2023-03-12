
int tls1_new(int param_1)

{
  int iVar1;
  
  iVar1 = ssl3_new(param_1);
  if (iVar1 != 0) {
    (**(code **)(*(int *)(param_1 + 8) + 8))(param_1);
    iVar1 = 1;
  }
  return iVar1;
}

