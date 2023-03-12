
void cca_rsa_verify(int param_1,uchar *param_2,int param_3,undefined4 param_4,undefined4 param_5,
                   RSA *param_6)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  uint local_8c;
  int local_80;
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
  
  local_34 = *(undefined4 *)PTR_DAT_000efeec;
  uStack_30 = *(undefined4 *)(PTR_DAT_000efeec + 4);
  puVar4 = &local_34;
  local_7c = param_5;
  local_74 = 1;
  local_2c = __TMC_END__;
  local_78 = 0;
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
      ERR_put_error(CCA4758_lib_error_code,0x6a,0x6d,"e_4758cca.c",0x28b);
      local_8c = 0;
      goto LAB_000efcfc;
    }
    local_8c = (local_54.algorithm)->length;
    if (local_8c == 0) {
      if (CCA4758_lib_error_code == 0) {
        CCA4758_lib_error_code = ERR_get_next_error_library();
      }
      ERR_put_error(CCA4758_lib_error_code,0x6a,0x65,"e_4758cca.c",0x292);
      goto LAB_000efcfc;
    }
    local_54.parameter = &local_5c;
    local_64.digest = &local_4c;
    local_5c.value.ptr = (char *)0x0;
    local_5c.type = 5;
    local_4c.length = param_3;
    local_4c.data = param_2;
    local_6c = i2d_X509_SIG(&local_64,(uchar **)0x0);
  }
  iVar3 = RSA_size(param_6);
  if (iVar3 < local_6c + -1) {
    if (CCA4758_lib_error_code == 0) {
      CCA4758_lib_error_code = ERR_get_next_error_library();
    }
    iVar3 = 0x2a6;
LAB_000efdde:
    ERR_put_error(CCA4758_lib_error_code,0x6a,0x6b,"e_4758cca.c",iVar3);
    local_8c = 0;
    goto LAB_000efcfc;
  }
  if (param_1 == 0x40) {
    param_2 = (uchar *)CRYPTO_malloc(iVar3 + 1,"e_4758cca.c",0x2ca);
    if (param_2 == (uchar *)0x0) {
      local_68 = param_2;
      if (CCA4758_lib_error_code == 0) {
        CCA4758_lib_error_code = ERR_get_next_error_library();
      }
      iVar3 = 0x2ce;
LAB_000efe5a:
      local_8c = 0;
      ERR_put_error(CCA4758_lib_error_code,0x6a,0x41,"e_4758cca.c",iVar3);
      goto LAB_000efcfc;
    }
LAB_000efd2a:
    local_68 = param_2;
    i2d_X509_SIG(&local_64,&local_68);
    iVar1 = local_6c;
LAB_000efd34:
    local_6c = iVar1;
    (*digitalSignatureVerify)
              (&local_80,&local_68,&local_78,auStack_3c,&local_74,&local_34,&local_70,puVar2 + 1,
               &local_6c,param_2,&local_7c,param_4,puVar4);
    if (param_1 == 4 || param_1 == 0x40) {
      OPENSSL_cleanse(param_2,iVar3 + 1);
      CRYPTO_free(param_2);
    }
    if (local_80 == 0) {
      local_8c = count_leading_zeroes(local_68);
      local_8c = local_8c >> 5;
      goto LAB_000efcfc;
    }
  }
  else {
    if (param_1 == 0x72) {
      iVar1 = param_3;
      if (param_3 != 0x24) {
        if (CCA4758_lib_error_code == 0) {
          CCA4758_lib_error_code = ERR_get_next_error_library();
        }
        iVar3 = 0x2b0;
        goto LAB_000efdde;
      }
      goto LAB_000efd34;
    }
    if (param_1 == 4) {
      param_2 = (uchar *)CRYPTO_malloc(iVar3 + 1,"e_4758cca.c",699);
      if (param_2 != (uchar *)0x0) goto LAB_000efd2a;
      local_68 = param_2;
      if (CCA4758_lib_error_code == 0) {
        CCA4758_lib_error_code = ERR_get_next_error_library();
      }
      iVar3 = 0x2bf;
      goto LAB_000efe5a;
    }
  }
  local_8c = 0;
LAB_000efcfc:
  if (local_2c == __TMC_END__) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(local_8c);
}

