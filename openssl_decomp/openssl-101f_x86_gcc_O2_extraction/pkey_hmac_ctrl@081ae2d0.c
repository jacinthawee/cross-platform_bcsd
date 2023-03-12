
uint pkey_hmac_ctrl(int param_1,int param_2,int param_3,EVP_MD *param_4)

{
  EVP_MD **ppEVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  
  ppEVar1 = *(EVP_MD ***)(param_1 + 0x14);
  if (param_2 == 6) {
    if ((param_3 < 1 || param_4 != (EVP_MD *)0x0) && (-2 < param_3)) {
      iVar4 = ASN1_OCTET_STRING_set((ASN1_STRING *)(ppEVar1 + 1),param_4,param_3);
      uVar3 = (uint)(iVar4 != 0);
    }
    else {
      uVar3 = 0;
    }
  }
  else {
    if (param_2 == 7) {
      piVar2 = *(int **)(*(int *)(param_1 + 8) + 0x14);
      iVar4 = HMAC_Init_ex((HMAC_CTX *)(ppEVar1 + 5),(void *)piVar2[2],*piVar2,*ppEVar1,
                           *(ENGINE **)(param_1 + 4));
      return (uint)(iVar4 != 0);
    }
    if (param_2 == 1) {
      *ppEVar1 = param_4;
      return 1;
    }
    uVar3 = 0xfffffffe;
  }
  return uVar3;
}

