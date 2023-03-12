
void ENGINE_load_cswift(void)

{
  ENGINE *e;
  int iVar1;
  RSA_METHOD *pRVar2;
  DH_METHOD *pDVar3;
  ENGINE *e_00;
  
  e = ENGINE_new();
  if (e != (ENGINE *)0x0) {
    iVar1 = ENGINE_set_id(e,"cswift");
    if (iVar1 != 0) {
      iVar1 = ENGINE_set_name(e,"CryptoSwift hardware engine support");
      if (iVar1 != 0) {
        iVar1 = ENGINE_set_RSA(e,(RSA_METHOD *)cswift_rsa);
        if (iVar1 != 0) {
          iVar1 = ENGINE_set_DSA(e,(DSA_METHOD *)cswift_dsa);
          if (iVar1 != 0) {
            iVar1 = ENGINE_set_DH(e,(DH_METHOD *)cswift_dh);
            if (iVar1 != 0) {
              iVar1 = ENGINE_set_RAND(e,(RAND_METHOD *)cswift_random);
              if (iVar1 != 0) {
                iVar1 = ENGINE_set_destroy_function(e,cswift_destroy);
                if (iVar1 != 0) {
                  iVar1 = ENGINE_set_init_function(e,cswift_init);
                  if (iVar1 != 0) {
                    iVar1 = ENGINE_set_finish_function(e,cswift_finish);
                    if (iVar1 != 0) {
                      iVar1 = ENGINE_set_ctrl_function(e,cswift_ctrl);
                      if (iVar1 != 0) {
                        iVar1 = ENGINE_set_cmd_defns(e,(ENGINE_CMD_DEFN *)cswift_cmd_defns);
                        if (iVar1 != 0) {
                          pRVar2 = RSA_PKCS1_SSLeay();
                          cswift_rsa._4_4_ = pRVar2->rsa_pub_enc;
                          cswift_rsa._8_4_ = pRVar2->rsa_pub_dec;
                          cswift_rsa._12_4_ = pRVar2->rsa_priv_enc;
                          cswift_rsa._16_4_ = pRVar2->rsa_priv_dec;
                          pDVar3 = DH_OpenSSL();
                          cswift_dh._4_4_ = pDVar3->generate_key;
                          e_00 = (ENGINE *)pDVar3->compute_key;
                          cswift_dh._8_4_ = e_00;
                          if (CSWIFT_lib_error_code == (ENGINE *)0x0) {
                            e_00 = (ENGINE *)ERR_get_next_error_library();
                            CSWIFT_lib_error_code = e_00;
                          }
                          if (CSWIFT_error_init != 0) {
                            CSWIFT_error_init = 0;
                            ERR_load_strings((int)CSWIFT_lib_error_code,
                                             (ERR_STRING_DATA *)CSWIFT_str_functs);
                            e_00 = CSWIFT_lib_error_code;
                            ERR_load_strings((int)CSWIFT_lib_error_code,
                                             (ERR_STRING_DATA *)CSWIFT_str_reasons);
                            CSWIFT_lib_name._0_4_ = (int)CSWIFT_lib_error_code << 0x18;
                            ERR_load_strings(0,(ERR_STRING_DATA *)CSWIFT_lib_name);
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
    ENGINE_free(e);
  }
  return;
}

