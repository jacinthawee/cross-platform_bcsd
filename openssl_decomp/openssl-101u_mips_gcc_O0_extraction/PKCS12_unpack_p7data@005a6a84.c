
stack_st_PKCS12_SAFEBAG * PKCS12_unpack_p7data(PKCS7 *p7)

{
  int iVar1;
  stack_st_PKCS12_SAFEBAG *psVar2;
  
  iVar1 = (*(code *)PTR_OBJ_obj2nid_006a712c)(p7->type);
  if (iVar1 == 0x15) {
                    /* WARNING: Could not recover jumptable at 0x005a6acc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    psVar2 = (stack_st_PKCS12_SAFEBAG *)
             (*(code *)PTR_ASN1_item_unpack_006a91d8)((p7->d).ptr,PTR_PKCS12_SAFEBAGS_it_006a91d4);
    return psVar2;
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(0x23,0x83,0x79,"p12_add.c",0xab);
  return (stack_st_PKCS12_SAFEBAG *)0x0;
}

