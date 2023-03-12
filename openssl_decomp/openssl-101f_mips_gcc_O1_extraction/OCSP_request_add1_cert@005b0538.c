
int OCSP_request_add1_cert(OCSP_REQUEST *req,X509 *cert)

{
  int iVar1;
  stack_st_X509 *psVar2;
  OCSP_SIGNATURE *pOVar3;
  
  pOVar3 = req->optionalSignature;
  if (pOVar3 == (OCSP_SIGNATURE *)0x0) {
    pOVar3 = OCSP_SIGNATURE_new();
    req->optionalSignature = pOVar3;
    if (pOVar3 == (OCSP_SIGNATURE *)0x0) {
      return 0;
    }
  }
  if (cert == (X509 *)0x0) {
    return 1;
  }
  psVar2 = pOVar3->certs;
  if (psVar2 == (stack_st_X509 *)0x0) {
    psVar2 = (stack_st_X509 *)(*(code *)PTR_sk_new_null_006a80a4)();
    pOVar3->certs = psVar2;
    if (psVar2 == (stack_st_X509 *)0x0) {
      return 0;
    }
  }
  iVar1 = (*(code *)PTR_sk_push_006a80a8)(psVar2,cert);
  if (iVar1 == 0) {
    return 0;
  }
  (*(code *)PTR_CRYPTO_add_lock_006a9080)(&cert->references,1,3,"ocsp_cl.c",0x85);
  return 1;
}

