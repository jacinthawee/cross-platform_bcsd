
void ENGINE_load_sureware(void)

{
  ENGINE *e;
  int iVar1;
  RSA_METHOD *pRVar2;
  DSA_METHOD *pDVar3;
  DH_METHOD *e_00;
  
  e = ENGINE_new();
  if (e != (ENGINE *)0x0) {
    iVar1 = ENGINE_set_id(e,"sureware");
    if (iVar1 != 0) {
      iVar1 = ENGINE_set_name(e,"SureWare hardware engine support");
      if (iVar1 != 0) {
        iVar1 = ENGINE_set_RSA(e,(RSA_METHOD *)surewarehk_rsa);
        if (iVar1 != 0) {
          iVar1 = ENGINE_set_DSA(e,(DSA_METHOD *)surewarehk_dsa);
          if (iVar1 != 0) {
            iVar1 = ENGINE_set_DH(e,(DH_METHOD *)surewarehk_dh);
            if (iVar1 != 0) {
              iVar1 = ENGINE_set_RAND(e,(RAND_METHOD *)surewarehk_rand);
              if (iVar1 != 0) {
                iVar1 = ENGINE_set_destroy_function(e,surewarehk_destroy);
                if (iVar1 != 0) {
                  iVar1 = ENGINE_set_init_function(e,surewarehk_init);
                  if (iVar1 != 0) {
                    iVar1 = ENGINE_set_finish_function(e,surewarehk_finish);
                    if (iVar1 != 0) {
                      iVar1 = ENGINE_set_ctrl_function(e,surewarehk_ctrl);
                      if (iVar1 != 0) {
                        iVar1 = ENGINE_set_load_privkey_function(e,surewarehk_load_privkey);
                        if (iVar1 != 0) {
                          iVar1 = ENGINE_set_load_pubkey_function(e,surewarehk_load_pubkey);
                          if (iVar1 != 0) {
                            pRVar2 = RSA_PKCS1_SSLeay();
                            if (pRVar2 != (RSA_METHOD *)0x0) {
                              surewarehk_rsa._4_4_ = pRVar2->rsa_pub_enc;
                              surewarehk_rsa._8_4_ = pRVar2->rsa_pub_dec;
                            }
                            pDVar3 = DSA_OpenSSL();
                            if (pDVar3 != (DSA_METHOD *)0x0) {
                              surewarehk_dsa._12_4_ = pDVar3->dsa_do_verify;
                            }
                            e_00 = DH_OpenSSL();
                            if (e_00 != (DH_METHOD *)0x0) {
                              surewarehk_dh._4_4_ = e_00->generate_key;
                              e_00 = (DH_METHOD *)e_00->compute_key;
                              surewarehk_dh._8_4_ = e_00;
                            }
                            if (SUREWARE_lib_error_code == (DH_METHOD *)0x0) {
                              e_00 = (DH_METHOD *)ERR_get_next_error_library();
                              SUREWARE_lib_error_code = e_00;
                            }
                            if (SUREWARE_error_init != 0) {
                              SUREWARE_error_init = 0;
                              ERR_load_strings((int)SUREWARE_lib_error_code,
                                               (ERR_STRING_DATA *)SUREWARE_str_functs);
                              e_00 = SUREWARE_lib_error_code;
                              ERR_load_strings((int)SUREWARE_lib_error_code,
                                               (ERR_STRING_DATA *)SUREWARE_str_reasons);
                              SUREWARE_lib_name._0_4_ = (int)SUREWARE_lib_error_code << 0x18;
                              ERR_load_strings(0,(ERR_STRING_DATA *)SUREWARE_lib_name);
                            }
                            ENGINE_add((ENGINE *)e_00);
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

