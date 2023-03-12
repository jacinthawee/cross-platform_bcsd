
int BN_asc2bn(BIGNUM **a,char *str)

{
  byte bVar1;
  char cVar4;
  int *piVar2;
  BIGNUM *pBVar3;
  byte *pbVar5;
  int iVar6;
  ulong *puVar7;
  int iVar8;
  ulong w;
  ulong uVar9;
  byte *pbVar10;
  int iVar11;
  int iVar12;
  BIGNUM *a_00;
  
  cVar4 = *str;
  pbVar10 = (byte *)str;
  if (cVar4 == '-') {
    cVar4 = str[1];
    pbVar10 = (byte *)(str + 1);
  }
  if (cVar4 == '0') {
    if ((pbVar10[1] & 0xdf) == 0x58) {
      iVar11 = BN_hex2bn(a,(char *)(pbVar10 + 2));
joined_r0x004f8b4c:
      if (iVar11 == 0) {
        return 0;
      }
      if (*str == '-') {
        (*a)->neg = 1;
        return 1;
      }
      return 1;
    }
  }
  else {
    if (cVar4 == '\0') {
      return 0;
    }
    iVar11 = 1;
    if (cVar4 == '-') {
      pbVar10 = pbVar10 + 1;
      goto LAB_004f89d8;
    }
  }
  iVar11 = 0;
LAB_004f89d8:
  iVar12 = 0;
  piVar2 = (int *)(*(code *)PTR___ctype_b_loc_006a9938)();
  pbVar5 = pbVar10;
  while (bVar1 = *pbVar5, pbVar5 = pbVar5 + 1, (*(ushort *)(*piVar2 + (uint)bVar1 * 2) & 8) != 0) {
    iVar12 = iVar12 + 1;
    a_00 = (BIGNUM *)0x0;
    if (iVar12 == 0x20000000) {
LAB_004f8a1c:
      pBVar3 = *a;
LAB_004f8a20:
      if (pBVar3 == (BIGNUM *)0x0) {
        BN_free(a_00);
      }
      return 0;
    }
  }
  if (a == (BIGNUM **)0x0) goto LAB_004f8c14;
  a_00 = *a;
  if (a_00 == (BIGNUM *)0x0) {
    a_00 = BN_new();
    if (a_00 == (BIGNUM *)0x0) {
      return 0;
    }
  }
  else {
    BN_set_word(a_00,0);
  }
  if (0x7fffffe0 < iVar12 * 4) goto LAB_004f8a1c;
  iVar8 = iVar12 * 4 + 0x1f >> 5;
  if ((a_00->dmax < iVar8) && (pBVar3 = bn_expand2(a_00,iVar8), pBVar3 == (BIGNUM *)0x0)) {
    pBVar3 = *a;
    goto LAB_004f8a20;
  }
  iVar8 = (iVar12 / 9) * 9 - iVar12;
  iVar6 = iVar8 + 9;
  uVar9 = 0;
  if (iVar8 == 0) {
    iVar6 = 0;
  }
  while( true ) {
    bVar1 = *pbVar10;
    iVar6 = iVar6 + 1;
    if ((char)bVar1 == 0) break;
    pbVar10 = pbVar10 + 1;
    w = (int)(char)bVar1 + uVar9 * 10 + -0x30;
    uVar9 = w;
    if (iVar6 == 9) {
      BN_mul_word(a_00,1000000000);
      uVar9 = 0;
      BN_add_word(a_00,w);
      iVar6 = 0;
    }
  }
  iVar8 = a_00->top;
  a_00->neg = iVar11;
  if (0 < iVar8) {
    puVar7 = a_00->d + iVar8 + -2;
    do {
      if (puVar7[1] != 0) break;
      iVar8 = iVar8 + -1;
      puVar7 = puVar7 + -1;
    } while (iVar8 != 0);
    a_00->top = iVar8;
  }
  *a = a_00;
LAB_004f8c14:
  iVar11 = iVar11 + iVar12;
  goto joined_r0x004f8b4c;
}

