
int asn1_Finish(ASN1_CTX *c)

{
  int iVar1;
  uchar *puVar2;
  
  if (c->inf == 0x21) {
    iVar1 = c->slen;
    if ((c->eos == 0) && (0 < iVar1)) {
      if ((iVar1 != 1) && ((puVar2 = c->p, *puVar2 == '\0' && (puVar2[1] == '\0')))) {
        c->p = puVar2 + 2;
        return 1;
      }
      c->error = 0x3f;
      return 0;
    }
    if (iVar1 == 0) {
      return 1;
    }
  }
  else {
    iVar1 = c->slen;
    if (iVar1 == 0) {
      return 1;
    }
    if ((c->inf & 1U) == 0) {
      c->error = 0x3e;
      return 0;
    }
  }
  if (-1 < iVar1) {
    return 1;
  }
  c->error = 0x3e;
  return 0;
}

