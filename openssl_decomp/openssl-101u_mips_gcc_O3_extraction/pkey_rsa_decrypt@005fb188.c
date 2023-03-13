
int pkey_rsa_decrypt(int param_1,undefined4 param_2,int *param_3,undefined4 param_4,
                    undefined4 param_5)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_RSA_private_decrypt_006a7644)
                    (param_5,param_4,param_2,*(undefined4 *)(*(int *)(param_1 + 8) + 0x14),
                     *(undefined4 *)(*(int *)(param_1 + 0x14) + 0x10));
  if (-1 < iVar1) {
    *param_3 = iVar1;
    iVar1 = 1;
  }
  return iVar1;
}

