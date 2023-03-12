
int BN_lshift(BIGNUM *r,BIGNUM *a,int n)

{
  BIGNUM *pBVar1;
  uint uVar2;
  int iVar3;
  size_t __n;
  int iVar4;
  int iVar5;
  ulong *puVar6;
  uint uVar7;
  ulong *puVar8;
  ulong *puVar9;
  ulong *__s;
  char in_CY;
  
  uVar2 = n + 0x1fU & n >> 0x20;
  if (in_CY == '\0') {
    uVar2 = n;
  }
  iVar5 = (int)uVar2 >> 5;
  iVar4 = a->top + iVar5;
  r->neg = a->neg;
  if (r->dmax <= iVar4) {
    pBVar1 = bn_expand2(r,iVar4 + 1);
    if (pBVar1 == (BIGNUM *)0x0) {
      return 0;
    }
    iVar4 = a->top + iVar5;
  }
  __s = r->d;
  puVar9 = a->d;
  iVar3 = 0;
  __s[iVar4] = 0;
  iVar4 = a->top;
  uVar2 = n % 0x20;
  if (uVar2 == 0) {
    if (0 < iVar4) {
      __n = iVar5 * 4;
      puVar9 = puVar9 + iVar4;
      puVar6 = __s + iVar5 + iVar4;
      do {
        puVar9 = puVar9 + -1;
        puVar6 = puVar6 + -1;
        *puVar6 = *puVar9;
      } while (puVar6 != __s + iVar5);
      goto LAB_0008d210;
    }
  }
  else if (0 < iVar4) {
    puVar9 = puVar9 + iVar4;
    puVar8 = __s + iVar5 + iVar4;
    puVar6 = puVar8;
    do {
      puVar9 = puVar9 + -1;
      uVar7 = *puVar9;
      *(uint *)((int)puVar8 + iVar3) =
           uVar7 >> (0x20 - uVar2 & 0xff) | *(uint *)((int)puVar8 + iVar3);
      iVar3 = iVar3 + -4;
      puVar6 = puVar6 + -1;
      *puVar6 = uVar7 << (uVar2 & 0xff);
    } while (iVar3 != iVar4 * -4);
  }
  __n = iVar5 << 2;
LAB_0008d210:
  memset(__s,0,__n);
  iVar5 = a->top + iVar5;
  iVar4 = iVar5 + 1;
  r->top = iVar4;
  if (0 < iVar4) {
    puVar9 = r->d + iVar5;
    do {
      if (*puVar9 != 0) break;
      iVar4 = iVar4 + -1;
      puVar9 = puVar9 + -1;
    } while (iVar4 != 0);
    r->top = iVar4;
  }
  return 1;
}

