
int X509_REQ_set_version(X509_REQ *x,long version)

{
  int iVar1;
  
  if (x != (X509_REQ *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0057c644. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (*(code *)PTR_ASN1_INTEGER_set_006a7164)(x->req_info->version);
    return iVar1;
  }
  return 0;
}

