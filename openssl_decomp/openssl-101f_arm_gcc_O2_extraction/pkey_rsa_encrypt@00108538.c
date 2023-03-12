
int pkey_rsa_encrypt(int param_1,uchar *param_2,int *param_3,uchar *param_4,int param_5)

{
  int iVar1;
  
  iVar1 = RSA_public_encrypt(param_5,param_4,param_2,*(RSA **)(*(int *)(param_1 + 8) + 0x14),
                             *(int *)(*(int *)(param_1 + 0x14) + 0x10));
  if (-1 < iVar1) {
    *param_3 = iVar1;
    iVar1 = 1;
  }
  return iVar1;
}

