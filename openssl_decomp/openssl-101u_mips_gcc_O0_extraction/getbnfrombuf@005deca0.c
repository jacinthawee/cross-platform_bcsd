
undefined4 getbnfrombuf(char *param_1,int param_2)

{
  char cVar1;
  undefined4 uVar2;
  
  cVar1 = *param_1;
  while (cVar1 == '\0') {
    param_1 = param_1 + 1;
    if (param_2 == 0) goto LAB_005decf4;
    param_2 = param_2 + -1;
    cVar1 = *param_1;
  }
  if (param_2 != 0) {
                    /* WARNING: Could not recover jumptable at 0x005decec. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*(code *)PTR_BN_bin2bn_006a7904)(param_1,param_2,0);
    return uVar2;
  }
LAB_005decf4:
  uVar2 = (*(code *)PTR_BN_new_006a71b4)();
  (*(code *)PTR_BN_set_word_006a7730)(uVar2,0);
  return uVar2;
}

