
int CMS_add0_crl(CMS_ContentInfo *cms,X509_CRL *crl)

{
  int iVar1;
  undefined4 *val;
  _STACK *p_Var2;
  _STACK **pp_Var3;
  
  iVar1 = OBJ_obj2nid(*(ASN1_OBJECT **)cms);
  if (iVar1 == 0x16) {
    pp_Var3 = (_STACK **)(*(int *)(cms + 4) + 0x10);
  }
  else {
    if (iVar1 != 0x17) {
      ERR_put_error(0x2e,0x84,0x98,"cms_lib.c",0x201);
      return 0;
    }
    pp_Var3 = (_STACK **)(*(int *)(*(int *)(cms + 4) + 4) + 4);
  }
  if (pp_Var3 != (_STACK **)0x0) {
    if (*pp_Var3 == (_STACK *)0x0) {
      p_Var2 = sk_new_null();
      *pp_Var3 = p_Var2;
      if (p_Var2 == (_STACK *)0x0) {
        return 0;
      }
    }
    val = (undefined4 *)ASN1_item_new((ASN1_ITEM *)CMS_RevocationInfoChoice_it);
    if (val != (undefined4 *)0x0) {
      iVar1 = sk_push(*pp_Var3,val);
      if (iVar1 != 0) {
        *val = 0;
        val[1] = crl;
        return 1;
      }
      ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)CMS_RevocationInfoChoice_it);
    }
  }
  return 0;
}

