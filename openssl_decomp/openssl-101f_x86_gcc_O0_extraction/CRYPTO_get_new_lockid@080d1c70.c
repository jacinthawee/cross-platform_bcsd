
int CRYPTO_get_new_lockid(char *name)

{
  char *data;
  int iVar1;
  
  if (app_locks == (_STACK *)0x0) {
    app_locks = sk_new_null();
    if (app_locks == (_STACK *)0x0) {
      iVar1 = 0xd7;
      goto LAB_080d1cf8;
    }
  }
  data = BUF_strdup(name);
  if (data != (char *)0x0) {
    iVar1 = sk_push(app_locks,data);
    if (iVar1 != 0) {
      return iVar1 + 0x29;
    }
    CRYPTO_free(data);
    return 0;
  }
  iVar1 = 0xdc;
LAB_080d1cf8:
  ERR_put_error(0xf,0x65,0x41,"cryptlib.c",iVar1);
  return 0;
}

