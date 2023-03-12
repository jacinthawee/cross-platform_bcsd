
undefined4 cert_status_cb(SSL *param_1,char **param_2)

{
  BIO *bp;
  X509 *x;
  _STACK *sk;
  char *url;
  int iVar1;
  SSL_CTX *pSVar2;
  X509_STORE *store;
  void *pvVar3;
  X509_NAME *name;
  OCSP_ONEREQ *pOVar4;
  X509_EXTENSION *ex;
  int iVar5;
  OCSP_CERTID *cid;
  undefined4 uVar6;
  OCSP_RESPONSE *a;
  int in_GS_OFFSET;
  OCSP_REQUEST *local_dc;
  char *local_c8;
  char *local_c4;
  char *local_c0;
  char *local_bc;
  uchar *local_b8;
  _STACK *local_b4;
  X509_OBJECT local_b0;
  X509_STORE_CTX local_a8;
  int local_20;
  
  local_b8 = (uchar *)0x0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  bp = (BIO *)param_2[5];
  if (param_2[6] != (char *)0x0) {
    BIO_puts(bp,"cert_status: callback called\n");
  }
  x = SSL_get_certificate(param_1);
  sk = (_STACK *)X509_get1_ocsp(x);
  if (sk != (_STACK *)0x0) {
    url = (char *)sk_value(sk,0);
    iVar1 = OCSP_parse_url(url,&local_c8,&local_c4,&local_c0,(int *)&local_bc);
    if (iVar1 != 0) {
      if (param_2[6] != (char *)0x0) {
        pvVar3 = sk_value(sk,0);
        BIO_printf(bp,"cert_status: AIA URL: %s\n",pvVar3);
      }
      goto LAB_080676f4;
    }
    a = (OCSP_RESPONSE *)0x0;
    uVar6 = 2;
    BIO_puts(bp,"cert_status: can\'t parse AIA URL\n");
    ERR_print_errors(bp);
    local_dc = (OCSP_REQUEST *)0x0;
    cid = (OCSP_CERTID *)0x0;
    goto LAB_08067745;
  }
  if (*param_2 == (char *)0x0) {
    uVar6 = 3;
    BIO_puts((BIO *)param_2[5],"cert_status: no AIA and no default responder URL\n");
    ERR_print_errors(bp);
    goto LAB_080677ae;
  }
  local_c0 = param_2[1];
  local_c4 = param_2[2];
  local_bc = param_2[3];
  local_c8 = *param_2;
LAB_080676f4:
  pSVar2 = SSL_get_SSL_CTX(param_1);
  store = SSL_CTX_get_cert_store(pSVar2);
  iVar1 = X509_STORE_CTX_init(&local_a8,store,(X509 *)0x0,(stack_st_X509 *)0x0);
  if (iVar1 == 0) {
LAB_08067722:
    uVar6 = 2;
    a = (OCSP_RESPONSE *)0x0;
    local_dc = (OCSP_REQUEST *)0x0;
    goto LAB_08067730;
  }
  name = X509_get_issuer_name(x);
  iVar1 = X509_STORE_get_by_subject(&local_a8,1,name,&local_b0);
  if (iVar1 < 1) {
    a = (OCSP_RESPONSE *)0x0;
    BIO_puts(bp,"cert_status: Can\'t retrieve issuer certificate.\n");
    uVar6 = 3;
    X509_STORE_CTX_cleanup(&local_a8);
    local_dc = (OCSP_REQUEST *)0x0;
    goto LAB_08067730;
  }
  local_dc = OCSP_REQUEST_new();
  if (local_dc == (OCSP_REQUEST *)0x0) goto LAB_08067722;
  cid = OCSP_cert_to_id((EVP_MD *)0x0,x,local_b0.data.x509);
  X509_free(local_b0.data.x509);
  X509_STORE_CTX_cleanup(&local_a8);
  if (cid == (OCSP_CERTID *)0x0) {
LAB_08067a40:
    uVar6 = 2;
    a = (OCSP_RESPONSE *)0x0;
    goto LAB_08067730;
  }
  pOVar4 = OCSP_request_add0_id(local_dc,cid);
  if (pOVar4 == (OCSP_ONEREQ *)0x0) {
    a = (OCSP_RESPONSE *)0x0;
    uVar6 = 2;
    ERR_print_errors(bp);
    if (sk != (_STACK *)0x0) {
LAB_08067745:
      CRYPTO_free(local_c8);
      CRYPTO_free(local_c0);
      CRYPTO_free(local_c4);
      X509_email_free((stack_st_OPENSSL_STRING *)sk);
      if (cid == (OCSP_CERTID *)0x0) goto LAB_08067788;
    }
    OCSP_CERTID_free(cid);
LAB_08067788:
    if (local_dc != (OCSP_REQUEST *)0x0) goto LAB_0806778f;
  }
  else {
    SSL_ctrl(param_1,0x42,0,&local_b4);
    for (iVar1 = 0; iVar5 = sk_num(local_b4), iVar1 < iVar5; iVar1 = iVar1 + 1) {
      ex = (X509_EXTENSION *)sk_value(local_b4,iVar1);
      iVar5 = OCSP_REQUEST_add_ext(local_dc,ex,-1);
      if (iVar5 == 0) goto LAB_08067a40;
    }
    a = (OCSP_RESPONSE *)
        process_responder(bp,local_dc,local_c8,local_c0,local_c4,local_bc,0,param_2[4]);
    if (a == (OCSP_RESPONSE *)0x0) {
      uVar6 = 3;
      BIO_puts(bp,"cert_status: error querying responder\n");
LAB_08067730:
      ERR_print_errors(bp);
      cid = (OCSP_CERTID *)0x0;
      if (sk != (_STACK *)0x0) goto LAB_08067745;
      goto LAB_08067788;
    }
    uVar6 = 2;
    iVar1 = i2d_OCSP_RESPONSE(a,&local_b8);
    if (iVar1 < 1) goto LAB_08067730;
    SSL_ctrl(param_1,0x47,iVar1,local_b8);
    if (param_2[6] != (char *)0x0) {
      BIO_puts(bp,"cert_status: ocsp response sent:\n");
      OCSP_RESPONSE_print(bp,a,2);
    }
    cid = (OCSP_CERTID *)0x0;
    uVar6 = 0;
    if (sk != (_STACK *)0x0) goto LAB_08067745;
LAB_0806778f:
    OCSP_REQUEST_free(local_dc);
  }
  if (a != (OCSP_RESPONSE *)0x0) {
    OCSP_RESPONSE_free(a);
  }
LAB_080677ae:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar6;
}

