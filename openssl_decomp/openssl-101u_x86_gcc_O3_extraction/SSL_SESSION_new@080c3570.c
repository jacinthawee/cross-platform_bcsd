
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

SSL_SESSION * SSL_SESSION_new(void)

{
  SSL_SESSION *obj;
  time_t tVar1;
  uint uVar2;
  undefined4 *puVar3;
  byte bVar4;
  
  bVar4 = 0;
  obj = (SSL_SESSION *)CRYPTO_malloc(0xf4,"ssl_sess.c",0xc4);
  if (obj == (SSL_SESSION *)0x0) {
    ERR_put_error(0x14,0xbd,0x41,"ssl_sess.c",0xc6);
    obj = (SSL_SESSION *)0x0;
  }
  else {
    obj->ssl_version = 0;
    *(undefined4 *)(obj->krb5_client_princ + 0x60) = 0;
    puVar3 = (undefined4 *)((uint)&obj->key_arg_length & 0xfffffffc);
    uVar2 = (uint)((int)obj + (0xf4 - (int)puVar3)) >> 2;
    for (; uVar2 != 0; uVar2 = uVar2 - 1) {
      *puVar3 = 0;
      puVar3 = puVar3 + (uint)bVar4 * -2 + 1;
    }
    *(undefined4 *)(obj->krb5_client_princ + 0x10) = 1;
    *(undefined4 *)(obj->krb5_client_princ + 0x14) = 1;
    *(undefined4 *)(obj->krb5_client_princ + 0x18) = 0x130;
    tVar1 = time((time_t *)0x0);
    *(time_t *)(obj->krb5_client_princ + 0x1c) = tVar1;
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

