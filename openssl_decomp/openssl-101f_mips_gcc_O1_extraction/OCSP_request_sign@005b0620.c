
int OCSP_request_sign(OCSP_REQUEST *req,X509 *signer,EVP_PKEY *key,EVP_MD *dgst,stack_st_X509 *certs
                     ,ulong flags)

{
  undefined4 uVar1;
  GENERAL_NAME *pGVar2;
  int iVar3;
  OCSP_REQINFO *pOVar4;
  OCSP_SIGNATURE *pOVar5;
  int iVar6;
  int iVar7;
  stack_st_X509 *psVar8;
  OCSP_SIGNATURE *a;
  
  uVar1 = (*(code *)PTR_X509_get_subject_name_006a8000)(signer);
  pGVar2 = (GENERAL_NAME *)(*(code *)PTR_GENERAL_NAME_new_006aa150)();
  if (pGVar2 != (GENERAL_NAME *)0x0) {
    iVar3 = (*(code *)PTR_X509_NAME_set_006aa048)(&pGVar2->d,uVar1);
    if (iVar3 == 0) {
      (*(code *)PTR_GENERAL_NAME_free_006a84a4)(pGVar2);
    }
    else {
      pOVar4 = req->tbsRequest;
      pGVar2->type = 4;
      if (pOVar4->requestorName != (GENERAL_NAME *)0x0) {
        (*(code *)PTR_GENERAL_NAME_free_006a84a4)();
        pOVar4 = req->tbsRequest;
      }
      pOVar4->requestorName = pGVar2;
      pOVar5 = OCSP_SIGNATURE_new();
      req->optionalSignature = pOVar5;
      if (pOVar5 == (OCSP_SIGNATURE *)0x0) {
LAB_005b08fc:
        a = (OCSP_SIGNATURE *)0x0;
        goto LAB_005b0778;
      }
      if (key == (EVP_PKEY *)0x0) {
        if ((flags & 1) != 0) {
          return 1;
        }
      }
      else {
        iVar3 = (*(code *)PTR_X509_check_private_key_006a817c)(signer,key);
        if (iVar3 == 0) {
          (*(code *)PTR_ERR_put_error_006a9030)(0x27,0x6e,0x6e,"ocsp_cl.c",0xa2);
          a = req->optionalSignature;
          goto LAB_005b0778;
        }
        iVar3 = (*(code *)PTR_ASN1_item_sign_006aa0a4)
                          (PTR_OCSP_REQINFO_it_006aa390,req->optionalSignature->signatureAlgorithm,0
                           ,req->optionalSignature->signature,req->tbsRequest,key,dgst);
        if (iVar3 == 0) goto LAB_005b0774;
        if ((flags & 1) != 0) {
          return 1;
        }
        pOVar5 = req->optionalSignature;
        if (pOVar5 == (OCSP_SIGNATURE *)0x0) {
          pOVar5 = OCSP_SIGNATURE_new();
          a = (OCSP_SIGNATURE *)0x0;
          req->optionalSignature = pOVar5;
          if (pOVar5 == (OCSP_SIGNATURE *)0x0) goto LAB_005b0778;
        }
      }
      if (signer == (X509 *)0x0) {
LAB_005b0848:
        iVar3 = 0;
        do {
          iVar6 = (*(code *)PTR_sk_num_006a7f2c)(certs);
          if (iVar6 <= iVar3) {
            return 1;
          }
          iVar6 = (*(code *)PTR_sk_value_006a7f24)(certs,iVar3);
          pOVar5 = req->optionalSignature;
          if (pOVar5 == (OCSP_SIGNATURE *)0x0) {
            pOVar5 = OCSP_SIGNATURE_new();
            req->optionalSignature = pOVar5;
            if (pOVar5 == (OCSP_SIGNATURE *)0x0) goto LAB_005b08fc;
          }
          if (iVar6 != 0) {
            psVar8 = pOVar5->certs;
            if (psVar8 == (stack_st_X509 *)0x0) {
              psVar8 = (stack_st_X509 *)(*(code *)PTR_sk_new_null_006a80a4)();
              pOVar5->certs = psVar8;
              if (psVar8 == (stack_st_X509 *)0x0) {
                a = req->optionalSignature;
                goto LAB_005b0778;
              }
            }
            iVar7 = (*(code *)PTR_sk_push_006a80a8)(psVar8,iVar6);
            if (iVar7 == 0) goto LAB_005b0774;
            (*(code *)PTR_CRYPTO_add_lock_006a9080)(iVar6 + 0x10,1,3,"ocsp_cl.c",0x85);
          }
          iVar3 = iVar3 + 1;
        } while( true );
      }
      psVar8 = pOVar5->certs;
      if (psVar8 == (stack_st_X509 *)0x0) {
        psVar8 = (stack_st_X509 *)(*(code *)PTR_sk_new_null_006a80a4)();
        pOVar5->certs = psVar8;
        if (psVar8 == (stack_st_X509 *)0x0) {
          a = req->optionalSignature;
          goto LAB_005b0778;
        }
      }
      iVar3 = (*(code *)PTR_sk_push_006a80a8)(psVar8,signer);
      if (iVar3 != 0) {
        (*(code *)PTR_CRYPTO_add_lock_006a9080)(&signer->references,1,3,"ocsp_cl.c",0x85);
        goto LAB_005b0848;
      }
    }
  }
LAB_005b0774:
  a = req->optionalSignature;
LAB_005b0778:
  OCSP_SIGNATURE_free(a);
  req->optionalSignature = (OCSP_SIGNATURE *)0x0;
  return 0;
}

