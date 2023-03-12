
void ENGINE_load_ubsec(void)

{
  ENGINE *e;
  int iVar1;
  RSA_METHOD *pRVar2;
  DH_METHOD *pDVar3;
  ENGINE *e_00;
  
  e = ENGINE_new();
  if (e != (ENGINE *)0x0) {
    iVar1 = ENGINE_set_id(e,"ubsec");
    if (iVar1 != 0) {
      iVar1 = ENGINE_set_name(e,"UBSEC hardware engine support");
      if (iVar1 != 0) {
        iVar1 = ENGINE_set_RSA(e,(RSA_METHOD *)ubsec_rsa);
        if (iVar1 != 0) {
          iVar1 = ENGINE_set_DSA(e,(DSA_METHOD *)ubsec_dsa);
          if (iVar1 != 0) {
            iVar1 = ENGINE_set_DH(e,(DH_METHOD *)ubsec_dh);
            if (iVar1 != 0) {
              iVar1 = ENGINE_set_destroy_function(e,ubsec_destroy);
              if (iVar1 != 0) {
                iVar1 = ENGINE_set_init_function(e,ubsec_init);
                if (iVar1 != 0) {
                  iVar1 = ENGINE_set_finish_function(e,ubsec_finish);
                  if (iVar1 != 0) {
                    iVar1 = ENGINE_set_ctrl_function(e,ubsec_ctrl);
                    if (iVar1 != 0) {
                      iVar1 = ENGINE_set_cmd_defns(e,(ENGINE_CMD_DEFN *)ubsec_cmd_defns);
                      if (iVar1 != 0) {
                        pRVar2 = RSA_PKCS1_SSLeay();
                        ubsec_rsa._4_4_ = pRVar2->rsa_pub_enc;
                        ubsec_rsa._8_4_ = pRVar2->rsa_pub_dec;
                        ubsec_rsa._12_4_ = pRVar2->rsa_priv_enc;
                        ubsec_rsa._16_4_ = pRVar2->rsa_priv_dec;
                        pDVar3 = DH_OpenSSL();
                        ubsec_dh._4_4_ = pDVar3->generate_key;
                        e_00 = (ENGINE *)pDVar3->compute_key;
                        ubsec_dh._8_4_ = e_00;
                        if (UBSEC_lib_error_code == (ENGINE *)0x0) {
                          e_00 = (ENGINE *)ERR_get_next_error_library();
                          UBSEC_lib_error_code = e_00;
                        }
                        if (UBSEC_error_init != 0) {
                          UBSEC_error_init = 0;
                          ERR_load_strings((int)UBSEC_lib_error_code,
                                           (ERR_STRING_DATA *)UBSEC_str_functs);
                          e_00 = UBSEC_lib_error_code;
                          ERR_load_strings((int)UBSEC_lib_error_code,
                                           (ERR_STRING_DATA *)UBSEC_str_reasons);
                          UBSEC_lib_name._0_4_ = (int)UBSEC_lib_error_code << 0x18;
                          ERR_load_strings(0,(ERR_STRING_DATA *)UBSEC_lib_name);
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

