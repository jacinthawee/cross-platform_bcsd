
int BN_cmp(BIGNUM *a,BIGNUM *b)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  bool bVar8;
  
  if ((a == (BIGNUM *)0x0) || (b == (BIGNUM *)0x0)) {
    if (a == (BIGNUM *)0x0) {
      uVar4 = (uint)(b != (BIGNUM *)0x0);
    }
    else {
      uVar4 = 0xffffffff;
    }
  }
  else {
    iVar2 = a->neg;
    if (iVar2 != b->neg) {
      return (-(uint)(iVar2 == 0) & 2) - 1;
    }
    iVar5 = a->top;
    uVar7 = -(uint)(iVar2 == 0) | 1;
    uVar6 = (-(uint)(iVar2 == 0) & 2) - 1;
    uVar4 = uVar6;
    if ((iVar5 <= b->top) && (uVar4 = uVar7, b->top <= iVar5)) {
      iVar5 = iVar5 + -1;
      if (iVar5 < 0) {
LAB_080f50d3:
        uVar4 = 0;
      }
      else {
        uVar3 = b->d[iVar5];
        puVar1 = a->d + iVar5;
        bVar8 = uVar3 <= *puVar1;
        uVar4 = uVar6;
        if ((!bVar8 || *puVar1 == uVar3) && (uVar4 = uVar7, bVar8)) {
          do {
            iVar5 = iVar5 + -1;
            if (iVar5 == -1) goto LAB_080f50d3;
            uVar3 = b->d[iVar5];
            puVar1 = a->d + iVar5;
            bVar8 = uVar3 <= *puVar1;
            uVar4 = uVar6;
          } while ((!bVar8 || *puVar1 == uVar3) && (uVar4 = uVar7, bVar8));
        }
      }
    }
  }
  return uVar4;
}

