
int OCSP_request_set1_name(OCSP_REQUEST *req,X509_NAME *nm)

{
  GENERAL_NAME *pGVar1;
  int iVar2;
  OCSP_REQINFO *pOVar3;
  
  pGVar1 = (GENERAL_NAME *)(*(code *)PTR_GENERAL_NAME_new_006aa150)();
  if (pGVar1 == (GENERAL_NAME *)0x0) {
    return 0;
  }
  iVar2 = (*(code *)PTR_X509_NAME_set_006aa048)(&pGVar1->d,nm);
  if (iVar2 != 0) {
    pOVar3 = req->tbsRequest;
    pGVar1->type = 4;
    if (pOVar3->requestorName != (GENERAL_NAME *)0x0) {
      (*(code *)PTR_GENERAL_NAME_free_006a84a4)();
      pOVar3 = req->tbsRequest;
    }
    pOVar3->requestorName = pGVar1;
    return 1;
  }
  (*(code *)PTR_GENERAL_NAME_free_006a84a4)(pGVar1);
  return 0;
}

