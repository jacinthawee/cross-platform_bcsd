
int PKCS7_add_recipient_info(PKCS7 *p7,PKCS7_RECIP_INFO *ri)

{
  int iVar1;
  stack_st_PKCS7_RECIP_INFO *psVar2;
  
  iVar1 = (*(code *)PTR_OBJ_obj2nid_006a822c)(p7->type);
  if (iVar1 == 0x17) {
    psVar2 = (stack_st_PKCS7_RECIP_INFO *)((p7->d).data)->type;
  }
  else {
    if (iVar1 != 0x18) {
      (*(code *)PTR_ERR_put_error_006a9030)(0x21,0x66,0x71,"pk7_lib.c",0x208);
      return 0;
    }
    psVar2 = ((p7->d).signed_and_enveloped)->recipientinfo;
  }
  iVar1 = (*(code *)PTR_sk_push_006a80a8)(psVar2,ri);
  return (uint)(iVar1 != 0);
}

