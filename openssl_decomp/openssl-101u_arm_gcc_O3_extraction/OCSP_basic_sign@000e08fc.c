
int OCSP_basic_sign(OCSP_BASICRESP *brsp,X509 *signer,EVP_PKEY *key,EVP_MD *dgst,
                   stack_st_X509 *certs,ulong flags)

{
  int iVar1;
  EVP_MD *type;
  ASN1_OCTET_STRING *str;
  X509_NAME *name;
  ASN1_TIME *pAVar2;
  _STACK *p_Var3;
  void *data;
  OCSP_RESPID *pOVar4;
  int iVar5;
  uchar auStack_40 [20];
  int local_2c;
  
  local_2c = __stack_chk_guard;
  iVar1 = X509_check_private_key(signer,key);
  if (iVar1 == 0) {
    ERR_put_error(0x27,0x68,0x6e,"ocsp_srv.c",0xe3);
    goto LAB_000e09bc;
  }
  if ((int)(flags << 0x1f) < 0) {
LAB_000e092c:
    pOVar4 = brsp->tbsResponseData->responderId;
    if ((flags & 0x400) == 0) {
      name = X509_get_subject_name(signer);
      iVar1 = X509_NAME_set(&(pOVar4->value).byName,name);
      if (iVar1 != 0) {
        pOVar4->type = 0;
        goto LAB_000e0974;
      }
    }
    else {
      type = EVP_sha1();
      X509_pubkey_digest(signer,type,auStack_40,(uint *)0x0);
      str = ASN1_OCTET_STRING_new();
      (pOVar4->value).byKey = str;
      if ((str != (ASN1_OCTET_STRING *)0x0) &&
         (iVar1 = ASN1_OCTET_STRING_set(str,auStack_40,0x14), iVar1 != 0)) {
        pOVar4->type = 1;
LAB_000e0974:
        if (((flags & 0x800) != 0) ||
           (pAVar2 = X509_gmtime_adj(brsp->tbsResponseData->producedAt,0),
           pAVar2 != (ASN1_TIME *)0x0)) {
          iVar1 = ASN1_item_sign((ASN1_ITEM *)OCSP_RESPDATA_it,brsp->signatureAlgorithm,
                                 (X509_ALGOR *)0x0,brsp->signature,brsp->tbsResponseData,key,dgst);
          if (iVar1 != 0) {
            iVar1 = 1;
          }
          goto LAB_000e09bc;
        }
      }
    }
  }
  else {
    p_Var3 = (_STACK *)brsp->certs;
    if (p_Var3 == (_STACK *)0x0) {
      p_Var3 = sk_new_null();
      brsp->certs = (stack_st_X509 *)p_Var3;
      if (p_Var3 != (_STACK *)0x0) goto LAB_000e09b2;
    }
    else {
LAB_000e09b2:
      iVar1 = sk_push(p_Var3,signer);
      if (iVar1 != 0) {
        iVar5 = 0;
        CRYPTO_add_lock(&signer->references,1,3,"ocsp_srv.c",0xd6);
        iVar1 = sk_num(&certs->stack);
        if (-1 < -iVar1) goto LAB_000e092c;
        data = sk_value(&certs->stack,0);
        p_Var3 = (_STACK *)brsp->certs;
        if (p_Var3 == (_STACK *)0x0) goto LAB_000e0a56;
        do {
          do {
            iVar1 = sk_push(p_Var3,data);
            if (iVar1 == 0) goto LAB_000e09ba;
            iVar5 = iVar5 + 1;
            CRYPTO_add_lock((int *)((int)data + 0x10),1,3,"ocsp_srv.c",0xd6);
            iVar1 = sk_num(&certs->stack);
            if (iVar1 <= iVar5) goto LAB_000e092c;
            data = sk_value(&certs->stack,iVar5);
            p_Var3 = (_STACK *)brsp->certs;
          } while (p_Var3 != (_STACK *)0x0);
LAB_000e0a56:
          p_Var3 = sk_new_null();
          brsp->certs = (stack_st_X509 *)p_Var3;
        } while (p_Var3 != (_STACK *)0x0);
      }
    }
  }
LAB_000e09ba:
  iVar1 = 0;
LAB_000e09bc:
  if (local_2c != __stack_chk_guard) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar1;
}

