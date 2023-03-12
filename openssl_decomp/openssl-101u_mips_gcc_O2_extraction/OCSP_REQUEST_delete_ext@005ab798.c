
X509_EXTENSION * OCSP_REQUEST_delete_ext(OCSP_REQUEST *x,int loc)

{
  X509_EXTENSION *pXVar1;
  
                    /* WARNING: Could not recover jumptable at 0x005ab7a8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pXVar1 = (X509_EXTENSION *)
           (*(code *)PTR_X509v3_delete_ext_006a8f58)(x->tbsRequest->requestExtensions);
  return pXVar1;
}

