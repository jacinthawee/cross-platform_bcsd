
stack_st_PKCS7 * PKCS12_unpack_authsafes(PKCS12 *p12)

{
  int iVar1;
  stack_st_PKCS7 *psVar2;
  
  iVar1 = OBJ_obj2nid(p12->authsafes->type);
  if (iVar1 == 0x15) {
    psVar2 = (stack_st_PKCS7 *)
             ASN1_item_unpack((p12->authsafes->d).data,(ASN1_ITEM *)PKCS12_AUTHSAFES_it);
    return psVar2;
  }
  ERR_put_error(0x23,0x82,0x79,"p12_add.c",0xfd);
  return (stack_st_PKCS7 *)0x0;
}

