
void ENGINE_load_aep(void)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  
  iVar1 = (*(code *)PTR_ENGINE_new_006a98ec)();
  if (iVar1 == 0) {
    return;
  }
  iVar2 = (*(code *)PTR_ENGINE_set_id_006a99e4)(iVar1,&DAT_00673d98);
  if (iVar2 != 0) {
    iVar2 = (*(code *)PTR_ENGINE_set_name_006a99e8)(iVar1,"Aep hardware engine support");
    if (iVar2 != 0) {
      iVar2 = (*(code *)PTR_ENGINE_set_RSA_006aa650)(iVar1,aep_rsa);
      if (iVar2 != 0) {
        iVar2 = (*(code *)PTR_ENGINE_set_DSA_006aa664)(iVar1,aep_dsa);
        if (iVar2 != 0) {
          iVar2 = (*(code *)PTR_ENGINE_set_DH_006aa668)(iVar1,aep_dh);
          if (iVar2 != 0) {
            iVar2 = (*(code *)PTR_ENGINE_set_init_function_006a99ec)(iVar1,aep_init);
            if (iVar2 != 0) {
              iVar2 = (*(code *)PTR_ENGINE_set_destroy_function_006aa658)(iVar1,aep_destroy);
              if (iVar2 != 0) {
                iVar2 = (*(code *)PTR_ENGINE_set_finish_function_006a99f0)(iVar1,aep_finish);
                if (iVar2 != 0) {
                  iVar2 = (*(code *)PTR_ENGINE_set_ctrl_function_006a99f4)(iVar1,aep_ctrl);
                  if (iVar2 != 0) {
                    iVar2 = (*(code *)PTR_ENGINE_set_cmd_defns_006a99fc)(iVar1,aep_cmd_defns);
                    if (iVar2 != 0) {
                      iVar2 = (*(code *)PTR_RSA_PKCS1_SSLeay_006a8bd8)();
                      aep_rsa._4_4_ = *(undefined4 *)(iVar2 + 4);
                      aep_rsa._8_4_ = *(undefined4 *)(iVar2 + 8);
                      aep_rsa._12_4_ = *(undefined4 *)(iVar2 + 0xc);
                      aep_rsa._16_4_ = *(undefined4 *)(iVar2 + 0x10);
                      iVar2 = (*(code *)PTR_DSA_OpenSSL_006a9870)();
                      aep_dsa._4_4_ = *(undefined4 *)(iVar2 + 4);
                      aep_dsa._8_4_ = *(undefined4 *)(iVar2 + 8);
                      aep_dsa._12_4_ = *(undefined4 *)(iVar2 + 0xc);
                      puVar3 = (undefined4 *)(*(code *)PTR_DSA_get_default_method_006aa66c)();
                      puVar4 = puVar3;
                      puVar6 = (undefined4 *)aep_dsa;
                      do {
                        puVar5 = puVar4 + 4;
                        uVar9 = puVar4[1];
                        uVar8 = puVar4[2];
                        uVar7 = puVar4[3];
                        *puVar6 = *puVar4;
                        puVar6[1] = uVar9;
                        puVar6[2] = uVar8;
                        puVar6[3] = uVar7;
                        puVar4 = puVar5;
                        puVar6 = puVar6 + 4;
                      } while (puVar5 != puVar3 + 0xc);
                      aep_dsa._16_4_ = aep_dsa_mod_exp;
                      aep_dsa._20_4_ = aep_mod_exp_dsa;
                      iVar2 = (*(code *)PTR_DH_OpenSSL_006a98ac)();
                      aep_dh._4_4_ = *(undefined4 *)(iVar2 + 4);
                      aep_dh._8_4_ = *(undefined4 *)(iVar2 + 8);
                      aep_dh._12_4_ = *(undefined4 *)(iVar2 + 0xc);
                      if (AEPHK_lib_error_code == 0) {
                        AEPHK_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
                      }
                      if (AEPHK_error_init != 0) {
                        AEPHK_error_init = 0;
                        (*(code *)PTR_ERR_load_strings_006a9564)
                                  (AEPHK_lib_error_code,AEPHK_str_functs);
                        (*(code *)PTR_ERR_load_strings_006a9564)
                                  (AEPHK_lib_error_code,AEPHK_str_reasons);
                      }
                      (*(code *)PTR_ENGINE_add_006a99d8)(iVar1);
                      (*(code *)PTR_ENGINE_free_006a7f84)(iVar1);
                    /* WARNING: Could not recover jumptable at 0x005d0be0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                      (*(code *)PTR_ERR_clear_error_006a7fe0)();
                      return;
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
                    /* WARNING: Could not recover jumptable at 0x005d099c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_ENGINE_free_006a7f84)(iVar1);
  return;
}

