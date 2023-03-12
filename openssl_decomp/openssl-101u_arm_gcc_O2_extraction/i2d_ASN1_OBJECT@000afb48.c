
int i2d_ASN1_OBJECT(ASN1_OBJECT *a,uchar **pp)

{
  uchar *puVar1;
  uint constructed;
  uchar *local_1c [2];
  
  if (a == (ASN1_OBJECT *)0x0) {
    return 0;
  }
  puVar1 = a->data;
  if (puVar1 != (uchar *)0x0) {
    puVar1 = (uchar *)ASN1_object_size(0,a->length,6);
    constructed = (uint)(pp == (uchar **)0x0 || puVar1 == (uchar *)0xffffffff);
    if (pp != (uchar **)0x0 && puVar1 != (uchar *)0xffffffff) {
      local_1c[0] = *pp;
      ASN1_put_object(local_1c,constructed,a->length,6,constructed);
      memcpy(local_1c[0],a->data,a->length);
      *pp = local_1c[0] + a->length;
      return (int)puVar1;
    }
  }
  return (int)puVar1;
}

