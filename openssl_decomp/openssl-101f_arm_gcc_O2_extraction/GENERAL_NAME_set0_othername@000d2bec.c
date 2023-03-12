
int GENERAL_NAME_set0_othername(GENERAL_NAME *gen,ASN1_OBJECT *oid,ASN1_TYPE *value)

{
  OTHERNAME *pOVar1;
  
  pOVar1 = (OTHERNAME *)ASN1_item_new((ASN1_ITEM *)PTR_OTHERNAME_it_000d2c10);
  if (pOVar1 != (OTHERNAME *)0x0) {
    pOVar1->type_id = oid;
    pOVar1->value = value;
    gen->type = 0;
    (gen->d).otherName = pOVar1;
    return 1;
  }
  return 0;
}

