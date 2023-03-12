
int OCSP_response_status(OCSP_RESPONSE *resp)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x005b0980. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_ASN1_ENUMERATED_get_006a9e4c)(resp->responseStatus);
  return iVar1;
}

