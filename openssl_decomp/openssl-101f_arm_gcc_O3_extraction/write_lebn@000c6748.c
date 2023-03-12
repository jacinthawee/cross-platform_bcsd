
void write_lebn(uchar **param_1,BIGNUM *param_2,int param_3)

{
  uchar uVar1;
  int iVar2;
  uchar *puVar3;
  uchar *puVar4;
  uchar *puVar5;
  uchar *puVar6;
  int iVar7;
  size_t __n;
  
  puVar4 = *param_1;
  iVar2 = BN_num_bits(param_2);
  iVar7 = iVar2 + 0xe;
  if (-1 < iVar2 + 7) {
    iVar7 = iVar2 + 7;
  }
  BN_bn2bin(param_2,puVar4);
  iVar2 = iVar7 >> 3;
  iVar7 = iVar2 - (iVar7 >> 0x1f) >> 1;
  if (0 < iVar7) {
    puVar3 = puVar4 + iVar2 + -1;
    puVar5 = puVar4;
    do {
      uVar1 = *puVar5;
      puVar6 = puVar5 + 1;
      *puVar5 = *puVar3;
      *puVar3 = uVar1;
      puVar3 = puVar3 + -1;
      puVar5 = puVar6;
    } while (puVar6 != puVar4 + iVar7);
  }
  puVar4 = *param_1;
  *param_1 = puVar4 + iVar2;
  if (param_3 < 1) {
    return;
  }
  __n = param_3 - iVar2;
  if (0 < (int)__n) {
    memset(puVar4 + iVar2,0,__n);
    *param_1 = *param_1 + __n;
  }
  return;
}

