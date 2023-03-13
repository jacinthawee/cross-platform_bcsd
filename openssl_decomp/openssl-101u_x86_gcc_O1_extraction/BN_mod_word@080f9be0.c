
ulong BN_mod_word(BIGNUM *a,ulong w)

{
  ulong *puVar1;
  ulong *puVar2;
  ulong uVar3;
  int iVar4;
  
  uVar3 = 0xffffffff;
  if (w != 0) {
    iVar4 = a->top + -1;
    if (-1 < iVar4) {
      uVar3 = 0;
      puVar2 = a->d;
      do {
        puVar1 = puVar2 + iVar4;
        iVar4 = iVar4 + -1;
        uVar3 = __umoddi3(*puVar1,uVar3,w,0);
      } while (iVar4 != -1);
      return uVar3;
    }
    uVar3 = 0;
  }
  return uVar3;
}

