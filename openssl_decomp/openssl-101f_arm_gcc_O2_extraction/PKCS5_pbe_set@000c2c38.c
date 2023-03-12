
X509_ALGOR * PKCS5_pbe_set(int alg,int iter,uchar *salt,int saltlen)

{
  X509_ALGOR *alg_00;
  ASN1_STRING **val;
  int iVar1;
  uchar *buf;
  ASN1_STRING *pAVar2;
  ASN1_OBJECT *aobj;
  int line;
  ASN1_STRING *local_24;
  
  alg_00 = X509_ALGOR_new();
  if (alg_00 == (X509_ALGOR *)0x0) {
    ERR_put_error(0xd,0xca,0x41,"p5_pbe.c",0x8b);
    return (X509_ALGOR *)0x0;
  }
  local_24 = (ASN1_STRING *)0x0;
  val = (ASN1_STRING **)ASN1_item_new((ASN1_ITEM *)&PBEPARAM_it);
  if (val == (ASN1_STRING **)0x0) {
    ERR_put_error(0xd,0xd7,0x41,"p5_pbe.c",0x57);
    goto LAB_000c2cb8;
  }
  if (iter < 1) {
    iter = 0x800;
  }
  iVar1 = ASN1_INTEGER_set(val[1],iter);
  line = 0x5e;
  if (iVar1 == 0) {
LAB_000c2c9a:
    ERR_put_error(0xd,0xd7,0x41,"p5_pbe.c",line);
  }
  else {
    if (saltlen == 0) {
      saltlen = 8;
    }
    iVar1 = ASN1_STRING_set(*val,(void *)0x0,saltlen);
    line = 0x65;
    if (iVar1 == 0) goto LAB_000c2c9a;
    buf = ASN1_STRING_data(*val);
    if (salt != (uchar *)0x0) {
      memcpy(buf,salt,saltlen);
LAB_000c2ce2:
      pAVar2 = ASN1_item_pack(val,(ASN1_ITEM *)&PBEPARAM_it,&local_24);
      if (pAVar2 != (ASN1_STRING *)0x0) {
        ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)&PBEPARAM_it);
        aobj = OBJ_nid2obj(alg);
        iVar1 = X509_ALGOR_set0(alg_00,aobj,0x10,local_24);
        if (iVar1 != 0) {
          return alg_00;
        }
        goto LAB_000c2cb8;
      }
      line = 0x70;
      goto LAB_000c2c9a;
    }
    iVar1 = RAND_pseudo_bytes(buf,saltlen);
    if (-1 < iVar1) goto LAB_000c2ce2;
  }
  ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)&PBEPARAM_it);
LAB_000c2cb8:
  if (local_24 != (ASN1_STRING *)0x0) {
    ASN1_STRING_free(local_24);
  }
  X509_ALGOR_free(alg_00);
  return (X509_ALGOR *)0x0;
}

