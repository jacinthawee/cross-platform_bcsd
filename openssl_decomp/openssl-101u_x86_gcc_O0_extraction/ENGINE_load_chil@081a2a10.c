
void ENGINE_load_chil(void)

{
  ENGINE *e;
  int iVar1;
  RSA_METHOD *pRVar2;
  DH_METHOD *pDVar3;
  ENGINE *e_00;
  
  e = ENGINE_new();
  if (e != (ENGINE *)0x0) {
    iVar1 = ENGINE_set_id(e,"chil");
    if (iVar1 != 0) {
      iVar1 = ENGINE_set_name(e,"CHIL hardware engine support");
      if (iVar1 != 0) {
        iVar1 = ENGINE_set_RSA(e,(RSA_METHOD *)hwcrhk_rsa);
        if (iVar1 != 0) {
          iVar1 = ENGINE_set_DH(e,(DH_METHOD *)hwcrhk_dh);
          if (iVar1 != 0) {
            iVar1 = ENGINE_set_RAND(e,(RAND_METHOD *)hwcrhk_rand);
            if (iVar1 != 0) {
              iVar1 = ENGINE_set_destroy_function(e,hwcrhk_destroy);
              if (iVar1 != 0) {
                iVar1 = ENGINE_set_init_function(e,hwcrhk_init);
                if (iVar1 != 0) {
                  iVar1 = ENGINE_set_finish_function(e,hwcrhk_finish);
                  if (iVar1 != 0) {
                    iVar1 = ENGINE_set_ctrl_function(e,hwcrhk_ctrl);
                    if (iVar1 != 0) {
                      iVar1 = ENGINE_set_load_privkey_function(e,hwcrhk_load_privkey);
                      if (iVar1 != 0) {
                        iVar1 = ENGINE_set_load_pubkey_function(e,hwcrhk_load_pubkey);
                        if (iVar1 != 0) {
                          iVar1 = ENGINE_set_cmd_defns(e,(ENGINE_CMD_DEFN *)hwcrhk_cmd_defns);
                          if (iVar1 != 0) {
                            pRVar2 = RSA_PKCS1_SSLeay();
                            hwcrhk_rsa._4_4_ = pRVar2->rsa_pub_enc;
                            hwcrhk_rsa._8_4_ = pRVar2->rsa_pub_dec;
                            hwcrhk_rsa._12_4_ = pRVar2->rsa_priv_enc;
                            hwcrhk_rsa._16_4_ = pRVar2->rsa_priv_dec;
                            pDVar3 = DH_OpenSSL();
                            hwcrhk_dh._4_4_ = pDVar3->generate_key;
                            e_00 = (ENGINE *)pDVar3->compute_key;
                            hwcrhk_dh._8_4_ = e_00;
                            if (HWCRHK_lib_error_code == (ENGINE *)0x0) {
                              e_00 = (ENGINE *)ERR_get_next_error_library();
                              HWCRHK_lib_error_code = e_00;
                            }
                            if (HWCRHK_error_init != 0) {
                              HWCRHK_error_init = 0;
                              ERR_load_strings((int)HWCRHK_lib_error_code,
                                               (ERR_STRING_DATA *)HWCRHK_str_functs);
                              e_00 = HWCRHK_lib_error_code;
                              ERR_load_strings((int)HWCRHK_lib_error_code,
                                               (ERR_STRING_DATA *)HWCRHK_str_reasons);
                              HWCRHK_lib_name._0_4_ = (int)HWCRHK_lib_error_code << 0x18;
                              ERR_load_strings(0,(ERR_STRING_DATA *)HWCRHK_lib_name);
                            }
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
    ENGINE_free(e);
  }
  return;
}

