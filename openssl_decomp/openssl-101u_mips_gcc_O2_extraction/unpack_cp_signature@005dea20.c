
undefined4 * unpack_cp_signature(char *param_1,uint param_2)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  char *pcVar4;
  uint uVar5;
  
  puVar2 = (undefined4 *)(*(code *)PTR_DSA_SIG_new_006a875c)();
  if (puVar2 == (undefined4 *)0x0) {
    (*(code *)PTR_ERR_GOST_error_006a95e4)(0x89,0x76,"gost_sign.c",0x146);
    puVar2 = (undefined4 *)0x0;
  }
  else {
    param_2 = param_2 >> 1;
    cVar1 = *param_1;
    uVar5 = param_2;
    pcVar4 = param_1;
    while (cVar1 == '\0') {
      if (uVar5 == 0) goto LAB_005deb14;
      pcVar4 = pcVar4 + 1;
      uVar5 = uVar5 - 1;
      cVar1 = *pcVar4;
    }
    if (uVar5 == 0) {
LAB_005deb14:
      uVar3 = (*(code *)PTR_BN_new_006a71b4)();
      (*(code *)PTR_BN_set_word_006a7730)(uVar3,0);
      param_1 = param_1 + param_2;
      puVar2[1] = uVar3;
      cVar1 = *param_1;
    }
    else {
      uVar3 = (*(code *)PTR_BN_bin2bn_006a7904)(pcVar4,uVar5,0);
      param_1 = param_1 + param_2;
      puVar2[1] = uVar3;
      cVar1 = *param_1;
    }
    while (cVar1 == '\0') {
      if (param_2 == 0) goto LAB_005deb5c;
      param_1 = param_1 + 1;
      param_2 = param_2 - 1;
      cVar1 = *param_1;
    }
    if (param_2 == 0) {
LAB_005deb5c:
      uVar3 = (*(code *)PTR_BN_new_006a71b4)();
      (*(code *)PTR_BN_set_word_006a7730)(uVar3,0);
    }
    else {
      uVar3 = (*(code *)PTR_BN_bin2bn_006a7904)(param_1,param_2,0);
    }
    *puVar2 = uVar3;
  }
  return puVar2;
}

