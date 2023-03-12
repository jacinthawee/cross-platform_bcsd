
int PKCS7_verify(PKCS7 *p7,stack_st_X509 *certs,X509_STORE *store,BIO *indata,BIO *out,int flags)

{
  int iVar1;
  long lVar2;
  _STACK *p_Var3;
  BIO *pBVar4;
  X509 *pXVar5;
  char *pcVar6;
  BIO *b;
  PKCS7_SIGNER_INFO *si;
  BIO_METHOD *type;
  BIO *pBVar7;
  uint uVar8;
  BIO *pBVar9;
  BIO *b_00;
  void *local_10b8;
  X509_STORE_CTX XStack_10b4;
  undefined auStack_102c [4096];
  int local_2c;
  
  local_2c = __TMC_END__;
  if (p7 == (PKCS7 *)0x0) {
    ERR_put_error(0x21,0x75,0x8f,"pk7_smime.c",0x118);
    pBVar4 = (BIO *)p7;
    goto LAB_000de640;
  }
  iVar1 = OBJ_obj2nid(p7->type);
  if (iVar1 != 0x16) {
    ERR_put_error(0x21,0x75,0x71,"pk7_smime.c",0x11d);
    pBVar4 = (BIO *)0x0;
    goto LAB_000de640;
  }
  lVar2 = PKCS7_ctrl(p7,2,0,(char *)0x0);
  if ((lVar2 != 0) && (indata == (BIO *)0x0)) {
    ERR_put_error(0x21,0x75,0x7a,"pk7_smime.c",0x123);
    pBVar4 = indata;
    goto LAB_000de640;
  }
  p_Var3 = (_STACK *)PKCS7_get_signer_info(p7);
  if ((p_Var3 == (_STACK *)0x0) || (iVar1 = sk_num(p_Var3), iVar1 == 0)) {
    ERR_put_error(0x21,0x75,0x7b,"pk7_smime.c",0x135);
    pBVar4 = (BIO *)0x0;
    goto LAB_000de640;
  }
  pBVar4 = (BIO *)PKCS7_get0_signers(p7,certs,flags);
  if (pBVar4 == (BIO *)0x0) goto LAB_000de640;
  pBVar7 = (BIO *)(flags & 0x20);
  if (pBVar7 == (BIO *)0x0) {
    if (flags << 0x12 < 0) {
      pBVar9 = pBVar7;
      if ((flags & 8U) == 0) {
        for (; iVar1 = sk_num((_STACK *)pBVar4), (int)pBVar9 < iVar1;
            pBVar9 = (BIO *)((int)&pBVar9->method + 1)) {
          pXVar5 = (X509 *)sk_value((_STACK *)pBVar4,(int)pBVar9);
          iVar1 = X509_STORE_CTX_init(&XStack_10b4,store,pXVar5,((p7->d).sign)->cert);
          if (iVar1 == 0) goto LAB_000dea22;
          X509_STORE_CTX_set_default(&XStack_10b4,"smime_sign");
          iVar1 = X509_verify_cert(&XStack_10b4);
          if (iVar1 < 1) goto LAB_000de724;
          X509_STORE_CTX_cleanup(&XStack_10b4);
        }
      }
      else {
        for (; iVar1 = sk_num((_STACK *)pBVar4), (int)pBVar9 < iVar1;
            pBVar9 = (BIO *)((int)&pBVar9->method + 1)) {
          pXVar5 = (X509 *)sk_value((_STACK *)pBVar4,(int)pBVar9);
          iVar1 = X509_STORE_CTX_init(&XStack_10b4,store,pXVar5,(stack_st_X509 *)0x0);
          if (iVar1 == 0) goto LAB_000dea42;
          iVar1 = X509_verify_cert(&XStack_10b4);
          if (iVar1 < 1) goto LAB_000de724;
          X509_STORE_CTX_cleanup(&XStack_10b4);
        }
      }
    }
    else {
      pBVar9 = pBVar7;
      if ((flags & 8U) == 0) {
        for (; iVar1 = sk_num((_STACK *)pBVar4), (int)pBVar9 < iVar1;
            pBVar9 = (BIO *)((int)&pBVar9->method + 1)) {
          pXVar5 = (X509 *)sk_value((_STACK *)pBVar4,(int)pBVar9);
          iVar1 = X509_STORE_CTX_init(&XStack_10b4,store,pXVar5,((p7->d).sign)->cert);
          if (iVar1 == 0) goto LAB_000dea22;
          X509_STORE_CTX_set_default(&XStack_10b4,"smime_sign");
          X509_STORE_CTX_set0_crls(&XStack_10b4,((p7->d).sign)->crl);
          iVar1 = X509_verify_cert(&XStack_10b4);
          if (iVar1 < 1) goto LAB_000de724;
          X509_STORE_CTX_cleanup(&XStack_10b4);
        }
      }
      else {
        for (; iVar1 = sk_num((_STACK *)pBVar4), (int)pBVar9 < iVar1;
            pBVar9 = (BIO *)((int)&pBVar9->method + 1)) {
          pXVar5 = (X509 *)sk_value((_STACK *)pBVar4,(int)pBVar9);
          iVar1 = X509_STORE_CTX_init(&XStack_10b4,store,pXVar5,(stack_st_X509 *)0x0);
          if (iVar1 == 0) goto LAB_000dea42;
          X509_STORE_CTX_set0_crls(&XStack_10b4,((p7->d).sign)->crl);
          iVar1 = X509_verify_cert(&XStack_10b4);
          if (iVar1 < 1) goto LAB_000de724;
          X509_STORE_CTX_cleanup(&XStack_10b4);
        }
      }
    }
  }
  pBVar7 = indata;
  if ((indata != (BIO *)0x0) && (iVar1 = BIO_method_type(indata), iVar1 == 0x401)) {
    lVar2 = BIO_ctrl(indata,3,0,&local_10b8);
    pBVar7 = BIO_new_mem_buf(local_10b8,lVar2);
    if (pBVar7 == (BIO *)0x0) {
      ERR_put_error(0x21,0x75,0x41,"pk7_smime.c",0x16e);
      pBVar4 = pBVar7;
      goto LAB_000de640;
    }
  }
  b = PKCS7_dataInit(p7,pBVar7);
  pBVar9 = b;
  if (b != (BIO *)0x0) {
    b_00 = out;
    if ((flags & 1U) != 0) {
      type = BIO_s_mem();
      pBVar9 = BIO_new(type);
      if (pBVar9 == (BIO *)0x0) {
        ERR_put_error(0x21,0x75,0x41,"pk7_smime.c",0x17b);
        goto LAB_000de8b2;
      }
      BIO_ctrl(pBVar9,0x82,0,(void *)0x0);
      b_00 = pBVar9;
    }
    if (b_00 == (BIO *)0x0) {
      do {
        iVar1 = BIO_read(b,auStack_102c,0x1000);
      } while (0 < iVar1);
    }
    else {
      while (iVar1 = BIO_read(b,auStack_102c,0x1000), 0 < iVar1) {
        BIO_write(b_00,auStack_102c,iVar1);
      }
    }
    if ((flags & 1U) != 0) {
      pBVar9 = (BIO *)SMIME_text(b_00,out);
      if (pBVar9 == (BIO *)0x0) {
        ERR_put_error(0x21,0x75,0x81,"pk7_smime.c",0x18b);
        BIO_free(b_00);
        goto LAB_000de8b2;
      }
      BIO_free(b_00);
    }
    uVar8 = flags & 4;
    if (uVar8 == 0) {
      for (; iVar1 = sk_num(p_Var3), (int)uVar8 < iVar1; uVar8 = uVar8 + 1) {
        si = (PKCS7_SIGNER_INFO *)sk_value(p_Var3,uVar8);
        pXVar5 = (X509 *)sk_value((_STACK *)pBVar4,uVar8);
        iVar1 = PKCS7_signatureVerify(b,p7,si,pXVar5);
        if (iVar1 < 1) {
          pBVar9 = (BIO *)0x0;
          ERR_put_error(0x21,0x75,0x69,"pk7_smime.c",0x19a);
          goto LAB_000de8b2;
        }
      }
    }
    pBVar9 = (BIO *)0x1;
  }
LAB_000de8b2:
  if ((pBVar7 == indata) && (pBVar7 != (BIO *)0x0)) {
    BIO_pop(b);
  }
  BIO_free_all(b);
  sk_free((_STACK *)pBVar4);
  pBVar4 = pBVar9;
  goto LAB_000de640;
LAB_000dea22:
  iVar1 = 0x146;
  goto LAB_000dea2a;
LAB_000de724:
  iVar1 = X509_STORE_CTX_get_error(&XStack_10b4);
  X509_STORE_CTX_cleanup(&XStack_10b4);
  ERR_put_error(0x21,0x75,0x75,"pk7_smime.c",0x156);
  pcVar6 = X509_verify_cert_error_string(iVar1);
  ERR_add_error_data(2,"Verify error:",pcVar6);
  sk_free((_STACK *)pBVar4);
  pBVar4 = pBVar7;
  goto LAB_000de640;
LAB_000dea42:
  iVar1 = 0x14c;
LAB_000dea2a:
  ERR_put_error(0x21,0x75,0xb,"pk7_smime.c",iVar1);
  sk_free((_STACK *)pBVar4);
  pBVar4 = pBVar7;
LAB_000de640:
  if (local_2c == __TMC_END__) {
    return (int)pBVar4;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

