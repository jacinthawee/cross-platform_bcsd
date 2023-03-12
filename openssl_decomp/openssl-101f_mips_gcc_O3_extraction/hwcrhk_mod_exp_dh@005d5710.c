
undefined4 hwcrhk_mod_exp_dh(undefined4 param_1,int *param_2,int **param_3,char **param_4)

{
  undefined *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int **ppiVar6;
  int **ppiVar7;
  undefined4 uVar8;
  char *pcVar9;
  int *piVar10;
  int iVar11;
  undefined1 *unaff_s0;
  undefined *unaff_s1;
  undefined1 *unaff_s2;
  int *unaff_s3;
  char **unaff_s4;
  int **unaff_s5;
  undefined4 *unaff_s6;
  int **unaff_s7;
  code *pcVar12;
  undefined *puVar13;
  undefined *puVar14;
  undefined *puVar15;
  int *unaff_s8;
  code *unaff_retaddr;
  undefined auStackX_0 [16];
  
  do {
    ppiVar6 = param_3;
    puVar1 = PTR___stack_chk_guard_006aabf0;
    iVar5 = *(int *)((int)register0x00000074 + 0x10);
    ppiVar7 = ppiVar6 + 1;
    *(char ***)((int)register0x00000074 + 0x10) = param_4 + 1;
    *(int *)((int)register0x00000074 + 0x14) = iVar5;
    *(int *)((int)register0x00000074 + 0x18) = iVar5 + 4;
    puVar13 = &_gp;
    *(undefined **)((int)register0x00000074 + -0x24) = unaff_s1;
    *(int ***)((int)register0x00000074 + -0x14) = unaff_s5;
    *(undefined1 **)((int)register0x00000074 + -0x20) = unaff_s2;
    unaff_s2 = &_ITM_registerTMCloneTable;
    *(int **)((int)register0x00000074 + -8) = unaff_s8;
    *(undefined **)((int)register0x00000074 + -0x454) =
         (undefined *)((int)register0x00000074 + -0x42c);
    *(undefined4 **)((int)register0x00000074 + -0x10) = unaff_s6;
    *(int **)((int)register0x00000074 + -0x1c) = unaff_s3;
    *(code **)((int)register0x00000074 + -4) = unaff_retaddr;
    *(int ***)((int)register0x00000074 + -0xc) = unaff_s7;
    *(char ***)((int)register0x00000074 + -0x18) = unaff_s4;
    *(undefined1 **)((int)register0x00000074 + -0x28) = unaff_s0;
    *(undefined **)((int)register0x00000074 + -0x460) = &_gp;
    *(undefined4 *)((int)register0x00000074 + -0x450) = 0x400;
    unaff_s8 = *(int **)((int)register0x00000074 + 0x10);
    unaff_s6 = *(undefined4 **)((int)register0x00000074 + 0x14);
    unaff_s3 = *(int **)((int)register0x00000074 + 0x18);
    *(undefined4 *)((int)register0x00000074 + -0x2c) = *(undefined4 *)PTR___stack_chk_guard_006aabf0
    ;
    if (hwcrhk_context == 0) {
      if (HWCRHK_lib_error_code == 0) {
        HWCRHK_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
        puVar13 = *(undefined **)((int)register0x00000074 + -0x460);
      }
      pcVar12 = *(code **)(puVar13 + -0x6eb0);
      param_3 = (int **)&DAT_0000006a;
      pcVar9 = "e_chil.c";
      *(undefined4 *)((int)register0x00000074 + -0x478) = 0x390;
      piVar10 = (int *)&DAT_0000006b;
      (*pcVar12)(HWCRHK_lib_error_code);
      uVar8 = 0;
      puVar14 = *(undefined **)((int)register0x00000074 + -0x460);
    }
    else {
      (*(code *)PTR_bn_expand2_006a9680)(param_2,*unaff_s3);
      iVar2 = *unaff_s8;
      iVar5 = *unaff_s3;
      piVar10 = *ppiVar6;
      pcVar9 = *param_4;
      uVar8 = *unaff_s6;
      param_3 = (int **)((int)*ppiVar7 << 2);
      iVar11 = *param_2;
      *(int *)((int)register0x00000074 + -0x430) = param_2[2] << 2;
      *(int *)((int)register0x00000074 + -0x478) = iVar2 << 2;
      *(int *)((int)register0x00000074 + -0x440) = iVar2 << 2;
      *(undefined **)((int)register0x00000074 + -0x468) =
           (undefined *)((int)register0x00000074 + -0x454);
      *(int *)((int)register0x00000074 + -0x434) = iVar11;
      *(undefined4 *)((int)register0x00000074 + -0x474) = uVar8;
      *(undefined **)((int)register0x00000074 + -0x46c) =
           (undefined *)((int)register0x00000074 + -0x434);
      *(int *)((int)register0x00000074 + -0x470) = iVar5 << 2;
      *(int ***)((int)register0x00000074 + -0x448) = param_3;
      *(int **)((int)register0x00000074 + -0x44c) = piVar10;
      *(char **)((int)register0x00000074 + -0x444) = pcVar9;
      *(int *)((int)register0x00000074 + -0x438) = iVar5 << 2;
      *(undefined4 *)((int)register0x00000074 + -0x43c) = uVar8;
      iVar5 = (*p_hwcrhk_ModExp)(hwcrhk_context);
      uVar3 = *(uint *)((int)register0x00000074 + -0x430);
      puVar14 = *(undefined **)((int)register0x00000074 + -0x460);
      uVar4 = uVar3 >> 2;
      param_2[1] = uVar4;
      if (uVar4 != 0) {
        iVar2 = *param_2 + (uVar3 & 0xfffffffc) + -8;
        do {
          piVar10 = *(int **)(iVar2 + 4);
          if (piVar10 != (int *)0x0) break;
          uVar4 = uVar4 - 1;
          iVar2 = iVar2 + -4;
        } while (uVar4 != 0);
        param_2[1] = uVar4;
      }
      unaff_s4 = param_4;
      unaff_s7 = ppiVar7;
      if (iVar5 < 0) {
        if (iVar5 == -2) {
          if (HWCRHK_lib_error_code == 0) {
            HWCRHK_lib_error_code = (**(code **)(puVar14 + -0x589c))();
            puVar14 = *(undefined **)((int)register0x00000074 + -0x460);
          }
          pcVar12 = *(code **)(puVar14 + -0x6eb0);
          param_3 = (int **)&DAT_00000070;
          pcVar9 = "e_chil.c";
          *(undefined4 *)((int)register0x00000074 + -0x478) = 0x3a8;
          (*pcVar12)(HWCRHK_lib_error_code,0x6b);
          puVar15 = *(undefined **)((int)register0x00000074 + -0x460);
        }
        else {
          if (HWCRHK_lib_error_code == 0) {
            HWCRHK_lib_error_code = (**(code **)(puVar14 + -0x589c))();
            puVar14 = *(undefined **)((int)register0x00000074 + -0x460);
          }
          pcVar12 = *(code **)(puVar14 + -0x6eb0);
          param_3 = (int **)&DAT_0000006f;
          pcVar9 = "e_chil.c";
          *(undefined4 *)((int)register0x00000074 + -0x478) = 0x3ac;
          (*pcVar12)(HWCRHK_lib_error_code,0x6b);
          puVar15 = *(undefined **)((int)register0x00000074 + -0x460);
        }
        piVar10 = *(int **)((int)register0x00000074 + -0x454);
        (**(code **)(puVar15 + -0x6c7c))(1);
        uVar8 = 0;
        puVar14 = *(undefined **)((int)register0x00000074 + -0x460);
      }
      else {
        uVar8 = 1;
      }
    }
    unaff_s0 = &_ITM_registerTMCloneTable;
    if (*(int *)((int)register0x00000074 + -0x2c) == *(int *)puVar1) {
      return uVar8;
    }
    unaff_retaddr = hwcrhk_mod_exp_dh;
    (**(code **)(puVar14 + -0x5328))();
    param_2 = piVar10;
    param_4 = (char **)pcVar9;
    unaff_s1 = puVar1;
    unaff_s5 = ppiVar6;
    register0x00000074 = (BADSPACEBASE *)((int)register0x00000074 + -0x488);
  } while( true );
}

