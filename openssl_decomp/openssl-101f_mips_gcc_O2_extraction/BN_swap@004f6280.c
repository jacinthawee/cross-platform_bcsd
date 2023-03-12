
void BN_swap(BIGNUM *a,BIGNUM *b)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  ulong *puVar7;
  int iVar8;
  int iVar9;
  
  uVar2 = a->flags;
  uVar1 = b->flags;
  puVar7 = a->d;
  iVar6 = a->top;
  iVar5 = a->dmax;
  iVar4 = a->neg;
  iVar9 = b->top;
  iVar8 = b->dmax;
  iVar3 = b->neg;
  a->d = b->d;
  a->top = iVar9;
  a->dmax = iVar8;
  a->neg = iVar3;
  b->d = puVar7;
  b->top = iVar6;
  b->dmax = iVar5;
  b->neg = iVar4;
  a->flags = uVar2 & 1 | uVar1 & 2;
  b->flags = uVar1 & 1 | uVar2 & 2;
  return;
}

