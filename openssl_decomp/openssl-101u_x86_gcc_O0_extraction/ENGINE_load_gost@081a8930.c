
void ENGINE_load_gost(void)

{
  ENGINE *e;
  int iVar1;
  ENGINE *e_00;
  undefined4 extraout_ECX;
  undefined8 uVar2;
  
  if (pmeth_GostR3410_94 != 0) {
    return;
  }
  e = ENGINE_new();
  if (e != (ENGINE *)0x0) {
    if (ameth_GostR3410_94 == 0) {
      iVar1 = ENGINE_set_id(e,"gost");
      if (iVar1 == 0) {
        puts("ENGINE_set_id failed");
      }
      else {
        iVar1 = ENGINE_set_name(e,"Reference implementation of GOST engine");
        if (iVar1 == 0) {
          puts("ENGINE_set_name failed");
        }
        else {
          iVar1 = ENGINE_set_digests(e,gost_digests);
          if (iVar1 == 0) {
            puts("ENGINE_set_digests failed");
          }
          else {
            iVar1 = ENGINE_set_ciphers(e,gost_ciphers);
            if (iVar1 == 0) {
              puts("ENGINE_set_ciphers failed");
            }
            else {
              iVar1 = ENGINE_set_pkey_meths(e,gost_pkey_meths);
              if (iVar1 == 0) {
                puts("ENGINE_set_pkey_meths failed");
              }
              else {
                iVar1 = ENGINE_set_pkey_asn1_meths(e,gost_pkey_asn1_meths);
                if (iVar1 == 0) {
                  puts("ENGINE_set_pkey_asn1_meths failed");
                }
                else {
                  iVar1 = ENGINE_set_cmd_defns(e,(ENGINE_CMD_DEFN *)gost_cmds);
                  if (iVar1 == 0) {
                    fwrite("ENGINE_set_cmd_defns failed\n",1,0x1c,stderr);
                  }
                  else {
                    iVar1 = ENGINE_set_ctrl_function(e,gost_control_func);
                    if (iVar1 == 0) {
                      fwrite("ENGINE_set_ctrl_func failed\n",1,0x1c,stderr);
                    }
                    else {
                      iVar1 = ENGINE_set_destroy_function(e,gost_engine_destroy);
                      if (iVar1 != 0) {
                        iVar1 = ENGINE_set_init_function(e,gost_engine_init);
                        if (iVar1 != 0) {
                          iVar1 = ENGINE_set_finish_function(e,gost_engine_finish);
                          if (iVar1 != 0) {
                            iVar1 = register_ameth_gost(0x32c,&ameth_GostR3410_94,"GOST94",
                                                        "GOST R 34.10-94");
                            if (iVar1 != 0) {
                              iVar1 = register_ameth_gost(0x32b,&ameth_GostR3410_2001,"GOST2001",
                                                          "GOST R 34.10-2001");
                              if (iVar1 != 0) {
                                iVar1 = register_ameth_gost(0x32f,&ameth_Gost28147_MAC,"GOST-MAC",
                                                            "GOST 28147-89 MAC");
                                if (iVar1 != 0) {
                                  uVar2 = register_pmeth_gost(0x32c,&pmeth_GostR3410_94,0,
                                                              extraout_ECX);
                                  if ((int)uVar2 != 0) {
                                    iVar1 = register_pmeth_gost(0x32b,&pmeth_GostR3410_2001,0,
                                                                (int)((ulonglong)uVar2 >> 0x20));
                                    if (iVar1 != 0) {
                                      iVar1 = register_pmeth_gost(0x32f,&pmeth_Gost28147_MAC,0,iVar1
                                                                 );
                                      if (iVar1 != 0) {
                                        iVar1 = ENGINE_register_ciphers(e);
                                        if (iVar1 != 0) {
                                          iVar1 = ENGINE_register_digests(e);
                                          if (iVar1 != 0) {
                                            iVar1 = ENGINE_register_pkey_meths(e);
                                            if (iVar1 != 0) {
                                              iVar1 = EVP_add_cipher((EVP_CIPHER *)cipher_gost);
                                              if (iVar1 != 0) {
                                                iVar1 = EVP_add_cipher((EVP_CIPHER *)
                                                                       cipher_gost_cpacnt);
                                                if (iVar1 != 0) {
                                                  iVar1 = EVP_add_digest((EVP_MD *)digest_gost);
                                                  if (iVar1 != 0) {
                                                    iVar1 = EVP_add_digest((EVP_MD *)imit_gost_cpa);
                                                    if (iVar1 != 0) {
                                                      e_00 = (ENGINE *)ERR_load_GOST_strings();
                                                      ENGINE_add(e_00);
                                                      ENGINE_free(e);
                                                      ERR_clear_error();
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
      puts("GOST engine already loaded");
    }
    ENGINE_free(e);
  }
  return;
}

