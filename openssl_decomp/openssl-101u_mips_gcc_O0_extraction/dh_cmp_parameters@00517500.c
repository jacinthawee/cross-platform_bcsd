
bool dh_cmp_parameters(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_BN_cmp_006a7960)
                    (*(undefined4 *)(*(int *)(param_1 + 0x14) + 8),
                     *(undefined4 *)(*(int *)(param_2 + 0x14) + 8));
  if (iVar1 != 0) {
    return false;
  }
  iVar1 = (*(code *)PTR_BN_cmp_006a7960)
                    (*(undefined4 *)(*(int *)(param_1 + 0x14) + 0xc),
                     *(undefined4 *)(*(int *)(param_2 + 0x14) + 0xc));
  return iVar1 == 0;
}

