
int X509V3_EXT_add_list(X509V3_EXT_METHOD *extlist)

{
  int iVar1;
  
  iVar1 = extlist->ext_nid;
  while( true ) {
    if (iVar1 == -1) {
      return 1;
    }
    if ((ext_list == (_STACK *)0x0) && (ext_list = sk_new(ext_cmp), ext_list == (_STACK *)0x0))
    break;
    iVar1 = sk_push(ext_list,extlist);
    if (iVar1 == 0) {
      iVar1 = 0x51;
      goto LAB_08168aa7;
    }
    extlist = extlist + 1;
    iVar1 = extlist->ext_nid;
  }
  iVar1 = 0x4d;
LAB_08168aa7:
  ERR_put_error(0x22,0x68,0x41,"v3_lib.c",iVar1);
  return 0;
}

