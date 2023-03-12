
int PKCS5_pbe_set0_algor(X509_ALGOR *algor,int alg,int iter,uchar *salt,int saltlen)

{
  ASN1_STRING **val;
  int iVar1;
  uchar *buf;
  ASN1_STRING *pAVar2;
  ASN1_OBJECT *aobj;
  int line;
  ASN1_STRING *local_24;
  
  local_24 = (ASN1_STRING *)0x0;
  val = (ASN1_STRING **)ASN1_item_new((ASN1_ITEM *)&PBEPARAM_it);
  if (val == (ASN1_STRING **)0x0) {
    ERR_put_error(0xd,0xd7,0x41,"p5_pbe.c",0x56);
    goto LAB_000c05a4;
  }
  if (iter < 1) {
    iter = 0x800;
  }
  iVar1 = ASN1_INTEGER_set(val[1],iter);
  line = 0x5c;
  if (iVar1 == 0) {
LAB_000c0586:
    ERR_put_error(0xd,0xd7,0x41,"p5_pbe.c",line);
  }
  else {
    if (saltlen == 0) {
      saltlen = 8;
    }
    iVar1 = ASN1_STRING_set(*val,(void *)0x0,saltlen);
    line = 0x62;
    if (iVar1 == 0) goto LAB_000c0586;
    buf = ASN1_STRING_data(*val);
    if (salt != (uchar *)0x0) {
      memcpy(buf,salt,saltlen);
LAB_000c05c8:
      pAVar2 = ASN1_item_pack(val,(ASN1_ITEM *)&PBEPARAM_it,&local_24);
      if (pAVar2 != (ASN1_STRING *)0x0) {
        ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)&PBEPARAM_it);
        aobj = OBJ_nid2obj(alg);
        iVar1 = X509_ALGOR_set0(algor,aobj,0x10,local_24);
        if (iVar1 != 0) {
          return 1;
        }
        goto LAB_000c05a4;
      }
      line = 0x6c;
      goto LAB_000c0586;
    }
    iVar1 = RAND_bytes(buf,saltlen);
    if (0 < iVar1) goto LAB_000c05c8;
  }
  ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)&PBEPARAM_it);
LAB_000c05a4:
  if (local_24 != (ASN1_STRING *)0x0) {
    ASN1_STRING_free(local_24);
    local_24 = (ASN1_STRING *)0x0;
  }
  return (int)local_24;
}

