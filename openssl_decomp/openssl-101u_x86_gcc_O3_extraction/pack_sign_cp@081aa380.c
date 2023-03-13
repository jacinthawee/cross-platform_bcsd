
undefined4 pack_sign_cp(DSA_SIG *param_1,size_t param_2,void *param_3,size_t *param_4)

{
  BIGNUM *pBVar1;
  int iVar2;
  int iVar3;
  
  *param_4 = param_2 * 2;
  memset(param_3,0,param_2 * 2);
  pBVar1 = param_1->s;
  iVar2 = BN_num_bits(pBVar1);
  iVar3 = iVar2 + 7;
  if (iVar2 + 7 < 0) {
    iVar3 = iVar2 + 0xe;
  }
  if (iVar3 >> 3 <= (int)param_2) {
    memset(param_3,0,param_2);
    BN_bn2bin(pBVar1,(uchar *)((param_2 - (iVar3 >> 3)) + (int)param_3));
  }
  pBVar1 = param_1->r;
  iVar2 = BN_num_bits(pBVar1);
  iVar3 = iVar2 + 7;
  if (iVar2 + 7 < 0) {
    iVar3 = iVar2 + 0xe;
  }
  if (iVar3 >> 3 <= (int)param_2) {
    memset((void *)((int)param_3 + param_2),0,param_2);
    BN_bn2bin(pBVar1,(uchar *)((param_2 - (iVar3 >> 3)) + (int)(void *)((int)param_3 + param_2)));
  }
  DSA_SIG_free(param_1);
  return 1;
}

