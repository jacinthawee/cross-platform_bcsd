
int ASN1_template_new(ASN1_VALUE **pval,ASN1_TEMPLATE *tt)

{
  _STACK *p_Var1;
  int iVar2;
  uint uVar3;
  
  uVar3 = tt->flags;
  if ((int)(uVar3 << 0x1f) < 0) {
    if ((uVar3 & 0x306) == 0) {
      asn1_item_clear();
      return 1;
    }
  }
  else if ((uVar3 & 0x300) == 0) {
    if ((uVar3 & 6) == 0) {
      iVar2 = asn1_item_ex_combine_new(pval,tt->item,uVar3 & 0x400);
      return iVar2;
    }
    p_Var1 = sk_new_null();
    if (p_Var1 == (_STACK *)0x0) {
      ERR_put_error(0xd,0x85,0x41,"tasn_new.c",0x125);
      return 0;
    }
    *pval = (ASN1_VALUE *)p_Var1;
    return 1;
  }
  *pval = (ASN1_VALUE *)0x0;
  return 1;
}

