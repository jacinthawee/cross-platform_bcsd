
int SSL_set1_param(SSL *ssl,X509_VERIFY_PARAM *vpm)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x004a9efc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_X509_VERIFY_PARAM_set1_006a9438)(ssl->param);
  return iVar1;
}

