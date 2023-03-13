
int OCSP_request_sign(OCSP_REQUEST *req,X509 *signer,EVP_PKEY *key,EVP_MD *dgst,stack_st_X509 *certs
                     ,ulong flags)

{
  X509_NAME *name;
  GENERAL_NAME *a;
  int iVar1;
  OCSP_REQINFO *pOVar2;
  OCSP_SIGNATURE *pOVar3;
  int iVar4;
  void *data;
  _STACK *p_Var5;
  
  name = X509_get_subject_name(signer);
  a = GENERAL_NAME_new();
  if (a != (GENERAL_NAME *)0x0) {
    iVar1 = X509_NAME_set(&(a->d).directoryName,name);
    if (iVar1 == 0) {
      GENERAL_NAME_free(a);
    }
    else {
      pOVar2 = req->tbsRequest;
      a->type = 4;
      if (pOVar2->requestorName != (GENERAL_NAME *)0x0) {
        GENERAL_NAME_free(pOVar2->requestorName);
        pOVar2 = req->tbsRequest;
      }
      pOVar2->requestorName = a;
      pOVar3 = OCSP_SIGNATURE_new();
      req->optionalSignature = pOVar3;
      if (pOVar3 == (OCSP_SIGNATURE *)0x0) {
LAB_08185bc0:
        pOVar3 = (OCSP_SIGNATURE *)0x0;
        goto LAB_08185bd7;
      }
      if (key == (EVP_PKEY *)0x0) {
        if ((flags & 1) != 0) {
          return 1;
        }
      }
      else {
        iVar1 = X509_check_private_key(signer,key);
        if (iVar1 == 0) {
          ERR_put_error(0x27,0x6e,0x6e,"ocsp_cl.c",0xa8);
          pOVar3 = req->optionalSignature;
          goto LAB_08185bd7;
        }
        iVar1 = ASN1_item_sign((ASN1_ITEM *)OCSP_REQINFO_it,
                               req->optionalSignature->signatureAlgorithm,(X509_ALGOR *)0x0,
                               req->optionalSignature->signature,req->tbsRequest,key,dgst);
        if (iVar1 == 0) goto LAB_08185bd4;
        if ((flags & 1) != 0) {
          return 1;
        }
        pOVar3 = req->optionalSignature;
        if (pOVar3 == (OCSP_SIGNATURE *)0x0) {
          pOVar3 = OCSP_SIGNATURE_new();
          req->optionalSignature = pOVar3;
          if (pOVar3 == (OCSP_SIGNATURE *)0x0) goto LAB_08185bc0;
        }
      }
      if (signer == (X509 *)0x0) goto LAB_08185c7b;
      p_Var5 = (_STACK *)pOVar3->certs;
      if (p_Var5 == (_STACK *)0x0) {
        p_Var5 = sk_new_null();
        pOVar3->certs = (stack_st_X509 *)p_Var5;
        if (p_Var5 == (_STACK *)0x0) goto LAB_08185bd4;
      }
      iVar1 = sk_push(p_Var5,signer);
      if (iVar1 != 0) {
        CRYPTO_add_lock(&signer->references,1,3,"ocsp_cl.c",0x8c);
LAB_08185c7b:
        iVar1 = 0;
        do {
          iVar4 = sk_num(&certs->stack);
          if (iVar4 <= iVar1) {
            return 1;
          }
          data = sk_value(&certs->stack,iVar1);
          pOVar3 = req->optionalSignature;
          if (pOVar3 == (OCSP_SIGNATURE *)0x0) {
            pOVar3 = OCSP_SIGNATURE_new();
            req->optionalSignature = pOVar3;
            if (pOVar3 == (OCSP_SIGNATURE *)0x0) {
              pOVar3 = (OCSP_SIGNATURE *)0x0;
              goto LAB_08185bd7;
            }
          }
          if (data != (void *)0x0) {
            p_Var5 = (_STACK *)pOVar3->certs;
            if (p_Var5 == (_STACK *)0x0) {
              p_Var5 = sk_new_null();
              pOVar3->certs = (stack_st_X509 *)p_Var5;
              if (p_Var5 == (_STACK *)0x0) break;
            }
            iVar4 = sk_push(p_Var5,data);
            if (iVar4 == 0) break;
            CRYPTO_add_lock((int *)((int)data + 0x10),1,3,"ocsp_cl.c",0x8c);
          }
          iVar1 = iVar1 + 1;
        } while( true );
      }
    }
  }
LAB_08185bd4:
  pOVar3 = req->optionalSignature;
LAB_08185bd7:
  OCSP_SIGNATURE_free(pOVar3);
  req->optionalSignature = (OCSP_SIGNATURE *)0x0;
  return 0;
}

