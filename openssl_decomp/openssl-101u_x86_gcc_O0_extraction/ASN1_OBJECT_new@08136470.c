
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ASN1_OBJECT * ASN1_OBJECT_new(void)

{
  ASN1_OBJECT *pAVar1;
  
  pAVar1 = (ASN1_OBJECT *)CRYPTO_malloc(0x18,"a_object.c",0x15e);
  if (pAVar1 == (ASN1_OBJECT *)0x0) {
    ERR_put_error(0xd,0x7b,0x41,"a_object.c",0x160);
    pAVar1 = (ASN1_OBJECT *)0x0;
  }
  else {
    pAVar1->length = 0;
    pAVar1->data = (uchar *)0x0;
    pAVar1->nid = 0;
    pAVar1->sn = (char *)0x0;
    pAVar1->ln = (char **)0x0;
    pAVar1->flags = 1;
  }
  return pAVar1;
}

