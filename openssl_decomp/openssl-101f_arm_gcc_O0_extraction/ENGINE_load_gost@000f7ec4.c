
void ENGINE_load_gost(void)

{
  ENGINE *e;
  int iVar1;
  
  if ((pmeth_GostR3410_94 != 0) || (e = ENGINE_new(), e == (ENGINE *)0x0)) {
    return;
  }
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
        iVar1 = ENGINE_set_digests(e,gost_digests + 1);
        if (iVar1 == 0) {
          puts("ENGINE_set_digests failed");
        }
        else {
          iVar1 = ENGINE_set_ciphers(e,gost_ciphers + 1);
          if (iVar1 == 0) {
            puts("ENGINE_set_ciphers failed");
          }
          else {
            iVar1 = ENGINE_set_pkey_meths(e,gost_pkey_meths + 1);
            if (iVar1 == 0) {
              puts("ENGINE_set_pkey_meths failed");
            }
            else {
              iVar1 = ENGINE_set_pkey_asn1_meths(e,gost_pkey_asn1_meths + 1);
              if (iVar1 == 0) {
                puts("ENGINE_set_pkey_asn1_meths failed");
              }
              else {
                iVar1 = ENGINE_set_cmd_defns(e,(ENGINE_CMD_DEFN *)&gost_cmds);
                if (iVar1 == 0) {
                  fwrite("ENGINE_set_cmd_defns failed\n",1,0x1c,stderr);
                }
                else {
                  iVar1 = ENGINE_set_ctrl_function(e,gost_control_func + 1);
                  if (iVar1 == 0) {
                    fwrite("ENGINE_set_ctrl_func failed\n",1,0x1c,stderr);
                  }
                  else {
                    iVar1 = ENGINE_set_destroy_function(e,gost_engine_destroy + 1);
                    if (((((iVar1 != 0) &&
                          (iVar1 = ENGINE_set_init_function(e,gost_engine_init + 1), iVar1 != 0)) &&
                         (iVar1 = ENGINE_set_finish_function(e,gost_engine_finish + 1), iVar1 != 0))
                        && (((iVar1 = register_ameth_gost(0x32c,PTR_ameth_GostR3410_94_000f8160,
                                                          "GOST94","GOST R 34.10-94"), iVar1 != 0 &&
                             (iVar1 = register_ameth_gost(0x32b,PTR_ameth_GostR3410_2001_000f8164,
                                                          "GOST2001","GOST R 34.10-2001"),
                             iVar1 != 0)) &&
                            ((iVar1 = register_ameth_gost(0x32f,PTR_ameth_Gost28147_MAC_000f8168,
                                                          "GOST-MAC","GOST 28147-89 MAC"),
                             iVar1 != 0 &&
                             ((iVar1 = register_pmeth_gost(0x32c,&pmeth_GostR3410_94,0), iVar1 != 0
                              && (iVar1 = register_pmeth_gost(0x32b,
                                                  PTR_pmeth_GostR3410_2001_000f816c,0), iVar1 != 0))
                             )))))) &&
                       ((iVar1 = register_pmeth_gost(0x32f,PTR_pmeth_Gost28147_MAC_000f8170,0),
                        iVar1 != 0 &&
                        (((((iVar1 = ENGINE_register_ciphers(e), iVar1 != 0 &&
                            (iVar1 = ENGINE_register_digests(e), iVar1 != 0)) &&
                           (iVar1 = ENGINE_register_pkey_meths(e), iVar1 != 0)) &&
                          ((iVar1 = EVP_add_cipher((EVP_CIPHER *)cipher_gost), iVar1 != 0 &&
                           (iVar1 = EVP_add_cipher((EVP_CIPHER *)cipher_gost_cpacnt), iVar1 != 0))))
                         && ((iVar1 = EVP_add_digest((EVP_MD *)&digest_gost), iVar1 != 0 &&
                             (iVar1 = EVP_add_digest((EVP_MD *)imit_gost_cpa), iVar1 != 0)))))))) {
                      ERR_load_GOST_strings();
                      ENGINE_add(e);
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
  else {
    puts("GOST engine already loaded");
  }
  ENGINE_free(e);
  return;
}

