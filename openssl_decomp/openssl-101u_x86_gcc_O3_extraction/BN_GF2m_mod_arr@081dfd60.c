
undefined4 BN_GF2m_mod_arr(BIGNUM *param_1,BIGNUM *param_2,int *param_3)

{
  ulong *puVar1;
  ulong *puVar2;
  int iVar3;
  undefined4 uVar4;
  BIGNUM *pBVar5;
  int words;
  
  if (*param_3 == 0) {
    BN_set_word(param_1,0);
    return 1;
  }
  if (param_1 != param_2) {
    words = param_2->top;
    if (param_1->dmax < words) {
      pBVar5 = bn_expand2(param_1,words);
      if (pBVar5 == (BIGNUM *)0x0) {
        return 0;
      }
      words = param_2->top;
    }
    if (0 < words) {
      puVar1 = param_1->d;
      puVar2 = param_2->d;
      iVar3 = 0;
      do {
        puVar1[iVar3] = puVar2[iVar3];
        words = param_2->top;
        iVar3 = iVar3 + 1;
      } while (iVar3 < words);
    }
    param_1->top = words;
  }
  uVar4 = BN_GF2m_mod_arr_part_0();
  return uVar4;
}

