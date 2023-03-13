
int ssl_do_client_cert_cb(SSL *param_1,X509 **param_2,EVP_PKEY **param_3)

{
  stack_st_X509_NAME *ca_dn;
  int iVar1;
  _func_3154 *p_Var2;
  
  p_Var2 = param_1->psk_server_callback;
  if (*(int *)(p_Var2 + 0xfc) != 0) {
    ca_dn = SSL_get_client_CA_list(param_1);
    iVar1 = ENGINE_load_ssl_client_cert
                      (*(ENGINE **)(param_1->psk_server_callback + 0xfc),param_1,ca_dn,param_2,
                       param_3,(stack_st_X509 **)0x0,(UI_METHOD *)0x0,(void *)0x0);
    if (iVar1 != 0) {
      return iVar1;
    }
    p_Var2 = param_1->psk_server_callback;
  }
  if (*(code **)(p_Var2 + 0x74) == (code *)0x0) {
    return 0;
  }
                    /* WARNING: Could not recover jumptable at 0x0809f9b6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (**(code **)(p_Var2 + 0x74))();
  return iVar1;
}

