
OCSP_CERTID * OCSP_onereq_get0_id(OCSP_ONEREQ *one)

{
  return one->reqCert;
}

