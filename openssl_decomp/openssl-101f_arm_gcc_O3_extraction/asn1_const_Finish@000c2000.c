
int asn1_const_Finish(ASN1_const_CTX *c)

{
  int iVar1;
  uchar *puVar2;
  
  if ((c->inf == 0x21) && (c->eos == 0)) {
    iVar1 = c->slen;
    if (iVar1 < 1) goto LAB_000c200c;
    if (((iVar1 == 1) || (puVar2 = c->p, *puVar2 != '\0')) || (puVar2[1] != '\0')) {
      c->error = 0x3f;
      return 0;
    }
    c->p = puVar2 + 2;
  }
  else {
    iVar1 = c->slen;
LAB_000c200c:
    if (iVar1 == 0) {
      return 1;
    }
    if (-1 < c->inf << 0x1f) goto LAB_000c201e;
  }
  if (-1 < iVar1) {
    return 1;
  }
LAB_000c201e:
  c->error = 0x3e;
  return 0;
}

