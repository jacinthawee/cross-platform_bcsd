
int SSL_CTX_set_trust(SSL_CTX *s,int trust)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x004a70c8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_X509_VERIFY_PARAM_set_trust_006a8318)(s->param);
  return iVar1;
}

