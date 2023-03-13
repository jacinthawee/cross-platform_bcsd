
int X509V3_EXT_add(X509V3_EXT_METHOD *ext)

{
  int iVar1;
  
  if ((ext_list == 0) && (ext_list = (*(code *)PTR_sk_new_006a806c)(ext_cmp), ext_list == 0)) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0x68,0x41,"v3_lib.c",0x4d);
    return 0;
  }
  iVar1 = (*(code *)PTR_sk_push_006a6fa8)(ext_list,ext);
  if (iVar1 != 0) {
    return 1;
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0x68,0x41,"v3_lib.c",0x51);
  return 0;
}

