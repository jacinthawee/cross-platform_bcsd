
undefined4 BN_GF2m_arr2poly(int *param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  
  (*(code *)PTR_BN_set_word_006a8820)(param_2,0);
  if (*param_1 != -1) {
    piVar2 = param_1 + 1;
    do {
      iVar1 = (*(code *)PTR_BN_set_bit_006a9710)(param_2);
      if (iVar1 == 0) {
        return 0;
      }
      iVar1 = *piVar2;
      piVar2 = piVar2 + 1;
    } while (iVar1 != -1);
  }
  return 1;
}

