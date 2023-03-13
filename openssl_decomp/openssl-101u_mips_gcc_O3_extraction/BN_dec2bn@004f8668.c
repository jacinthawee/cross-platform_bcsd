
int BN_dec2bn(BIGNUM **a,char *str)

{
  char cVar1;
  byte bVar2;
  int *piVar3;
  BIGNUM *pBVar4;
  byte *pbVar5;
  ulong *puVar6;
  int iVar7;
  ulong w;
  uint uVar8;
  int iVar9;
  int iVar10;
  BIGNUM *a_00;
  
  if (str == (char *)0x0) {
    return 0;
  }
  cVar1 = *str;
  if (cVar1 != '\0') {
    if (cVar1 == '-') {
      str = str + 1;
    }
    uVar8 = (uint)(cVar1 == '-');
    iVar10 = 0;
    piVar3 = (int *)(*(code *)PTR___ctype_b_loc_006a9938)();
    pbVar5 = (byte *)str;
    do {
      bVar2 = *pbVar5;
      pbVar5 = pbVar5 + 1;
      if ((*(ushort *)(*piVar3 + (uint)bVar2 * 2) & 8) == 0) {
        iVar9 = uVar8 + iVar10;
        if (a == (BIGNUM **)0x0) {
          return iVar9;
        }
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
        if (iVar10 * 4 < 0x7fffffe1) {
          iVar7 = iVar10 * 4 + 0x1f >> 5;
          if ((iVar7 <= a_00->dmax) || (pBVar4 = bn_expand2(a_00,iVar7), pBVar4 != (BIGNUM *)0x0)) {
            w = 0;
            iVar10 = (iVar10 / 9) * 9 - iVar10;
            iVar7 = iVar10 + 9;
            if (iVar10 == 0) {
              iVar7 = 0;
            }
            do {
              bVar2 = *str;
              iVar10 = w * 10;
              while( true ) {
                if ((char)bVar2 == 0) {
                  iVar10 = a_00->top;
                  a_00->neg = uVar8;
                  if (iVar10 < 1) goto LAB_004f8888;
                  puVar6 = a_00->d + iVar10 + -2;
                  goto LAB_004f8868;
                }
                iVar7 = iVar7 + 1;
                str = (char *)((byte *)str + 1);
                w = (int)(char)bVar2 + iVar10 + -0x30;
                if (iVar7 != 9) break;
                BN_mul_word(a_00,1000000000);
                BN_add_word(a_00,w);
                bVar2 = *str;
                iVar7 = 0;
                iVar10 = 0;
              }
            } while( true );
          }
          pBVar4 = *a;
          goto LAB_004f8708;
        }
        break;
      }
      iVar10 = iVar10 + 1;
      a_00 = (BIGNUM *)0x0;
    } while (iVar10 != 0x20000000);
    pBVar4 = *a;
LAB_004f8708:
    if (pBVar4 == (BIGNUM *)0x0) {
      BN_free(a_00);
      return 0;
    }
  }
  return 0;
  while( true ) {
    iVar10 = iVar10 + -1;
    puVar6 = puVar6 + -1;
    if (iVar10 == 0) break;
LAB_004f8868:
    if (puVar6[1] != 0) break;
  }
  a_00->top = iVar10;
LAB_004f8888:
  *a = a_00;
  return iVar9;
}

