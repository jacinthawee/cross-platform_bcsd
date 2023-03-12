
int OCSP_request_verify(OCSP_REQUEST *req,stack_st_X509 *certs,X509_STORE *store,ulong flags)

{
  undefined *puVar1;
  GENERAL_NAME *pGVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  char *pcVar7;
  undefined auStack_ac [136];
  int local_24;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_24 = *(int *)PTR___stack_chk_guard_006a9ae8;
  if (req->optionalSignature == (OCSP_SIGNATURE *)0x0) {
    uVar6 = 0x80;
    uVar3 = 0x17b;
  }
  else {
    pGVar2 = req->tbsRequest->requestorName;
    if ((pGVar2 != (GENERAL_NAME *)0x0) && (pGVar2->type == 4)) {
      pcVar7 = (pGVar2->d).ptr;
      if (((flags & 2) != 0) ||
         (iVar4 = (*(code *)PTR_X509_find_by_subject_006a92b4)(req->optionalSignature->certs,pcVar7)
         , iVar4 == 0)) {
        iVar4 = (*(code *)PTR_X509_find_by_subject_006a92b4)(certs,pcVar7);
        if (iVar4 == 0) {
          uVar6 = 0x76;
          uVar3 = 0x188;
          goto LAB_005b04a0;
        }
        if ((flags & 0x200) != 0) {
          flags = flags | 0x10;
        }
      }
      if ((flags & 4) == 0) {
        uVar3 = (*(code *)PTR_X509_get_pubkey_006a6f08)(iVar4);
        iVar5 = (*(code *)PTR_ASN1_item_verify_006a8d20)
                          (PTR_OCSP_REQINFO_it_006a9284,req->optionalSignature->signatureAlgorithm,
                           req->optionalSignature->signature,req->tbsRequest,uVar3);
        (*(code *)PTR_EVP_PKEY_free_006a6e78)(uVar3);
        if (iVar5 < 1) {
          uVar6 = 0x75;
          uVar3 = 0x193;
          goto LAB_005b04a0;
        }
      }
      if ((flags & 0x10) == 0) {
        if ((flags & 8) == 0) {
          iVar4 = (*(code *)PTR_X509_STORE_CTX_init_006a7270)
                            (auStack_ac,store,iVar4,req->optionalSignature->certs);
        }
        else {
          iVar4 = (*(code *)PTR_X509_STORE_CTX_init_006a7270)(auStack_ac,store,iVar4,0);
        }
        if (iVar4 == 0) {
          uVar6 = 0xb;
          uVar3 = 0x19f;
          goto LAB_005b04a0;
        }
        (*(code *)PTR_X509_STORE_CTX_set_purpose_006a9168)(auStack_ac,8);
        (*(code *)PTR_X509_STORE_CTX_set_trust_006a92b8)(auStack_ac,7);
        iVar4 = (*(code *)PTR_X509_verify_cert_006a728c)(auStack_ac);
        (*(code *)PTR_X509_STORE_CTX_cleanup_006a7294)(auStack_ac);
        if (iVar4 < 1) {
          uVar3 = (*(code *)PTR_X509_STORE_CTX_get_error_006a729c)(auStack_ac);
          (*(code *)PTR_ERR_put_error_006a7f34)(0x27,0x74,0x65,"ocsp_vfy.c",0x1aa);
          uVar3 = (*(code *)PTR_X509_verify_cert_error_string_006a72a0)(uVar3);
          (*(code *)PTR_ERR_add_error_data_006a813c)(2,"Verify error:",uVar3);
          iVar4 = 0;
          goto LAB_005b04b8;
        }
      }
      iVar4 = 1;
      goto LAB_005b04b8;
    }
    uVar6 = 0x81;
    uVar3 = 0x181;
  }
LAB_005b04a0:
  (*(code *)PTR_ERR_put_error_006a7f34)(0x27,0x74,uVar6,"ocsp_vfy.c",uVar3);
  iVar4 = 0;
LAB_005b04b8:
  if (local_24 == *(int *)puVar1) {
    return iVar4;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  iVar4 = (*(code *)PTR_ERR_func_error_string_006a8440)(OCSP_str_functs._0_4_);
  if (iVar4 == 0) {
    (*(code *)PTR_ERR_load_strings_006a8444)(0,OCSP_str_functs);
                    /* WARNING: Could not recover jumptable at 0x005b07a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar4 = (*(code *)PTR_ERR_load_strings_006a8444)(0,OCSP_str_reasons);
    return iVar4;
  }
  return iVar4;
}

