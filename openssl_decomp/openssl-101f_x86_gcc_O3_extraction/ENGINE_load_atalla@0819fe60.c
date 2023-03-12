
void ENGINE_load_atalla(void)

{
  ENGINE *e;
  int iVar1;
  RSA_METHOD *pRVar2;
  DSA_METHOD *pDVar3;
  DH_METHOD *pDVar4;
  ENGINE *e_00;
  
  e = ENGINE_new();
  if (e != (ENGINE *)0x0) {
    iVar1 = ENGINE_set_id(e,"atalla");
    if (iVar1 != 0) {
      iVar1 = ENGINE_set_name(e,"Atalla hardware engine support");
      if (iVar1 != 0) {
        iVar1 = ENGINE_set_RSA(e,(RSA_METHOD *)atalla_rsa);
        if (iVar1 != 0) {
          iVar1 = ENGINE_set_DSA(e,(DSA_METHOD *)atalla_dsa);
          if (iVar1 != 0) {
            iVar1 = ENGINE_set_DH(e,(DH_METHOD *)atalla_dh);
            if (iVar1 != 0) {
              iVar1 = ENGINE_set_destroy_function(e,atalla_destroy);
              if (iVar1 != 0) {
                iVar1 = ENGINE_set_init_function(e,atalla_init);
                if (iVar1 != 0) {
                  iVar1 = ENGINE_set_finish_function(e,atalla_finish);
                  if (iVar1 != 0) {
                    iVar1 = ENGINE_set_ctrl_function(e,atalla_ctrl);
                    if (iVar1 != 0) {
                      iVar1 = ENGINE_set_cmd_defns(e,(ENGINE_CMD_DEFN *)atalla_cmd_defns);
                      if (iVar1 != 0) {
                        pRVar2 = RSA_PKCS1_SSLeay();
                        atalla_rsa._4_4_ = pRVar2->rsa_pub_enc;
                        atalla_rsa._8_4_ = pRVar2->rsa_pub_dec;
                        atalla_rsa._12_4_ = pRVar2->rsa_priv_enc;
                        atalla_rsa._16_4_ = pRVar2->rsa_priv_dec;
                        pDVar3 = DSA_OpenSSL();
                        atalla_dsa._4_4_ = pDVar3->dsa_do_sign;
                        atalla_dsa._8_4_ = pDVar3->dsa_sign_setup;
                        atalla_dsa._12_4_ = pDVar3->dsa_do_verify;
                        pDVar4 = DH_OpenSSL();
                        atalla_dh._4_4_ = pDVar4->generate_key;
                        e_00 = (ENGINE *)pDVar4->compute_key;
                        atalla_dh._8_4_ = e_00;
                        if (ATALLA_lib_error_code == (ENGINE *)0x0) {
                          e_00 = (ENGINE *)ERR_get_next_error_library();
                          ATALLA_lib_error_code = e_00;
                        }
                        if (ATALLA_error_init != 0) {
                          ATALLA_error_init = 0;
                          ERR_load_strings((int)ATALLA_lib_error_code,
                                           (ERR_STRING_DATA *)ATALLA_str_functs);
                          e_00 = ATALLA_lib_error_code;
                          ERR_load_strings((int)ATALLA_lib_error_code,
                                           (ERR_STRING_DATA *)ATALLA_str_reasons);
                          ATALLA_lib_name._0_4_ = (int)ATALLA_lib_error_code << 0x18;
                          ERR_load_strings(0,(ERR_STRING_DATA *)ATALLA_lib_name);
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

