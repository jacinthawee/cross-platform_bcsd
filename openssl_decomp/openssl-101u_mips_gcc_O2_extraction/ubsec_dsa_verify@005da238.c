
int ubsec_dsa_verify(undefined4 param_1,undefined4 param_2,undefined4 *param_3,int param_4)

{
  undefined *puVar1;
  code *pcVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  int iVar10;
  int iVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  undefined4 local_44;
  undefined4 local_40 [2];
  int local_38;
  int local_2c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  (*(code *)PTR_BN_init_006a857c)(local_40);
  iVar11 = *(int *)(param_4 + 0xc);
  if (local_38 < *(int *)(iVar11 + 4)) {
    iVar11 = (*(code *)PTR_bn_expand2_006a8524)(local_40);
    if (iVar11 != 0) goto LAB_005da600;
    if (UBSEC_lib_error_code == 0) {
      UBSEC_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
    }
    param_4 = 0;
    (*(code *)PTR_ERR_put_error_006a7f34)(UBSEC_lib_error_code,0x67,0x65,"e_ubsec.c",0x350);
    goto LAB_005da460;
  }
  do {
    local_44 = (*(code *)PTR_BN_num_bits_006a71f4)(iVar11);
    uVar3 = (*p_UBSEC_ubsec_bytes_to_bits)(param_1,param_2);
    iVar11 = (*p_UBSEC_ubsec_open)("/dev/ubskey");
    pcVar2 = p_UBSEC_dsa_verify_ioctl;
    if (iVar11 < 1) {
      if (UBSEC_lib_error_code == 0) {
        UBSEC_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
      }
      (*(code *)PTR_ERR_put_error_006a7f34)(UBSEC_lib_error_code,0x67,0x6c,"e_ubsec.c",0x35b);
LAB_005da564:
      iVar11 = (*(code *)PTR_DSA_OpenSSL_006a874c)();
      param_4 = (**(code **)(iVar11 + 0xc))(param_1,param_2,param_3,param_4);
    }
    else {
      uVar17 = **(undefined4 **)(param_4 + 0xc);
      uVar4 = (*(code *)PTR_BN_num_bits_006a71f4)(*(undefined4 **)(param_4 + 0xc));
      uVar12 = **(undefined4 **)(param_4 + 0x10);
      uVar5 = (*(code *)PTR_BN_num_bits_006a71f4)(*(undefined4 **)(param_4 + 0x10));
      uVar13 = **(undefined4 **)(param_4 + 0x14);
      uVar6 = (*(code *)PTR_BN_num_bits_006a71f4)(*(undefined4 **)(param_4 + 0x14));
      uVar14 = **(undefined4 **)(param_4 + 0x18);
      uVar7 = (*(code *)PTR_BN_num_bits_006a71f4)(*(undefined4 **)(param_4 + 0x18));
      uVar15 = *(undefined4 *)*param_3;
      uVar8 = (*(code *)PTR_BN_num_bits_006a71f4)((undefined4 *)*param_3);
      uVar16 = *(undefined4 *)param_3[1];
      uVar9 = (*(code *)PTR_BN_num_bits_006a71f4)((undefined4 *)param_3[1]);
      iVar10 = (*pcVar2)(iVar11,0,param_1,uVar3,uVar17,uVar4,uVar12,uVar5,uVar13,uVar6,uVar14,uVar7,
                         uVar15,uVar8,uVar16,uVar9,local_40[0],&local_44);
      if (iVar10 != 0) {
        if (UBSEC_lib_error_code == 0) {
          UBSEC_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
        }
        (*(code *)PTR_ERR_put_error_006a7f34)(UBSEC_lib_error_code,0x67,0x6a,"e_ubsec.c",0x371);
        (*p_UBSEC_ubsec_close)(iVar11);
        goto LAB_005da564;
      }
      param_4 = 1;
      (*p_UBSEC_ubsec_close)(iVar11);
    }
LAB_005da460:
    (*(code *)PTR_BN_clear_free_006a7fa8)(local_40);
    if (local_2c == *(int *)puVar1) {
      return param_4;
    }
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_005da600:
    iVar11 = *(int *)(param_4 + 0xc);
  } while( true );
}

