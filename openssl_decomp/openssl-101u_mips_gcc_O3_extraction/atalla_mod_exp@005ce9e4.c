
/* WARNING: Restarted to delay deadcode elimination for space: ram */

undefined4
atalla_mod_exp(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,
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
  int local_6c;
  char *local_68;
  int local_5c;
  char *local_58;
  int local_2c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  if (atalla_dso == 0) {
    if (ATALLA_lib_error_code == 0) {
      ATALLA_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
    }
    param_1 = 0x69;
    in_stack_ffffff68 = 0x1de;
  }
  else {
    (*(code *)PTR_BN_CTX_start_006a8528)(param_5);
    piVar2 = (int *)(*(code *)PTR_BN_CTX_get_006a852c)(param_5);
    piVar3 = (int *)(*(code *)PTR_BN_CTX_get_006a852c)(param_5);
    piVar4 = (int *)(*(code *)PTR_BN_CTX_get_006a852c)(param_5);
    puVar5 = (undefined4 *)(*(code *)PTR_BN_CTX_get_006a852c)(param_5);
    if (puVar5 == (undefined4 *)0x0) {
      if (ATALLA_lib_error_code == 0) {
        ATALLA_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
      }
      param_1 = 0x65;
      in_stack_ffffff68 = 0x1e8;
    }
    else {
      iVar7 = *(int *)(param_4 + 4);
      if (piVar2[2] < iVar7) {
        iVar7 = (*(code *)PTR_bn_expand2_006a8524)(piVar2);
        if (iVar7 != 0) {
          iVar7 = *(int *)(param_4 + 4);
          goto LAB_005ceac0;
        }
LAB_005ceda8:
        if (ATALLA_lib_error_code == 0) {
          ATALLA_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
          param_1 = 0x66;
          in_stack_ffffff68 = 0x1ed;
        }
        else {
          param_1 = 0x66;
          in_stack_ffffff68 = 0x1ed;
        }
      }
      else {
LAB_005ceac0:
        if (piVar3[2] < iVar7) {
          iVar7 = (*(code *)PTR_bn_expand2_006a8524)(piVar3);
          if (iVar7 == 0) goto LAB_005ceda8;
          iVar7 = *(int *)(param_4 + 4);
          if (piVar4[2] < iVar7) goto LAB_005ced30;
LAB_005ceae0:
          if ((int)puVar5[2] < iVar7) {
LAB_005ced98:
            iVar7 = (*(code *)PTR_bn_expand2_006a8524)(puVar5);
            if (iVar7 == 0) goto LAB_005ceda8;
          }
        }
        else {
          if (iVar7 <= piVar4[2]) goto LAB_005ceae0;
LAB_005ced30:
          iVar7 = (*(code *)PTR_bn_expand2_006a8524)(piVar4);
          if (iVar7 == 0) goto LAB_005ceda8;
          if ((int)puVar5[2] < *(int *)(param_4 + 4)) goto LAB_005ced98;
        }
        (*(code *)PTR_memset_006a99f4)(auStack_78,0,0x4c);
        iVar6 = (*(code *)PTR_BN_num_bits_006a71f4)(param_4);
        iVar7 = iVar6 + 7;
        if (iVar6 + 7 < 0) {
          iVar7 = iVar6 + 0xe;
        }
        pcVar10 = (char *)(iVar7 >> 3);
        (*(code *)PTR_memset_006a99f4)(*piVar3,0,pcVar10);
        (*(code *)PTR_memset_006a99f4)(*piVar2,0,pcVar10);
        iVar8 = *piVar3;
        iVar6 = (*(code *)PTR_BN_num_bits_006a71f4)(param_3);
        iVar7 = iVar6 + 7;
        if (iVar6 + 7 < 0) {
          iVar7 = iVar6 + 0xe;
        }
        (*(code *)PTR_BN_bn2bin_006a7200)(param_3,pcVar10 + (iVar8 - (iVar7 >> 3)));
        iVar8 = *piVar2;
        iVar6 = (*(code *)PTR_BN_num_bits_006a71f4)(param_4);
        iVar7 = iVar6 + 7;
        if (iVar6 + 7 < 0) {
          iVar7 = iVar6 + 0xe;
        }
        (*(code *)PTR_BN_bn2bin_006a7200)(param_4,pcVar10 + (iVar8 - (iVar7 >> 3)));
        local_5c = *piVar3;
        local_6c = *piVar2;
        local_68 = pcVar10;
        local_58 = pcVar10;
        (*(code *)PTR_memset_006a99f4)(*piVar4,0,pcVar10);
        (*(code *)PTR_memset_006a99f4)(*puVar5,0,pcVar10);
        iVar8 = *piVar4;
        iVar6 = (*(code *)PTR_BN_num_bits_006a71f4)(param_2);
        iVar7 = iVar6 + 7;
        if (iVar6 + 7 < 0) {
          iVar7 = iVar6 + 0xe;
        }
        (*(code *)PTR_BN_bn2bin_006a7200)(param_2,pcVar10 + (iVar8 - (iVar7 >> 3)));
        pcVar9 = local_68;
        iVar7 = (*p_Atalla_RSAPrivateKeyOpFn)(auStack_78,*puVar5,*piVar4,local_68);
        if (iVar7 == 0) {
          uVar11 = 1;
          (*(code *)PTR_BN_bin2bn_006a7904)(*puVar5,pcVar10,param_1);
          goto LAB_005cecb8;
        }
        if (ATALLA_lib_error_code == 0) {
          ATALLA_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
        }
        param_1 = 0x6a;
        in_stack_ffffff68 = 0x203;
      }
    }
  }
  pcVar9 = "e_atalla.c";
  pcVar10 = (char *)0x67;
  uVar11 = 0;
  (*(code *)PTR_ERR_put_error_006a7f34)(ATALLA_lib_error_code,0x67,param_1,"e_atalla.c");
LAB_005cecb8:
  (*(code *)PTR_BN_CTX_end_006a8530)(param_5);
  if (local_2c != *(int *)puVar1) {
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
    uVar11 = atalla_mod_exp(pcVar10,param_1,pcVar9,in_stack_ffffff68,uStack_94);
    return uVar11;
  }
  return uVar11;
}
