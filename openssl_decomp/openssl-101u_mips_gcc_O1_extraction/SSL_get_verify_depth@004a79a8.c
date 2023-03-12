
int SSL_get_verify_depth(SSL *s)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x004a79b4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_X509_VERIFY_PARAM_get_depth_006a832c)(s->param);
  return iVar1;
}

