
int SSL_CTX_set_purpose(SSL_CTX *s,int purpose)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x004a9e98. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_X509_VERIFY_PARAM_set_purpose_006a8cf8)(s->param);
  return iVar1;
}

