
EVP_PKEY * X509_REQ_get_pubkey(X509_REQ *req)

{
  EVP_PKEY *pEVar1;
  
  if ((req != (X509_REQ *)0x0) && (req->req_info != (X509_REQ_INFO *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00576ae8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    pEVar1 = (EVP_PKEY *)(*(code *)PTR_X509_PUBKEY_get_006a8d64)(req->req_info->pubkey);
    return pEVar1;
  }
  return (EVP_PKEY *)0x0;
}

