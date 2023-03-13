
undefined4 hwcrhk_mod_exp_isra_1(int *param_1,int **param_2,int **param_3,char **param_4)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int **ppiVar6;
  undefined4 uVar7;
  char *pcVar8;
  int *piVar9;
  int iVar10;
  undefined *unaff_s0;
  undefined *unaff_s1;
  undefined *unaff_s2;
  int *unaff_s3;
  char **unaff_s4;
  int **unaff_s5;
  undefined4 *unaff_s6;
  int **unaff_s7;
  code *pcVar11;
  undefined *puVar12;
  undefined *puVar13;
  undefined *puVar14;
  int *unaff_s8;
  code *unaff_retaddr;
  undefined auStackX_0 [16];
  
  do {
    ppiVar6 = param_2;
    puVar1 = PTR___stack_chk_guard_006a9ae8;
    puVar12 = &_gp;
    *(undefined **)((int)register0x00000074 + -0x24) = unaff_s1;
    *(int ***)((int)register0x00000074 + -0x14) = unaff_s5;
    *(undefined **)((int)register0x00000074 + -0x20) = unaff_s2;
    unaff_s2 = &_gp_1;
    *(int **)((int)register0x00000074 + -8) = unaff_s8;
    *(undefined **)((int)register0x00000074 + -0x454) =
         (undefined *)((int)register0x00000074 + -0x42c);
    *(undefined4 **)((int)register0x00000074 + -0x10) = unaff_s6;
    *(int **)((int)register0x00000074 + -0x1c) = unaff_s3;
    *(code **)((int)register0x00000074 + -4) = unaff_retaddr;
    *(int ***)((int)register0x00000074 + -0xc) = unaff_s7;
    *(char ***)((int)register0x00000074 + -0x18) = unaff_s4;
    *(undefined **)((int)register0x00000074 + -0x28) = unaff_s0;
    *(undefined **)((int)register0x00000074 + -0x460) = &_gp;
    *(undefined4 *)((int)register0x00000074 + -0x450) = 0x400;
    unaff_s8 = *(int **)((int)register0x00000074 + 0x10);
    unaff_s6 = *(undefined4 **)((int)register0x00000074 + 0x14);
    unaff_s3 = *(int **)((int)register0x00000074 + 0x18);
    *(undefined4 *)((int)register0x00000074 + -0x2c) = *(undefined4 *)PTR___stack_chk_guard_006a9ae8
    ;
    if (hwcrhk_context == 0) {
      if (HWCRHK_lib_error_code == 0) {
        HWCRHK_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
        puVar12 = *(undefined **)((int)register0x00000074 + -0x460);
      }
      pcVar11 = *(code **)(puVar12 + -0x6eac);
      param_2 = (int **)&DAT_0000006a;
      pcVar8 = "e_chil.c";
      *(undefined4 *)((int)register0x00000074 + -0x478) = 0x39a;
      param_1 = (int *)&DAT_0000006b;
      (*pcVar11)(HWCRHK_lib_error_code);
      uVar7 = 0;
      puVar13 = *(undefined **)((int)register0x00000074 + -0x460);
    }
    else {
      (*(code *)PTR_bn_expand2_006a8524)(param_1,*unaff_s3);
      iVar3 = *unaff_s8;
      iVar2 = *unaff_s3;
      piVar9 = *ppiVar6;
      pcVar8 = *param_4;
      uVar7 = *unaff_s6;
      param_2 = (int **)((int)*param_3 << 2);
      iVar10 = *param_1;
      *(int *)((int)register0x00000074 + -0x430) = param_1[2] << 2;
      *(int *)((int)register0x00000074 + -0x478) = iVar3 << 2;
      *(int *)((int)register0x00000074 + -0x440) = iVar3 << 2;
      *(undefined **)((int)register0x00000074 + -0x468) =
           (undefined *)((int)register0x00000074 + -0x454);
      *(int *)((int)register0x00000074 + -0x434) = iVar10;
      *(undefined4 *)((int)register0x00000074 + -0x474) = uVar7;
      *(undefined **)((int)register0x00000074 + -0x46c) =
           (undefined *)((int)register0x00000074 + -0x434);
      *(int *)((int)register0x00000074 + -0x470) = iVar2 << 2;
      *(int ***)((int)register0x00000074 + -0x448) = param_2;
      *(int **)((int)register0x00000074 + -0x44c) = piVar9;
      *(char **)((int)register0x00000074 + -0x444) = pcVar8;
      *(int *)((int)register0x00000074 + -0x438) = iVar2 << 2;
      *(undefined4 *)((int)register0x00000074 + -0x43c) = uVar7;
      iVar2 = (*p_hwcrhk_ModExp)(hwcrhk_context);
      uVar4 = *(uint *)((int)register0x00000074 + -0x430);
      puVar13 = *(undefined **)((int)register0x00000074 + -0x460);
      uVar5 = uVar4 >> 2;
      param_1[1] = uVar5;
      if (uVar5 != 0) {
        iVar3 = *param_1 + (uVar4 & 0xfffffffc) + -8;
        do {
          piVar9 = *(int **)(iVar3 + 4);
          if (piVar9 != (int *)0x0) break;
          uVar5 = uVar5 - 1;
          iVar3 = iVar3 + -4;
        } while (uVar5 != 0);
        param_1[1] = uVar5;
      }
      param_1 = piVar9;
      unaff_s4 = param_4;
      unaff_s7 = param_3;
      if (iVar2 < 0) {
        if (iVar2 == -2) {
          if (HWCRHK_lib_error_code == 0) {
            HWCRHK_lib_error_code = (**(code **)(puVar13 + -0x58a8))();
            puVar13 = *(undefined **)((int)register0x00000074 + -0x460);
          }
          pcVar11 = *(code **)(puVar13 + -0x6eac);
          param_2 = (int **)&DAT_00000070;
          pcVar8 = "e_chil.c";
          *(undefined4 *)((int)register0x00000074 + -0x478) = 0x3b1;
          (*pcVar11)(HWCRHK_lib_error_code,0x6b);
          puVar14 = *(undefined **)((int)register0x00000074 + -0x460);
        }
        else {
          if (HWCRHK_lib_error_code == 0) {
            HWCRHK_lib_error_code = (**(code **)(puVar13 + -0x58a8))();
            puVar13 = *(undefined **)((int)register0x00000074 + -0x460);
          }
          pcVar11 = *(code **)(puVar13 + -0x6eac);
          param_2 = (int **)&DAT_0000006f;
          pcVar8 = "e_chil.c";
          *(undefined4 *)((int)register0x00000074 + -0x478) = 0x3b3;
          (*pcVar11)(HWCRHK_lib_error_code,0x6b);
          puVar14 = *(undefined **)((int)register0x00000074 + -0x460);
        }
        param_1 = *(int **)((int)register0x00000074 + -0x454);
        (**(code **)(puVar14 + -0x6ca4))(1);
        uVar7 = 0;
        puVar13 = *(undefined **)((int)register0x00000074 + -0x460);
      }
      else {
        uVar7 = 1;
      }
    }
    unaff_s0 = &_gp_1;
    if (*(int *)((int)register0x00000074 + -0x2c) == *(int *)puVar1) {
      return uVar7;
    }
    unaff_retaddr = hwcrhk_mod_exp_dh;
    (**(code **)(puVar13 + -0x5330))();
    iVar2 = *(int *)((int)register0x00000074 + -0x478);
    param_3 = param_2 + 1;
    *(char ***)((int)register0x00000074 + -0x478) = (char **)((int)pcVar8 + 4);
    *(int *)((int)register0x00000074 + -0x474) = iVar2;
    *(int *)((int)register0x00000074 + -0x470) = iVar2 + 4;
    param_4 = (char **)pcVar8;
    unaff_s1 = puVar1;
    unaff_s5 = ppiVar6;
    register0x00000074 = (BADSPACEBASE *)((int)register0x00000074 + -0x488);
  } while( true );
}

