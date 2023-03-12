
int X509V3_EXT_add(X509V3_EXT_METHOD *ext)

{
  int iVar1;
  
  if ((ext_list == 0) && (ext_list = (*(code *)PTR_sk_new_006a91b4)(ext_cmp), ext_list == 0)) {
    (*(code *)PTR_ERR_put_error_006a9030)(0x22,0x68,0x41,"v3_lib.c",0x4c);
    return 0;
  }
  iVar1 = (*(code *)PTR_sk_push_006a80a8)(ext_list,ext);
  if (iVar1 != 0) {
    return 1;
  }
  (*(code *)PTR_ERR_put_error_006a9030)(0x22,0x68,0x41,"v3_lib.c",0x50);
  return 0;
}

