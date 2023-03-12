
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
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_1c = *(int *)PTR___stack_chk_guard_006aabf0;
  if (atalla_dso == 0) {
    pcVar6 = ATALLA_LIBNAME;
    if (ATALLA_LIBNAME == (char *)0x0) {
      pcVar6 = "atasi";
    }
    atalla_dso = (*(code *)PTR_DSO_load_006a99a4)(0,pcVar6,0,0);
    if (atalla_dso == 0) {
      if (ATALLA_lib_error_code == 0) {
        ATALLA_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
      }
      uVar7 = 0x69;
      uVar2 = 0x16c;
      goto LAB_005d1764;
    }
    pcVar3 = (code *)(*(code *)PTR_DSO_bind_func_006a99ac)(atalla_dso,"ASI_GetHardwareConfig");
    if (pcVar3 == (code *)0x0) {
LAB_005d1898:
      if (ATALLA_lib_error_code == 0) {
        ATALLA_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
      }
      uVar7 = 0x69;
      uVar2 = 0x176;
      goto LAB_005d1764;
    }
    iVar4 = (*(code *)PTR_DSO_bind_func_006a99ac)(atalla_dso,"ASI_RSAPrivateKeyOpFn");
    if (iVar4 == 0) goto LAB_005d1898;
    iVar5 = (*(code *)PTR_DSO_bind_func_006a99ac)(atalla_dso,"ASI_GetPerformanceStatistics");
    if (iVar5 == 0) goto LAB_005d1898;
    p_Atalla_RSAPrivateKeyOpFn = iVar4;
    iVar4 = (*pcVar3)(0,auStack_101c);
    if (iVar4 == 0) {
      uVar2 = 1;
      goto LAB_005d179c;
    }
    if (ATALLA_lib_error_code == 0) {
      ATALLA_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
    }
    (*(code *)PTR_ERR_put_error_006a9030)(ATALLA_lib_error_code,0x66,0x6b,"e_atalla.c",0x181);
  }
  else {
    if (ATALLA_lib_error_code == 0) {
      ATALLA_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
    }
    uVar7 = 100;
    uVar2 = 0x15f;
LAB_005d1764:
    (*(code *)PTR_ERR_put_error_006a9030)(ATALLA_lib_error_code,0x66,uVar7,"e_atalla.c",uVar2);
  }
  if (atalla_dso != 0) {
    (*(code *)PTR_DSO_free_006a9994)();
  }
  uVar2 = 0;
  atalla_dso = 0;
  p_Atalla_RSAPrivateKeyOpFn = 0;
LAB_005d179c:
  if (local_1c == *(int *)puVar1) {
    return uVar2;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  iVar4 = (*(code *)PTR_ENGINE_new_006a98ec)();
  if (iVar4 != 0) {
    iVar5 = (*(code *)PTR_ENGINE_set_id_006a99e4)(iVar4,"atalla");
    if (iVar5 != 0) {
      iVar5 = (*(code *)PTR_ENGINE_set_name_006a99e8)(iVar4,"Atalla hardware engine support");
      if (iVar5 != 0) {
        iVar5 = (*(code *)PTR_ENGINE_set_RSA_006aa650)(iVar4,atalla_rsa);
        if (iVar5 != 0) {
          iVar5 = (*(code *)PTR_ENGINE_set_DSA_006aa664)(iVar4,atalla_dsa);
          if (iVar5 != 0) {
            iVar5 = (*(code *)PTR_ENGINE_set_DH_006aa668)(iVar4,atalla_dh);
            if (iVar5 != 0) {
              iVar5 = (*(code *)PTR_ENGINE_set_destroy_function_006aa658)(iVar4,atalla_destroy);
              if (iVar5 != 0) {
                iVar5 = (*(code *)PTR_ENGINE_set_init_function_006a99ec)(iVar4,atalla_init);
                if (iVar5 != 0) {
                  iVar5 = (*(code *)PTR_ENGINE_set_finish_function_006a99f0)(iVar4,atalla_finish);
                  if (iVar5 != 0) {
                    iVar5 = (*(code *)PTR_ENGINE_set_ctrl_function_006a99f4)(iVar4,atalla_ctrl);
                    if (iVar5 != 0) {
                      iVar5 = (*(code *)PTR_ENGINE_set_cmd_defns_006a99fc)(iVar4,atalla_cmd_defns);
                      if (iVar5 != 0) {
                        iVar5 = (*(code *)PTR_RSA_PKCS1_SSLeay_006a8bd8)();
                        atalla_rsa._4_4_ = *(undefined4 *)(iVar5 + 4);
                        atalla_rsa._8_4_ = *(undefined4 *)(iVar5 + 8);
                        atalla_rsa._12_4_ = *(undefined4 *)(iVar5 + 0xc);
                        atalla_rsa._16_4_ = *(undefined4 *)(iVar5 + 0x10);
                        iVar5 = (*(code *)PTR_DSA_OpenSSL_006a9870)();
                        atalla_dsa._4_4_ = *(undefined4 *)(iVar5 + 4);
                        atalla_dsa._8_4_ = *(undefined4 *)(iVar5 + 8);
                        atalla_dsa._12_4_ = *(undefined4 *)(iVar5 + 0xc);
                        iVar5 = (*(code *)PTR_DH_OpenSSL_006a98ac)();
                        atalla_dh._4_4_ = *(undefined4 *)(iVar5 + 4);
                        atalla_dh._8_4_ = *(undefined4 *)(iVar5 + 8);
                        if (ATALLA_lib_error_code == 0) {
                          ATALLA_lib_error_code =
                               (*(code *)PTR_ERR_get_next_error_library_006aa644)();
                        }
                        if (ATALLA_error_init != 0) {
                          ATALLA_error_init = 0;
                          (*(code *)PTR_ERR_load_strings_006a9564)
                                    (ATALLA_lib_error_code,ATALLA_str_functs);
                          (*(code *)PTR_ERR_load_strings_006a9564)
                                    (ATALLA_lib_error_code,ATALLA_str_reasons);
                          ATALLA_lib_name._0_4_ = ATALLA_lib_error_code << 0x18;
                          (*(code *)PTR_ERR_load_strings_006a9564)(0,ATALLA_lib_name);
                        }
                        (*(code *)PTR_ENGINE_add_006a99d8)(iVar4);
                        (*(code *)PTR_ENGINE_free_006a7f84)(iVar4);
                    /* WARNING: Could not recover jumptable at 0x005d1bc0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                        uVar2 = (*(code *)PTR_ERR_clear_error_006a7fe0)();
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
                    /* WARNING: Could not recover jumptable at 0x005d19f0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*(code *)PTR_ENGINE_free_006a7f84)(iVar4);
    return uVar2;
  }
  return 0;
}

