
int X509V3_EXT_add_list(X509V3_EXT_METHOD *extlist)

{
  int iVar1;
  
  if (extlist->ext_nid == -1) {
    return 1;
  }
  while ((ext_list != (_STACK *)0x0 || (ext_list = sk_new(ext_cmp + 1), ext_list != (_STACK *)0x0)))
  {
    iVar1 = sk_push(ext_list,extlist);
    if (iVar1 == 0) {
      iVar1 = 0x50;
      goto LAB_000d0cc6;
    }
    extlist = extlist + 1;
    if (extlist->ext_nid == -1) {
      return 1;
    }
  }
  iVar1 = 0x4c;
LAB_000d0cc6:
  ERR_put_error(0x22,0x68,0x41,"v3_lib.c",iVar1);
  return 0;
}

