
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

SSL_SESSION * SSL_SESSION_new(void)

{
  undefined *puVar1;
  SSL_SESSION *obj;
  undefined4 uVar2;
  
  obj = (SSL_SESSION *)CRYPTO_malloc(0xf4,"ssl_sess.c",0xc0);
  if (obj == (SSL_SESSION *)0x0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0x14,0xbd,0x41,"ssl_sess.c",0xc3);
    obj = (SSL_SESSION *)0x0;
  }
  else {
    (*(code *)PTR_memset_006aab00)(obj,0,0xf4);
    *(undefined4 *)(obj->krb5_client_princ + 0x10) = 1;
    *(undefined4 *)(obj->krb5_client_princ + 0x14) = 1;
    puVar1 = PTR_time_006aabe4;
    *(undefined4 *)(obj->krb5_client_princ + 0x18) = 0x130;
    uVar2 = (*(code *)puVar1)(0);
    *(undefined4 *)(obj->krb5_client_princ + 0x1c) = uVar2;
    *(undefined4 *)(obj->krb5_client_princ + 0x38) = 0;
    *(undefined4 *)(obj->krb5_client_princ + 0x3c) = 0;
    *(undefined4 *)(obj->krb5_client_princ + 0x20) = 0;
    *(undefined4 *)(obj->krb5_client_princ + 0x40) = 0;
    *(undefined4 *)(obj->krb5_client_princ + 0x44) = 0;
    *(undefined4 *)(obj->krb5_client_princ + 0x48) = 0;
    *(undefined4 *)(obj->krb5_client_princ + 0x4c) = 0;
    *(undefined4 *)(obj->krb5_client_princ + 0x50) = 0;
    CRYPTO_new_ex_data(3,obj,(CRYPTO_EX_DATA *)(obj->krb5_client_princ + 0x30));
    obj->krb5_client_princ_len = 0;
    *(undefined4 *)obj->krb5_client_princ = 0;
    *(undefined4 *)(obj->krb5_client_princ + 0x60) = 0;
  }
  return obj;
}

