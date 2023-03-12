
int OCSP_BASICRESP_get_ext_count(OCSP_BASICRESP *x)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x005ae3d4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_X509v3_get_ext_count_006aa060)(x->tbsResponseData->responseExtensions);
  return iVar1;
}

