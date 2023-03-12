
void cca_rsa_sign(int param_1,uchar *param_2,int param_3,undefined4 param_4,undefined4 *param_5,
                 RSA *param_6)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  uint local_98;
  int local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  int local_6c;
  uchar *local_68;
  X509_SIG local_64;
  ASN1_TYPE local_5c;
  X509_ALGOR local_54;
  ASN1_OCTET_STRING local_4c;
  undefined auStack_3c [8];
  undefined4 local_34;
  undefined4 uStack_30;
  int local_2c;
  
  local_34 = *(undefined4 *)PTR_DAT_000edddc;
  uStack_30 = *(undefined4 *)(PTR_DAT_000edddc + 4);
  local_2c = __stack_chk_guard;
  local_78 = 1;
  local_7c = 0;
  local_74 = 0x100;
  puVar2 = (undefined4 *)RSA_get_ex_data(param_6,hndidx);
  local_6c = 0x24;
  local_70 = *puVar2;
  if (param_1 == 4 || param_1 == 0x40) {
    local_64.algor = &local_54;
    local_54.algorithm = OBJ_nid2obj(param_1);
    if (local_54.algorithm == (ASN1_OBJECT *)0x0) {
      if (CCA4758_lib_error_code == 0) {
        CCA4758_lib_error_code = ERR_get_next_error_library();
      }
      ERR_put_error(CCA4758_lib_error_code,0x69,0x6d,"e_4758cca.c",0x2f1);
      local_98 = 0;
      goto LAB_000edbe0;
    }
    local_98 = (local_54.algorithm)->length;
    if (local_98 == 0) {
      if (CCA4758_lib_error_code == 0) {
        CCA4758_lib_error_code = ERR_get_next_error_library();
      }
      ERR_put_error(CCA4758_lib_error_code,0x69,0x65,"e_4758cca.c",0x2f7);
      goto LAB_000edbe0;
    }
    local_54.parameter = &local_5c;
    local_5c.type = 5;
    local_64.digest = &local_4c;
    local_5c.value.ptr = (char *)0x0;
    local_4c.length = param_3;
    local_4c.data = param_2;
    local_6c = i2d_X509_SIG(&local_64,(uchar **)0x0);
  }
  iVar3 = RSA_size(param_6);
  if (iVar3 < local_6c + -1) {
    if (CCA4758_lib_error_code == 0) {
      CCA4758_lib_error_code = ERR_get_next_error_library();
    }
    iVar3 = 0x30a;
LAB_000edccc:
    ERR_put_error(CCA4758_lib_error_code,0x69,0x6b,"e_4758cca.c",iVar3);
    local_98 = 0;
    goto LAB_000edbe0;
  }
  if (param_1 == 0x40) {
    param_2 = (uchar *)CRYPTO_malloc(iVar3 + 1,"e_4758cca.c",0x326);
    if (param_2 == (uchar *)0x0) {
      local_68 = param_2;
      if (CCA4758_lib_error_code == 0) {
        CCA4758_lib_error_code = ERR_get_next_error_library();
      }
      iVar3 = 0x328;
LAB_000edd48:
      local_98 = 0;
      ERR_put_error(CCA4758_lib_error_code,0x69,0x41,"e_4758cca.c",iVar3);
      goto LAB_000edbe0;
    }
LAB_000edc0e:
    local_68 = param_2;
    i2d_X509_SIG(&local_64,&local_68);
    iVar1 = local_6c;
LAB_000edc18:
    local_6c = iVar1;
    (*digitalSignatureGenerate)
              (&local_84,&local_80,&local_7c,auStack_3c,&local_78,&local_34,&local_70,puVar2 + 1,
               &local_6c,param_2,&local_74,&local_68,param_4);
    if (param_1 == 4 || param_1 == 0x40) {
      OPENSSL_cleanse(param_2,iVar3 + 1);
      CRYPTO_free(param_2);
    }
    *param_5 = local_74;
    if (local_84 == 0) {
      local_98 = count_leading_zeroes(local_80);
      local_98 = local_98 >> 5;
      goto LAB_000edbe0;
    }
  }
  else {
    if (param_1 == 0x72) {
      iVar1 = param_3;
      if (param_3 != 0x24) {
        if (CCA4758_lib_error_code == 0) {
          CCA4758_lib_error_code = ERR_get_next_error_library();
        }
        iVar3 = 0x312;
        goto LAB_000edccc;
      }
      goto LAB_000edc18;
    }
    if (param_1 == 4) {
      param_2 = (uchar *)CRYPTO_malloc(iVar3 + 1,"e_4758cca.c",0x31b);
      if (param_2 != (uchar *)0x0) goto LAB_000edc0e;
      local_68 = param_2;
      if (CCA4758_lib_error_code == 0) {
        CCA4758_lib_error_code = ERR_get_next_error_library();
      }
      iVar3 = 0x31d;
      goto LAB_000edd48;
    }
  }
  local_98 = 0;
LAB_000edbe0:
  if (local_2c == __stack_chk_guard) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(local_98);
}

