
int CRYPTO_get_new_lockid(char *name)

{
  _STACK *data;
  int iVar1;
  
  if (app_locks == (_STACK *)0x0) {
    data = sk_new_null();
    iVar1 = 0xd7;
    app_locks = data;
    if (data == (_STACK *)0x0) goto LAB_0006b960;
  }
  data = (_STACK *)BUF_strdup(name);
  if (data != (_STACK *)0x0) {
    iVar1 = sk_push(app_locks,data);
    if (iVar1 != 0) {
      return iVar1 + 0x29;
    }
    CRYPTO_free(data);
    return 0;
  }
  iVar1 = 0xdc;
LAB_0006b960:
  ERR_put_error(0xf,0x65,0x41,"cryptlib.c",iVar1);
  return (int)data;
}

