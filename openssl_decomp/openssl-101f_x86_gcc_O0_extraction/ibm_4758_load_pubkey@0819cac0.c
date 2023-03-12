
EVP_PKEY * ibm_4758_load_pubkey(ENGINE *param_1,char *param_2)

{
  size_t sVar1;
  undefined4 *arg;
  EVP_PKEY *pkey;
  RSA *r;
  BIGNUM *pBVar2;
  uint len;
  uint len_00;
  int in_GS_OFFSET;
  int reason;
  int line;
  undefined4 local_484;
  int local_480;
  undefined local_47c [4];
  undefined4 local_478;
  undefined4 local_474;
  undefined local_470 [8];
  undefined local_468 [8];
  undefined4 local_460;
  undefined4 local_45c;
  undefined4 local_458;
  undefined4 local_454;
  undefined4 local_450;
  undefined4 local_44c;
  undefined4 local_448;
  undefined4 local_444;
  undefined4 local_440;
  undefined4 local_43c;
  undefined4 local_438;
  undefined4 local_434;
  undefined4 local_430;
  undefined4 local_42c;
  undefined4 local_428;
  undefined4 local_424;
  uchar local_420 [512];
  uchar local_220 [512];
  int local_20;
  
  local_484 = 0x9c4;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_478 = 0;
  local_474 = 0;
  sVar1 = strlen(param_2);
  if (sVar1 < 0x41) {
    local_460 = 0x20202020;
    local_45c = 0x20202020;
    local_458 = 0x20202020;
    local_454 = 0x20202020;
    local_450 = 0x20202020;
    local_44c = 0x20202020;
    local_448 = 0x20202020;
    local_444 = 0x20202020;
    local_440 = 0x20202020;
    local_43c = 0x20202020;
    local_438 = 0x20202020;
    local_434 = 0x20202020;
    local_430 = 0x20202020;
    local_42c = 0x20202020;
    local_428 = 0x20202020;
    local_424 = 0x20202020;
    __memcpy_chk(&local_460,param_2,sVar1,0x40);
    arg = (undefined4 *)CRYPTO_malloc(0x9c8,"e_4758cca.c",0x207);
    if (arg != (undefined4 *)0x0) {
      (*keyRecordRead)(&local_480,local_47c,&local_478,local_470,&local_474,local_468,&local_460,
                       &local_484,arg + 1);
      if (local_480 == 0) {
        if ((((*(char *)(arg + 1) == '\x1e') && (*(char *)((int)arg + 5) == '\0')) &&
            (*(char *)(arg + 3) == '\x04')) && (*(char *)((int)arg + 0xd) == '\0')) {
          len_00 = (uint)(ushort)(*(ushort *)((int)arg + 0x12) << 8 |
                                 *(ushort *)((int)arg + 0x12) >> 8);
          len = (uint)(ushort)(*(ushort *)((int)arg + 0x16) << 8 | *(ushort *)((int)arg + 0x16) >> 8
                              );
          __memcpy_chk(local_220,arg + 6,len_00,0x200);
          __memcpy_chk(local_420,(int)(arg + 6) + len_00,len,0x200);
          *arg = local_484;
          r = RSA_new_method(param_1);
          RSA_set_ex_data(r,hndidx,arg);
          pBVar2 = BN_bin2bn(local_220,len_00,(BIGNUM *)0x0);
          r->e = pBVar2;
          pBVar2 = BN_bin2bn(local_420,len,(BIGNUM *)0x0);
          r->flags = r->flags | 0x20;
          r->n = pBVar2;
          pkey = EVP_PKEY_new();
          EVP_PKEY_assign(pkey,6,r);
          goto LAB_0819cc3e;
        }
        if (CCA4758_lib_error_code == 0) {
          CCA4758_lib_error_code = ERR_get_next_error_library();
        }
        ERR_put_error(CCA4758_lib_error_code,0x68,0x69,"e_4758cca.c",0x21e);
      }
      else {
        if (CCA4758_lib_error_code == 0) {
          CCA4758_lib_error_code = ERR_get_next_error_library();
        }
        ERR_put_error(CCA4758_lib_error_code,0x68,0x41,"e_4758cca.c",0x216);
      }
      CRYPTO_free(arg);
      pkey = (EVP_PKEY *)0x0;
      goto LAB_0819cc3e;
    }
    if (CCA4758_lib_error_code == 0) {
      CCA4758_lib_error_code = ERR_get_next_error_library();
    }
    line = 0x20b;
    reason = 0x41;
  }
  else {
    if (CCA4758_lib_error_code == 0) {
      CCA4758_lib_error_code = ERR_get_next_error_library();
    }
    line = 0x200;
    reason = 0x6b;
  }
  ERR_put_error(CCA4758_lib_error_code,0x68,reason,"e_4758cca.c",line);
  pkey = (EVP_PKEY *)0x0;
LAB_0819cc3e:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return pkey;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

