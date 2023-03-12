
int cert_load(BIO *param_1,_STACK *param_2)

{
  X509 *data;
  int iVar1;
  
  iVar1 = 0;
  while( true ) {
    data = PEM_read_bio_X509(param_1,(X509 **)0x0,(undefined1 *)0x0,(void *)0x0);
    if (data == (X509 *)0x0) break;
    iVar1 = 1;
    sk_push(param_2,data);
  }
  if (iVar1 != 0) {
    ERR_clear_error();
  }
  return iVar1;
}

