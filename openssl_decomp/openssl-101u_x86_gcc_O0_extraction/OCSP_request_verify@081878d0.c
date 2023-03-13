
int OCSP_request_verify(OCSP_REQUEST *req,stack_st_X509 *certs,X509_STORE *store,ulong flags)

{
  GENERAL_NAME *pGVar1;
  X509_NAME *name;
  ulong uVar2;
  X509 *x;
  char *pcVar3;
  EVP_PKEY *pkey;
  int in_GS_OFFSET;
  int iVar4;
  int line;
  stack_st_X509 *chain;
  X509_STORE_CTX local_a8;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (req->optionalSignature == (OCSP_SIGNATURE *)0x0) {
    line = 0x17b;
    iVar4 = 0x80;
  }
  else {
    pGVar1 = req->tbsRequest->requestorName;
    if ((pGVar1 != (GENERAL_NAME *)0x0) && (pGVar1->type == 4)) {
      name = (pGVar1->d).directoryName;
      if (((flags & 2) != 0) ||
         (x = X509_find_by_subject(req->optionalSignature->certs,name), uVar2 = flags,
         x == (X509 *)0x0)) {
        x = X509_find_by_subject(certs,name);
        if (x == (X509 *)0x0) {
          line = 0x188;
          iVar4 = 0x76;
          goto LAB_08187929;
        }
        uVar2 = flags | 0x10;
        if ((flags & 0x200) == 0) {
          uVar2 = flags;
        }
      }
      flags = uVar2;
      if ((flags & 4) == 0) {
        pkey = X509_get_pubkey(x);
        iVar4 = ASN1_item_verify((ASN1_ITEM *)OCSP_REQINFO_it,
                                 req->optionalSignature->signatureAlgorithm,
                                 req->optionalSignature->signature,req->tbsRequest,pkey);
        EVP_PKEY_free(pkey);
        if (iVar4 < 1) {
          line = 0x193;
          iVar4 = 0x75;
          goto LAB_08187929;
        }
      }
      if ((flags & 0x10) == 0) {
        if ((flags & 8) == 0) {
          chain = req->optionalSignature->certs;
        }
        else {
          chain = (stack_st_X509 *)0x0;
        }
        iVar4 = X509_STORE_CTX_init(&local_a8,store,x,chain);
        if (iVar4 == 0) {
          line = 0x19f;
          iVar4 = 0xb;
          goto LAB_08187929;
        }
        X509_STORE_CTX_set_purpose(&local_a8,8);
        X509_STORE_CTX_set_trust(&local_a8,7);
        iVar4 = X509_verify_cert(&local_a8);
        X509_STORE_CTX_cleanup(&local_a8);
        if (iVar4 < 1) {
          iVar4 = X509_STORE_CTX_get_error(&local_a8);
          ERR_put_error(0x27,0x74,0x65,"ocsp_vfy.c",0x1aa);
          pcVar3 = X509_verify_cert_error_string(iVar4);
          ERR_add_error_data(2,"Verify error:",pcVar3);
          iVar4 = 0;
          goto LAB_08187937;
        }
      }
      iVar4 = 1;
      goto LAB_08187937;
    }
    line = 0x181;
    iVar4 = 0x81;
  }
LAB_08187929:
  ERR_put_error(0x27,0x74,iVar4,"ocsp_vfy.c",line);
  iVar4 = 0;
LAB_08187937:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar4;
}

