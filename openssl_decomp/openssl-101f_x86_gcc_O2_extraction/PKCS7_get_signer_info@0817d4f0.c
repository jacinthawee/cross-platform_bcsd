
stack_st_PKCS7_SIGNER_INFO * PKCS7_get_signer_info(PKCS7 *p7)

{
  int iVar1;
  
  iVar1 = OBJ_obj2nid(p7->type);
  if ((iVar1 != 0x16) && (iVar1 = OBJ_obj2nid(p7->type), iVar1 != 0x18)) {
    return (stack_st_PKCS7_SIGNER_INFO *)0x0;
  }
  return ((p7->d).sign)->signer_info;
}

