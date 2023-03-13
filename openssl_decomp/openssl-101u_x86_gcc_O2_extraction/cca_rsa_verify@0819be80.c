
uint cca_rsa_verify(int param_1,uchar *param_2,int param_3,undefined4 param_4,undefined4 param_5,
                   RSA *param_6)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  int in_GS_OFFSET;
  int reason;
  int local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  int local_60;
  uchar *local_5c;
  X509_SIG local_58;
  ASN1_TYPE local_50;
  X509_ALGOR local_48;
  ASN1_OCTET_STRING local_40;
  undefined local_30 [8];
  undefined4 local_28;
  undefined4 local_24;
  int local_20;
  
  local_6c = 0;
  local_68 = 1;
  local_28 = 0x53434b50;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_24 = 0x312e312d;
  local_70 = param_5;
  puVar1 = (undefined4 *)RSA_get_ex_data(param_6,hndidx);
  local_60 = 0x24;
  local_64 = *puVar1;
  if (param_1 == 4 || param_1 == 0x40) {
    local_58.algor = &local_48;
    local_48.algorithm = OBJ_nid2obj(param_1);
    if (local_48.algorithm != (ASN1_OBJECT *)0x0) {
      uVar3 = (local_48.algorithm)->length;
      if (uVar3 == 0) {
        if (CCA4758_lib_error_code == 0) {
          CCA4758_lib_error_code = ERR_get_next_error_library();
        }
        ERR_put_error(CCA4758_lib_error_code,0x6a,0x65,"e_4758cca.c",0x286);
        goto LAB_0819bfc0;
      }
      local_48.parameter = &local_50;
      local_50.type = 5;
      local_50.value.ptr = (char *)0x0;
      local_40.data = param_2;
      local_58.digest = &local_40;
      local_40.length = param_3;
      local_60 = i2d_X509_SIG(&local_58,(uchar **)0x0);
      goto LAB_0819bf84;
    }
    if (CCA4758_lib_error_code == 0) {
      CCA4758_lib_error_code = ERR_get_next_error_library();
    }
    iVar2 = 0x280;
    reason = 0x6d;
  }
  else {
LAB_0819bf84:
    iVar2 = RSA_size(param_6);
    if (iVar2 < local_60 + -1) {
      if (CCA4758_lib_error_code == 0) {
        CCA4758_lib_error_code = ERR_get_next_error_library();
      }
      iVar2 = 0x299;
LAB_0819c0e3:
      reason = 0x6b;
    }
    else if (param_1 == 0x40) {
      param_2 = (uchar *)CRYPTO_malloc(iVar2 + 1,"e_4758cca.c",0x2b7);
      if (param_2 != (uchar *)0x0) {
LAB_0819c007:
        local_5c = param_2;
        i2d_X509_SIG(&local_58,&local_5c);
        goto LAB_0819c01c;
      }
      local_5c = param_2;
      if (CCA4758_lib_error_code == 0) {
        CCA4758_lib_error_code = ERR_get_next_error_library();
      }
      iVar2 = 0x2b9;
      reason = 0x41;
    }
    else {
      if (param_1 == 0x72) {
        if (param_3 != 0x24) {
          if (CCA4758_lib_error_code == 0) {
            CCA4758_lib_error_code = ERR_get_next_error_library();
          }
          iVar2 = 0x2a1;
          goto LAB_0819c0e3;
        }
        local_60 = 0x24;
LAB_0819c01c:
        (*digitalSignatureVerify)
                  (&local_74,&local_5c,&local_6c,local_30,&local_68,&local_28,&local_64,puVar1 + 1,
                   &local_60,param_2,&local_70,param_4);
        if (param_1 == 4 || param_1 == 0x40) {
          OPENSSL_cleanse(param_2,iVar2 + 1);
          CRYPTO_free(param_2);
        }
        uVar3 = 0;
        if (local_74 == 0) {
          uVar3 = (uint)(local_5c == (uchar *)0x0);
        }
        goto LAB_0819bfc0;
      }
      uVar3 = 0;
      if (param_1 != 4) goto LAB_0819bfc0;
      param_2 = (uchar *)CRYPTO_malloc(iVar2 + 1,"e_4758cca.c",0x2ab);
      if (param_2 != (uchar *)0x0) goto LAB_0819c007;
      local_5c = param_2;
      if (CCA4758_lib_error_code == 0) {
        CCA4758_lib_error_code = ERR_get_next_error_library();
      }
      iVar2 = 0x2ad;
      reason = 0x41;
    }
  }
  ERR_put_error(CCA4758_lib_error_code,0x6a,reason,"e_4758cca.c",iVar2);
  uVar3 = 0;
LAB_0819bfc0:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar3;
}

