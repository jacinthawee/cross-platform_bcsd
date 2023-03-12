
X509_REQ * X509_to_X509_REQ(X509 *x,EVP_PKEY *pkey,EVP_MD *md)

{
  X509_REQ *req;
  uchar *puVar1;
  X509_NAME *name;
  int iVar2;
  EVP_PKEY *pkey_00;
  ASN1_INTEGER *pAVar3;
  ASN1_INTEGER *pAVar4;
  X509_REQ_INFO *pXVar5;
  
  req = X509_REQ_new();
  if (req == (X509_REQ *)0x0) {
    ERR_put_error(0xb,0x7e,0x41,"x509_req.c",0x50);
  }
  else {
    pXVar5 = req->req_info;
    pAVar4 = pXVar5->version;
    pAVar4->length = 1;
    puVar1 = (uchar *)CRYPTO_malloc(1,"x509_req.c",0x57);
    pAVar3 = pXVar5->version;
    pAVar4->data = puVar1;
    puVar1 = pAVar3->data;
    if (puVar1 != (uchar *)0x0) {
      *puVar1 = '\0';
      name = X509_get_subject_name(x);
      iVar2 = X509_REQ_set_subject_name(req,name);
      if (iVar2 != 0) {
        pkey_00 = X509_get_pubkey(x);
        iVar2 = X509_REQ_set_pubkey(req,pkey_00);
        EVP_PKEY_free(pkey_00);
        if ((iVar2 != 0) &&
           ((pkey == (EVP_PKEY *)0x0 || (iVar2 = X509_REQ_sign(req,pkey,md), iVar2 != 0)))) {
          return req;
        }
      }
    }
  }
  X509_REQ_free(req);
  return (X509_REQ *)0x0;
}

