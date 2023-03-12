
int i2c_ASN1_INTEGER(ASN1_INTEGER *a,uchar **pp)

{
  uchar *puVar1;
  byte *pbVar2;
  byte bVar3;
  uint uVar4;
  size_t __n;
  size_t sVar5;
  byte *pbVar6;
  byte *pbVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  
  if (a == (ASN1_INTEGER *)0x0) {
    return 0;
  }
  __n = a->length;
  uVar4 = a->type & 0x100;
  if (__n == 0) {
    iVar11 = 1;
    uVar8 = __n;
    uVar9 = __n;
    goto LAB_000b112e;
  }
  pbVar7 = a->data;
  bVar3 = *pbVar7;
  uVar9 = (uint)(bVar3 == 0 && __n == 1);
  if (bVar3 != 0 || __n != 1) {
    uVar10 = (uint)(0x7f < bVar3);
    if (uVar4 != 0) {
      uVar10 = 0;
    }
    if (uVar10 == 0) {
      uVar8 = uVar4;
      uVar9 = uVar4;
      if (uVar4 != 0) {
        if (bVar3 < 0x81) {
          uVar8 = uVar10;
          uVar9 = uVar10;
          if ((bVar3 != 0x80) || ((int)__n < 2)) goto LAB_000b112a;
          if (pbVar7[1] == 0) {
            pbVar2 = pbVar7 + 2;
            do {
              if (pbVar2 == pbVar7 + __n) {
                uVar8 = 0;
                uVar9 = 0;
                goto LAB_000b112a;
              }
              bVar3 = *pbVar2;
              pbVar2 = pbVar2 + 1;
            } while (bVar3 == 0);
          }
        }
        uVar8 = 1;
        uVar9 = 0xff;
      }
    }
    else {
      uVar4 = uVar9;
      uVar8 = 1;
    }
  }
  else {
    uVar4 = 0;
    uVar8 = 0;
    uVar9 = 0;
  }
LAB_000b112a:
  iVar11 = uVar8 + __n;
LAB_000b112e:
  if (pp == (uchar **)0x0) {
    return iVar11;
  }
  puVar1 = *pp;
  if (uVar8 != 0) {
    *puVar1 = (uchar)uVar9;
    puVar1 = puVar1 + 1;
    __n = a->length;
  }
  if (__n == 0) {
    *puVar1 = '\0';
  }
  else {
    if (uVar4 == 0) {
      memcpy(puVar1,a->data,__n);
      *pp = *pp + iVar11;
      return iVar11;
    }
    sVar5 = __n - 1;
    pbVar7 = puVar1 + sVar5;
    puVar1 = a->data + sVar5;
    bVar3 = a->data[sVar5];
    if (bVar3 == 0) {
      pbVar2 = pbVar7;
      if (1 < (int)__n) {
        while( true ) {
          __n = sVar5;
          puVar1 = puVar1 + -1;
          pbVar7 = pbVar2 + -1;
          *pbVar2 = 0;
          if (*puVar1 != '\0') break;
          sVar5 = __n - 1;
          pbVar2 = pbVar7;
          if (__n == 1) {
            *pbVar7 = 0;
            *pp = *pp + iVar11;
            return iVar11;
          }
        }
        bVar3 = -*puVar1;
      }
    }
    else {
      bVar3 = -bVar3;
    }
    *pbVar7 = bVar3;
    if (1 < (int)__n) {
      pbVar2 = puVar1 + -1;
      do {
        pbVar6 = pbVar2 + -1;
        pbVar7 = pbVar7 + -1;
        *pbVar7 = ~*pbVar2;
        pbVar2 = pbVar6;
      } while (pbVar6 != puVar1 + -__n);
      *pp = *pp + iVar11;
      return iVar11;
    }
  }
  *pp = *pp + iVar11;
  return iVar11;
}

