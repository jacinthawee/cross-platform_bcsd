
void BN_swap(BIGNUM *a,BIGNUM *b)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  ulong *puVar6;
  int iVar7;
  ulong *puVar8;
  
  uVar2 = b->flags;
  puVar6 = b->d;
  iVar5 = b->top;
  iVar1 = a->dmax;
  a->dmax = b->dmax;
  puVar8 = a->d;
  iVar4 = a->top;
  iVar7 = a->neg;
  a->neg = b->neg;
  uVar3 = a->flags;
  a->d = puVar6;
  a->top = iVar5;
  b->d = puVar8;
  b->top = iVar4;
  b->neg = iVar7;
  b->dmax = iVar1;
  a->flags = uVar2 & 2 | uVar3 & 1;
  b->flags = uVar3 & 2 | uVar2 & 1;
  return;
}

