
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
  
  iVar1 = (*(code *)PTR_ENGINE_new_006a87cc)();
  if (iVar1 == 0) {
    return;
  }
  iVar2 = (*(code *)PTR_ENGINE_set_id_006a88c4)(iVar1,&DAT_00673488);
  if (iVar2 != 0) {
    iVar2 = (*(code *)PTR_ENGINE_set_name_006a88c8)(iVar1,"Aep hardware engine support");
    if (iVar2 != 0) {
      iVar2 = (*(code *)PTR_ENGINE_set_RSA_006a9544)(iVar1,aep_rsa);
      if (iVar2 != 0) {
        iVar2 = (*(code *)PTR_ENGINE_set_DSA_006a9558)(iVar1,aep_dsa);
        if (iVar2 != 0) {
          iVar2 = (*(code *)PTR_ENGINE_set_DH_006a955c)(iVar1,aep_dh);
          if (iVar2 != 0) {
            iVar2 = (*(code *)PTR_ENGINE_set_init_function_006a88cc)(iVar1,aep_init);
            if (iVar2 != 0) {
              iVar2 = (*(code *)PTR_ENGINE_set_destroy_function_006a954c)(iVar1,aep_destroy);
              if (iVar2 != 0) {
                iVar2 = (*(code *)PTR_ENGINE_set_finish_function_006a88d0)(iVar1,aep_finish);
                if (iVar2 != 0) {
                  iVar2 = (*(code *)PTR_ENGINE_set_ctrl_function_006a88d4)(iVar1,aep_ctrl);
                  if (iVar2 != 0) {
                    iVar2 = (*(code *)PTR_ENGINE_set_cmd_defns_006a88dc)(iVar1,aep_cmd_defns);
                    if (iVar2 != 0) {
                      iVar2 = (*(code *)PTR_RSA_PKCS1_SSLeay_006a7aec)();
                      aep_rsa._4_4_ = *(undefined4 *)(iVar2 + 4);
                      aep_rsa._8_4_ = *(undefined4 *)(iVar2 + 8);
                      aep_rsa._12_4_ = *(undefined4 *)(iVar2 + 0xc);
                      aep_rsa._16_4_ = *(undefined4 *)(iVar2 + 0x10);
                      iVar2 = (*(code *)PTR_DSA_OpenSSL_006a874c)();
                      aep_dsa._4_4_ = *(undefined4 *)(iVar2 + 4);
                      aep_dsa._8_4_ = *(undefined4 *)(iVar2 + 8);
                      aep_dsa._12_4_ = *(undefined4 *)(iVar2 + 0xc);
                      puVar3 = (undefined4 *)(*(code *)PTR_DSA_get_default_method_006a9560)();
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
                      iVar2 = (*(code *)PTR_DH_OpenSSL_006a8788)();
                      aep_dh._4_4_ = *(undefined4 *)(iVar2 + 4);
                      aep_dh._8_4_ = *(undefined4 *)(iVar2 + 8);
                      aep_dh._12_4_ = *(undefined4 *)(iVar2 + 0xc);
                      if (AEPHK_lib_error_code == 0) {
                        AEPHK_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
                      }
                      if (AEPHK_error_init != 0) {
                        AEPHK_error_init = 0;
                        (*(code *)PTR_ERR_load_strings_006a8444)
                                  (AEPHK_lib_error_code,AEPHK_str_functs);
                        (*(code *)PTR_ERR_load_strings_006a8444)
                                  (AEPHK_lib_error_code,AEPHK_str_reasons);
                      }
                      (*(code *)PTR_ENGINE_add_006a88b8)(iVar1);
                      (*(code *)PTR_ENGINE_free_006a6e84)(iVar1);
                    /* WARNING: Could not recover jumptable at 0x005ce610. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                      (*(code *)PTR_ERR_clear_error_006a6ee0)();
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
                    /* WARNING: Could not recover jumptable at 0x005ce3cc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_ENGINE_free_006a6e84)(iVar1);
  return;
}

