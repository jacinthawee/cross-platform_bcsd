
_STACK * cert_status_cb(SSL *param_1,char **param_2)

{
  X509 *x;
  _STACK *sk;
  char *url;
  _STACK *cid;
  SSL_CTX *pSVar1;
  X509_STORE *store;
  int iVar2;
  void *pvVar3;
  X509_NAME *name;
  _STACK *req;
  _STACK *a;
  X509_EXTENSION *ex;
  int iVar4;
  _STACK *p_Var5;
  BIO *bp;
  char *local_c8;
  char *local_c4;
  char *local_c0;
  char *local_bc;
  uchar *local_b8;
  _STACK *local_b4;
  X509_OBJECT XStack_b0;
  X509_STORE_CTX XStack_a8;
  
  bp = (BIO *)param_2[5];
  local_b8 = (uchar *)0x0;
  if (param_2[6] != (char *)0x0) {
    BIO_puts(bp,"cert_status: callback called\n");
  }
  x = SSL_get_certificate(param_1);
  sk = (_STACK *)X509_get1_ocsp(x);
  if (sk == (_STACK *)0x0) {
    if (*param_2 == (char *)0x0) {
      p_Var5 = (_STACK *)0x3;
      BIO_puts((BIO *)param_2[5],"cert_status: no AIA and no default responder URL\n");
      cid = sk;
      req = sk;
      a = sk;
      goto LAB_00025fbe;
    }
    local_c0 = param_2[1];
    local_c4 = param_2[2];
    local_bc = param_2[3];
    local_c8 = *param_2;
  }
  else {
    url = (char *)sk_value(sk,0);
    cid = (_STACK *)OCSP_parse_url(url,&local_c8,&local_c4,&local_c0,(int *)&local_bc);
    if (cid == (_STACK *)0x0) {
      BIO_puts(bp,"cert_status: can\'t parse AIA URL\n");
      p_Var5 = (_STACK *)0x2;
      req = cid;
      a = cid;
      goto LAB_00025fbe;
    }
    if (param_2[6] != (char *)0x0) {
      pvVar3 = sk_value(sk,0);
      BIO_printf(bp,"cert_status: AIA URL: %s\n",pvVar3);
    }
  }
  pSVar1 = SSL_get_SSL_CTX(param_1);
  store = SSL_CTX_get_cert_store(pSVar1);
  iVar2 = X509_STORE_CTX_init(&XStack_a8,store,(X509 *)0x0,(stack_st_X509 *)0x0);
  if (iVar2 != 0) {
    name = X509_get_issuer_name(x);
    iVar2 = X509_STORE_get_by_subject(&XStack_a8,1,name,&XStack_b0);
    if (iVar2 < 1) {
      BIO_puts(bp,"cert_status: Can\'t retrieve issuer certificate.\n");
      X509_STORE_CTX_cleanup(&XStack_a8);
      p_Var5 = (_STACK *)0x3;
      cid = (_STACK *)0x0;
      req = (_STACK *)0x0;
      a = (_STACK *)0x0;
      goto LAB_00025fbe;
    }
    req = (_STACK *)OCSP_REQUEST_new();
    if (req != (_STACK *)0x0) {
      cid = (_STACK *)OCSP_cert_to_id((EVP_MD *)0x0,x,XStack_b0.data.x509);
      X509_free(XStack_b0.data.x509);
      X509_STORE_CTX_cleanup(&XStack_a8);
      if (cid != (_STACK *)0x0) {
        a = (_STACK *)OCSP_request_add0_id((OCSP_REQUEST *)req,(OCSP_CERTID *)cid);
        if (a == (_STACK *)0x0) {
          p_Var5 = (_STACK *)0x2;
          goto LAB_00025fbe;
        }
        SSL_ctrl(param_1,0x42,0,&local_b4);
        iVar2 = 0;
        do {
          iVar4 = sk_num(local_b4);
          if (iVar4 <= iVar2) {
            a = (_STACK *)process_responder(bp,req,local_c8,local_c0,local_c4,local_bc,0,param_2[4])
            ;
            if (a == (_STACK *)0x0) {
              p_Var5 = (_STACK *)0x3;
              BIO_puts(bp,"cert_status: error querying responder\n");
              cid = a;
              goto LAB_00025fbe;
            }
            iVar2 = i2d_OCSP_RESPONSE((OCSP_RESPONSE *)a,&local_b8);
            if (iVar2 < 1) {
              p_Var5 = (_STACK *)0x2;
              cid = (_STACK *)0x0;
              goto LAB_00025fbe;
            }
            SSL_ctrl(param_1,0x47,iVar2,local_b8);
            if (param_2[6] != (char *)0x0) {
              BIO_puts(bp,"cert_status: ocsp response sent:\n");
              OCSP_RESPONSE_print(bp,(OCSP_RESPONSE *)a,2);
            }
            cid = (_STACK *)0x0;
            p_Var5 = cid;
            goto LAB_00025fc4;
          }
          ex = (X509_EXTENSION *)sk_value(local_b4,iVar2);
          cid = (_STACK *)OCSP_REQUEST_add_ext((OCSP_REQUEST *)req,ex,-1);
          iVar2 = iVar2 + 1;
        } while (cid != (_STACK *)0x0);
      }
      p_Var5 = (_STACK *)0x2;
      a = cid;
      goto LAB_00025fbe;
    }
  }
  p_Var5 = (_STACK *)0x2;
  cid = (_STACK *)0x0;
  req = (_STACK *)0x0;
  a = (_STACK *)0x0;
LAB_00025fbe:
  ERR_print_errors(bp);
LAB_00025fc4:
  if (sk != (_STACK *)0x0) {
    CRYPTO_free(local_c8);
    CRYPTO_free(local_c0);
    CRYPTO_free(local_c4);
    X509_email_free((stack_st_OPENSSL_STRING *)sk);
  }
  if (cid != (_STACK *)0x0) {
    OCSP_CERTID_free((OCSP_CERTID *)cid);
  }
  if (req != (_STACK *)0x0) {
    OCSP_REQUEST_free((OCSP_REQUEST *)req);
  }
  if (a != (_STACK *)0x0) {
    OCSP_RESPONSE_free((OCSP_RESPONSE *)a);
  }
  return p_Var5;
}

