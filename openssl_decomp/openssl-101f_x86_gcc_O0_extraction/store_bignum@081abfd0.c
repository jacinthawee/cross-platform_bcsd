
bool store_bignum(BIGNUM *param_1,void *param_2,size_t param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = BN_num_bits(param_1);
  iVar2 = iVar1 + 7;
  if (iVar1 + 7 < 0) {
    iVar2 = iVar1 + 0xe;
  }
  iVar2 = iVar2 >> 3;
  if (iVar2 <= (int)param_3) {
    memset(param_2,0,param_3);
    BN_bn2bin(param_1,(uchar *)((param_3 - iVar2) + (int)param_2));
  }
  return iVar2 <= (int)param_3;
}

