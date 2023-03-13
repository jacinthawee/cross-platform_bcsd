
void BN_swap(BIGNUM *a,BIGNUM *b)

{
  int iVar1;
  uint uVar2;
  ulong *puVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  
  iVar1 = a->dmax;
  uVar2 = b->flags;
  puVar3 = a->d;
  iVar4 = a->top;
  uVar5 = a->flags;
  iVar6 = a->neg;
  a->d = b->d;
  a->top = b->top;
  a->dmax = b->dmax;
  a->neg = b->neg;
  b->d = puVar3;
  b->neg = iVar6;
  b->dmax = iVar1;
  b->top = iVar4;
  a->flags = uVar2 & 2 | uVar5 & 1;
  b->flags = uVar5 & 2 | uVar2 & 1;
  return;
}

