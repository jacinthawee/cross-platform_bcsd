
undefined4 hashsum2bn(char *param_1)

{
  char cVar1;
  undefined *puVar2;
  char *pcVar3;
  undefined4 uVar4;
  char *pcVar5;
  int iVar6;
  char cStack_35;
  char local_34 [32];
  char *local_14;
  
  puVar2 = PTR___stack_chk_guard_006aabf0;
  local_14 = *(char **)PTR___stack_chk_guard_006aabf0;
  pcVar5 = local_34 + 0x1f;
  do {
    cVar1 = *param_1;
    pcVar3 = pcVar5 + -1;
    param_1 = param_1 + 1;
    *pcVar5 = cVar1;
    pcVar5 = pcVar3;
  } while (pcVar3 != &cStack_35);
  iVar6 = 0x20;
  pcVar5 = local_34;
  if (local_34[0] == '\0') {
    do {
      pcVar5 = pcVar5 + 1;
      iVar6 = iVar6 + -1;
      if (*pcVar5 != '\0') {
        if (iVar6 != 0) goto LAB_005e0f9c;
        break;
      }
    } while (iVar6 != 0);
    uVar4 = (*(code *)PTR_BN_new_006a82b4)();
    iVar6 = 0;
    (*(code *)PTR_BN_set_word_006a8820)(uVar4);
  }
  else {
LAB_005e0f9c:
    uVar4 = (*(code *)PTR_BN_bin2bn_006a89f0)(pcVar5,iVar6,0);
  }
  if (local_14 == *(char **)puVar2) {
    return uVar4;
  }
  pcVar5 = local_14;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  cVar1 = *pcVar5;
  while (cVar1 == '\0') {
    pcVar5 = pcVar5 + 1;
    if (iVar6 == 0) goto LAB_005e1058;
    iVar6 = iVar6 + -1;
    cVar1 = *pcVar5;
  }
  if (iVar6 != 0) {
                    /* WARNING: Could not recover jumptable at 0x005e1050. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar4 = (*(code *)PTR_BN_bin2bn_006a89f0)();
    return uVar4;
  }
LAB_005e1058:
  uVar4 = (*(code *)PTR_BN_new_006a82b4)();
  (*(code *)PTR_BN_set_word_006a8820)(uVar4,0);
  return uVar4;
}

