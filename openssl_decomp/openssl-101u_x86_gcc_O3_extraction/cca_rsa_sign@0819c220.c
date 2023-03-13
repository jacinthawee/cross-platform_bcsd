
uint cca_rsa_sign(int param_1,uchar *param_2,int param_3,undefined4 param_4,undefined4 *param_5,
                 RSA *param_6)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  int in_GS_OFFSET;
  int reason;
  int local_78;
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
  
  local_70 = 0;
  local_6c = 1;
  local_28 = 0x53434b50;
  local_24 = 0x312e312d;
  local_68 = 0x100;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
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
        ERR_put_error(CCA4758_lib_error_code,0x69,0x65,"e_4758cca.c",0x2f7);
        goto LAB_0819c368;
      }
      local_48.parameter = &local_50;
      local_50.type = 5;
      local_50.value.ptr = (char *)0x0;
      local_40.data = param_2;
      local_58.digest = &local_40;
      local_40.length = param_3;
      local_60 = i2d_X509_SIG(&local_58,(uchar **)0x0);
      goto LAB_0819c32c;
    }
    if (CCA4758_lib_error_code == 0) {
      CCA4758_lib_error_code = ERR_get_next_error_library();
    }
    iVar2 = 0x2f1;
    reason = 0x6d;
  }
  else {
LAB_0819c32c:
    iVar2 = RSA_size(param_6);
    if (iVar2 < local_60 + -1) {
      if (CCA4758_lib_error_code == 0) {
        CCA4758_lib_error_code = ERR_get_next_error_library();
      }
      iVar2 = 0x30a;
LAB_0819c4a3:
      reason = 0x6b;
    }
    else if (param_1 == 0x40) {
      param_2 = (uchar *)CRYPTO_malloc(iVar2 + 1,"e_4758cca.c",0x326);
      if (param_2 != (uchar *)0x0) {
LAB_0819c3af:
        local_5c = param_2;
        i2d_X509_SIG(&local_58,&local_5c);
        goto LAB_0819c3c4;
      }
      local_5c = param_2;
      if (CCA4758_lib_error_code == 0) {
        CCA4758_lib_error_code = ERR_get_next_error_library();
      }
      iVar2 = 0x328;
      reason = 0x41;
    }
    else {
      if (param_1 == 0x72) {
        if (param_3 != 0x24) {
          if (CCA4758_lib_error_code == 0) {
            CCA4758_lib_error_code = ERR_get_next_error_library();
          }
          iVar2 = 0x312;
          goto LAB_0819c4a3;
        }
        local_60 = 0x24;
LAB_0819c3c4:
        (*digitalSignatureGenerate)
                  (&local_78,&local_74,&local_70,local_30,&local_6c,&local_28,&local_64,puVar1 + 1,
                   &local_60,param_2,&local_68,&local_5c,param_4);
        if (param_1 == 4 || param_1 == 0x40) {
          OPENSSL_cleanse(param_2,iVar2 + 1);
          CRYPTO_free(param_2);
        }
        uVar3 = 0;
        *param_5 = local_68;
        if (local_78 == 0) {
          uVar3 = (uint)(local_74 == 0);
        }
        goto LAB_0819c368;
      }
      uVar3 = 0;
      if (param_1 != 4) goto LAB_0819c368;
      param_2 = (uchar *)CRYPTO_malloc(iVar2 + 1,"e_4758cca.c",0x31b);
      if (param_2 != (uchar *)0x0) goto LAB_0819c3af;
      local_5c = param_2;
      if (CCA4758_lib_error_code == 0) {
        CCA4758_lib_error_code = ERR_get_next_error_library();
      }
      iVar2 = 0x31d;
      reason = 0x41;
    }
  }
  ERR_put_error(CCA4758_lib_error_code,0x69,reason,"e_4758cca.c",iVar2);
  uVar3 = 0;
LAB_0819c368:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar3;
}

