
int SSL_set_purpose(SSL *s,int purpose)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x004a70b4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_X509_VERIFY_PARAM_set_purpose_006a7c0c)(s->param);
  return iVar1;
}

