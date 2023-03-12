
int OCSP_request_is_signed(OCSP_REQUEST *req)

{
  return (uint)(req->optionalSignature != (OCSP_SIGNATURE *)0x0);
}

