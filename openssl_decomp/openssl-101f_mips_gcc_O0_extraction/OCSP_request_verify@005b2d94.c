
int OCSP_request_verify(OCSP_REQUEST *req,stack_st_X509 *certs,X509_STORE *store,ulong flags)

{
  undefined *puVar1;
  GENERAL_NAME *pGVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined auStack_ac [136];
  int local_24;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_24 = *(int *)PTR___stack_chk_guard_006aabf0;
  if (req->optionalSignature == (OCSP_SIGNATURE *)0x0) {
    uVar6 = 0x80;
    uVar3 = 0x174;
  }
  else {
    pGVar2 = req->tbsRequest->requestorName;
    if ((pGVar2 != (GENERAL_NAME *)0x0) && (pGVar2->type == 4)) {
      if ((flags & 2) == 0) {
        iVar4 = (*(code *)PTR_X509_find_by_subject_006aa3c0)
                          (req->optionalSignature->certs,(pGVar2->d).ptr);
      }
      else {
        iVar4 = (*(code *)PTR_X509_find_by_subject_006aa3c0)(certs);
        if (iVar4 == 0) {
          uVar6 = 0x76;
          uVar3 = 0x181;
          goto LAB_005b2e14;
        }
        if ((flags & 0x200) != 0) {
          flags = flags | 0x10;
        }
      }
      if ((flags & 4) == 0) {
        uVar3 = (*(code *)PTR_X509_get_pubkey_006a8008)(iVar4);
        iVar5 = (*(code *)PTR_ASN1_item_verify_006a9e40)
                          (PTR_OCSP_REQINFO_it_006aa390,req->optionalSignature->signatureAlgorithm,
                           req->optionalSignature->signature,req->tbsRequest,uVar3);
        (*(code *)PTR_EVP_PKEY_free_006a7f78)(uVar3);
        if (iVar5 < 1) {
          uVar6 = 0x75;
          uVar3 = 0x18e;
          goto LAB_005b2e14;
        }
      }
      if ((flags & 0x10) == 0) {
        if ((flags & 8) == 0) {
          iVar4 = (*(code *)PTR_X509_STORE_CTX_init_006a8304)
                            (auStack_ac,store,iVar4,req->optionalSignature->certs);
        }
        else {
          iVar4 = (*(code *)PTR_X509_STORE_CTX_init_006a8304)(auStack_ac,store,iVar4,0);
        }
        if (iVar4 == 0) {
          uVar6 = 0xb;
          uVar3 = 0x19c;
          goto LAB_005b2e14;
        }
        (*(code *)PTR_X509_STORE_CTX_set_purpose_006aa284)(auStack_ac,8);
        (*(code *)PTR_X509_STORE_CTX_set_trust_006aa3c4)(auStack_ac,7);
        iVar4 = (*(code *)PTR_X509_verify_cert_006a8308)(auStack_ac);
        (*(code *)PTR_X509_STORE_CTX_cleanup_006a8310)(auStack_ac);
        if (iVar4 < 1) {
          uVar3 = (*(code *)PTR_X509_STORE_CTX_get_error_006a8314)(auStack_ac);
          (*(code *)PTR_ERR_put_error_006a9030)(0x27,0x74,0x65,"ocsp_vfy.c",0x1a7);
          uVar3 = (*(code *)PTR_X509_verify_cert_error_string_006a839c)(uVar3);
          (*(code *)PTR_ERR_add_error_data_006a9264)(2,"Verify error:",uVar3);
          iVar4 = 0;
          goto LAB_005b2e2c;
        }
      }
      iVar4 = 1;
      goto LAB_005b2e2c;
    }
    uVar6 = 0x81;
    uVar3 = 0x17a;
  }
LAB_005b2e14:
  (*(code *)PTR_ERR_put_error_006a9030)(0x27,0x74,uVar6,"ocsp_vfy.c",uVar3);
  iVar4 = 0;
LAB_005b2e2c:
  if (local_24 == *(int *)puVar1) {
    return iVar4;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  iVar4 = (*(code *)PTR_ERR_func_error_string_006a9560)(OCSP_str_functs._0_4_);
  if (iVar4 != 0) {
    return iVar4;
  }
  (*(code *)PTR_ERR_load_strings_006a9564)(0,OCSP_str_functs);
                    /* WARNING: Could not recover jumptable at 0x005b30f0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar4 = (*(code *)PTR_ERR_load_strings_006a9564)(0,OCSP_str_reasons);
  return iVar4;
}

