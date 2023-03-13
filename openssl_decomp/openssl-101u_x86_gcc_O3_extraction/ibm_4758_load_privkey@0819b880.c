
EVP_PKEY * ibm_4758_load_privkey(ENGINE *param_1,char *param_2)

{
  size_t sVar1;
  undefined4 *arg;
  EVP_PKEY *pkey;
  RSA *r;
  BIGNUM *pBVar2;
  uint len;
  uint len_00;
  int in_GS_OFFSET;
  int iVar3;
  int line;
  undefined4 local_c4c;
  undefined4 local_c48;
  int local_c44;
  undefined local_c40 [4];
  undefined4 local_c3c;
  undefined4 local_c38;
  undefined local_c34 [8];
  undefined local_c2c [8];
  undefined4 local_c24;
  undefined4 local_c20;
  undefined4 local_c1c;
  undefined4 local_c18;
  undefined4 local_c14;
  undefined4 local_c10;
  undefined4 local_c0c;
  undefined4 local_c08;
  undefined4 local_c04;
  undefined4 local_c00;
  undefined4 local_bfc;
  undefined4 local_bf8;
  undefined4 local_bf4;
  undefined4 local_bf0;
  undefined4 local_bec;
  undefined4 local_be8;
  uchar local_be4 [256];
  uchar local_ae4 [256];
  char local_9e4;
  char local_9e3;
  char local_9dc;
  char local_9db;
  ushort local_9d6;
  ushort local_9d2;
  undefined local_9d0 [2480];
  int local_20;
  
  local_c4c = 0x9c4;
  local_c48 = 0x9c4;
  local_c3c = 0;
  local_c38 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  sVar1 = strlen(param_2);
  if (sVar1 < 0x41) {
    local_c24 = 0x20202020;
    local_c20 = 0x20202020;
    local_c1c = 0x20202020;
    local_c18 = 0x20202020;
    local_c14 = 0x20202020;
    local_c10 = 0x20202020;
    local_c0c = 0x20202020;
    local_c08 = 0x20202020;
    local_c04 = 0x20202020;
    local_c00 = 0x20202020;
    local_bfc = 0x20202020;
    local_bf8 = 0x20202020;
    local_bf4 = 0x20202020;
    local_bf0 = 0x20202020;
    local_bec = 0x20202020;
    local_be8 = 0x20202020;
    __memcpy_chk(&local_c24,param_2,sVar1,0x40);
    arg = (undefined4 *)CRYPTO_malloc(0x9c8,"e_4758cca.c",0x1ad);
    if (arg != (undefined4 *)0x0) {
      (*keyRecordRead)(&local_c44,local_c40,&local_c3c,local_c34,&local_c38,local_c2c,&local_c24,
                       &local_c48,arg + 1);
      if (local_c44 == 0) {
        (*publicKeyExtract)(&local_c44,local_c40,&local_c3c,local_c34,&local_c38,local_c2c,
                            &local_c48,arg + 1,&local_c4c,&local_9e4);
        if (local_c44 == 0) {
          if ((((local_9e4 == '\x1e') && (local_9e3 == '\0')) && (local_9dc == '\x04')) &&
             (local_9db == '\0')) {
            len_00 = (uint)(ushort)(local_9d6 << 8 | local_9d6 >> 8);
            __memcpy_chk(local_ae4,local_9d0,len_00,0x100);
            len = (uint)(ushort)(local_9d2 << 8 | local_9d2 >> 8);
            __memcpy_chk(local_be4,local_9d0 + len_00,len,0x100);
            *arg = local_c48;
            r = RSA_new_method(param_1);
            RSA_set_ex_data(r,hndidx,arg);
            pBVar2 = BN_bin2bn(local_ae4,len_00,(BIGNUM *)0x0);
            r->e = pBVar2;
            pBVar2 = BN_bin2bn(local_be4,len,(BIGNUM *)0x0);
            r->flags = r->flags | 0x20;
            r->n = pBVar2;
            pkey = EVP_PKEY_new();
            EVP_PKEY_assign(pkey,6,r);
            goto LAB_0819ba16;
          }
          if (CCA4758_lib_error_code == 0) {
            CCA4758_lib_error_code = ERR_get_next_error_library();
          }
          iVar3 = 0x1cc;
        }
        else {
          if (CCA4758_lib_error_code == 0) {
            CCA4758_lib_error_code = ERR_get_next_error_library();
          }
          iVar3 = 0x1c4;
        }
      }
      else {
        if (CCA4758_lib_error_code == 0) {
          CCA4758_lib_error_code = ERR_get_next_error_library();
        }
        iVar3 = 0x1b9;
      }
      ERR_put_error(CCA4758_lib_error_code,0x67,0x68,"e_4758cca.c",iVar3);
      CRYPTO_free(arg);
      pkey = (EVP_PKEY *)0x0;
      goto LAB_0819ba16;
    }
    if (CCA4758_lib_error_code == 0) {
      CCA4758_lib_error_code = ERR_get_next_error_library();
    }
    line = 0x1af;
    iVar3 = 0x41;
  }
  else {
    if (CCA4758_lib_error_code == 0) {
      CCA4758_lib_error_code = ERR_get_next_error_library();
    }
    line = 0x1a6;
    iVar3 = 0x6b;
  }
  ERR_put_error(CCA4758_lib_error_code,0x67,iVar3,"e_4758cca.c",line);
  pkey = (EVP_PKEY *)0x0;
LAB_0819ba16:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return pkey;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

