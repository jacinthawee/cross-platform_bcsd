
stack_st_PKCS7 * PKCS12_unpack_authsafes(PKCS12 *p12)

{
  int iVar1;
  stack_st_PKCS7 *psVar2;
  
  iVar1 = (*(code *)PTR_OBJ_obj2nid_006a712c)(p12->authsafes->type);
  if (iVar1 == 0x15) {
                    /* WARNING: Could not recover jumptable at 0x005a6e74. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    psVar2 = (stack_st_PKCS7 *)
             (*(code *)PTR_ASN1_item_unpack_006a91d8)
                       ((p12->authsafes->d).ptr,PTR_PKCS12_AUTHSAFES_it_006a91ec);
    return psVar2;
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(0x23,0x82,0x79,"p12_add.c",0xfd);
  return (stack_st_PKCS7 *)0x0;
}

