
int OCSP_BASICRESP_get_ext_by_NID(OCSP_BASICRESP *x,int nid,int lastpos)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x005ab90c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_X509v3_get_ext_by_NID_006a8f48)(x->tbsResponseData->responseExtensions);
  return iVar1;
}
