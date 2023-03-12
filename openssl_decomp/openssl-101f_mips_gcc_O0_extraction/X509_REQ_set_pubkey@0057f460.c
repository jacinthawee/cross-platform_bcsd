
int X509_REQ_set_pubkey(X509_REQ *x,EVP_PKEY *pkey)

{
  int iVar1;
  
  if ((x != (X509_REQ *)0x0) && (x->req_info != (X509_REQ_INFO *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0057f47c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (*(code *)PTR_X509_PUBKEY_set_006a9fe4)(&x->req_info->pubkey);
    return iVar1;
  }
  return 0;
}

