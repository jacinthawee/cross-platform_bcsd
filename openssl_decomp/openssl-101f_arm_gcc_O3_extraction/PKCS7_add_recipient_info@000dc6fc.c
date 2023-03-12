
int PKCS7_add_recipient_info(PKCS7 *p7,PKCS7_RECIP_INFO *ri)

{
  int iVar1;
  _STACK *st;
  
  iVar1 = OBJ_obj2nid(p7->type);
  if (iVar1 == 0x17) {
    st = (_STACK *)((p7->d).sign)->md_algs;
  }
  else {
    if (iVar1 != 0x18) {
      ERR_put_error(0x21,0x66,0x71,"pk7_lib.c",0x208);
      return 0;
    }
    st = (_STACK *)((p7->d).signed_and_enveloped)->recipientinfo;
  }
  iVar1 = sk_push(st,ri);
  if (iVar1 != 0) {
    iVar1 = 1;
  }
  return iVar1;
}

