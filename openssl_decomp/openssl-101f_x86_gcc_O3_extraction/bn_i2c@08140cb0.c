
int bn_i2c(BIGNUM **param_1,uchar *param_2)

{
  BIGNUM *a;
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  a = *param_1;
  if (a == (BIGNUM *)0x0) {
    return -1;
  }
  uVar1 = BN_num_bits(a);
  if ((uVar1 & 7) == 0) {
    iVar4 = 1;
    if (param_2 == (uchar *)0x0) goto LAB_08140ce4;
    *param_2 = '\0';
    iVar4 = 1;
    param_2 = param_2 + 1;
  }
  else {
    iVar4 = 0;
    if (param_2 == (uchar *)0x0) goto LAB_08140ce4;
  }
  BN_bn2bin(a,param_2);
LAB_08140ce4:
  iVar2 = BN_num_bits(a);
  iVar3 = iVar2 + 7;
  if (iVar2 + 7 < 0) {
    iVar3 = iVar2 + 0xe;
  }
  return (iVar3 >> 3) + iVar4;
}

