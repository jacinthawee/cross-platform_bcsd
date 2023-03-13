
int BN_lshift(BIGNUM *r,BIGNUM *a,int n)

{
  ulong *puVar1;
  ulong *__s;
  uint uVar2;
  sbyte sVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  BIGNUM *pBVar7;
  uint *puVar8;
  
  if (n < 0) {
    ERR_put_error(3,0x91,0x77,"bn_shift.c",0x8d);
    iVar4 = 0;
  }
  else {
    r->neg = a->neg;
    iVar4 = n >> 5;
    iVar5 = iVar4 + a->top;
    if (r->dmax <= iVar5) {
      pBVar7 = bn_expand2(r,iVar5 + 1);
      if (pBVar7 == (BIGNUM *)0x0) {
        return 0;
      }
      iVar5 = iVar4 + a->top;
    }
    puVar1 = a->d;
    __s = r->d;
    __s[iVar5] = 0;
    if ((n & 0x1fU) == 0) {
      iVar5 = a->top + -1;
      if (-1 < iVar5) {
        do {
          __s[iVar4 + iVar5] = puVar1[iVar5];
          iVar5 = iVar5 + -1;
        } while (iVar5 != -1);
      }
    }
    else {
      iVar5 = a->top + -1;
      if (-1 < iVar5) {
        uVar6 = __s[a->top + iVar4];
        sVar3 = (sbyte)(n & 0x1fU);
        puVar8 = __s + iVar4 + iVar5;
        do {
          uVar2 = puVar1[iVar5];
          iVar5 = iVar5 + -1;
          puVar8[1] = uVar6 | uVar2 >> (0x20U - sVar3 & 0x1f);
          uVar6 = uVar2 << sVar3;
          *puVar8 = uVar6;
          puVar8 = puVar8 + -1;
        } while (iVar5 != -1);
      }
    }
    memset(__s,0,iVar4 << 2);
    iVar4 = a->top + iVar4 + 1;
    r->top = iVar4;
    if (0 < iVar4) {
      do {
        if (r->d[iVar4 + -1] != 0) break;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
      r->top = iVar4;
    }
    iVar4 = 1;
  }
  return iVar4;
}

