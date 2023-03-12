
/* WARNING: Restarted to delay deadcode elimination for space: ram */

undefined4 atalla_init(void)

{
  undefined *puVar1;
  undefined4 uVar2;
  code *pcVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  undefined4 uVar7;
  undefined auStack_101c [4096];
  int local_1c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_1c = *(int *)PTR___stack_chk_guard_006a9ae8;
  if (atalla_dso == 0) {
    pcVar6 = ATALLA_LIBNAME;
    if (ATALLA_LIBNAME == (char *)0x0) {
      pcVar6 = "atasi";
    }
    atalla_dso = (*(code *)PTR_DSO_load_006a8884)(0,pcVar6,0,0);
    if (atalla_dso == 0) {
      if (ATALLA_lib_error_code == 0) {
        ATALLA_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
      }
      uVar7 = 0x69;
      uVar2 = 0x17f;
      goto LAB_005cf194;
    }
    pcVar3 = (code *)(*(code *)PTR_DSO_bind_func_006a888c)(atalla_dso,"ASI_GetHardwareConfig");
    if (pcVar3 == (code *)0x0) {
LAB_005cf2c8:
      if (ATALLA_lib_error_code == 0) {
        ATALLA_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
      }
      uVar7 = 0x69;
      uVar2 = 0x189;
      goto LAB_005cf194;
    }
    iVar4 = (*(code *)PTR_DSO_bind_func_006a888c)(atalla_dso,"ASI_RSAPrivateKeyOpFn");
    if (iVar4 == 0) goto LAB_005cf2c8;
    iVar5 = (*(code *)PTR_DSO_bind_func_006a888c)(atalla_dso,"ASI_GetPerformanceStatistics");
    if (iVar5 == 0) goto LAB_005cf2c8;
    p_Atalla_RSAPrivateKeyOpFn = iVar4;
    iVar4 = (*pcVar3)(0,auStack_101c);
    if (iVar4 == 0) {
      uVar2 = 1;
      goto LAB_005cf1cc;
    }
    if (ATALLA_lib_error_code == 0) {
      ATALLA_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
    }
    (*(code *)PTR_ERR_put_error_006a7f34)(ATALLA_lib_error_code,0x66,0x6b,"e_atalla.c",0x194);
  }
  else {
    if (ATALLA_lib_error_code == 0) {
      ATALLA_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
    }
    uVar7 = 100;
    uVar2 = 0x170;
LAB_005cf194:
    (*(code *)PTR_ERR_put_error_006a7f34)(ATALLA_lib_error_code,0x66,uVar7,"e_atalla.c",uVar2);
  }
  if (atalla_dso != 0) {
    (*(code *)PTR_DSO_free_006a8874)();
  }
  uVar2 = 0;
  atalla_dso = 0;
  p_Atalla_RSAPrivateKeyOpFn = 0;
LAB_005cf1cc:
  if (local_1c == *(int *)puVar1) {
    return uVar2;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  iVar4 = (*(code *)PTR_ENGINE_new_006a87cc)();
  if (iVar4 != 0) {
    iVar5 = (*(code *)PTR_ENGINE_set_id_006a88c4)(iVar4,"atalla");
    if (iVar5 != 0) {
      iVar5 = (*(code *)PTR_ENGINE_set_name_006a88c8)(iVar4,"Atalla hardware engine support");
      if (iVar5 != 0) {
        iVar5 = (*(code *)PTR_ENGINE_set_RSA_006a9544)(iVar4,atalla_rsa);
        if (iVar5 != 0) {
          iVar5 = (*(code *)PTR_ENGINE_set_DSA_006a9558)(iVar4,atalla_dsa);
          if (iVar5 != 0) {
            iVar5 = (*(code *)PTR_ENGINE_set_DH_006a955c)(iVar4,atalla_dh);
            if (iVar5 != 0) {
              iVar5 = (*(code *)PTR_ENGINE_set_destroy_function_006a954c)(iVar4,atalla_destroy);
              if (iVar5 != 0) {
                iVar5 = (*(code *)PTR_ENGINE_set_init_function_006a88cc)(iVar4,atalla_init);
                if (iVar5 != 0) {
                  iVar5 = (*(code *)PTR_ENGINE_set_finish_function_006a88d0)(iVar4,atalla_finish);
                  if (iVar5 != 0) {
                    iVar5 = (*(code *)PTR_ENGINE_set_ctrl_function_006a88d4)(iVar4,atalla_ctrl);
                    if (iVar5 != 0) {
                      iVar5 = (*(code *)PTR_ENGINE_set_cmd_defns_006a88dc)(iVar4,atalla_cmd_defns);
                      if (iVar5 != 0) {
                        iVar5 = (*(code *)PTR_RSA_PKCS1_SSLeay_006a7aec)();
                        atalla_rsa._4_4_ = *(undefined4 *)(iVar5 + 4);
                        atalla_rsa._8_4_ = *(undefined4 *)(iVar5 + 8);
                        atalla_rsa._12_4_ = *(undefined4 *)(iVar5 + 0xc);
                        atalla_rsa._16_4_ = *(undefined4 *)(iVar5 + 0x10);
                        iVar5 = (*(code *)PTR_DSA_OpenSSL_006a874c)();
                        atalla_dsa._4_4_ = *(undefined4 *)(iVar5 + 4);
                        atalla_dsa._8_4_ = *(undefined4 *)(iVar5 + 8);
                        atalla_dsa._12_4_ = *(undefined4 *)(iVar5 + 0xc);
                        iVar5 = (*(code *)PTR_DH_OpenSSL_006a8788)();
                        atalla_dh._4_4_ = *(undefined4 *)(iVar5 + 4);
                        atalla_dh._8_4_ = *(undefined4 *)(iVar5 + 8);
                        if (ATALLA_lib_error_code == 0) {
                          ATALLA_lib_error_code =
                               (*(code *)PTR_ERR_get_next_error_library_006a9538)();
                        }
                        if (ATALLA_error_init != 0) {
                          ATALLA_error_init = 0;
                          (*(code *)PTR_ERR_load_strings_006a8444)
                                    (ATALLA_lib_error_code,ATALLA_str_functs);
                          (*(code *)PTR_ERR_load_strings_006a8444)
                                    (ATALLA_lib_error_code,ATALLA_str_reasons);
                          ATALLA_lib_name._0_4_ = ATALLA_lib_error_code << 0x18;
                          (*(code *)PTR_ERR_load_strings_006a8444)(0,ATALLA_lib_name);
                        }
                        (*(code *)PTR_ENGINE_add_006a88b8)(iVar4);
                        (*(code *)PTR_ENGINE_free_006a6e84)(iVar4);
                    /* WARNING: Could not recover jumptable at 0x005cf5f0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                        uVar2 = (*(code *)PTR_ERR_clear_error_006a6ee0)();
                        return uVar2;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
                    /* WARNING: Could not recover jumptable at 0x005cf420. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*(code *)PTR_ENGINE_free_006a6e84)(iVar4);
    return uVar2;
  }
  return 0;
}

