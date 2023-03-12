
void bn_free(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (iVar1 != 0) {
    if ((*(uint *)(param_2 + 0x14) & 1) == 0) {
      (*(code *)PTR_BN_free_006a811c)(iVar1);
    }
    else {
      (*(code *)PTR_BN_clear_free_006a9130)(iVar1);
    }
    *param_1 = 0;
  }
  return;
}

