
int do_pk8pkey(BIO *param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6,
              undefined4 param_7,code *param_8,void *param_9)

{
  undefined *puVar1;
  PKCS8_PRIV_KEY_INFO *p8inf;
  X509_SIG *p8;
  int iVar2;
  char acStack_42c [1024];
  int local_2c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  p8inf = (PKCS8_PRIV_KEY_INFO *)(*(code *)PTR_EVP_PKEY2PKCS8_006a9fb8)(param_2);
  if (p8inf == (PKCS8_PRIV_KEY_INFO *)0x0) {
    (*(code *)PTR_ERR_put_error_006a9030)(9,0x7e,0x73,"pem_pk8.c",0x7a);
    iVar2 = 0;
  }
  else if ((param_5 == 0) && (param_4 == -1)) {
    if (param_3 == 0) {
      iVar2 = PEM_ASN1_write_bio(PTR_i2d_PKCS8_PRIV_KEY_INFO_006a9fc0,"PRIVATE KEY",param_1,p8inf,
                                 (EVP_CIPHER *)0x0,(uchar *)0x0,0,(undefined1 *)0x0,(void *)0x0);
    }
    else {
      iVar2 = i2d_PKCS8_PRIV_KEY_INFO_bio(param_1,p8inf);
    }
    PKCS8_PRIV_KEY_INFO_free(p8inf);
  }
  else {
    if (param_6 == 0) {
      if (param_8 == (code *)0x0) {
        iVar2 = PEM_def_callback(acStack_42c,0x400,1,param_9);
      }
      else {
        iVar2 = (*param_8)(acStack_42c,0x400,1,param_9);
      }
      if (iVar2 < 1) {
        (*(code *)PTR_ERR_put_error_006a9030)(9,0x7e,0x6f,"pem_pk8.c",0x82);
        PKCS8_PRIV_KEY_INFO_free(p8inf);
        iVar2 = 0;
        goto LAB_00572ac4;
      }
      p8 = (X509_SIG *)
           (*(code *)PTR_PKCS8_encrypt_006a8dac)(param_4,param_5,acStack_42c,iVar2,0,0,0,p8inf);
      (*(code *)PTR_OPENSSL_cleanse_006a8174)(acStack_42c,iVar2);
    }
    else {
      p8 = (X509_SIG *)
           (*(code *)PTR_PKCS8_encrypt_006a8dac)(param_4,param_5,param_6,param_7,0,0,0,p8inf);
    }
    PKCS8_PRIV_KEY_INFO_free(p8inf);
    if (param_3 == 0) {
      iVar2 = PEM_ASN1_write_bio(PTR_i2d_X509_SIG_006a9858,"ENCRYPTED PRIVATE KEY",param_1,p8,
                                 (EVP_CIPHER *)0x0,(uchar *)0x0,0,(undefined1 *)0x0,(void *)0x0);
    }
    else {
      iVar2 = i2d_PKCS8_bio(param_1,p8);
    }
    X509_SIG_free(p8);
  }
LAB_00572ac4:
  if (local_2c == *(int *)puVar1) {
    return iVar2;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  iVar2 = do_pk8pkey();
  return iVar2;
}

