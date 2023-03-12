
void ibm_4758_load_pubkey(ENGINE *param_1,char *param_2)

{
  size_t sVar1;
  undefined4 *arg;
  EVP_PKEY *pkey;
  RSA *r;
  BIGNUM *pBVar2;
  uint len;
  uint len_00;
  undefined4 local_488;
  int local_484;
  undefined auStack_480 [4];
  undefined4 local_47c;
  undefined4 local_478;
  undefined auStack_474 [8];
  undefined auStack_46c [8];
  undefined auStack_464 [64];
  uchar auStack_424 [512];
  uchar auStack_224 [512];
  int local_24;
  
  local_488 = 0x9c4;
  local_24 = __stack_chk_guard;
  local_47c = 0;
  local_478 = 0;
  sVar1 = strlen(param_2);
  if (sVar1 < 0x41) {
    memset(auStack_464,0x20,0x40);
    __memcpy_chk(auStack_464,param_2,sVar1,0x40);
    arg = (undefined4 *)CRYPTO_malloc(0x9c8,"e_4758cca.c",0x201);
    if (arg == (undefined4 *)0x0) {
      if (CCA4758_lib_error_code == 0) {
        CCA4758_lib_error_code = ERR_get_next_error_library();
      }
      ERR_put_error(CCA4758_lib_error_code,0x68,0x41,"e_4758cca.c",0x203);
      pkey = (EVP_PKEY *)0x0;
    }
    else {
      (*keyRecordRead)(&local_484,auStack_480,&local_47c,auStack_474,&local_478,auStack_46c,
                       auStack_464,&local_488,arg + 1);
      if (local_484 == 0) {
        if ((((*(char *)(arg + 1) == '\x1e') && (*(char *)((int)arg + 5) == '\0')) &&
            (*(char *)(arg + 3) == '\x04')) && (*(char *)((int)arg + 0xd) == '\0')) {
          len = (uint)CONCAT11(*(undefined *)((int)arg + 0x12),*(undefined *)((int)arg + 0x13));
          len_00 = (uint)CONCAT11(*(undefined *)((int)arg + 0x16),*(undefined *)((int)arg + 0x17));
          __memcpy_chk(auStack_224,arg + 6,len,0x200);
          __memcpy_chk(auStack_424,(int)(arg + 6) + len,len_00,0x200);
          *arg = local_488;
          r = RSA_new_method(param_1);
          RSA_set_ex_data(r,hndidx,arg);
          pBVar2 = BN_bin2bn(auStack_224,len,(BIGNUM *)0x0);
          r->e = pBVar2;
          pBVar2 = BN_bin2bn(auStack_424,len_00,(BIGNUM *)0x0);
          r->flags = r->flags | 0x20;
          r->n = pBVar2;
          pkey = EVP_PKEY_new();
          EVP_PKEY_assign(pkey,6,r);
          goto LAB_000ed60e;
        }
        if (CCA4758_lib_error_code == 0) {
          CCA4758_lib_error_code = ERR_get_next_error_library();
        }
        ERR_put_error(CCA4758_lib_error_code,0x68,0x69,"e_4758cca.c",0x214);
      }
      else {
        if (CCA4758_lib_error_code == 0) {
          CCA4758_lib_error_code = ERR_get_next_error_library();
        }
        ERR_put_error(CCA4758_lib_error_code,0x68,0x41,"e_4758cca.c",0x20c);
      }
      CRYPTO_free(arg);
      pkey = (EVP_PKEY *)0x0;
    }
  }
  else {
    if (CCA4758_lib_error_code == 0) {
      CCA4758_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(CCA4758_lib_error_code,0x68,0x6b,"e_4758cca.c",0x1fa);
    pkey = (EVP_PKEY *)0x0;
  }
LAB_000ed60e:
  if (local_24 == __stack_chk_guard) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(pkey);
}

