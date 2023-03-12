
bool rinf_cb(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  
  if (param_1 != 1) {
    return true;
  }
  iVar2 = *param_2;
  iVar1 = (*(code *)PTR_sk_new_null_006a80a4)();
  *(int *)(iVar2 + 0x18) = iVar1;
  return iVar1 != 0;
}

