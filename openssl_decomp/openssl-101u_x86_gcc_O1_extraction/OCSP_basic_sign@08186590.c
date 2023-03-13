
int OCSP_basic_sign(OCSP_BASICRESP *brsp,X509 *signer,EVP_PKEY *key,EVP_MD *dgst,
                   stack_st_X509 *certs,ulong flags)

{
  OCSP_RESPID *pOVar1;
  uint uVar2;
  EVP_MD *type;
  ASN1_OCTET_STRING *str;
  int iVar3;
  X509_NAME *name;
  ASN1_TIME *pAVar4;
  _STACK *p_Var5;
  int iVar6;
  void *data;
  int in_GS_OFFSET;
  uchar local_34 [20];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  uVar2 = X509_check_private_key(signer,key);
  if (uVar2 == 0) {
    ERR_put_error(0x27,0x68,0x6e,"ocsp_srv.c",0xe3);
    goto LAB_0818677d;
  }
  if ((flags & 1) == 0) {
    p_Var5 = (_STACK *)brsp->certs;
    if (p_Var5 == (_STACK *)0x0) {
      p_Var5 = sk_new_null();
      brsp->certs = (stack_st_X509 *)p_Var5;
      if (p_Var5 != (_STACK *)0x0) goto LAB_081866e0;
    }
    else {
LAB_081866e0:
      iVar3 = sk_push(p_Var5,signer);
      if (iVar3 != 0) {
        CRYPTO_add_lock(&signer->references,1,3,"ocsp_srv.c",0xd6);
        for (iVar3 = 0; iVar6 = sk_num(&certs->stack), iVar3 < iVar6; iVar3 = iVar3 + 1) {
          data = sk_value(&certs->stack,iVar3);
          p_Var5 = (_STACK *)brsp->certs;
          if (p_Var5 == (_STACK *)0x0) {
            p_Var5 = sk_new_null();
            brsp->certs = (stack_st_X509 *)p_Var5;
            if (p_Var5 == (_STACK *)0x0) goto LAB_0818677b;
          }
          iVar6 = sk_push(p_Var5,data);
          if (iVar6 == 0) goto LAB_0818677b;
          CRYPTO_add_lock((int *)((int)data + 0x10),1,3,"ocsp_srv.c",0xd6);
        }
        goto LAB_081865e1;
      }
    }
  }
  else {
LAB_081865e1:
    pOVar1 = brsp->tbsResponseData->responderId;
    if ((flags & 0x400) == 0) {
      name = X509_get_subject_name(signer);
      iVar3 = X509_NAME_set(&(pOVar1->value).byName,name);
      if (iVar3 != 0) {
        pOVar1->type = 0;
        goto LAB_08186669;
      }
    }
    else {
      type = EVP_sha1();
      X509_pubkey_digest(signer,type,local_34,(uint *)0x0);
      str = ASN1_OCTET_STRING_new();
      (pOVar1->value).byKey = str;
      if ((str != (ASN1_OCTET_STRING *)0x0) &&
         (iVar3 = ASN1_OCTET_STRING_set(str,local_34,0x14), iVar3 != 0)) {
        pOVar1->type = 1;
LAB_08186669:
        if (((flags & 0x800) != 0) ||
           (pAVar4 = X509_gmtime_adj(brsp->tbsResponseData->producedAt,0),
           pAVar4 != (ASN1_TIME *)0x0)) {
          iVar3 = ASN1_item_sign((ASN1_ITEM *)OCSP_RESPDATA_it,brsp->signatureAlgorithm,
                                 (X509_ALGOR *)0x0,brsp->signature,brsp->tbsResponseData,key,dgst);
          uVar2 = (uint)(iVar3 != 0);
          goto LAB_0818677d;
        }
      }
    }
  }
LAB_0818677b:
  uVar2 = 0;
LAB_0818677d:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar2;
}

