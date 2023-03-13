
int X509V3_EXT_add(X509V3_EXT_METHOD *ext)

{
  int iVar1;
  
  if ((ext_list == (_STACK *)0x0) && (ext_list = sk_new(ext_cmp), ext_list == (_STACK *)0x0)) {
    ERR_put_error(0x22,0x68,0x41,"v3_lib.c",0x4d);
    return 0;
  }
  iVar1 = sk_push(ext_list,ext);
  if (iVar1 != 0) {
    return 1;
  }
  ERR_put_error(0x22,0x68,0x41,"v3_lib.c",0x51);
  return 0;
}

