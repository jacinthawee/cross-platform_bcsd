
uint int_ctrl_helper_isra_1(uint **param_1,int param_2,uint param_3,int param_4)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined *puVar6;
  undefined *puVar7;
  uint *puVar8;
  uint unaff_s0;
  int unaff_s1;
  char *pcStackX_c;
  int aiStack_5c [2];
  uint uStack_54;
  int iStack_50;
  int iStack_4c;
  undefined *puStack_48;
  code *pcStack_44;
  int *apiStack_3c [3];
  char *pcStack_30;
  char **ppcStack_2c;
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
          iVar5 = (*(code *)PTR_strcmp_006aac20)(uVar3,param_4);
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
      iVar4 = 0x86;
      goto LAB_0051b860;
    }
LAB_0051b670:
    iVar5 = 0x43;
    iVar4 = 0x7b;
LAB_0051b860:
    ERR_put_error(0x26,0xac,iVar5,"eng_ctrl.c",iVar4);
    return 0xffffffff;
  }
  if (((param_2 == 0xf) || (param_2 == 0x11)) && (param_4 == 0)) goto LAB_0051b670;
  puVar8 = *param_1;
  if (puVar8 == (uint *)0x0) {
LAB_0051b650:
    iVar5 = 0x8a;
    iVar4 = 0x91;
    goto LAB_0051b860;
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
  if (param_3 != uVar3) goto LAB_0051b650;
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
    iVar4 = 0xb2;
    goto LAB_0051b860;
  case 0xe:
    uVar3 = puVar8[iVar4 * 4 + 1];
    goto LAB_0051b7e8;
  case 0xf:
    pcStackX_c = (char *)puVar8[iVar4 * 4 + 1];
    break;
  case 0x10:
    uVar3 = puVar8[iVar4 * 4 + 2];
    if (uVar3 == 0) {
      return 0;
    }
LAB_0051b7e8:
                    /* WARNING: Could not recover jumptable at 0x0051b7fc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar3 = (*(code *)PTR_strlen_006aab30)(uVar3);
    return uVar3;
  case 0x11:
    pcStackX_c = (char *)puVar8[iVar4 * 4 + 2];
    if (pcStackX_c == (char *)0x0) {
      pcStackX_c = "";
      iStack_18 = 1;
      goto LAB_0051b7b4;
    }
    break;
  case 0x12:
    return puVar8[iVar4 * 4 + 3];
  }
  iStack_18 = (*(code *)PTR_strlen_006aab30)(pcStackX_c);
  iStack_18 = iStack_18 + 1;
LAB_0051b7b4:
  puStack_48 = PTR___stack_chk_guard_006aabf0;
  ppcStack_2c = &pcStackX_c;
  puVar7 = &stack0xfffffff0;
  pcStack_30 = "%s";
  puVar6 = &stack0xffffffec;
  apiStack_3c[0] = &iStack_18;
  puVar9 = &_gp;
  aiStack_5c[0] = *(int *)PTR___stack_chk_guard_006aabf0;
  iStack_1c = param_4;
  _dopr_constprop_0(&iStack_1c);
  if (unaff_s1 == 0) {
    if ((int)unaff_s0 < 0) {
      unaff_s0 = 0xffffffff;
    }
  }
  else {
    unaff_s0 = 0xffffffff;
  }
  if (aiStack_5c[0] == *(int *)puStack_48) {
    return unaff_s0;
  }
  pcStack_44 = BIO_vsnprintf;
  (**(code **)(puVar9 + -0x5328))();
  puVar9 = PTR___stack_chk_guard_006aabf0;
  iStack_4c = *(int *)PTR___stack_chk_guard_006aabf0;
  _dopr_constprop_0(aiStack_5c,apiStack_3c,&uStack_54,&iStack_50,puVar6,puVar7);
  if (iStack_50 == 0) {
    if ((int)uStack_54 < 0) {
      uStack_54 = 0xffffffff;
    }
  }
  else {
    uStack_54 = 0xffffffff;
  }
  if (iStack_4c == *(int *)puVar9) {
    return uStack_54;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
                    /* WARNING: Could not recover jumptable at 0x00529660. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar3 = (*(code *)PTR_fwrite_006aab7c)();
  return uVar3;
}

