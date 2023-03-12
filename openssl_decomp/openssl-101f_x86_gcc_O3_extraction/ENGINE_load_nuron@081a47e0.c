
void ENGINE_load_nuron(void)

{
  ENGINE *e;
  int iVar1;
  RSA_METHOD *pRVar2;
  DSA_METHOD *pDVar3;
  DH_METHOD *pDVar4;
  ENGINE *e_00;
  
  e = ENGINE_new();
  if (e != (ENGINE *)0x0) {
    iVar1 = ENGINE_set_id(e,"nuron");
    if (iVar1 != 0) {
      iVar1 = ENGINE_set_name(e,"Nuron hardware engine support");
      if (iVar1 != 0) {
        iVar1 = ENGINE_set_RSA(e,(RSA_METHOD *)nuron_rsa);
        if (iVar1 != 0) {
          iVar1 = ENGINE_set_DSA(e,(DSA_METHOD *)nuron_dsa);
          if (iVar1 != 0) {
            iVar1 = ENGINE_set_DH(e,(DH_METHOD *)nuron_dh);
            if (iVar1 != 0) {
              iVar1 = ENGINE_set_destroy_function(e,nuron_destroy);
              if (iVar1 != 0) {
                iVar1 = ENGINE_set_init_function(e,nuron_init);
                if (iVar1 != 0) {
                  iVar1 = ENGINE_set_finish_function(e,nuron_finish);
                  if (iVar1 != 0) {
                    iVar1 = ENGINE_set_ctrl_function(e,nuron_ctrl);
                    if (iVar1 != 0) {
                      iVar1 = ENGINE_set_cmd_defns(e,(ENGINE_CMD_DEFN *)nuron_cmd_defns);
                      if (iVar1 != 0) {
                        pRVar2 = RSA_PKCS1_SSLeay();
                        nuron_rsa._4_4_ = pRVar2->rsa_pub_enc;
                        nuron_rsa._8_4_ = pRVar2->rsa_pub_dec;
                        nuron_rsa._12_4_ = pRVar2->rsa_priv_enc;
                        nuron_rsa._16_4_ = pRVar2->rsa_priv_dec;
                        pDVar3 = DSA_OpenSSL();
                        nuron_dsa._4_4_ = pDVar3->dsa_do_sign;
                        nuron_dsa._8_4_ = pDVar3->dsa_sign_setup;
                        nuron_dsa._12_4_ = pDVar3->dsa_do_verify;
                        pDVar4 = DH_OpenSSL();
                        nuron_dh._4_4_ = pDVar4->generate_key;
                        e_00 = (ENGINE *)pDVar4->compute_key;
                        nuron_dh._8_4_ = e_00;
                        if (NURON_lib_error_code == (ENGINE *)0x0) {
                          e_00 = (ENGINE *)ERR_get_next_error_library();
                          NURON_lib_error_code = e_00;
                        }
                        if (NURON_error_init != 0) {
                          NURON_error_init = 0;
                          ERR_load_strings((int)NURON_lib_error_code,
                                           (ERR_STRING_DATA *)NURON_str_functs);
                          e_00 = NURON_lib_error_code;
                          ERR_load_strings((int)NURON_lib_error_code,
                                           (ERR_STRING_DATA *)NURON_str_reasons);
                          NURON_lib_name._0_4_ = (int)NURON_lib_error_code << 0x18;
                          ERR_load_strings(0,(ERR_STRING_DATA *)NURON_lib_name);
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
    ENGINE_free(e);
  }
  return;
}

