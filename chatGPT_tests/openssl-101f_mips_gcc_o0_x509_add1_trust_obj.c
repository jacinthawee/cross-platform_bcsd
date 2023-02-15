
int X509_add1_trust_object(X509 *x,ASN1_OBJECT *obj)

{
  ASN1_OBJECT *data;
  int iVar1;
  _STACK *st;
  _STACK **pp_Var2;
  
  data = OBJ_dup(obj);
  if ((data != (ASN1_OBJECT *)0x0) && (x != (X509 *)0x0)) {
    pp_Var2 = *(_STACK ***)(x->sha1_hash + 0xc);
    if (pp_Var2 == (_STACK **)0x0) {
      pp_Var2 = (_STACK **)ASN1_item_new((ASN1_ITEM *)X509_CERT_AUX_it);
      *(_STACK ***)(x->sha1_hash + 0xc) = pp_Var2;
      if (pp_Var2 == (_STACK **)0x0) {
        return 0;
      }
    }
    st = *pp_Var2;
    if (st == (_STACK *)0x0) {
      st = sk_new_null();
      *pp_Var2 = st;
      if (st == (_STACK *)0x0) {
        return 0;
      }
    }
                    /* WARNING: Treating indirect jump as call */
    iVar1 = sk_push(st,data);
    return iVar1;
  }
  return 0;
}

