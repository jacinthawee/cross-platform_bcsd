
void ENGINE_load_aep(void)

{
  ENGINE *e;
  int iVar1;
  RSA_METHOD *pRVar2;
  DSA_METHOD *pDVar3;
  DH_METHOD *pDVar4;
  ENGINE *e_00;
  char **ppcVar5;
  byte bVar6;
  
  bVar6 = 0;
  e = ENGINE_new();
  if (e != (ENGINE *)0x0) {
    iVar1 = ENGINE_set_id(e,"aep");
    if (iVar1 != 0) {
      iVar1 = ENGINE_set_name(e,"Aep hardware engine support");
      if (iVar1 != 0) {
        iVar1 = ENGINE_set_RSA(e,(RSA_METHOD *)aep_rsa);
        if (iVar1 != 0) {
          iVar1 = ENGINE_set_DSA(e,(DSA_METHOD *)aep_dsa);
          if (iVar1 != 0) {
            iVar1 = ENGINE_set_DH(e,(DH_METHOD *)aep_dh);
            if (iVar1 != 0) {
              iVar1 = ENGINE_set_init_function(e,aep_init);
              if (iVar1 != 0) {
                iVar1 = ENGINE_set_destroy_function(e,aep_destroy);
                if (iVar1 != 0) {
                  iVar1 = ENGINE_set_finish_function(e,aep_finish);
                  if (iVar1 != 0) {
                    iVar1 = ENGINE_set_ctrl_function(e,aep_ctrl);
                    if (iVar1 != 0) {
                      iVar1 = ENGINE_set_cmd_defns(e,(ENGINE_CMD_DEFN *)aep_cmd_defns);
                      if (iVar1 != 0) {
                        pRVar2 = RSA_PKCS1_SSLeay();
                        aep_rsa._4_4_ = pRVar2->rsa_pub_enc;
                        aep_rsa._8_4_ = pRVar2->rsa_pub_dec;
                        aep_rsa._12_4_ = pRVar2->rsa_priv_enc;
                        aep_rsa._16_4_ = pRVar2->rsa_priv_dec;
                        pDVar3 = DSA_OpenSSL();
                        aep_dsa._4_4_ = pDVar3->dsa_do_sign;
                        aep_dsa._8_4_ = pDVar3->dsa_sign_setup;
                        aep_dsa._12_4_ = pDVar3->dsa_do_verify;
                        pDVar3 = DSA_get_default_method();
                        ppcVar5 = (char **)aep_dsa;
                        for (iVar1 = 0xc; iVar1 != 0; iVar1 = iVar1 + -1) {
                          *ppcVar5 = pDVar3->name;
                          pDVar3 = (DSA_METHOD *)((int)pDVar3 + (uint)bVar6 * -8 + 4);
                          ppcVar5 = ppcVar5 + (uint)bVar6 * -2 + 1;
                        }
                        aep_dsa._16_4_ = aep_dsa_mod_exp;
                        aep_dsa._20_4_ = aep_mod_exp_dsa;
                        pDVar4 = DH_OpenSSL();
                        aep_dh._4_4_ = pDVar4->generate_key;
                        aep_dh._8_4_ = pDVar4->compute_key;
                        e_00 = (ENGINE *)pDVar4->bn_mod_exp;
                        aep_dh._12_4_ = e_00;
                        if (AEPHK_lib_error_code == (ENGINE *)0x0) {
                          e_00 = (ENGINE *)ERR_get_next_error_library();
                          AEPHK_lib_error_code = e_00;
                        }
                        if (AEPHK_error_init != 0) {
                          AEPHK_error_init = 0;
                          ERR_load_strings((int)AEPHK_lib_error_code,
                                           (ERR_STRING_DATA *)AEPHK_str_functs);
                          ERR_load_strings((int)AEPHK_lib_error_code,
                                           (ERR_STRING_DATA *)AEPHK_str_reasons);
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

