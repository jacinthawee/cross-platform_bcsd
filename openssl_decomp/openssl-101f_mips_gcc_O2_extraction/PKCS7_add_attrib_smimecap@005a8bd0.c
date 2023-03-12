
int PKCS7_add_attrib_smimecap(PKCS7_SIGNER_INFO *si,stack_st_X509_ALGOR *cap)

{
  undefined4 *data;
  undefined4 uVar1;
  int iVar2;
  
  data = (undefined4 *)(*(code *)PTR_ASN1_STRING_new_006a98b4)();
  if (data != (undefined4 *)0x0) {
    uVar1 = (*(code *)PTR_ASN1_item_i2d_006a979c)(cap,data + 2,PTR_X509_ALGORS_it_006aa2c8);
    *data = uVar1;
    iVar2 = PKCS7_add_signed_attribute(si,0xa7,0x10,data);
    return iVar2;
  }
  (*(code *)PTR_ERR_put_error_006a9030)(0x21,0x76,0x41,"pk7_attr.c",0x49);
  return 0;
}

