
X509_REQ * X509_to_X509_REQ(X509 *x,EVP_PKEY *pkey,EVP_MD *md)

{
  undefined *puVar1;
  X509_REQ *req;
  uchar *puVar2;
  X509_NAME *name;
  int iVar3;
  EVP_PKEY *pkey_00;
  ASN1_INTEGER *pAVar4;
  ASN1_INTEGER *pAVar5;
  X509_REQ_INFO *pXVar6;
  
  req = (X509_REQ *)(*(code *)PTR_X509_REQ_new_006a6ed0)();
  puVar1 = PTR_CRYPTO_malloc_006a7008;
  if (req == (X509_REQ *)0x0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0xb,0x7e,0x41,"x509_req.c",0x4f);
  }
  else {
    pXVar6 = req->req_info;
    pAVar5 = pXVar6->version;
    pAVar5->length = 1;
    puVar2 = (uchar *)(*(code *)puVar1)(1,"x509_req.c",0x56);
    pAVar4 = pXVar6->version;
    pAVar5->data = puVar2;
    puVar2 = pAVar4->data;
    if (puVar2 != (uchar *)0x0) {
      *puVar2 = '\0';
      name = X509_get_subject_name(x);
      iVar3 = X509_REQ_set_subject_name(req,name);
      if (iVar3 != 0) {
        pkey_00 = X509_get_pubkey(x);
        if (pkey_00 != (EVP_PKEY *)0x0) {
          iVar3 = X509_REQ_set_pubkey(req,pkey_00);
          (*(code *)PTR_EVP_PKEY_free_006a6e78)(pkey_00);
          if (iVar3 != 0) {
            if (pkey != (EVP_PKEY *)0x0) {
              iVar3 = X509_REQ_sign(req,pkey,md);
              if (iVar3 == 0) goto LAB_00576a98;
            }
            return req;
          }
        }
      }
    }
  }
LAB_00576a98:
  (*(code *)PTR_X509_REQ_free_006a6e8c)(req);
  return (X509_REQ *)0x0;
}

