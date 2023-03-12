
int OCSP_REQUEST_get_ext_by_NID(OCSP_REQUEST *x,int nid,int lastpos)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x005ae228. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_X509v3_get_ext_by_NID_006aa064)(x->tbsRequest->requestExtensions);
  return iVar1;
}

