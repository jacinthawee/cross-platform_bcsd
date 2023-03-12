
void ASN1_TYPE_set(ASN1_TYPE *a,int type,void *value)

{
  ASN1_BOOLEAN AVar1;
  ASN1_TYPE *local_res0 [4];
  
  if ((a->value).ptr == (char *)0x0) {
    a->type = type;
  }
  else {
    local_res0[0] = a;
    ASN1_primitive_free((ASN1_VALUE **)local_res0,(ASN1_ITEM *)0x0);
    local_res0[0]->type = type;
    a = local_res0[0];
  }
  if (type != 1) {
    (a->value).ptr = (char *)value;
    return;
  }
  AVar1 = 0xff;
  if (value == (void *)0x0) {
    AVar1 = 0;
  }
  (a->value).boolean = AVar1;
  return;
}

