
int ASN1_TYPE_get(ASN1_TYPE *a)

{
  int iVar1;
  
  iVar1 = a->type;
  if ((a->value).ptr != (char *)0x0) {
    return iVar1;
  }
  if (iVar1 != 5) {
    iVar1 = 0;
  }
  return iVar1;
}

