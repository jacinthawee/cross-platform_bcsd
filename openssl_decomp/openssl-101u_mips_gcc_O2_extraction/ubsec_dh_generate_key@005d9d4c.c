
/* WARNING: Restarted to delay deadcode elimination for space: ram */

uint ubsec_dh_generate_key(int param_1,int param_2,undefined4 param_3,char *param_4)

{
  undefined *puVar1;
  code *pcVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  int local_34;
  int local_30;
  int local_2c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  puVar10 = *(undefined4 **)(param_1 + 0x18);
  uVar12 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  if (puVar10 == (undefined4 *)0x0) {
    puVar10 = (undefined4 *)(*(code *)PTR_BN_new_006a71b4)();
    if (puVar10 != (undefined4 *)0x0) {
      local_30 = (*(code *)PTR_BN_num_bits_006a71f4)(*(undefined4 *)(param_1 + 8));
      param_2 = *(int *)(*(int *)(param_1 + 8) + 4);
      iVar3 = *(int *)(param_1 + 8);
      if ((int)puVar10[2] < param_2) {
        iVar3 = (*(code *)PTR_bn_expand2_006a8524)(puVar10);
        if (iVar3 != 0) goto LAB_005da080;
        uVar7 = 0;
        goto LAB_005d9ec0;
      }
      while (param_2 = iVar3, iVar3 = (*(code *)PTR_BN_rand_range_006a868c)(puVar10), iVar3 != 0) {
        if (puVar10[1] != 0) {
          uVar12 = (*(code *)PTR_BN_num_bits_006a71f4)(puVar10);
          goto LAB_005d9dac;
        }
LAB_005da080:
        iVar3 = *(int *)(param_1 + 8);
      }
    }
  }
  else {
LAB_005d9dac:
    puVar11 = *(undefined4 **)(param_1 + 0x14);
    if (puVar11 != (undefined4 *)0x0) {
LAB_005d9dbc:
      iVar3 = (*p_UBSEC_ubsec_open)("/dev/ubskey");
      pcVar2 = p_UBSEC_diffie_hellman_generate_ioctl;
      if (iVar3 < 1) {
        if (UBSEC_lib_error_code == 0) {
          UBSEC_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
        }
        param_4 = "e_ubsec.c";
        param_2 = 0x6f;
        (*(code *)PTR_ERR_put_error_006a7f34)(UBSEC_lib_error_code,0x6f,0x6c,"e_ubsec.c",0x3d5);
      }
      else {
        uVar8 = *puVar10;
        uVar9 = *puVar11;
        uVar14 = **(undefined4 **)(param_1 + 0xc);
        uVar4 = (*(code *)PTR_BN_num_bits_006a71f4)(*(undefined4 **)(param_1 + 0xc));
        uVar13 = **(undefined4 **)(param_1 + 8);
        uVar5 = (*(code *)PTR_BN_num_bits_006a71f4)(*(undefined4 **)(param_1 + 8));
        iVar6 = (*pcVar2)(iVar3,uVar8,&local_30,uVar9,&local_34,uVar14,uVar4,uVar13,uVar5,0,0,uVar12
                         );
        if (iVar6 == 0) {
          (*p_UBSEC_ubsec_close)(iVar3);
          uVar7 = 1;
          *(undefined4 **)(param_1 + 0x14) = puVar11;
          param_2 = local_30 + 0x3e;
          param_4 = (char *)(uint)(local_30 + 0x1f < 0);
          iVar3 = local_34 + 0x1f;
          if (local_34 + 0x1f < 0) {
            iVar3 = local_34 + 0x3e;
          }
          iVar6 = local_30 + 0x1f;
          if (param_4 != (char *)0x0) {
            iVar6 = param_2;
          }
          puVar11[1] = iVar3 >> 5;
          *(undefined4 **)(param_1 + 0x18) = puVar10;
          puVar10[1] = iVar6 >> 5;
          goto LAB_005d9ec0;
        }
        if (UBSEC_lib_error_code == 0) {
          UBSEC_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
        }
        param_4 = "e_ubsec.c";
        param_2 = 0x6f;
        (*(code *)PTR_ERR_put_error_006a7f34)(UBSEC_lib_error_code,0x6f,0x6a,"e_ubsec.c",1000);
        (*p_UBSEC_ubsec_close)(iVar3);
      }
      iVar3 = (*(code *)PTR_DH_OpenSSL_006a8788)();
      uVar7 = (**(code **)(iVar3 + 4))(param_1);
      goto LAB_005d9ec0;
    }
    puVar11 = (undefined4 *)(*(code *)PTR_BN_new_006a71b4)();
    if (puVar11 != (undefined4 *)0x0) {
      local_34 = (*(code *)PTR_BN_num_bits_006a71f4)(*(undefined4 *)(param_1 + 8));
      param_2 = *(int *)(*(int *)(param_1 + 8) + 4);
      if ((param_2 <= (int)puVar11[2]) ||
         (iVar3 = (*(code *)PTR_bn_expand2_006a8524)(puVar11), iVar3 != 0)) goto LAB_005d9dbc;
    }
  }
  uVar7 = 0;
LAB_005d9ec0:
  if (local_2c == *(int *)puVar1) {
    return uVar7;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (param_2 != 200) {
    if (UBSEC_lib_error_code == 0) {
      UBSEC_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
    }
    (*(code *)PTR_ERR_put_error_006a7f34)(UBSEC_lib_error_code,100,0x66,"e_ubsec.c",0x232);
    return 0;
  }
  if (param_4 == (char *)0x0) {
    if (UBSEC_lib_error_code == 0) {
      UBSEC_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
    }
    uVar4 = 0x43;
    uVar12 = 0x227;
  }
  else {
    if (ubsec_dso == 0) {
      if (UBSEC_LIBNAME != 0) {
        (*(code *)PTR_CRYPTO_free_006a6e88)();
      }
      UBSEC_LIBNAME = 0;
      UBSEC_LIBNAME = (*(code *)PTR_BUF_strdup_006a6fdc)(param_4);
      return (uint)(UBSEC_LIBNAME != 0);
    }
    if (UBSEC_lib_error_code == 0) {
      UBSEC_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
    }
    uVar4 = 100;
    uVar12 = 0x22b;
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(UBSEC_lib_error_code,100,uVar4,"e_ubsec.c",uVar12);
  return 0;
}

