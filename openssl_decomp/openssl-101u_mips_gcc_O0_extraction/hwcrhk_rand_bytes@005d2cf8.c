
undefined4 hwcrhk_rand_bytes(int **param_1,int **param_2)

{
  undefined *puVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int **ppiVar7;
  int *piVar8;
  char *pcVar9;
  char *pcVar10;
  int *piVar11;
  int iVar12;
  undefined *puVar13;
  undefined *unaff_s1;
  undefined *unaff_s2;
  int *unaff_s3;
  int ***unaff_s4;
  int **unaff_s5;
  undefined4 *unaff_s6;
  int **unaff_s7;
  undefined *puVar14;
  undefined *puVar15;
  undefined *puVar16;
  undefined *puVar17;
  int *unaff_s8;
  code *pcVar18;
  undefined auStack_440 [16];
  undefined4 local_430;
  undefined *local_428;
  int **local_41c;
  undefined4 local_418;
  int *apiStack_414 [256];
  int *local_14;
  
  puVar13 = PTR___stack_chk_guard_006a9ae8;
  local_41c = apiStack_414;
  local_428 = &_gp;
  local_418 = 0x400;
  local_14 = *(int **)PTR___stack_chk_guard_006a9ae8;
  if (hwcrhk_context == 0) {
    unaff_s1 = &_gp_1;
    if (HWCRHK_lib_error_code == 0) {
      HWCRHK_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
    }
    param_2 = (int **)&DAT_0000006a;
    pcVar9 = "e_chil.c";
    local_430 = 0x45e;
    param_1 = (int **)&DAT_0000006c;
    (**(code **)(local_428 + -0x6eac))(HWCRHK_lib_error_code);
    uVar3 = 0;
  }
  else {
    pcVar9 = (char *)&local_41c;
    iVar2 = (*p_hwcrhk_RandomBytes)(hwcrhk_context);
    if (iVar2 < 0) {
      unaff_s1 = &_gp_1;
      if (iVar2 == -2) {
        if (HWCRHK_lib_error_code == 0) {
          HWCRHK_lib_error_code = (**(code **)(local_428 + -0x58a8))();
        }
        param_2 = (int **)&DAT_00000070;
        pcVar9 = "e_chil.c";
        local_430 = 0x469;
        (**(code **)(local_428 + -0x6eac))(HWCRHK_lib_error_code,0x6c);
      }
      else {
        if (HWCRHK_lib_error_code == 0) {
          HWCRHK_lib_error_code = (**(code **)(local_428 + -0x58a8))();
        }
        param_2 = (int **)&DAT_0000006f;
        pcVar9 = "e_chil.c";
        local_430 = 0x46b;
        (**(code **)(local_428 + -0x6eac))(HWCRHK_lib_error_code,0x6c);
      }
      param_1 = local_41c;
      (**(code **)(local_428 + -0x6ca4))(1);
      uVar3 = 0;
    }
    else {
      uVar3 = 1;
    }
  }
  if (local_14 == *(int **)puVar13) {
    return uVar3;
  }
  pcVar18 = hwcrhk_mod_exp_isra_1;
  piVar8 = local_14;
  (**(code **)(local_428 + -0x5330))();
  puVar17 = auStack_440;
  do {
    ppiVar7 = param_1;
    puVar1 = PTR___stack_chk_guard_006a9ae8;
    puVar14 = &_gp;
    *(undefined **)(puVar17 + -0x24) = unaff_s1;
    *(int ***)(puVar17 + -0x14) = unaff_s5;
    *(undefined **)(puVar17 + -0x20) = unaff_s2;
    unaff_s2 = &_gp_1;
    *(int **)(puVar17 + -8) = unaff_s8;
    *(undefined **)(puVar17 + -0x454) = puVar17 + -0x42c;
    *(undefined4 **)(puVar17 + -0x10) = unaff_s6;
    *(int **)(puVar17 + -0x1c) = unaff_s3;
    *(code **)(puVar17 + -4) = pcVar18;
    *(int ***)(puVar17 + -0xc) = unaff_s7;
    *(int ****)(puVar17 + -0x18) = unaff_s4;
    *(undefined **)(puVar17 + -0x28) = puVar13;
    *(undefined **)(puVar17 + -0x460) = &_gp;
    *(undefined4 *)(puVar17 + -0x450) = 0x400;
    unaff_s8 = *(int **)(puVar17 + 0x10);
    unaff_s6 = *(undefined4 **)(puVar17 + 0x14);
    unaff_s3 = *(int **)(puVar17 + 0x18);
    *(undefined4 *)(puVar17 + -0x2c) = *(undefined4 *)PTR___stack_chk_guard_006a9ae8;
    if (hwcrhk_context == 0) {
      if (HWCRHK_lib_error_code == 0) {
        HWCRHK_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
        puVar14 = *(undefined **)(puVar17 + -0x460);
      }
      pcVar18 = *(code **)(puVar14 + -0x6eac);
      param_1 = (int **)&DAT_0000006a;
      pcVar10 = "e_chil.c";
      *(undefined4 *)(puVar17 + -0x478) = 0x39a;
      piVar8 = (int *)&DAT_0000006b;
      (*pcVar18)(HWCRHK_lib_error_code);
      uVar3 = 0;
      puVar15 = *(undefined **)(puVar17 + -0x460);
    }
    else {
      (*(code *)PTR_bn_expand2_006a8524)();
      iVar4 = *unaff_s8;
      iVar2 = *unaff_s3;
      piVar11 = *ppiVar7;
      pcVar10 = *(char **)pcVar9;
      uVar3 = *unaff_s6;
      param_1 = (int **)((int)*param_2 << 2);
      iVar12 = *piVar8;
      *(int *)(puVar17 + -0x430) = piVar8[2] << 2;
      *(int *)(puVar17 + -0x478) = iVar4 << 2;
      *(int *)(puVar17 + -0x440) = iVar4 << 2;
      *(undefined **)(puVar17 + -0x468) = puVar17 + -0x454;
      *(int *)(puVar17 + -0x434) = iVar12;
      *(undefined4 *)(puVar17 + -0x474) = uVar3;
      *(undefined **)(puVar17 + -0x46c) = puVar17 + -0x434;
      *(int *)(puVar17 + -0x470) = iVar2 << 2;
      *(int ***)(puVar17 + -0x448) = param_1;
      *(int **)(puVar17 + -0x44c) = piVar11;
      *(char **)(puVar17 + -0x444) = pcVar10;
      *(int *)(puVar17 + -0x438) = iVar2 << 2;
      *(undefined4 *)(puVar17 + -0x43c) = uVar3;
      iVar2 = (*p_hwcrhk_ModExp)(hwcrhk_context);
      uVar5 = *(uint *)(puVar17 + -0x430);
      puVar15 = *(undefined **)(puVar17 + -0x460);
      uVar6 = uVar5 >> 2;
      piVar8[1] = uVar6;
      if (uVar6 != 0) {
        iVar4 = *piVar8 + (uVar5 & 0xfffffffc) + -8;
        do {
          piVar11 = *(int **)(iVar4 + 4);
          if (piVar11 != (int *)0x0) break;
          uVar6 = uVar6 - 1;
          iVar4 = iVar4 + -4;
        } while (uVar6 != 0);
        piVar8[1] = uVar6;
      }
      piVar8 = piVar11;
      unaff_s4 = (int ***)pcVar9;
      unaff_s7 = param_2;
      if (iVar2 < 0) {
        if (iVar2 == -2) {
          if (HWCRHK_lib_error_code == 0) {
            HWCRHK_lib_error_code = (**(code **)(puVar15 + -0x58a8))();
            puVar15 = *(undefined **)(puVar17 + -0x460);
          }
          pcVar18 = *(code **)(puVar15 + -0x6eac);
          param_1 = (int **)&DAT_00000070;
          pcVar10 = "e_chil.c";
          *(undefined4 *)(puVar17 + -0x478) = 0x3b1;
          (*pcVar18)(HWCRHK_lib_error_code,0x6b);
          puVar16 = *(undefined **)(puVar17 + -0x460);
        }
        else {
          if (HWCRHK_lib_error_code == 0) {
            HWCRHK_lib_error_code = (**(code **)(puVar15 + -0x58a8))();
            puVar15 = *(undefined **)(puVar17 + -0x460);
          }
          pcVar18 = *(code **)(puVar15 + -0x6eac);
          param_1 = (int **)&DAT_0000006f;
          pcVar10 = "e_chil.c";
          *(undefined4 *)(puVar17 + -0x478) = 0x3b3;
          (*pcVar18)(HWCRHK_lib_error_code,0x6b);
          puVar16 = *(undefined **)(puVar17 + -0x460);
        }
        piVar8 = *(int **)(puVar17 + -0x454);
        (**(code **)(puVar16 + -0x6ca4))(1);
        uVar3 = 0;
        puVar15 = *(undefined **)(puVar17 + -0x460);
      }
      else {
        uVar3 = 1;
      }
    }
    puVar13 = &_gp_1;
    if (*(int *)(puVar17 + -0x2c) == *(int *)puVar1) {
      return uVar3;
    }
    pcVar18 = hwcrhk_mod_exp_dh;
    (**(code **)(puVar15 + -0x5330))();
    iVar2 = *(int *)(puVar17 + -0x478);
    param_2 = param_1 + 1;
    *(int ****)(puVar17 + -0x478) = (int ***)((int)pcVar10 + 4);
    *(int *)(puVar17 + -0x474) = iVar2;
    *(int *)(puVar17 + -0x470) = iVar2 + 4;
    pcVar9 = pcVar10;
    unaff_s1 = puVar1;
    unaff_s5 = ppiVar7;
    puVar17 = puVar17 + -0x488;
  } while( true );
}

