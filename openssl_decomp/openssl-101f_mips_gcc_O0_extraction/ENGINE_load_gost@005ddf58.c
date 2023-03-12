
void ENGINE_load_gost(void)

{
  int iVar1;
  int iVar2;
  
  if (pmeth_GostR3410_94 == 0) {
    iVar1 = (*(code *)PTR_ENGINE_new_006a98ec)();
    if (iVar1 != 0) {
      if (ameth_GostR3410_94 == 0) {
        iVar2 = (*(code *)PTR_ENGINE_set_id_006a99e4)(iVar1,&DAT_00675194);
        if (iVar2 == 0) {
          (*(code *)PTR_puts_006aab60)("ENGINE_set_id failed");
        }
        else {
          iVar2 = (*(code *)PTR_ENGINE_set_name_006a99e8)
                            (iVar1,"Reference implementation of GOST engine");
          if (iVar2 == 0) {
            (*(code *)PTR_puts_006aab60)("ENGINE_set_name failed");
          }
          else {
            iVar2 = (*(code *)PTR_ENGINE_set_digests_006aa6a8)(iVar1,gost_digests);
            if (iVar2 == 0) {
              (*(code *)PTR_puts_006aab60)("ENGINE_set_digests failed");
            }
            else {
              iVar2 = (*(code *)PTR_ENGINE_set_ciphers_006aa6ac)(iVar1,gost_ciphers);
              if (iVar2 == 0) {
                (*(code *)PTR_puts_006aab60)("ENGINE_set_ciphers failed");
              }
              else {
                iVar2 = (*(code *)PTR_ENGINE_set_pkey_meths_006aa6b0)(iVar1,gost_pkey_meths);
                if (iVar2 == 0) {
                  (*(code *)PTR_puts_006aab60)("ENGINE_set_pkey_meths failed");
                }
                else {
                  iVar2 = (*(code *)PTR_ENGINE_set_pkey_asn1_meths_006aa6b4)
                                    (iVar1,gost_pkey_asn1_meths);
                  if (iVar2 == 0) {
                    (*(code *)PTR_puts_006aab60)("ENGINE_set_pkey_asn1_meths failed");
                  }
                  else {
                    iVar2 = (*(code *)PTR_ENGINE_set_cmd_defns_006a99fc)
                                      (iVar1,PTR_gost_cmds_006aa6b8);
                    if (iVar2 == 0) {
                      (*(code *)PTR_fwrite_006aab7c)
                                ("ENGINE_set_cmd_defns failed\n",1,0x1c,
                                 *(undefined4 *)PTR_stderr_006aac00);
                    }
                    else {
                      iVar2 = (*(code *)PTR_ENGINE_set_ctrl_function_006a99f4)
                                        (iVar1,PTR_gost_control_func_006aa6bc);
                      if (iVar2 == 0) {
                        (*(code *)PTR_fwrite_006aab7c)
                                  ("ENGINE_set_ctrl_func failed\n",1,0x1c,
                                   *(undefined4 *)PTR_stderr_006aac00);
                      }
                      else {
                        iVar2 = (*(code *)PTR_ENGINE_set_destroy_function_006aa658)
                                          (iVar1,gost_engine_destroy);
                        if (iVar2 != 0) {
                          iVar2 = (*(code *)PTR_ENGINE_set_init_function_006a99ec)
                                            (iVar1,gost_engine_init);
                          if (iVar2 != 0) {
                            iVar2 = (*(code *)PTR_ENGINE_set_finish_function_006a99f0)
                                              (iVar1,gost_engine_finish);
                            if (iVar2 != 0) {
                              iVar2 = (*(code *)PTR_register_ameth_gost_006aa6c0)
                                                (0x32c,&ameth_GostR3410_94,"GOST94",
                                                 "GOST R 34.10-94");
                              if (iVar2 != 0) {
                                iVar2 = (*(code *)PTR_register_ameth_gost_006aa6c0)
                                                  (0x32b,&ameth_GostR3410_2001,"GOST2001",
                                                   "GOST R 34.10-2001");
                                if (iVar2 != 0) {
                                  iVar2 = (*(code *)PTR_register_ameth_gost_006aa6c0)
                                                    (0x32f,&ameth_Gost28147_MAC,"GOST-MAC",
                                                     "GOST 28147-89 MAC");
                                  if (iVar2 != 0) {
                                    iVar2 = register_pmeth_gost(0x32c,&pmeth_GostR3410_94,0);
                                    if (iVar2 != 0) {
                                      iVar2 = register_pmeth_gost(0x32b,&pmeth_GostR3410_2001,0);
                                      if (iVar2 != 0) {
                                        iVar2 = register_pmeth_gost(0x32f,&pmeth_Gost28147_MAC,0);
                                        if (iVar2 != 0) {
                                          iVar2 = (*(code *)PTR_ENGINE_register_ciphers_006a991c)
                                                            (iVar1);
                                          if (iVar2 != 0) {
                                            iVar2 = (*(code *)PTR_ENGINE_register_digests_006a9920)
                                                              (iVar1);
                                            if (iVar2 != 0) {
                                              iVar2 = (*(code *)
                                                  PTR_ENGINE_register_pkey_meths_006a993c)(iVar1);
                                              if (iVar2 != 0) {
                                                iVar2 = (*(code *)PTR_EVP_add_cipher_006a9524)
                                                                  (PTR_cipher_gost_006aa69c);
                                                if (iVar2 != 0) {
                                                  iVar2 = (*(code *)PTR_EVP_add_cipher_006a9524)
                                                                    (PTR_cipher_gost_cpacnt_006aa6a0
                                                                    );
                                                  if (iVar2 != 0) {
                                                    iVar2 = (*(code *)PTR_EVP_add_digest_006a953c)
                                                                      (PTR_digest_gost_006aa694);
                                                    if (iVar2 != 0) {
                                                      iVar2 = (*(code *)PTR_EVP_add_digest_006a953c)
                                                                        (PTR_imit_gost_cpa_006aa698)
                                                      ;
                                                      if (iVar2 != 0) {
                                                        (*(code *)PTR_ERR_load_GOST_strings_006aa6c8
                                                        )();
                                                        (*(code *)PTR_ENGINE_add_006a99d8)(iVar1);
                                                        (*(code *)PTR_ENGINE_free_006a7f84)(iVar1);
                    /* WARNING: Could not recover jumptable at 0x005de2dc. Too many branches */
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
        (*(code *)PTR_puts_006aab60)("GOST engine already loaded");
      }
                    /* WARNING: Could not recover jumptable at 0x005ddfec. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)PTR_ENGINE_free_006a7f84)(iVar1);
      return;
    }
  }
  return;
}

