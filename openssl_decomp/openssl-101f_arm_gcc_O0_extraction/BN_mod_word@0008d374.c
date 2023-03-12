
ulong BN_mod_word(BIGNUM *a,ulong w)

{
  ulong uVar1;
  ulong uVar2;
  int iVar3;
  ulong *puVar4;
  
  if (w == 0) {
    return 0xffffffff;
  }
  iVar3 = a->top + -1;
  if (-1 < iVar3) {
    puVar4 = a->d + a->top;
    uVar2 = 0;
    do {
      puVar4 = puVar4 + -1;
      iVar3 = iVar3 + -1;
      uVar1 = w;
      __aeabi_uldivmod(*puVar4,uVar2,w,0);
      uVar2 = uVar1;
    } while (iVar3 != -1);
    return uVar1;
  }
  return 0;
}

