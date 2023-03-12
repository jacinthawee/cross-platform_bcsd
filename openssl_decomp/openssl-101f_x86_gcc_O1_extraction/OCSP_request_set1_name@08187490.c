
int OCSP_request_set1_name(OCSP_REQUEST *req,X509_NAME *nm)

{
  GENERAL_NAME *a;
  int iVar1;
  OCSP_REQINFO *pOVar2;
  
  a = GENERAL_NAME_new();
  iVar1 = 0;
  if (a != (GENERAL_NAME *)0x0) {
    iVar1 = X509_NAME_set(&(a->d).directoryName,nm);
    if (iVar1 == 0) {
      GENERAL_NAME_free(a);
      return 0;
    }
    pOVar2 = req->tbsRequest;
    a->type = 4;
    if (pOVar2->requestorName != (GENERAL_NAME *)0x0) {
      GENERAL_NAME_free(pOVar2->requestorName);
      pOVar2 = req->tbsRequest;
    }
    pOVar2->requestorName = a;
    iVar1 = 1;
  }
  return iVar1;
}

