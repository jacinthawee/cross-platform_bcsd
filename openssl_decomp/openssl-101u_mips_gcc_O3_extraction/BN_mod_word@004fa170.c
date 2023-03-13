
ulong BN_mod_word(BIGNUM *a,ulong w)

{
  ulong *puVar1;
  ulong extraout_v1;
  ulong uVar2;
  ulong *puVar3;
  ulong *puVar4;
  
  if (w != 0) {
    if (a->top < 1) {
      uVar2 = 0;
    }
    else {
      puVar4 = a->d;
      uVar2 = 0;
      puVar3 = puVar4 + a->top;
      do {
        puVar1 = puVar3 + -1;
        puVar3 = puVar3 + -1;
        (*(code *)PTR___umoddi3_006a85bc)(uVar2,*puVar1,0,w);
        uVar2 = extraout_v1;
      } while (puVar4 != puVar3);
    }
    return uVar2;
  }
  return 0xffffffff;
}

