
void ASN1_TYPE_set(ASN1_TYPE *a,int type,void *value)

{
  ASN1_BOOLEAN AVar1;
  ASN1_TYPE *local_14 [2];
  
  local_14[0] = a;
  if ((a->value).ptr == (char *)0x0) {
    a->type = type;
    if (type != 1) {
      (a->value).ptr = (char *)value;
      return;
    }
  }
  else {
    ASN1_primitive_free((ASN1_VALUE **)local_14,(ASN1_ITEM *)0x0);
    local_14[0]->type = type;
    if (type != 1) {
      (local_14[0]->value).ptr = (char *)value;
      return;
    }
  }
  if (value == (void *)0x0) {
    AVar1 = 0;
  }
  else {
    AVar1 = 0xff;
  }
  (local_14[0]->value).boolean = AVar1;
  return;
}

