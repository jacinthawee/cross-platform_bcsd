
PKCS7_ISSUER_AND_SERIAL * PKCS7_get_issuer_and_serial(PKCS7 *p7,int idx)

{
  _STACK *p_Var1;
  int iVar2;
  void *pvVar3;
  
  iVar2 = OBJ_obj2nid(p7->type);
  if (((iVar2 == 0x18) && ((p7->d).signed_and_enveloped != (PKCS7_SIGN_ENVELOPE *)0x0)) &&
     (p_Var1 = (_STACK *)((p7->d).signed_and_enveloped)->recipientinfo, p_Var1 != (_STACK *)0x0)) {
    sk_value(p_Var1,0);
    iVar2 = sk_num(p_Var1);
    if (idx < iVar2) {
      pvVar3 = sk_value(p_Var1,idx);
      return *(PKCS7_ISSUER_AND_SERIAL **)((int)pvVar3 + 4);
    }
  }
  return (PKCS7_ISSUER_AND_SERIAL *)0x0;
}

