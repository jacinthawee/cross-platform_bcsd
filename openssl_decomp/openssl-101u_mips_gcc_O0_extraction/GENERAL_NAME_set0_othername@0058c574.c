
int GENERAL_NAME_set0_othername(GENERAL_NAME *gen,ASN1_OBJECT *oid,ASN1_TYPE *value)

{
  OTHERNAME *pOVar1;
  
  pOVar1 = (OTHERNAME *)(*(code *)PTR_ASN1_item_new_006a8654)(OTHERNAME_it);
  if (pOVar1 != (OTHERNAME *)0x0) {
    pOVar1->type_id = oid;
    pOVar1->value = value;
    (gen->d).otherName = pOVar1;
    gen->type = 0;
    return 1;
  }
  return 0;
}

