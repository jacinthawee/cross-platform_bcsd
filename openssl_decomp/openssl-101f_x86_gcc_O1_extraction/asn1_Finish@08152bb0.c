
int asn1_Finish(ASN1_CTX *c)

{
  uchar *puVar1;
  int iVar2;
  
  if (c->inf == 0x21) {
    iVar2 = c->slen;
    if ((c->eos == 0) && (0 < iVar2)) {
      if ((iVar2 != 1) && ((puVar1 = c->p, *puVar1 == '\0' && (puVar1[1] == '\0')))) {
        c->p = puVar1 + 2;
        return 1;
      }
      c->error = 0x3f;
      return c->eos;
    }
    if (iVar2 == 0) {
      return 1;
    }
  }
  else {
    iVar2 = c->slen;
    if (iVar2 == 0) {
      return 1;
    }
    if ((c->inf & 1U) == 0) {
      c->error = 0x3e;
      return 0;
    }
  }
  if (-1 < iVar2) {
    return 1;
  }
  c->error = 0x3e;
  return 0;
}

