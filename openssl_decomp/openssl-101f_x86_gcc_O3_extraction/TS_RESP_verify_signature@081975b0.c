
PKCS7 * TS_RESP_verify_signature
                  (PKCS7 *param_1,stack_st_X509 *param_2,X509_STORE *param_3,X509 **param_4)

{
  _STACK *p_Var1;
  int iVar2;
  PKCS7_SIGNER_INFO *si;
  long lVar3;
  X509 *x509;
  ASN1_TYPE *pAVar4;
  char *pcVar5;
  BIO *b;
  _STACK *p_Var6;
  _STACK *st;
  int in_GS_OFFSET;
  int iVar7;
  _STACK **local_10b4;
  X509_STORE_CTX local_10a8;
  undefined local_1020 [4096];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (param_1 == (PKCS7 *)0x0) {
    st = (_STACK *)0x0;
    b = (BIO *)0x0;
    p_Var6 = (_STACK *)0x0;
    ERR_put_error(0x2f,0x6a,0x66,"ts_rsp_verify.c",0x9b);
    goto LAB_08197627;
  }
  iVar2 = OBJ_obj2nid(param_1->type);
  if (iVar2 == 0x16) {
    p_Var6 = (_STACK *)PKCS7_get_signer_info(param_1);
    if (p_Var6 != (_STACK *)0x0) {
      iVar2 = sk_num(p_Var6);
      if (iVar2 == 1) {
        si = (PKCS7_SIGNER_INFO *)sk_value(p_Var6,0);
        lVar3 = PKCS7_ctrl(param_1,2,0,(char *)0x0);
        if (lVar3 == 0) {
          p_Var6 = (_STACK *)PKCS7_get0_signers(param_1,param_2,0);
          if (p_Var6 != (_STACK *)0x0) {
            iVar2 = sk_num(p_Var6);
            if (iVar2 == 1) {
              x509 = (X509 *)sk_value(p_Var6,0);
              X509_STORE_CTX_init(&local_10a8,param_3,x509,param_2);
              X509_STORE_CTX_set_purpose(&local_10a8,9);
              iVar2 = X509_verify_cert(&local_10a8);
              if (iVar2 < 1) {
                st = (_STACK *)0x0;
                iVar2 = X509_STORE_CTX_get_error(&local_10a8);
                ERR_put_error(0x2f,0x6d,100,"ts_rsp_verify.c",0xf6);
                param_1 = (PKCS7 *)0x0;
                pcVar5 = X509_verify_cert_error_string(iVar2);
                ERR_add_error_data(2,"Verify error:",pcVar5);
                b = (BIO *)0x0;
                X509_STORE_CTX_cleanup(&local_10a8);
              }
              else {
                st = (_STACK *)X509_STORE_CTX_get1_chain(&local_10a8);
                X509_STORE_CTX_cleanup(&local_10a8);
                pAVar4 = PKCS7_get_signed_attribute(si,0xdf);
                if (pAVar4 == (ASN1_TYPE *)0x0) {
                  local_10b4 = (_STACK **)0x0;
                }
                else {
                  local_10a8.ctx = (X509_STORE *)((pAVar4->value).asn1_string)->data;
                  local_10b4 = (_STACK **)
                               d2i_ESS_SIGNING_CERT
                                         (0,&local_10a8,((pAVar4->value).asn1_string)->length);
                  if (local_10b4 != (_STACK **)0x0) {
                    p_Var1 = *local_10b4;
                    sk_value(st,0);
                    iVar2 = TS_find_cert();
                    if (iVar2 == 0) {
                      iVar2 = sk_num(p_Var1);
                      if (1 < iVar2) {
                        iVar2 = 1;
                        while( true ) {
                          iVar7 = sk_num(st);
                          if (iVar7 <= iVar2) break;
                          sk_value(st,iVar2);
                          iVar7 = TS_find_cert();
                          if (iVar7 < 0) goto LAB_081977fd;
                          iVar2 = iVar2 + 1;
                        }
                      }
                      ESS_SIGNING_CERT_free(local_10b4);
                      b = PKCS7_dataInit(param_1,(BIO *)0x0);
                      do {
                        iVar2 = BIO_read(b,local_1020,0x1000);
                      } while (0 < iVar2);
                      iVar2 = PKCS7_signatureVerify(b,param_1,si,x509);
                      if (iVar2 < 1) {
                        param_1 = (PKCS7 *)0x0;
                        ERR_put_error(0x2f,0x6a,0x6d,"ts_rsp_verify.c",0xce);
                      }
                      else if (param_4 == (X509 **)0x0) {
                        param_1 = (PKCS7 *)0x1;
                      }
                      else {
                        param_1 = (PKCS7 *)0x1;
                        *param_4 = x509;
                        CRYPTO_add_lock(&x509->references,1,3,"ts_rsp_verify.c",0xd6);
                      }
                      goto LAB_08197627;
                    }
                  }
                }
LAB_081977fd:
                b = (BIO *)0x0;
                param_1 = (PKCS7 *)0x0;
                ERR_put_error(0x2f,0x67,0x65,"ts_rsp_verify.c",0x123);
                ESS_SIGNING_CERT_free(local_10b4);
              }
              goto LAB_08197627;
            }
          }
          st = (_STACK *)0x0;
          b = (BIO *)0x0;
          param_1 = (PKCS7 *)0x0;
          goto LAB_08197627;
        }
        iVar7 = 0xb3;
        iVar2 = 0x6a;
        goto LAB_08197613;
      }
    }
    iVar7 = 0xab;
    iVar2 = 0x6e;
  }
  else {
    iVar7 = 0xa2;
    iVar2 = 0x72;
  }
LAB_08197613:
  st = (_STACK *)0x0;
  b = (BIO *)0x0;
  param_1 = (PKCS7 *)0x0;
  p_Var6 = (_STACK *)0x0;
  ERR_put_error(0x2f,0x6a,iVar2,"ts_rsp_verify.c",iVar7);
LAB_08197627:
  BIO_free_all(b);
  sk_pop_free(st,X509_free);
  sk_free(p_Var6);
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return param_1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

