
int OCSP_request_verify(OCSP_REQUEST *req,stack_st_X509 *certs,X509_STORE *store,ulong flags)

{
  X509_STORE_CTX *ctx;
  X509 *x;
  int iVar1;
  char *pcVar2;
  EVP_PKEY *pkey;
  GENERAL_NAME *pGVar3;
  OCSP_SIGNATURE *pOVar4;
  bool bVar5;
  X509_STORE_CTX XStack_a8;
  
  pOVar4 = req->optionalSignature;
  if (pOVar4 == (OCSP_SIGNATURE *)0x0) {
    ERR_put_error(0x27,0x74,0x80,"ocsp_vfy.c",0x174);
  }
  else {
    pGVar3 = req->tbsRequest->requestorName;
    if ((pGVar3 == (GENERAL_NAME *)0x0) || (pGVar3->type != 4)) {
      ERR_put_error(0x27,0x74,0x81,"ocsp_vfy.c",0x17a);
      pOVar4 = (OCSP_SIGNATURE *)0x0;
    }
    else {
      if ((int)(flags << 0x1e) < 0) {
        x = X509_find_by_subject(certs,(pGVar3->d).directoryName);
        if (x == (X509 *)0x0) {
          ERR_put_error(0x27,0x74,0x76,"ocsp_vfy.c",0x181);
          return 0;
        }
        if ((int)(flags << 0x16) < 0) {
          flags = flags | 0x10;
        }
      }
      else {
        x = X509_find_by_subject(pOVar4->certs,(pGVar3->d).directoryName);
      }
      if ((flags & 4) == 0) {
        pkey = X509_get_pubkey(x);
        iVar1 = ASN1_item_verify((ASN1_ITEM *)OCSP_REQINFO_it,
                                 req->optionalSignature->signatureAlgorithm,
                                 req->optionalSignature->signature,req->tbsRequest,pkey);
        EVP_PKEY_free(pkey);
        if (iVar1 < 1) {
          ERR_put_error(0x27,0x74,0x75,"ocsp_vfy.c",0x18e);
          return 0;
        }
      }
      pOVar4 = (OCSP_SIGNATURE *)(flags & 0x10);
      if (pOVar4 != (OCSP_SIGNATURE *)0x0) {
        return 1;
      }
      bVar5 = -1 < (int)(flags << 0x1c);
      ctx = &XStack_a8;
      if (bVar5) {
        pOVar4 = req->optionalSignature;
        ctx = (X509_STORE_CTX *)req;
      }
      if (bVar5) {
        pOVar4 = (OCSP_SIGNATURE *)pOVar4->certs;
        ctx = &XStack_a8;
      }
      pOVar4 = (OCSP_SIGNATURE *)X509_STORE_CTX_init(ctx,store,x,(stack_st_X509 *)pOVar4);
      if (pOVar4 == (OCSP_SIGNATURE *)0x0) {
        ERR_put_error(0x27,0x74,0xb,"ocsp_vfy.c",0x19c);
      }
      else {
        X509_STORE_CTX_set_purpose(ctx,8);
        X509_STORE_CTX_set_trust(ctx,7);
        iVar1 = X509_verify_cert(ctx);
        X509_STORE_CTX_cleanup(ctx);
        if (0 < iVar1) {
          return 1;
        }
        iVar1 = X509_STORE_CTX_get_error(ctx);
        ERR_put_error(0x27,0x74,0x65,"ocsp_vfy.c",0x1a7);
        pcVar2 = X509_verify_cert_error_string(iVar1);
        ERR_add_error_data(2,"Verify error:",pcVar2);
        pOVar4 = (OCSP_SIGNATURE *)0x0;
      }
    }
  }
  return (int)pOVar4;
}

