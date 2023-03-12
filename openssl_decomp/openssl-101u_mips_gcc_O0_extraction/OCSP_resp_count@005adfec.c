
int OCSP_resp_count(OCSP_BASICRESP *bs)

{
  int iVar1;
  
  if (bs != (OCSP_BASICRESP *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x005ae000. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (*(code *)PTR_sk_num_006a6e2c)(bs->tbsResponseData->responses);
    return iVar1;
  }
  return -1;
}

