
int SSL_set1_param(SSL *ssl,X509_VERIFY_PARAM *vpm)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x004a7104. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_X509_VERIFY_PARAM_set1_006a831c)(ssl->param);
  return iVar1;
}

