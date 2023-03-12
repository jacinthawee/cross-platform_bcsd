
X509_REQ * X509_to_X509_REQ(X509 *x,EVP_PKEY *pkey,EVP_MD *md)

{
  X509_REQ_INFO *pXVar1;
  ASN1_INTEGER *pAVar2;
  X509_REQ *req;
  uchar *puVar3;
  X509_NAME *name;
  int iVar4;
  EVP_PKEY *pkey_00;
  
  req = X509_REQ_new();
  if (req == (X509_REQ *)0x0) {
    ERR_put_error(0xb,0x7e,0x41,"x509_req.c",0x50);
  }
  else {
    pXVar1 = req->req_info;
    pAVar2 = pXVar1->version;
    pAVar2->length = 1;
    puVar3 = (uchar *)CRYPTO_malloc(1,"x509_req.c",0x57);
    pAVar2->data = puVar3;
    puVar3 = pXVar1->version->data;
    if (puVar3 != (uchar *)0x0) {
      *puVar3 = '\0';
      name = X509_get_subject_name(x);
      iVar4 = X509_REQ_set_subject_name(req,name);
      if (iVar4 != 0) {
        pkey_00 = X509_get_pubkey(x);
        iVar4 = X509_REQ_set_pubkey(req,pkey_00);
        EVP_PKEY_free(pkey_00);
        if (iVar4 != 0) {
          if (pkey != (EVP_PKEY *)0x0) {
            iVar4 = X509_REQ_sign(req,pkey,md);
            if (iVar4 == 0) goto LAB_0815e3c8;
          }
          return req;
        }
      }
    }
  }
LAB_0815e3c8:
  X509_REQ_free(req);
  return (X509_REQ *)0x0;
}

