
/* WARNING: Restarted to delay deadcode elimination for space: ram */

undefined4
ubsec_mod_exp_dh(undefined4 param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4,
                undefined4 *param_5,undefined4 param_6)

{
  undefined *puVar1;
  code *pcVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  int local_30;
  int local_2c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_30 = 0;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  if (ubsec_dso == 0) {
    if (UBSEC_lib_error_code == 0) {
      UBSEC_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
    }
    uVar5 = 0x69;
    uVar4 = 0x23d;
LAB_005d93bc:
    (*(code *)PTR_ERR_put_error_006a7f34)(UBSEC_lib_error_code,0x6a,uVar5,"e_ubsec.c",uVar4);
    uVar4 = 0;
  }
  else {
    local_30 = (*(code *)PTR_BN_num_bits_006a71f4)(param_5);
    if (max_key_len < local_30) {
      if (UBSEC_lib_error_code == 0) {
        UBSEC_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
      }
      (*(code *)PTR_ERR_put_error_006a7f34)(UBSEC_lib_error_code,0x6a,0x6b,"e_ubsec.c",0x244);
    }
    else {
      if ((int)param_2[2] < (int)param_5[1]) {
        iVar3 = (*(code *)PTR_bn_expand2_006a8524)(param_2);
        if (iVar3 == 0) {
          if (UBSEC_lib_error_code == 0) {
            UBSEC_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
          }
          uVar5 = 0x65;
          uVar4 = 0x249;
          goto LAB_005d93bc;
        }
      }
      iVar3 = (*p_UBSEC_ubsec_open)("/dev/ubskey");
      pcVar2 = p_UBSEC_rsa_mod_exp_ioctl;
      if (iVar3 < 1) {
        if (UBSEC_lib_error_code == 0) {
          UBSEC_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
        }
        (*(code *)PTR_ERR_put_error_006a7f34)(UBSEC_lib_error_code,0x6a,0x6c,"e_ubsec.c",0x24f);
      }
      else {
        uVar8 = *param_3;
        uVar4 = (*(code *)PTR_BN_num_bits_006a71f4)(param_3);
        uVar9 = *param_5;
        uVar5 = (*(code *)PTR_BN_num_bits_006a71f4)(param_5);
        uVar10 = *param_4;
        uVar6 = (*(code *)PTR_BN_num_bits_006a71f4)(param_4);
        iVar7 = (*pcVar2)(iVar3,uVar8,uVar4,uVar9,uVar5,uVar10,uVar6,*param_2,&local_30);
        if (iVar7 == 0) {
          (*p_UBSEC_ubsec_close)(iVar3);
          iVar7 = (*(code *)PTR_BN_num_bits_006a71f4)(param_5);
          uVar4 = 1;
          iVar3 = iVar7 + 0x1f;
          if (iVar7 + 0x1f < 0) {
            iVar3 = iVar7 + 0x3e;
          }
          param_2[1] = iVar3 >> 5;
          goto LAB_005d9348;
        }
        if (UBSEC_lib_error_code == 0) {
          UBSEC_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
        }
        (*(code *)PTR_ERR_put_error_006a7f34)(UBSEC_lib_error_code,0x6a,0x6a,"e_ubsec.c",599);
        (*p_UBSEC_ubsec_close)(iVar3);
      }
    }
    uVar4 = (*(code *)PTR_BN_mod_exp_006a795c)(param_2,param_3,param_4,param_5,param_6);
  }
LAB_005d9348:
  if (local_2c == *(int *)puVar1) {
    return uVar4;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (UBSEC_LIBNAME != 0) {
    (*(code *)PTR_CRYPTO_free_006a6e88)();
  }
  UBSEC_LIBNAME = 0;
  if (ubsec_dso != 0) {
    iVar3 = (*(code *)PTR_DSO_free_006a8874)();
    if (iVar3 != 0) {
      ubsec_dso = 0;
      p_UBSEC_ubsec_bytes_to_bits = 0;
      p_UBSEC_ubsec_bits_to_bytes = 0;
      p_UBSEC_ubsec_open = (code *)0x0;
      p_UBSEC_ubsec_close = (code *)0x0;
      p_UBSEC_diffie_hellman_generate_ioctl = 0;
      p_UBSEC_diffie_hellman_agree_ioctl = 0;
      p_UBSEC_rsa_mod_exp_ioctl = (code *)0x0;
      p_UBSEC_rsa_mod_exp_crt_ioctl = 0;
      p_UBSEC_dsa_sign_ioctl = 0;
      p_UBSEC_dsa_verify_ioctl = 0;
      p_UBSEC_max_key_len_ioctl = 0;
      return 1;
    }
    if (UBSEC_lib_error_code == 0) {
      UBSEC_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
    }
    (*(code *)PTR_ERR_put_error_006a7f34)(UBSEC_lib_error_code,0x68,0x67,"e_ubsec.c",0x207);
    return 0;
  }
  if (UBSEC_lib_error_code == 0) {
    UBSEC_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(UBSEC_lib_error_code,0x68,0x69,"e_ubsec.c",0x203);
  return 0;
}

