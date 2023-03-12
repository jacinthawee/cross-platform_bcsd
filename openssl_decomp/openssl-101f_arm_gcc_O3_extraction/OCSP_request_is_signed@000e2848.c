
int OCSP_request_is_signed(OCSP_REQUEST *req)

{
  OCSP_SIGNATURE *pOVar1;
  
  pOVar1 = req->optionalSignature;
  if (pOVar1 != (OCSP_SIGNATURE *)0x0) {
    pOVar1 = (OCSP_SIGNATURE *)0x1;
  }
  return (int)pOVar1;
}

