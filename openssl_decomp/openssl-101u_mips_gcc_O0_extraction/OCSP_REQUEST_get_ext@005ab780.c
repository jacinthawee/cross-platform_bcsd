
X509_EXTENSION * OCSP_REQUEST_get_ext(OCSP_REQUEST *x,int loc)

{
  X509_EXTENSION *pXVar1;
  
                    /* WARNING: Could not recover jumptable at 0x005ab790. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pXVar1 = (X509_EXTENSION *)
           (*(code *)PTR_X509v3_get_ext_006a8f54)(x->tbsRequest->requestExtensions);
  return pXVar1;
}

