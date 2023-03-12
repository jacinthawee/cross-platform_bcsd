
int SSL_CTX_set_cipher_list(SSL_CTX *param_1,char *str)

{
  _STACK *p_Var1;
  int iVar2;
  
  iVar2 = 0;
  p_Var1 = (_STACK *)
           ssl_create_cipher_list
                     (param_1->method,&param_1->cipher_list,&param_1->cipher_list_by_id,str);
  if (p_Var1 != (_STACK *)0x0) {
    iVar2 = sk_num(p_Var1);
    if (iVar2 == 0) {
      ERR_put_error(0x14,0x10d,0xb9,"ssl_lib.c",0x522);
      return 0;
    }
    iVar2 = 1;
  }
  return iVar2;
}

