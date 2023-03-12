
void ibm_4758_load_privkey(ENGINE *param_1,char *param_2)

{
  size_t sVar1;
  undefined4 *arg;
  EVP_PKEY *pkey;
  RSA *r;
  BIGNUM *pBVar2;
  uint len;
  undefined4 local_c58;
  undefined4 local_c54;
  int local_c50;
  undefined auStack_c4c [4];
  undefined4 local_c48;
  undefined4 local_c44;
  undefined auStack_c40 [8];
  undefined auStack_c38 [8];
  undefined auStack_c30 [64];
  uchar auStack_bf0 [256];
  uchar auStack_af0 [256];
  char local_9f0;
  char local_9ef;
  char local_9e8;
  char local_9e7;
  undefined local_9e2;
  undefined local_9e1;
  undefined local_9de;
  undefined local_9dd;
  undefined auStack_9dc [2480];
  int local_2c;
  
  local_c58 = 0x9c4;
  local_2c = __stack_chk_guard;
  local_c54 = 0x9c4;
  local_c48 = 0;
  local_c44 = 0;
  sVar1 = strlen(param_2);
  if (sVar1 < 0x41) {
    memset(auStack_c30,0x20,0x40);
    __memcpy_chk(auStack_c30,param_2,sVar1,0x40);
    arg = (undefined4 *)CRYPTO_malloc(0x9c8,"e_4758cca.c",0x1ad);
    if (arg == (undefined4 *)0x0) {
      if (CCA4758_lib_error_code == 0) {
        CCA4758_lib_error_code = ERR_get_next_error_library();
      }
      ERR_put_error(CCA4758_lib_error_code,0x67,0x41,"e_4758cca.c",0x1af);
      pkey = (EVP_PKEY *)0x0;
    }
    else {
      (*keyRecordRead)(&local_c50,auStack_c4c,&local_c48,auStack_c40,&local_c44,auStack_c38,
                       auStack_c30,&local_c54,arg + 1);
      if (local_c50 == 0) {
        (*publicKeyExtract)(&local_c50,auStack_c4c,&local_c48,auStack_c40,&local_c44,auStack_c38,
                            &local_c54,arg + 1,&local_c58,&local_9f0);
        if (local_c50 == 0) {
          if ((((local_9f0 == '\x1e') && (local_9ef == '\0')) && (local_9e8 == '\x04')) &&
             (local_9e7 == '\0')) {
            len = (uint)CONCAT11(local_9e2,local_9e1);
            __memcpy_chk(auStack_af0,auStack_9dc,len,0x100);
            __memcpy_chk(auStack_bf0,auStack_9dc + len,(uint)CONCAT11(local_9de,local_9dd),0x100);
            *arg = local_c54;
            r = RSA_new_method(param_1);
            RSA_set_ex_data(r,hndidx,arg);
            pBVar2 = BN_bin2bn(auStack_af0,len,(BIGNUM *)0x0);
            r->e = pBVar2;
            pBVar2 = BN_bin2bn(auStack_bf0,(uint)CONCAT11(local_9de,local_9dd),(BIGNUM *)0x0);
            r->flags = r->flags | 0x20;
            r->n = pBVar2;
            pkey = EVP_PKEY_new();
            EVP_PKEY_assign(pkey,6,r);
            goto LAB_000ed802;
          }
          if (CCA4758_lib_error_code == 0) {
            CCA4758_lib_error_code = ERR_get_next_error_library();
          }
          ERR_put_error(CCA4758_lib_error_code,0x67,0x68,"e_4758cca.c",0x1cc);
        }
        else {
          if (CCA4758_lib_error_code == 0) {
            CCA4758_lib_error_code = ERR_get_next_error_library();
          }
          ERR_put_error(CCA4758_lib_error_code,0x67,0x68,"e_4758cca.c",0x1c4);
        }
      }
      else {
        if (CCA4758_lib_error_code == 0) {
          CCA4758_lib_error_code = ERR_get_next_error_library();
        }
        ERR_put_error(CCA4758_lib_error_code,0x67,0x68,"e_4758cca.c",0x1b9);
      }
      CRYPTO_free(arg);
      pkey = (EVP_PKEY *)0x0;
    }
  }
  else {
    if (CCA4758_lib_error_code == 0) {
      CCA4758_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(CCA4758_lib_error_code,0x67,0x6b,"e_4758cca.c",0x1a6);
    pkey = (EVP_PKEY *)0x0;
  }
LAB_000ed802:
  if (local_2c == __stack_chk_guard) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(pkey);
}

