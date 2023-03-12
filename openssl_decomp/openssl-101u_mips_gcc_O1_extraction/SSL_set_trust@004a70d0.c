
int SSL_set_trust(SSL *s,int trust)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x004a70dc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_X509_VERIFY_PARAM_set_trust_006a8318)(s->param);
  return iVar1;
}

