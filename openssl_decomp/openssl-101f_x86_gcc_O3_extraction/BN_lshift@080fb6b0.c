
int BN_lshift(BIGNUM *r,BIGNUM *a,int n)

{
  ulong *puVar1;
  ulong *__s;
  uint uVar2;
  byte bVar3;
  int iVar4;
  uint uVar5;
  BIGNUM *pBVar6;
  int iVar7;
  uint *puVar8;
  
  iVar7 = a->top;
  r->neg = a->neg;
  iVar4 = n + 0x1f;
  if (-1 < n) {
    iVar4 = n;
  }
  iVar4 = iVar4 >> 5;
  iVar7 = iVar7 + iVar4;
  if (r->dmax <= iVar7) {
    pBVar6 = bn_expand2(r,iVar7 + 1);
    if (pBVar6 == (BIGNUM *)0x0) {
      return 0;
    }
    iVar7 = iVar4 + a->top;
  }
  puVar1 = a->d;
  __s = r->d;
  __s[iVar7] = 0;
  if (n % 0x20 == 0) {
    iVar7 = a->top + -1;
    if (-1 < iVar7) {
      do {
        __s[iVar4 + iVar7] = puVar1[iVar7];
        iVar7 = iVar7 + -1;
      } while (iVar7 != -1);
    }
  }
  else {
    iVar7 = a->top + -1;
    if (-1 < iVar7) {
      uVar5 = __s[a->top + iVar4];
      bVar3 = (byte)(n % 0x20);
      puVar8 = __s + iVar4 + iVar7;
      do {
        uVar2 = puVar1[iVar7];
        iVar7 = iVar7 + -1;
        puVar8[1] = uVar5 | uVar2 >> (0x20 - bVar3 & 0x1f);
        uVar5 = uVar2 << (bVar3 & 0x1f);
        *puVar8 = uVar5;
        puVar8 = puVar8 + -1;
      } while (iVar7 != -1);
    }
  }
  memset(__s,0,iVar4 << 2);
  iVar7 = a->top + iVar4 + 1;
  r->top = iVar7;
  if (0 < iVar7) {
    do {
      if (r->d[iVar7 + -1] != 0) break;
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
    r->top = iVar7;
  }
  return 1;
}

