
void ASN1_TYPE_set(ASN1_TYPE *a,int type,void *value)

{
  int iVar1;
  
  iVar1 = type;
  if ((a->value).ptr != (char *)0x0) {
    ASN1_primitive_free((ASN1_VALUE **)&a,(ASN1_ITEM *)0x0);
  }
  a->type = iVar1;
  if (iVar1 != 1) {
    (a->value).ptr = (char *)value;
    return;
  }
  (a->value).boolean = ~-(uint)(value == (void *)0x0) & 0xff;
  return;
}

