
void PBKDF2PARAM_free(PBKDF2PARAM *a)

{
  ASN1_item_free((ASN1_VALUE *)a,(ASN1_ITEM *)PTR_PBKDF2PARAM_it_000c07c0);
  return;
}

