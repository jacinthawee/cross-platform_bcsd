
uint int_ctrl_helper_isra_1(uint **param_1,int param_2,uint param_3,int param_4)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  undefined *puVar7;
  uint *puVar8;
  uint unaff_s0;
  int unaff_s1;
  char *pcStackX_c;
  int aiStack_64 [2];
  uint uStack_5c;
  int iStack_58;
  int iStack_54;
  undefined *puStack_50;
  code *pcStack_4c;
  undefined4 auStack_44 [3];
  undefined *puStack_38;
  char *pcStack_34;
  char **ppcStack_30;
  undefined *puVar9;
  int iStack_1c;
  int iStack_18;
  
  if (param_2 == 0xb) {
    puVar8 = *param_1;
    if ((puVar8 != (uint *)0x0) && (uVar3 = *puVar8, uVar3 != 0)) {
      if (puVar8[1] == 0) {
        uVar3 = 0;
      }
      return uVar3;
    }
    return 0;
  }
  if (param_2 == 0xd) {
    if (param_4 != 0) {
      puVar8 = *param_1;
      if ((puVar8 != (uint *)0x0) && (*puVar8 != 0)) {
        iVar4 = 0;
        uVar3 = puVar8[1];
        puVar2 = puVar8;
        while (uVar3 != 0) {
          iVar5 = (*(code *)PTR_strcmp_006a9b18)(uVar3,param_4);
          if (iVar5 == 0) {
            return puVar8[iVar4 * 4];
          }
          iVar4 = iVar4 + 1;
          if (puVar2[4] == 0) break;
          uVar3 = puVar2[5];
          puVar2 = puVar2 + 4;
        }
      }
      iVar5 = 0x89;
      iVar4 = 0x83;
      goto LAB_00519970;
    }
LAB_00519780:
    iVar5 = 0x43;
    iVar4 = 0x7b;
LAB_00519970:
    ERR_put_error(0x26,0xac,iVar5,"eng_ctrl.c",iVar4);
    return 0xffffffff;
  }
  if (((param_2 == 0xf) || (param_2 == 0x11)) && (param_4 == 0)) goto LAB_00519780;
  puVar8 = *param_1;
  if (puVar8 == (uint *)0x0) {
LAB_00519760:
    iVar5 = 0x8a;
    iVar4 = 0x8f;
    goto LAB_00519970;
  }
  uVar3 = *puVar8;
  iVar4 = 0;
  if ((uVar3 != 0) && (puVar2 = puVar8, puVar8[1] != 0)) {
    while (uVar3 < param_3) {
      uVar3 = puVar2[4];
      iVar4 = iVar4 + 1;
      if ((uVar3 == 0) || (puVar1 = puVar2 + 5, puVar2 = puVar2 + 4, *puVar1 == 0)) break;
    }
  }
  if (param_3 != uVar3) goto LAB_00519760;
  switch(param_2) {
  case 0xc:
    uVar3 = puVar8[(iVar4 + 1) * 4];
    if (uVar3 == 0) {
      return 0;
    }
    if ((puVar8 + (iVar4 + 1) * 4)[1] == 0) {
      return 0;
    }
    return uVar3;
  default:
    iVar5 = 0x6e;
    iVar4 = 0xaf;
    goto LAB_00519970;
  case 0xe:
    uVar3 = puVar8[iVar4 * 4 + 1];
    goto LAB_005198f8;
  case 0xf:
    pcStackX_c = (char *)puVar8[iVar4 * 4 + 1];
    break;
  case 0x10:
    uVar3 = puVar8[iVar4 * 4 + 2];
    if (uVar3 == 0) {
      return 0;
    }
LAB_005198f8:
                    /* WARNING: Could not recover jumptable at 0x0051990c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar3 = (*(code *)PTR_strlen_006a9a24)(uVar3);
    return uVar3;
  case 0x11:
    pcStackX_c = (char *)puVar8[iVar4 * 4 + 2];
    if (pcStackX_c == (char *)0x0) {
      pcStackX_c = "";
      iStack_18 = 1;
      goto LAB_005198c4;
    }
    break;
  case 0x12:
    return puVar8[iVar4 * 4 + 3];
  }
  iStack_18 = (*(code *)PTR_strlen_006a9a24)(pcStackX_c);
  iStack_18 = iStack_18 + 1;
LAB_005198c4:
  puStack_50 = PTR___stack_chk_guard_006a9ae8;
  ppcStack_30 = &pcStackX_c;
  puStack_38 = &stack0xfffffff0;
  pcStack_34 = "%s";
  puVar7 = &stack0xffffffec;
  piVar6 = &iStack_18;
  auStack_44[0] = 0;
  puVar9 = &_gp;
  aiStack_64[0] = *(int *)PTR___stack_chk_guard_006a9ae8;
  iStack_1c = param_4;
  iVar4 = _dopr(&iStack_1c);
  if ((iVar4 == 0) || (unaff_s1 != 0)) {
    unaff_s0 = 0xffffffff;
  }
  else if ((int)unaff_s0 < 0) {
    unaff_s0 = 0xffffffff;
  }
  if (aiStack_64[0] == *(int *)puStack_50) {
    return unaff_s0;
  }
  pcStack_4c = BIO_vsnprintf;
  (**(code **)(puVar9 + -0x5330))();
  puVar9 = PTR___stack_chk_guard_006a9ae8;
  iStack_54 = *(int *)PTR___stack_chk_guard_006a9ae8;
  iVar4 = _dopr(aiStack_64,0,auStack_44,&uStack_5c,&iStack_58,piVar6,puVar7);
  if ((iVar4 == 0) || (iStack_58 != 0)) {
    uStack_5c = 0xffffffff;
  }
  else if ((int)uStack_5c < 0) {
    uStack_5c = 0xffffffff;
  }
  if (iStack_54 == *(int *)puVar9) {
    return uStack_5c;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
                    /* WARNING: Could not recover jumptable at 0x00526240. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar3 = (*(code *)PTR_fwrite_006a9a74)();
  return uVar3;
}

