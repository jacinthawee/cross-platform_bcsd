
/* WARNING: Restarted to delay deadcode elimination for space: ram */

undefined4
atalla_mod_exp_mont(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,
                   undefined4 param_5)

{
  undefined *puVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  char *pcVar9;
  char *pcVar10;
  undefined4 uVar11;
  undefined4 in_stack_ffffff68;
  undefined4 uStack_94;
  undefined auStack_78 [12];
  int iStack_6c;
  char *pcStack_68;
  int iStack_5c;
  char *pcStack_58;
  int iStack_2c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  iStack_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  if (atalla_dso == 0) {
    if (ATALLA_lib_error_code == 0) {
      ATALLA_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
    }
    param_1 = 0x69;
    in_stack_ffffff68 = 0x1d0;
  }
  else {
    (*(code *)PTR_BN_CTX_start_006a9644)(param_5);
    piVar2 = (int *)(*(code *)PTR_BN_CTX_get_006a9648)(param_5);
    piVar3 = (int *)(*(code *)PTR_BN_CTX_get_006a9648)(param_5);
    piVar4 = (int *)(*(code *)PTR_BN_CTX_get_006a9648)(param_5);
    puVar5 = (undefined4 *)(*(code *)PTR_BN_CTX_get_006a9648)(param_5);
    if (puVar5 == (undefined4 *)0x0) {
      if (ATALLA_lib_error_code == 0) {
        ATALLA_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
      }
      param_1 = 0x65;
      in_stack_ffffff68 = 0x1db;
    }
    else {
      iVar7 = *(int *)(param_4 + 4);
      if (piVar2[2] < iVar7) {
        iVar7 = (*(code *)PTR_bn_expand2_006a9680)(piVar2);
        if (iVar7 != 0) {
          iVar7 = *(int *)(param_4 + 4);
          goto LAB_005d1090;
        }
LAB_005d1378:
        if (ATALLA_lib_error_code == 0) {
          ATALLA_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
          param_1 = 0x66;
          in_stack_ffffff68 = 0x1e1;
        }
        else {
          param_1 = 0x66;
          in_stack_ffffff68 = 0x1e1;
        }
      }
      else {
LAB_005d1090:
        if (piVar3[2] < iVar7) {
          iVar7 = (*(code *)PTR_bn_expand2_006a9680)(piVar3);
          if (iVar7 == 0) goto LAB_005d1378;
          iVar7 = *(int *)(param_4 + 4);
          if (piVar4[2] < iVar7) goto LAB_005d1300;
LAB_005d10b0:
          if ((int)puVar5[2] < iVar7) {
LAB_005d1368:
            iVar7 = (*(code *)PTR_bn_expand2_006a9680)(puVar5);
            if (iVar7 == 0) goto LAB_005d1378;
          }
        }
        else {
          if (iVar7 <= piVar4[2]) goto LAB_005d10b0;
LAB_005d1300:
          iVar7 = (*(code *)PTR_bn_expand2_006a9680)(piVar4);
          if (iVar7 == 0) goto LAB_005d1378;
          if ((int)puVar5[2] < *(int *)(param_4 + 4)) goto LAB_005d1368;
        }
        (*(code *)PTR_memset_006aab00)(auStack_78,0,0x4c);
        iVar6 = (*(code *)PTR_BN_num_bits_006a82f4)(param_4);
        iVar7 = iVar6 + 7;
        if (iVar6 + 7 < 0) {
          iVar7 = iVar6 + 0xe;
        }
        pcVar10 = (char *)(iVar7 >> 3);
        (*(code *)PTR_memset_006aab00)(*piVar3,0,pcVar10);
        (*(code *)PTR_memset_006aab00)(*piVar2,0,pcVar10);
        iVar8 = *piVar3;
        iVar6 = (*(code *)PTR_BN_num_bits_006a82f4)(param_3);
        iVar7 = iVar6 + 7;
        if (iVar6 + 7 < 0) {
          iVar7 = iVar6 + 0xe;
        }
        (*(code *)PTR_BN_bn2bin_006a8300)(param_3,pcVar10 + (iVar8 - (iVar7 >> 3)));
        iVar8 = *piVar2;
        iVar6 = (*(code *)PTR_BN_num_bits_006a82f4)(param_4);
        iVar7 = iVar6 + 7;
        if (iVar6 + 7 < 0) {
          iVar7 = iVar6 + 0xe;
        }
        (*(code *)PTR_BN_bn2bin_006a8300)(param_4,pcVar10 + (iVar8 - (iVar7 >> 3)));
        iStack_5c = *piVar3;
        iStack_6c = *piVar2;
        pcStack_68 = pcVar10;
        pcStack_58 = pcVar10;
        (*(code *)PTR_memset_006aab00)(*piVar4,0,pcVar10);
        (*(code *)PTR_memset_006aab00)(*puVar5,0,pcVar10);
        iVar8 = *piVar4;
        iVar6 = (*(code *)PTR_BN_num_bits_006a82f4)(param_2);
        iVar7 = iVar6 + 7;
        if (iVar6 + 7 < 0) {
          iVar7 = iVar6 + 0xe;
        }
        (*(code *)PTR_BN_bn2bin_006a8300)(param_2,pcVar10 + (iVar8 - (iVar7 >> 3)));
        pcVar9 = pcStack_68;
        iVar7 = (*p_Atalla_RSAPrivateKeyOpFn)(auStack_78,*puVar5,*piVar4,pcStack_68);
        if (iVar7 == 0) {
          uVar11 = 1;
          (*(code *)PTR_BN_bin2bn_006a89f0)(*puVar5,pcVar10,param_1);
          goto LAB_005d1288;
        }
        if (ATALLA_lib_error_code == 0) {
          ATALLA_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
        }
        param_1 = 0x6a;
        in_stack_ffffff68 = 0x1f8;
      }
    }
  }
  pcVar9 = "e_atalla.c";
  pcVar10 = (char *)0x67;
  uVar11 = 0;
  (*(code *)PTR_ERR_put_error_006a9030)(ATALLA_lib_error_code,0x67,param_1,"e_atalla.c");
LAB_005d1288:
  (*(code *)PTR_BN_CTX_end_006a9654)(param_5);
  if (iStack_2c != *(int *)puVar1) {
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    uVar11 = atalla_mod_exp(pcVar10,param_1,pcVar9,in_stack_ffffff68,uStack_94);
    return uVar11;
  }
  return uVar11;
}

