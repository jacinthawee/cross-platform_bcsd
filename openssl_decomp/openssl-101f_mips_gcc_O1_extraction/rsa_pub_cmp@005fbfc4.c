
bool rsa_pub_cmp(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_BN_cmp_006a8a4c)
                    (*(undefined4 *)(*(int *)(param_2 + 0x14) + 0x10),
                     *(undefined4 *)(*(int *)(param_1 + 0x14) + 0x10));
  if (iVar1 != 0) {
    return false;
  }
  iVar1 = (*(code *)PTR_BN_cmp_006a8a4c)
                    (*(undefined4 *)(*(int *)(param_2 + 0x14) + 0x14),
                     *(undefined4 *)(*(int *)(param_1 + 0x14) + 0x14));
  return iVar1 == 0;
}

