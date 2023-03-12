
int X509V3_EXT_add_list(X509V3_EXT_METHOD *extlist)

{
  int iVar1;
  undefined4 uVar2;
  X509V3_EXT_METHOD *pXVar3;
  
  if (extlist->ext_nid == -1) {
    return 1;
  }
  while ((ext_list != 0 || (ext_list = (*(code *)PTR_sk_new_006a806c)(ext_cmp), ext_list != 0))) {
    pXVar3 = extlist + 1;
    iVar1 = (*(code *)PTR_sk_push_006a6fa8)(ext_list,extlist);
    if (iVar1 == 0) {
      uVar2 = 0x51;
      goto LAB_00587bcc;
    }
    extlist = pXVar3;
    if (pXVar3->ext_nid == -1) {
      return 1;
    }
  }
  uVar2 = 0x4d;
LAB_00587bcc:
  (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0x68,0x41,"v3_lib.c",uVar2);
  return 0;
}

