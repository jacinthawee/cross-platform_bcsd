
void ENGINE_load_gost(void)

{
  int iVar1;
  int iVar2;
  
  if (pmeth_GostR3410_94 == 0) {
    iVar1 = (*(code *)PTR_ENGINE_new_006a87cc)();
    if (iVar1 != 0) {
      if (ameth_GostR3410_94 == 0) {
        iVar2 = (*(code *)PTR_ENGINE_set_id_006a88c4)(iVar1,&DAT_006748a4);
        if (iVar2 == 0) {
          (*(code *)PTR_puts_006a9a54)("ENGINE_set_id failed");
        }
        else {
          iVar2 = (*(code *)PTR_ENGINE_set_name_006a88c8)
                            (iVar1,"Reference implementation of GOST engine");
          if (iVar2 == 0) {
            (*(code *)PTR_puts_006a9a54)("ENGINE_set_name failed");
          }
          else {
            iVar2 = (*(code *)PTR_ENGINE_set_digests_006a959c)(iVar1,gost_digests);
            if (iVar2 == 0) {
              (*(code *)PTR_puts_006a9a54)("ENGINE_set_digests failed");
            }
            else {
              iVar2 = (*(code *)PTR_ENGINE_set_ciphers_006a95a0)(iVar1,gost_ciphers);
              if (iVar2 == 0) {
                (*(code *)PTR_puts_006a9a54)("ENGINE_set_ciphers failed");
              }
              else {
                iVar2 = (*(code *)PTR_ENGINE_set_pkey_meths_006a95a4)(iVar1,gost_pkey_meths);
                if (iVar2 == 0) {
                  (*(code *)PTR_puts_006a9a54)("ENGINE_set_pkey_meths failed");
                }
                else {
                  iVar2 = (*(code *)PTR_ENGINE_set_pkey_asn1_meths_006a95a8)
                                    (iVar1,gost_pkey_asn1_meths);
                  if (iVar2 == 0) {
                    (*(code *)PTR_puts_006a9a54)("ENGINE_set_pkey_asn1_meths failed");
                  }
                  else {
                    iVar2 = (*(code *)PTR_ENGINE_set_cmd_defns_006a88dc)
                                      (iVar1,PTR_gost_cmds_006a95ac);
                    if (iVar2 == 0) {
                      (*(code *)PTR_fwrite_006a9a74)
                                ("ENGINE_set_cmd_defns failed\n",1,0x1c,
                                 *(undefined4 *)PTR_stderr_006a9af8);
                    }
                    else {
                      iVar2 = (*(code *)PTR_ENGINE_set_ctrl_function_006a88d4)
                                        (iVar1,PTR_gost_control_func_006a95b0);
                      if (iVar2 == 0) {
                        (*(code *)PTR_fwrite_006a9a74)
                                  ("ENGINE_set_ctrl_func failed\n",1,0x1c,
                                   *(undefined4 *)PTR_stderr_006a9af8);
                      }
                      else {
                        iVar2 = (*(code *)PTR_ENGINE_set_destroy_function_006a954c)
                                          (iVar1,gost_engine_destroy);
                        if (iVar2 != 0) {
                          iVar2 = (*(code *)PTR_ENGINE_set_init_function_006a88cc)
                                            (iVar1,gost_engine_init);
                          if (iVar2 != 0) {
                            iVar2 = (*(code *)PTR_ENGINE_set_finish_function_006a88d0)
                                              (iVar1,gost_engine_finish);
                            if (iVar2 != 0) {
                              iVar2 = (*(code *)PTR_register_ameth_gost_006a95b4)
                                                (0x32c,&ameth_GostR3410_94,"GOST94",
                                                 "GOST R 34.10-94");
                              if (iVar2 != 0) {
                                iVar2 = (*(code *)PTR_register_ameth_gost_006a95b4)
                                                  (0x32b,&ameth_GostR3410_2001,"GOST2001",
                                                   "GOST R 34.10-2001");
                                if (iVar2 != 0) {
                                  iVar2 = (*(code *)PTR_register_ameth_gost_006a95b4)
                                                    (0x32f,&ameth_Gost28147_MAC,"GOST-MAC",
                                                     "GOST 28147-89 MAC");
                                  if (iVar2 != 0) {
                                    iVar2 = register_pmeth_gost(0x32c,&pmeth_GostR3410_94,0);
                                    if (iVar2 != 0) {
                                      iVar2 = register_pmeth_gost(0x32b,&pmeth_GostR3410_2001,0);
                                      if (iVar2 != 0) {
                                        iVar2 = register_pmeth_gost(0x32f,&pmeth_Gost28147_MAC,0);
                                        if (iVar2 != 0) {
                                          iVar2 = (*(code *)PTR_ENGINE_register_ciphers_006a87fc)
                                                            (iVar1);
                                          if (iVar2 != 0) {
                                            iVar2 = (*(code *)PTR_ENGINE_register_digests_006a8800)
                                                              (iVar1);
                                            if (iVar2 != 0) {
                                              iVar2 = (*(code *)
                                                  PTR_ENGINE_register_pkey_meths_006a881c)(iVar1);
                                              if (iVar2 != 0) {
                                                iVar2 = (*(code *)PTR_EVP_add_cipher_006a8404)
                                                                  (PTR_cipher_gost_006a9590);
                                                if (iVar2 != 0) {
                                                  iVar2 = (*(code *)PTR_EVP_add_cipher_006a8404)
                                                                    (PTR_cipher_gost_cpacnt_006a9594
                                                                    );
                                                  if (iVar2 != 0) {
                                                    iVar2 = (*(code *)PTR_EVP_add_digest_006a841c)
                                                                      (PTR_digest_gost_006a9588);
                                                    if (iVar2 != 0) {
                                                      iVar2 = (*(code *)PTR_EVP_add_digest_006a841c)
                                                                        (PTR_imit_gost_cpa_006a958c)
                                                      ;
                                                      if (iVar2 != 0) {
                                                        (*(code *)PTR_ERR_load_GOST_strings_006a95bc
                                                        )();
                                                        (*(code *)PTR_ENGINE_add_006a88b8)(iVar1);
                                                        (*(code *)PTR_ENGINE_free_006a6e84)(iVar1);
                    /* WARNING: Could not recover jumptable at 0x005dbd0c. Too many branches */
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
              }
            }
          }
        }
      }
      else {
        (*(code *)PTR_puts_006a9a54)("GOST engine already loaded");
      }
                    /* WARNING: Could not recover jumptable at 0x005dba1c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)PTR_ENGINE_free_006a6e84)(iVar1);
      return;
    }
  }
  return;
}

