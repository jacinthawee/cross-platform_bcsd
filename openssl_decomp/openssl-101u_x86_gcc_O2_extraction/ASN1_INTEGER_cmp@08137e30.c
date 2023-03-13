
int ASN1_INTEGER_cmp(ASN1_INTEGER *x,ASN1_INTEGER *y)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = x->type & 0x100;
  if (uVar2 != (y->type & 0x100U)) {
    return (-(uint)(uVar2 == 0) & 2) - 1;
  }
  iVar1 = ASN1_STRING_cmp(x,y);
  if (uVar2 != 0) {
    iVar1 = -iVar1;
  }
  return iVar1;
}

