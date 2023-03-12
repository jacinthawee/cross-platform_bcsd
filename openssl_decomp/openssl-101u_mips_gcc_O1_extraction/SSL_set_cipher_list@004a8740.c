
int SSL_set_cipher_list(SSL *s,char *str)

{
  int iVar1;
  
  iVar1 = ssl_create_cipher_list
                    (*(undefined4 *)s->psk_server_callback,&s->cipher_list,&s->cipher_list_by_id,str
                    );
  if (iVar1 == 0) {
    return 0;
  }
  iVar1 = (*(code *)PTR_sk_num_006a6e2c)(iVar1);
  if (iVar1 != 0) {
    return 1;
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x10f,0xb9,"ssl_lib.c",0x51f);
  return 0;
}

