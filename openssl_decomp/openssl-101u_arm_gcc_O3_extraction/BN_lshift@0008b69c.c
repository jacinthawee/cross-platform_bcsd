
int BN_lshift(BIGNUM *r,BIGNUM *a,int n)

{
  BIGNUM *pBVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  size_t __n;
  int iVar5;
  ulong *puVar6;
  uint uVar7;
  ulong *puVar8;
  ulong *puVar9;
  ulong *__s;
  
  if (n < 0) {
    ERR_put_error(3,0x91,0x77,"bn_shift.c",0x8d);
    return 0;
  }
  iVar5 = n >> 5;
  iVar2 = a->top + iVar5;
  r->neg = a->neg;
  if (r->dmax <= iVar2) {
    pBVar1 = bn_expand2(r,iVar2 + 1);
    if (pBVar1 == (BIGNUM *)0x0) {
      return 0;
    }
    iVar2 = a->top + iVar5;
  }
  __s = r->d;
  iVar4 = 0;
  puVar9 = a->d;
  __s[iVar2] = 0;
  uVar3 = n & 0x1f;
  iVar2 = a->top;
  if (uVar3 == 0) {
    if (0 < iVar2) {
      __n = iVar5 * 4;
      puVar9 = puVar9 + iVar2;
      puVar6 = __s + iVar5 + iVar2;
      do {
        puVar9 = puVar9 + -1;
        puVar6 = puVar6 + -1;
        *puVar6 = *puVar9;
      } while (puVar6 != __s + iVar5);
      goto LAB_0008b6f8;
    }
  }
  else if (0 < iVar2) {
    puVar9 = puVar9 + iVar2;
    puVar8 = __s + iVar5 + iVar2;
    puVar6 = puVar8;
    do {
      puVar9 = puVar9 + -1;
      uVar7 = *puVar9;
      *(uint *)((int)puVar8 + iVar4) =
           uVar7 >> (0x20 - uVar3 & 0xff) | *(uint *)((int)puVar8 + iVar4);
      iVar4 = iVar4 + -4;
      puVar6 = puVar6 + -1;
      *puVar6 = uVar7 << uVar3;
    } while (iVar4 != iVar2 * -4);
  }
  __n = iVar5 << 2;
LAB_0008b6f8:
  memset(__s,0,__n);
  iVar5 = a->top + iVar5;
  iVar2 = iVar5 + 1;
  r->top = iVar2;
  if (0 < iVar2) {
    puVar9 = r->d + iVar5;
    do {
      if (*puVar9 != 0) break;
      iVar2 = iVar2 + -1;
      puVar9 = puVar9 + -1;
    } while (iVar2 != 0);
    r->top = iVar2;
  }
  return 1;
}

