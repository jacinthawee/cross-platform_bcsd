
OCSP_SINGLERESP * OCSP_resp_get0(OCSP_BASICRESP *bs,int idx)

{
  OCSP_SINGLERESP *pOVar1;
  
  if (bs != (OCSP_BASICRESP *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x005ae024. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    pOVar1 = (OCSP_SINGLERESP *)(*(code *)PTR_sk_value_006a6e24)(bs->tbsResponseData->responses);
    return pOVar1;
  }
  return (OCSP_SINGLERESP *)0x0;
}

