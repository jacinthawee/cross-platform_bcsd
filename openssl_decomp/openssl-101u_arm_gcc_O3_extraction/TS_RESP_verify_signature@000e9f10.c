
void TS_RESP_verify_signature
               (BIO *param_1,stack_st_X509 *param_2,X509_STORE *param_3,X509 **param_4)

{
  int iVar1;
  _STACK *p_Var2;
  PKCS7_SIGNER_INFO *si;
  BIO *pBVar3;
  BIO *pBVar4;
  X509 *x509;
  BIO *pBVar5;
  BIO *st;
  ASN1_TYPE *pAVar6;
  void *pvVar7;
  char *pcVar8;
  BIO *b;
  int iVar9;
  _STACK **local_10bc;
  X509_STORE_CTX local_10b4;
  undefined auStack_102c [4096];
  int local_2c;
  
  local_2c = __stack_chk_guard;
  if (param_1 == (BIO *)0x0) {
    ERR_put_error(0x2f,0x6a,0x66,"ts_rsp_verify.c",0xad);
    pBVar5 = param_1;
    pBVar4 = param_1;
    st = param_1;
    b = param_1;
    goto LAB_000e9f62;
  }
  iVar1 = OBJ_obj2nid((ASN1_OBJECT *)param_1->shutdown);
  if (iVar1 == 0x16) {
    p_Var2 = (_STACK *)PKCS7_get_signer_info((PKCS7 *)param_1);
    if ((p_Var2 == (_STACK *)0x0) || (iVar1 = sk_num(p_Var2), iVar1 != 1)) {
      iVar9 = 0xba;
      iVar1 = 0x6e;
    }
    else {
      si = (PKCS7_SIGNER_INFO *)sk_value(p_Var2,0);
      pBVar3 = (BIO *)PKCS7_ctrl((PKCS7 *)param_1,2,0,(char *)0x0);
      if (pBVar3 == (BIO *)0x0) {
        pBVar4 = (BIO *)PKCS7_get0_signers((PKCS7 *)param_1,param_2,0);
        pBVar5 = pBVar4;
        st = pBVar4;
        b = pBVar4;
        if ((pBVar4 != (BIO *)0x0) &&
           (iVar1 = sk_num((_STACK *)pBVar4), pBVar5 = pBVar3, st = pBVar3, b = pBVar3, iVar1 == 1))
        {
          x509 = (X509 *)sk_value((_STACK *)pBVar4,0);
          pBVar5 = (BIO *)X509_STORE_CTX_init(&local_10b4,param_3,x509,param_2);
          st = pBVar5;
          b = pBVar5;
          if (pBVar5 != (BIO *)0x0) {
            X509_STORE_CTX_set_purpose(&local_10b4,9);
            iVar1 = X509_verify_cert(&local_10b4);
            if (iVar1 < 1) {
              iVar1 = X509_STORE_CTX_get_error(&local_10b4);
              ERR_put_error(0x2f,0x6d,100,"ts_rsp_verify.c",0x108);
              pcVar8 = X509_verify_cert_error_string(iVar1);
              ERR_add_error_data(2,"Verify error:",pcVar8);
              X509_STORE_CTX_cleanup(&local_10b4);
              pBVar5 = pBVar3;
              st = pBVar3;
              b = pBVar3;
            }
            else {
              st = (BIO *)X509_STORE_CTX_get1_chain(&local_10b4);
              X509_STORE_CTX_cleanup(&local_10b4);
              pAVar6 = PKCS7_get_signed_attribute(si,0xdf);
              if (pAVar6 == (ASN1_TYPE *)0x0) {
                local_10bc = (_STACK **)0x0;
              }
              else {
                local_10b4.ctx = (X509_STORE *)((pAVar6->value).asn1_string)->data;
                local_10bc = (_STACK **)
                             d2i_ESS_SIGNING_CERT
                                       (0,&local_10b4,((pAVar6->value).asn1_string)->length);
                if (local_10bc != (_STACK **)0x0) {
                  p_Var2 = *local_10bc;
                  pvVar7 = sk_value((_STACK *)st,0);
                  iVar1 = TS_find_cert(p_Var2,pvVar7);
                  if (iVar1 == 0) {
                    iVar1 = sk_num(p_Var2);
                    if (1 < iVar1) {
                      for (iVar1 = 1; iVar9 = sk_num((_STACK *)st), iVar1 < iVar9; iVar1 = iVar1 + 1
                          ) {
                        pvVar7 = sk_value((_STACK *)st,iVar1);
                        iVar9 = TS_find_cert(p_Var2,pvVar7);
                        if (iVar9 < 0) goto LAB_000ea0a8;
                      }
                    }
                    ESS_SIGNING_CERT_free(local_10bc);
                    b = PKCS7_dataInit((PKCS7 *)param_1,(BIO *)0x0);
                    do {
                      iVar1 = BIO_read(b,auStack_102c,0x1000);
                    } while (0 < iVar1);
                    iVar1 = PKCS7_signatureVerify(b,(PKCS7 *)param_1,si,x509);
                    if (iVar1 < 1) {
                      ERR_put_error(0x2f,0x6a,0x6d,"ts_rsp_verify.c",0xe1);
                      pBVar5 = (BIO *)0x0;
                    }
                    else if (param_4 == (X509 **)0x0) {
                      pBVar5 = (BIO *)0x1;
                    }
                    else {
                      *param_4 = x509;
                      CRYPTO_add_lock(&x509->references,1,3,"ts_rsp_verify.c",0xe8);
                      pBVar5 = (BIO *)0x1;
                    }
                    goto LAB_000e9f62;
                  }
                }
              }
LAB_000ea0a8:
              ERR_put_error(0x2f,0x67,0x65,"ts_rsp_verify.c",0x137);
              ESS_SIGNING_CERT_free(local_10bc);
              pBVar5 = (BIO *)0x0;
              b = (BIO *)0x0;
            }
          }
        }
        goto LAB_000e9f62;
      }
      iVar1 = 0x6a;
      iVar9 = 0xc1;
    }
  }
  else {
    iVar9 = 0xb3;
    iVar1 = 0x72;
  }
  ERR_put_error(0x2f,0x6a,iVar1,"ts_rsp_verify.c",iVar9);
  pBVar5 = (BIO *)0x0;
  pBVar4 = (BIO *)0x0;
  st = (BIO *)0x0;
  b = (BIO *)0x0;
LAB_000e9f62:
  BIO_free_all(b);
  sk_pop_free((_STACK *)st,X509_free + 1);
  sk_free((_STACK *)pBVar4);
  if (local_2c == __stack_chk_guard) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(pBVar5);
}

