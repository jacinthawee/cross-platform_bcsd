
uint pkey_hmac_ctrl(int param_1,int param_2,int param_3,EVP_MD *param_4)

{
  uint uVar1;
  int *piVar2;
  EVP_MD **ppEVar3;
  
  ppEVar3 = *(EVP_MD ***)(param_1 + 0x14);
  if (param_2 == 6) {
    uVar1 = count_leading_zeroes(param_4);
    uVar1 = uVar1 >> 5;
    if (param_3 < 1) {
      uVar1 = 0;
    }
    if (uVar1 == 0) {
      if ((param_3 + 1 < 0 == SCARRY4(param_3,1)) &&
         (uVar1 = ASN1_OCTET_STRING_set((ASN1_STRING *)(ppEVar3 + 1),param_4,param_3), uVar1 != 0))
      {
        uVar1 = 1;
      }
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    if (param_2 == 7) {
      piVar2 = *(int **)(*(int *)(param_1 + 8) + 0x14);
      uVar1 = HMAC_Init_ex((HMAC_CTX *)(ppEVar3 + 5),(void *)piVar2[2],*piVar2,*ppEVar3,
                           *(ENGINE **)(param_1 + 4));
      if (uVar1 != 0) {
        uVar1 = 1;
      }
      return uVar1;
    }
    if (param_2 == 1) {
      *ppEVar3 = param_4;
      return 1;
    }
    uVar1 = 0xfffffffe;
  }
  return uVar1;
}

