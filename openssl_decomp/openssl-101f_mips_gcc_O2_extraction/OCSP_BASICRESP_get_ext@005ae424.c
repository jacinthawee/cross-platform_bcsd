
X509_EXTENSION * OCSP_BASICRESP_get_ext(OCSP_BASICRESP *x,int loc)

{
  X509_EXTENSION *pXVar1;
  
                    /* WARNING: Could not recover jumptable at 0x005ae434. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pXVar1 = (X509_EXTENSION *)
           (*(code *)PTR_X509v3_get_ext_006aa070)(x->tbsResponseData->responseExtensions);
  return pXVar1;
}

